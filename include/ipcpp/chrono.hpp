#pragma once

#include <bits/types/struct_timespec.h>
#include <chrono>

namespace ipcpp {
template <typename Duration>
constexpr auto to_timespec(std::chrono::time_point<std::chrono::system_clock, Duration> const &timepoint) noexcept
    -> ::timespec {
  using namespace std::chrono;
  auto timepoint_s  = time_point_cast<seconds>(timepoint);
  auto timepoint_ns = time_point_cast<nanoseconds>(timepoint);

  auto sec = timepoint_s.time_since_epoch().count();
  auto nsec =
      timepoint_ns.time_since_epoch().count() - time_point_cast<nanoseconds>(timepoint_s).time_since_epoch().count();

  return {.tv_sec = sec, .tv_nsec = nsec};
}
} // namespace ipcpp