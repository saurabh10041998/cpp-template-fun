#include <iostream>
#include <cxxabi.h>
#include <limits>

#include "util.h"

template<typename T>
void foo(T a) {
    int status;
    char* typeName = abi::__cxa_demangle(typeid(T).name(), 0, 0, &status);
    std::cout << (status == 0 ? typeName : typeid(T).name()) << std::endl;
    free(typeName);
}

void A() {

}

void B() {

}

// non-type template parameter
template<int value>
void printValue() {
    std::cout << value << std::endl;
}

template<typename T, size_t N>
size_t linear_search(const T(&arr)[N], const T& target) {
    for (size_t i = 0; i < N; ++i) {
        if (arr[i] == target) {
            return i; // Return the index of the found element
        }
    }
    return std::numeric_limits<size_t>::max(); // Return max size_t to indicate not found
}

int main() {
    foo(3u);
    foo(4);
    foo('a');


    // constness removed
    const int x = 5;
    foo(x);

    // array decays to pointer
    int y = 5;
    foo(&y);

    int arr[5] = {1, 2, 3, 4, 5};
    foo(arr);

    // function decays to pointer
    foo(A);
    foo(B);

    auto res = square_constexpr(5);   // evaluated at compile time
    std::cout << res << std::endl;

    // non-type template parameter call
    printValue<10>();

    int arr2[] = {10, 20, 30, 40, 50};
    // size_t index = linear_search(arr2, 5, 30);       potentially prone to error when size is not correctly specified
    size_t index = linear_search(arr2, 30);
    if (index != std::numeric_limits<size_t>::max()) {
        std::cout << "Element found at index: " << index << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}