#include <catch2/catch.hpp>
#include <ipcpp/mq.hpp>

using namespace ipcpp;
using namespace mq_constants;

TEST_CASE("sending and reading attributes") {
  SECTION("blocking then nonblocking") {
    auto name  = "/send";
    auto queue = mq::open(name, create | write_only, 0666, {.max_messages = 1, .max_message_size = 8});
    CHECK(queue->send(name, 0, 0));
    {
      auto attributes = queue->get_attributes();
      CHECK(attributes.mq_curmsgs == 1);
    }
    {
      queue->set_nonblock();
      auto result = queue->send(name, 0, 0);
      CHECK(not result);
      CHECK(result.error() == mq::SendError::queue_full);
    }
    CHECK(mq::unlink(name));
  }
  SECTION("nonblocking") {
    auto name  = "/send";
    auto queue = mq::open(name, create | write_only | nonblock, 0666, {.max_messages = 1, .max_message_size = 8});
    CHECK(queue->send(name, 0, 0));
    {
      auto attributes = queue->get_attributes();
      CHECK(attributes.mq_curmsgs == 1);
    }
    {
      auto result = queue->send(name, 0, 0);
      CHECK(not result);
      CHECK(result.error() == mq::SendError::queue_full);
      auto attributes = queue->get_attributes();
      CHECK(attributes.mq_curmsgs == 1);
    }
    CHECK(mq::unlink(name));
  }
}