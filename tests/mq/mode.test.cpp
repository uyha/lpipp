#include <catch2/catch.hpp>
#include <lpipp/mq.hpp>

using namespace lpipp::mq_constants;

TEST_CASE("open mode combinations") {

  CHECK(static_cast<int>(ReadOnly) == (O_RDONLY));
  CHECK(static_cast<int>(ReadOnly | Create) == (O_RDONLY | O_CREAT));
  CHECK(static_cast<int>(Create | ReadOnly) == (O_RDONLY | O_CREAT));
  CHECK(static_cast<int>(ReadOnly | Create | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL));
  CHECK(static_cast<int>(ReadOnly | Exclusive | Create) == (O_RDONLY | O_CREAT | O_EXCL));
  CHECK(static_cast<int>(Create | ReadOnly | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL));
  CHECK(static_cast<int>(Create | Exclusive | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL));
  CHECK(static_cast<int>(Exclusive | ReadOnly | Create) == (O_RDONLY | O_CREAT | O_EXCL));
  CHECK(static_cast<int>(Exclusive | Create | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL));
  CHECK(static_cast<int>(ReadOnly | Create | Exclusive | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(ReadOnly | Create | CloseOnExec | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(ReadOnly | Exclusive | Create | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(ReadOnly | Exclusive | CloseOnExec | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(ReadOnly | CloseOnExec | Create | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(ReadOnly | CloseOnExec | Exclusive | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(Create | ReadOnly | Exclusive | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(Create | ReadOnly | CloseOnExec | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(Create | Exclusive | ReadOnly | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(Create | Exclusive | CloseOnExec | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(Create | CloseOnExec | ReadOnly | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(Create | CloseOnExec | Exclusive | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(Exclusive | ReadOnly | Create | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(Exclusive | ReadOnly | CloseOnExec | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(Exclusive | Create | ReadOnly | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(Exclusive | Create | CloseOnExec | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(Exclusive | CloseOnExec | ReadOnly | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(Exclusive | CloseOnExec | Create | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(CloseOnExec | ReadOnly | Create | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(CloseOnExec | ReadOnly | Exclusive | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(CloseOnExec | Create | ReadOnly | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(CloseOnExec | Create | Exclusive | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(CloseOnExec | Exclusive | ReadOnly | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(CloseOnExec | Exclusive | Create | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC));
  CHECK(static_cast<int>(ReadOnly | Create | Exclusive | CloseOnExec | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | Create | Exclusive | Nonblock | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | Create | CloseOnExec | Exclusive | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | Create | CloseOnExec | Nonblock | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | Create | Nonblock | Exclusive | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | Create | Nonblock | CloseOnExec | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | Exclusive | Create | CloseOnExec | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | Exclusive | Create | Nonblock | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | Exclusive | CloseOnExec | Create | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | Exclusive | CloseOnExec | Nonblock | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | Exclusive | Nonblock | Create | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | Exclusive | Nonblock | CloseOnExec | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | CloseOnExec | Create | Exclusive | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | CloseOnExec | Create | Nonblock | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | CloseOnExec | Exclusive | Create | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | CloseOnExec | Exclusive | Nonblock | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | CloseOnExec | Nonblock | Create | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | CloseOnExec | Nonblock | Exclusive | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | Nonblock | Create | Exclusive | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | Nonblock | Create | CloseOnExec | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | Nonblock | Exclusive | Create | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | Nonblock | Exclusive | CloseOnExec | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | Nonblock | CloseOnExec | Create | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(ReadOnly | Nonblock | CloseOnExec | Exclusive | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | ReadOnly | Exclusive | CloseOnExec | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | ReadOnly | Exclusive | Nonblock | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | ReadOnly | CloseOnExec | Exclusive | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | ReadOnly | CloseOnExec | Nonblock | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | ReadOnly | Nonblock | Exclusive | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | ReadOnly | Nonblock | CloseOnExec | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | Exclusive | ReadOnly | CloseOnExec | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | Exclusive | ReadOnly | Nonblock | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | Exclusive | CloseOnExec | ReadOnly | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | Exclusive | CloseOnExec | Nonblock | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | Exclusive | Nonblock | ReadOnly | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | Exclusive | Nonblock | CloseOnExec | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | CloseOnExec | ReadOnly | Exclusive | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | CloseOnExec | ReadOnly | Nonblock | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | CloseOnExec | Exclusive | ReadOnly | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | CloseOnExec | Exclusive | Nonblock | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | CloseOnExec | Nonblock | ReadOnly | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | CloseOnExec | Nonblock | Exclusive | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | Nonblock | ReadOnly | Exclusive | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | Nonblock | ReadOnly | CloseOnExec | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | Nonblock | Exclusive | ReadOnly | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | Nonblock | Exclusive | CloseOnExec | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | Nonblock | CloseOnExec | ReadOnly | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Create | Nonblock | CloseOnExec | Exclusive | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | ReadOnly | Create | CloseOnExec | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | ReadOnly | Create | Nonblock | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | ReadOnly | CloseOnExec | Create | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | ReadOnly | CloseOnExec | Nonblock | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | ReadOnly | Nonblock | Create | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | ReadOnly | Nonblock | CloseOnExec | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | Create | ReadOnly | CloseOnExec | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | Create | ReadOnly | Nonblock | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | Create | CloseOnExec | ReadOnly | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | Create | CloseOnExec | Nonblock | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | Create | Nonblock | ReadOnly | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | Create | Nonblock | CloseOnExec | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | CloseOnExec | ReadOnly | Create | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | CloseOnExec | ReadOnly | Nonblock | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | CloseOnExec | Create | ReadOnly | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | CloseOnExec | Create | Nonblock | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | CloseOnExec | Nonblock | ReadOnly | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | CloseOnExec | Nonblock | Create | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | Nonblock | ReadOnly | Create | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | Nonblock | ReadOnly | CloseOnExec | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | Nonblock | Create | ReadOnly | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | Nonblock | Create | CloseOnExec | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | Nonblock | CloseOnExec | ReadOnly | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Exclusive | Nonblock | CloseOnExec | Create | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | ReadOnly | Create | Exclusive | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | ReadOnly | Create | Nonblock | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | ReadOnly | Exclusive | Create | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | ReadOnly | Exclusive | Nonblock | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | ReadOnly | Nonblock | Create | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | ReadOnly | Nonblock | Exclusive | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | Create | ReadOnly | Exclusive | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | Create | ReadOnly | Nonblock | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | Create | Exclusive | ReadOnly | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | Create | Exclusive | Nonblock | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | Create | Nonblock | ReadOnly | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | Create | Nonblock | Exclusive | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | Exclusive | ReadOnly | Create | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | Exclusive | ReadOnly | Nonblock | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | Exclusive | Create | ReadOnly | Nonblock) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | Exclusive | Create | Nonblock | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | Exclusive | Nonblock | ReadOnly | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | Exclusive | Nonblock | Create | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | Nonblock | ReadOnly | Create | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | Nonblock | ReadOnly | Exclusive | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | Nonblock | Create | ReadOnly | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | Nonblock | Create | Exclusive | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | Nonblock | Exclusive | ReadOnly | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(CloseOnExec | Nonblock | Exclusive | Create | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | ReadOnly | Create | Exclusive | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | ReadOnly | Create | CloseOnExec | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | ReadOnly | Exclusive | Create | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | ReadOnly | Exclusive | CloseOnExec | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | ReadOnly | CloseOnExec | Create | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | ReadOnly | CloseOnExec | Exclusive | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | Create | ReadOnly | Exclusive | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | Create | ReadOnly | CloseOnExec | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | Create | Exclusive | ReadOnly | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | Create | Exclusive | CloseOnExec | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | Create | CloseOnExec | ReadOnly | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | Create | CloseOnExec | Exclusive | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | Exclusive | ReadOnly | Create | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | Exclusive | ReadOnly | CloseOnExec | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | Exclusive | Create | ReadOnly | CloseOnExec) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | Exclusive | Create | CloseOnExec | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | Exclusive | CloseOnExec | ReadOnly | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | Exclusive | CloseOnExec | Create | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | CloseOnExec | ReadOnly | Create | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | CloseOnExec | ReadOnly | Exclusive | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | CloseOnExec | Create | ReadOnly | Exclusive) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | CloseOnExec | Create | Exclusive | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | CloseOnExec | Exclusive | ReadOnly | Create) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
  CHECK(static_cast<int>(Nonblock | CloseOnExec | Exclusive | Create | ReadOnly) == (O_RDONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NONBLOCK));
}
