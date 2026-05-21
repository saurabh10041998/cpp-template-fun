#include <iostream>

template <typename T>
T max(T a, T b) {
    std::cout << "Calling max with 2 arguments" << std::endl;
    return (a > b) ? a : b;
}

template <typename T>
T max(T a, T b, T c) {
    std::cout << "Calling max with 3 arguments" << std::endl;
    T temp = (a > b) ? a : b;
    return (temp > c) ? temp : c;
}

template <typename T>
T* max(T* a, T* b) {
    std::cout << "Calling max with pointer arguments" << std::endl;
    return (*a > *b) ? a : b;
}

// non template function for const char*
const char* max(const char* a, const char* b) {
    std::cout << "Calling non-template max for const char*" << std::endl;
    return (std::strcmp(a, b) > 0) ? a : b;
}

int main() {
    auto result1 = max(3, 7);
    auto result3 = max(3, 7, 5);

    std::cout << "Max of 3 and 7: " << result1 << std::endl;
    std::cout << "Max of 3, 7 and 5: " << result3 << std::endl;

    int x = 10, y = 20;
    auto result2 = max(&x, &y);
    std::cout << "Max of " << x << " and " << y << ": " << *result2 << std::endl;

    const char* str1 = "apple";
    const char* str2 = "banana";
    auto result4 = max(str1, str2);
    std::cout << "Max of \"" << str1 << "\" and \"" << str2 << "\": " << result4 << std::endl;

    return 0;
}