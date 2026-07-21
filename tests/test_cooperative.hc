// tests/test_cooperative.hc — Unit tests for non-blocking HTTP polling and actors
//
// Verifies that the server initialization, polling, and shutdown primitives
// can be used cooperatively alongside hica's built-in actor model.

import "../src/http_server"
import "std/actor"

// --- Message Type ---
type TestMsg {
  RunTask(id: int)
}

// --- Test Actor ---
actor TestWorker {
  var count = 0

  receive(msg) => match msg {
    RunTask(id) => {
      count = count + 1
    }
  }
}

// ============================================================
// Cooperative Execution Tests
// ============================================================

test "cooperative polling starts, polls, and stops" {
  // Initialize the server on a non-clashing test port
  let srv = server_init(8185, (req) => {
    accepted("ok")
  })

  // Perform a non-blocking poll
  server_poll(srv)

  // Verify actor works and maintains state
  var worker = TestWorkerState { count: 0 }
  worker = testworker_receive(worker, RunTask(100))
  assert(worker.count == 1)

  // Stop the server
  server_stop(srv)
}
