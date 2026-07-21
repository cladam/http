// server_cooperative_worker.hc — Cooperative Concurrency Server Example
//
// Demonstrates Pattern A (The Non-blocking Background Worker / Webhook Processor)
// using hica's high-level HTTP non-blocking FFI and built-in actor model.
//
// In this example, the HTTP route handler does not do any blocking processing.
// Instead, it enqueues the payload to an asynchronous actor's queue and
// immediately responds with `202 Accepted`. The main thread cooperatively
// polls the HTTP server and dispatches messages to the worker, ensuring the
// server remains highly responsive.

import "../src/http_server"
import "std/actor"

// --- Message Type ---
type WorkerMsg {
  ProcessPayload(data: string)
}

// --- Background Actor ---
actor WebhookWorker {
  var processed_count = 0

  receive(msg) => match msg {
    ProcessPayload(data) => {
      processed_count = processed_count + 1
      println("  [Worker] Processed webhook #" + show(processed_count) + " data: " + data)
    }
  }
}

// --- Main Entrypoint ---
pub fun main() {
  println("Initializing cooperative HTTP server on port 8080...")

  // We initialize the actor's state as a local variable
  var worker_state = WebhookWorkerState { processed_count: 0 }
  var pending_payloads = []

  // Register the non-blocking HTTP handler.
  // When a request comes in, we respond immediately with 202 Accepted.
  let srv = server_init(8080, (req) => {
    accepted("\{\"status\": \"queued\"\}")
  })

  println("Cooperative loop active. Sending some self-test requests...")

  // Run the cooperative loop, passing state explicitly
  run_loop(srv, 0, worker_state, pending_payloads)

  // Clean up
  server_stop(srv)
}

// --- Cooperative Loop ---
pub fun run_loop(srv: int, ticks: int, worker: WebhookWorkerState, payloads: list<string>) : () {
  // 1. Process one HTTP server poll cycle
  let _ = server_poll(srv)

  // 2. Perform mock self-test triggers to simulate incoming connections on ticks
  let current_payloads = if ticks == 5 {
    println("\n[Mock Client] POST /webhook body: 'payload_A'")
    payloads + ["payload_A"]
  } else if ticks == 15 {
    println("\n[Mock Client] POST /webhook body: 'payload_B'")
    payloads + ["payload_B"]
  } else {
    payloads
  }

  // 3. Process cooperative background worker tasks
  match current_payloads {
    [] => {
      if ticks < 30 {
        run_loop(srv, ticks + 1, worker, [])
      } else {
        println("\nSimulation complete. Stopping HTTP server.")
      }
    }
    [payload, ..rest] => {
      println("Scheduler: Dispatching task to WebhookWorker...")
      let next_worker = webhookworker_receive(worker, ProcessPayload(payload))
      if ticks < 30 {
        run_loop(srv, ticks + 1, next_worker, rest)
      } else {
        println("\nSimulation complete. Stopping HTTP server.")
      }
    }
  }
}
