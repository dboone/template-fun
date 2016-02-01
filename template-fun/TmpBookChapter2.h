#pragma once

#include <type_traits>

template <typename T>
struct add_const_ref
{
    using value = typename std::add_lvalue_reference<
        typename std::add_const< T >::type >::type;
};


template <typename T>
struct test_add_const_ref
{
    static_assert(
        std::is_same<typename add_const_ref<const T>::value, const T&>::value,
        "Const value type should return const reference type!");

    static_assert(
        std::is_same<typename add_const_ref<T>::value, const T&>::value,
        "Non-const value type should return const reference type!");

    static_assert(
        std::is_same<typename add_const_ref<T&>::value, T&>::value,
        "Non-const reference type should return non-const reference type!");

    static_assert(
        std::is_same<typename add_const_ref<const T&>::value, const T&>::value,
        "Const reference type should return const reference!");
};