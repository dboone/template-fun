#pragma once

#include <type_traits>

template <typename T>
struct add_const_ref
{
    using value = typename std::add_lvalue_reference<
        typename std::add_const< T >::type >::type;
};

static_assert(
    std::is_same<add_const_ref<double>::value, const double&>::value,
    "Non-reference type should return const reference!");

static_assert(
    std::is_same<add_const_ref<double&>::value, double&>::value,
    "Reference type should return reference!");