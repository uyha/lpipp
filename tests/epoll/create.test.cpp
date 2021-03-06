#include <catch2/catch.hpp>
#include <lpipp/epoll.hpp>

using namespace lpipp;

TEST_CASE("creating an epoll") {
  SECTION("without close_on_exec") {
    auto epoll_instance = epoll::create();
    REQUIRE(epoll_instance);
  }
  SECTION("with close_on_exec") {
    auto epoll_instance = epoll::create(true);
    REQUIRE(epoll_instance);
  }
}
