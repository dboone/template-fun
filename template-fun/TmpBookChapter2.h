#pragma once

#include <type_traits>

template <typename T>
struct add_const_ref
{
    typedef typename std::conditional<
        std::is_reference<T>::value,
        T,
        const T&>::type value;
};

static_assert(
    std::is_same<add_const_ref<double>::value, const double&>::value,
    "Non-reference type should return const reference!");

static_assert(
    std::is_same<add_const_ref<double&>::value, double&>::value,
    "Reference type should return reference!");