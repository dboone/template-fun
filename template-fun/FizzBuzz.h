#pragma once

// Not necessarily a complete FizzBuzz implementation because
// it does not process a list. Instead, this relies on 
// partial specialization to determine whether or not the 
// current number is evenly divisible by 3 and 5.
// 
// How could we utilize this FizzBuzz struct to generate the
// appropriate response for each integer in a list containing
// 1 to n?
template <size_t, bool, bool>
struct FizzBuzz;

template <size_t n, bool m3 = !(n % 3), bool m5 = !(n % 5)>
struct FizzBuzz {
    constexpr static auto value = n;
};

template <size_t n>
struct FizzBuzz<n, true, false> {
    constexpr static auto value = "Fizz";
};

template <size_t n>
struct FizzBuzz<n, false, true> {
    constexpr static auto value = "Buzz";
};

template <size_t n>
struct FizzBuzz<n, true, true> {
    constexpr static auto value = "FizzBuzz";
};