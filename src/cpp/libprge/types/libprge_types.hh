#ifndef LIBPRGE_TYPES_HH
#define LIBPRGE_TYPES_HH
#include <cstdint>
#include <string>
#include <array>

#include <thread>
#include <memory>
#include <future>

#include <iomanip>

// alter type of int32_t
typedef int32_t i32;

// alter type of int64_t
typedef int64_t i64;

// alter type of signed int 128
// has two array partition, which 0 & 1
using int128_t = std::array<int64_t, 2>;

// alter type of int128_t
// has two array partition, which 0 & 1
struct i128
{
    i128() { data = { 0,0 }; }
    i128(i64 first, i64 second) { data = { first, second }; }
    ~i128() {}

    int128_t data;
};

// alter type of uint32_t
typedef uint32_t ui32;

// alter type of uint64_t
typedef uint64_t ui64;

// alter type of unsigned int 128
// has two array partition, which 0 & 1
using uint128_t = std::array<uint64_t, 2>;

// alter type of uint128_t
// has two array partition, which 0 & 1
struct ui128
{
    ui128() { data = { 0, 0 }; }
    ui128(ui64 first, ui64 second) { data = { first, second }; }
    ~ui128() {}

    uint128_t data;
};

// alter type of float
typedef float f32;

// alter type of double
typedef double f64;

#endif // LIBPRGE_TYPES_HH
