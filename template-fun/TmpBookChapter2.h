#pragma once

#include <type_traits>

template <typename T>
struct add_const_ref
{
    using value = typename std::add_lvalue_reference<
        typename std::add_const< T >::type >::type;
};

static_assert(
    std::is_same<add_const_ref<const double>::value, const double&>::value,
    "Const value type should return const reference type!");

static_assert(
    std::is_same<add_const_ref<double>::value, const double&>::value,
    "Non-const value type should return const reference type!");

static_assert(
    std::is_same<add_const_ref<double&>::value, double&>::value,
    "Non-const reference type should return non-const reference type!");

static_assert(
    std::is_same<add_const_ref<const double&>::value, const double&>::value,
    "Const reference type should return const reference!");