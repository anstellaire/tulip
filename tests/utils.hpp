#ifndef TULIP_TESTS_UTILS_HPP
#define TULIP_TESTS_UTILS_HPP

#include "../include/tulip/tulip.hpp"

#include <type_traits> // std::is_same

struct test {
    template<bool flag>
    static void is_true() {
        static_assert(flag, "");
    }

    template<typename LT, typename RT>
    static void is_same() {
        is_true<std::is_same<LT, RT>::value>();
    }
};

template<template<typename> class F>
struct test_functor {
    template<typename First, typename Second, typename... Rest>
    static void on_types() {
        F<First>{}();
        on_types<Second, Rest...>();
    }

    template<typename Last>
    static void on_types() {
        F<Last>{}();
    }
};

template<typename V>
struct wrapper {
    V value;
};

struct wrap {
    template<typename... Args>
    auto operator()(Args... args)
        -> decltype(tulip::tuple<wrapper<Args>...>(wrapper<Args>{args}...)) {

        return tulip::tuple<wrapper<Args>...>(wrapper<Args>{args}...);
    }
};

struct noop {
    template<typename... Args>
    auto operator()(Args... args)
        -> decltype(tulip::tuple<Args...>(args...)) {

        return tulip::tuple<Args...>(args...);
    }
};

#endif // TULIP_TESTS_UTILS_HPP
