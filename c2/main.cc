#include <iostream>

template<typename T>
void foo(T a) {
    std::cout << typeid(T).name() << std::endl;
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
}