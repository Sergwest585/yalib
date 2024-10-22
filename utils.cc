
#pragma once

#include "types.cc"
#include "io.cc"

#include <vector>
#include <string>
#include <generator>
#include <cassert>

#define nameof(x) #x

constexpr size_t in(std::string str, std::vector<std::string> arr) {
  for (size_t i = 0; i < arr.size(); ++i) {
    if (str == arr[i]) return i;
  }
  return -1;
}
constexpr size_t in(char chr, std::vector<char> arr) {
  for (size_t i = 0; i < arr.size(); ++i) {
    if (chr == arr[i]) return i;
  }
  return -1;
}
constexpr size_t in(char chr, std::string str) {
  for (size_t i = 0; i < str.length(); ++i) {
    if (chr == str[i]) return i;
  }
  return -1;
}

constexpr size_t has(std::string str, std::vector<char> arr) {
  for (size_t i = 0; i < arr.size(); ++i) {
    if (in(arr[i], str) != -1) return i;
  }
  return -1;
}

#define f std::format

std::generator<std::vector<size_t>> all_cmb(std::size_t range, std::size_t len) {
  assert(range >= len);
  std::string bitmask(len, 1);
  bitmask.resize(range, 0);
  std::vector<size_t> arr(len);
  int iar;
  do {
    iar = 0;
    for (int i = 0; i < range; ++i) {
      if (bitmask[i]) {
	arr[iar] = i;
	++iar;
      }
    }
    co_yield arr;
  } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
}
