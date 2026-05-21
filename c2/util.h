#pragma once

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
T1 product1(T1 a, T2 b) {
    return a * b;
}
