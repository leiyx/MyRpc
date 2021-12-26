#ifndef UTILS_H
#define UTILS_H
#include <chrono>
#include <functional>
#include <iostream>
static void TestTime(std::function<void()> f) {
  using namespace std::literals;  // 允许用 24h 、 1ms 、 1s 代替对应的
                                  // std::chrono::hours(24) 等待
  const std::chrono::time_point<std::chrono::steady_clock> start =
      std::chrono::steady_clock::now();
  // “现实生活”的替用写法会是：
  // const auto start = std::chrono::steady_clock::now();
  f();

  const auto end = std::chrono::steady_clock::now();
  std::cout << "f took "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << "µs ≈ " << (end - start) / 1ms
            << "ms ≈ "                        // 几乎等价于以上形式，
            << (end - start) / 1s << "s.\n";  // 但分别使用毫秒和秒
  return;
}
#endif