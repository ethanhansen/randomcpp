#include <algorithm>
#include <array>
#include <concepts>
#include <iostream>
#include <utility>
#include <vector>

constexpr bool isEven(int v) { return (v % 2 == 0); };

template <std::size_t upTo, auto filter>
constexpr auto compileTimeFilteredVecImpl() {
  auto vec = std::vector<int>();

  for (auto i = 0; i < upTo; ++i)
    if (filter(i))
      vec.push_back(i);

  return vec;
}

template <std::size_t upTo, auto filter> constexpr auto compileTimeFiltered() {
  const auto vec = compileTimeFilteredVecImpl<upTo, filter>();
  std::array<int, compileTimeFilteredVecImpl<upTo, filter>().size()> arr;
  std::copy(std::begin(vec), std::end(vec), std::begin(arr));
  return arr;
}

int main() { constexpr auto filtered = compileTimeFiltered<10, isEven>(); }