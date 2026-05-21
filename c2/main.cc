#include <iostream>

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    auto result1 = max(3, 7);
    auto result2 = max(3.5, 2.1);

    std::cout << "Max of 3 and 7: " << result1 << std::endl;
    std::cout << "Max of 3.5 and 2.1: " << result2 << std::endl;

    return 0;

}