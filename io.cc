
#pragma once

#include "types.cc"

#include <print>
#include <cstdio>
#include <typeinfo>
#include <vector>
#include <concepts>
#include <cinttypes>
#include <fstream>
#include <sstream>
#include <utility>


/* ==================== WRITE ==================== */

template<typename T>
concept HasPrint = requires(T t) {
  {t.__print__()} -> std::convertible_to<void>;
};
template<typename T>
concept HasPrintil = requires(T t) {
  {t.__printil__()} -> std::convertible_to<void>;
};

[[maybe_unused]] constexpr void print() {putc('\n', stdout);}


[[maybe_unused]] constexpr void printil(i8  a) {printf("%" PRId8,  a);}
[[maybe_unused]] constexpr void printil(i16 a) {printf("%" PRId16, a);}
[[maybe_unused]] constexpr void printil(i32 a) {printf("%" PRId32, a);}
[[maybe_unused]] constexpr void printil(i64 a) {printf("%" PRId64, a);}

[[maybe_unused]] constexpr void printil(u8  a) {printf("%" PRIu8,  a);}
[[maybe_unused]] constexpr void printil(u16 a) {printf("%" PRIu16, a);}
[[maybe_unused]] constexpr void printil(u32 a) {printf("%" PRIu32, a);}
[[maybe_unused]] constexpr void printil(u64 a) {printf("%" PRIu64, a);}

[[maybe_unused]] constexpr void printil(char a)        {printf("%c", a);}
[[maybe_unused]] constexpr void printil(const char* a) {printf("%s", a);}
[[maybe_unused]] constexpr void printil(std::string a) {std::print("{}", a);}

[[maybe_unused]] constexpr void printil(float a)  {printf("%g",  a);}
[[maybe_unused]] constexpr void printil(double a) {printf("%lg", a);}

[[maybe_unused]] constexpr void printil(bool a) {if(a) puts("true"); else puts("false");}

template<typename T, typename U>
[[maybe_unused]] constexpr void printil(std::pair<T, U> a) {printil('<', a.first, ", ", a.second, '>');}
template<typename T>
[[maybe_unused]] constexpr void printil(std::vector<T> a) {
  if (a.size() == 0) {printil("{}"); return;}
  printil('{');for(size_t i=0;i<a.size()-1;++i){ printil(a[i]); printil(", ");}
  printil(a.back()); printil('}');
}
template<typename T, std::size_t size>
[[maybe_unused]] constexpr void printil(std::array<T, size> a) {
  if (size == 0) {printil("{}"); return;}
  printil('{');for(size_t i=0;i<size-1;++i){ printil(a[i]); printil(", ");}
  printil(a.back()); printil('}');
}

template<HasPrintil T>
[[maybe_unused]] constexpr void printil(T t) {t.__printil__();}

template<typename T>
[[maybe_unused, deprecated("unsupported printil")]] __attribute__((warning("unsupported printil"))) constexpr void printil(T t) {puts(typeid(t).name());}



[[maybe_unused]] constexpr void print(i8  a) {printf("%" PRId8  "\n", a);}
[[maybe_unused]] constexpr void print(i16 a) {printf("%" PRId16 "\n", a);}
[[maybe_unused]] constexpr void print(i32 a) {printf("%" PRId32 "\n", a);}
[[maybe_unused]] constexpr void print(i64 a) {printf("%" PRId64 "\n", a);}

[[maybe_unused]] constexpr void print(u8  a) {printf("%" PRIu8  "\n", a);}
[[maybe_unused]] constexpr void print(u16 a) {printf("%" PRIu16 "\n", a);}
[[maybe_unused]] constexpr void print(u32 a) {printf("%" PRIu32 "\n", a);}
[[maybe_unused]] constexpr void print(u64 a) {printf("%" PRIu64 "\n", a);}

[[maybe_unused]] constexpr void print(char a)        {printf("%c\n", a);}
[[maybe_unused]] constexpr void print(const char* a) {printf("%s\n", a);}
[[maybe_unused]] constexpr void print(std::string a) {std::print("{}\n", a);}

[[maybe_unused]] constexpr void print(float a)  {printf("%g\n",  a);}
[[maybe_unused]] constexpr void print(double a) {printf("%lg\n", a);}

[[maybe_unused]] constexpr void print(bool a) {if(a) puts("true\n"); else puts("false\n");}

template<typename T, typename U>
[[maybe_unused]] constexpr void print(std::pair<T, U> a) {printil('<', a.first, ", ", a.second, ">\n");}
template<typename T>
[[maybe_unused]] constexpr void print(std::vector<T> a) {
  if (a.size() == 0) {print("{}"); return;}
  printil('{');for(size_t i=0;i<a.size()-1;++i){ printil(a[i]); printil(", ");}
  printil(a.back()); printil("}\n");
}
template<typename T, std::size_t size>
[[maybe_unused]] constexpr void print(std::array<T, size> a) {
  if (size == 0) {print("{}"); return;}
  printil('{');for(size_t i=0;i<size-1;++i){ printil(a[i]); printil(", ");}
  printil(a.back()); printil("}\n");
}

template<HasPrint T>
[[maybe_unused]] constexpr void print(T t) {t.__print__();}

template<typename T>
[[maybe_unused, deprecated("unsupported print")]] __attribute__((warning("unsupported print"))) constexpr void print(T t) {puts(typeid(t).name());}




template<typename T, typename... Ts>
[[maybe_unused]] constexpr void print(T t, Ts ...ts) {printil(t); print(ts...);}

template<typename T, typename... Ts>
[[maybe_unused]] constexpr void printil(T t, Ts ...ts) {printil(t); printil(ts...);}

template<typename T>
[[maybe_unused]] constexpr void prints(T sep) {print();}
template<typename T, typename... Ts>
[[maybe_unused]] constexpr void prints(char sep, T t, Ts ...ts) {printil(t); printil(sep); prints(sep, ts...);}
template<typename T, typename... Ts>
[[maybe_unused]] constexpr void prints(std::string sep, T t, Ts ...ts) {printil(t); printil(sep); prints(sep, ts...);}

#define info(x) printil(x); printil(' '); print(#x);

namespace term {
  const std::string black    = "\x1B[30m";
  const std::string red      = "\x1B[31m";
  const std::string green    = "\x1B[32m";
  const std::string yellow   = "\x1B[33m";
  const std::string blue     = "\x1B[34m";
  const std::string magenta  = "\x1B[35m";
  const std::string cyan     = "\x1B[36m";
  const std::string lgray    = "\x1B[37m";
  const std::string gray     = "\x1B[90m";
  const std::string lred     = "\x1B[91m";
  const std::string lgreen   = "\x1B[92m";
  const std::string lorange  = "\x1B[93m";
  const std::string lblue    = "\x1B[94m";
  const std::string lmagenta = "\x1B[95m";
  const std::string lcyan    = "\x1B[96m";
  const std::string white    = "\x1B[97m";
  const std::string reset    = "\x1B[0m";
};

/* ==================== WRITE ==================== */
/* ==================== READ ==================== */

template<typename T>
concept HasRead = requires(T t) {
  {t.__read__()} -> std::convertible_to<void>;
};

[[maybe_unused]] constexpr void read(i8  &a) {scanf("%" PRId8 , &a);}
[[maybe_unused]] constexpr void read(i16 &a) {scanf("%" PRId16, &a);}
[[maybe_unused]] constexpr void read(i32 &a) {scanf("%" PRId32, &a);}
[[maybe_unused]] constexpr void read(i64 &a) {scanf("%" PRId64, &a);}

[[maybe_unused]] constexpr void read(u8  &a) {scanf("%" PRIu8 , &a);}
[[maybe_unused]] constexpr void read(u16 &a) {scanf("%" PRIu16, &a);}
[[maybe_unused]] constexpr void read(u32 &a) {scanf("%" PRIu32, &a);}
[[maybe_unused]] constexpr void read(u64 &a) {scanf("%" PRIu64, &a);}

[[maybe_unused]] constexpr void read(char &a)        {scanf("%c", &a);}
[[maybe_unused]] constexpr void read(const char* &a) {scanf("%s", &a);}
[[maybe_unused]] constexpr void read(std::string &a) {a.reserve(256); scanf("%s", a.data());}

[[maybe_unused]] constexpr void read(float &a)  {scanf("%f",  &a);}
[[maybe_unused]] constexpr void read(double &a) {scanf("%lf", &a);}

template<HasRead T>
[[maybe_unused]] constexpr void read(T &t) {t.__read__();}

template<typename T>
[[maybe_unused, deprecated("unsupported read")]] __attribute__((warning("unsupported read"))) constexpr void read(T &t) {puts(typeid(t).name());}

template<typename T, typename... Ts>
[[maybe_unused]] constexpr void read(T &t, Ts &...ts) {read(t); read(ts...);}

std::string read_file(std::ifstream file) {
  std::stringstream buffer;
  buffer << file.rdbuf();
  return buffer.str();
}
std::string read_file(std::string filename) {
  return read_file(std::ifstream(filename));
}

/* ==================== READ ==================== */
