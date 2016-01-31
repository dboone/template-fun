#pragma once

#include <type_traits>

template <typename T, bool select>
struct add_const_ref_impl
{
    typedef typename std::conditional<select, T, const T&>::type value;
};

template <typename T>
struct add_const_ref
{
    static const bool select = std::is_reference<T>::value;
    typedef typename add_const_ref_impl<T, select>::value value;
};

static_assert(
    std::is_same<add_const_ref<double>::value,
    const double&>::value,
    "Non-reference type should return const reference!");

static_assert(
    std::is_same<add_const_ref<double&>::value,
    double&>::value,
    "Reference type should return reference!");