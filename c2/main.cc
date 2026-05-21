#include <iostream>
#include "util.h"

int main() {
    auto result1 = max(3, 7);
    auto result2 = max(3.5, 2.1);

    std::cout << "Max of 3 and 7: " << result1 << std::endl;
    std::cout << "Max of 3.5 and 2.1: " << result2 << std::endl;

    auto square1 = square(5);
    auto square2 = square(2.5);

    std::cout << "Square of 5: " << square1 << std::endl;
    std::cout << "Square of 2.5: " << square2 << std::endl;

    // auto pro1 = product1(4, 6.2); This fails in template deduction

    auto pro1 = product2(4, 6.2); // This works with explicit template parameters
    std::cout << "Product of 4 and 6.2: " << pro1 << std::endl;


    return 0;

}