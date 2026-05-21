#pragma once

#include <type_traits>

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
T square(T x) {
    return x * x;
}

template<typename T>
T product1(T a, T b) {
    return a * b;
}

template<typename T1, typename T2>
T1 product2(T1 a, T2 b) {
    return a * b;
}

// correct old way
template<typename T1, typename T2, typename TResult>
TResult product3(T1 a, T2 b) {
    return a * b;
}

template<typename TResult, typename T1, typename T2>
TResult product4(T1 a, T2 b) {
    return a * b;
}

// c++11 decltype
template<typename T1, typename T2>
auto product5(T1 a, T2 b) -> decltype(a * b) {
    return a * b;
}

// c++14 auto return type deduction
template<typename T1, typename T2>
auto product6(T1 a, T2 b) {
    return a * b;
}

// common_type type trait
template<typename T1, typename T2>
typename std::common_type<T1, T2>::type product7(T1 a, T2 b) {
    return a * b;
}
