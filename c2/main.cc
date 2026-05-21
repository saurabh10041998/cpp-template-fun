#include <iostream>
#include <cxxabi.h>

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
}