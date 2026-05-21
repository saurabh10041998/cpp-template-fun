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

    auto pro1 = product2(4, 6.2); // This works with explicit template parameters, loss of info
    std::cout << "Product of 4 and 6.2: " << pro1 << std::endl;

    auto pro2 = product3<int, double, double>(4, 6.2); // This works with explicit template parameters, no loss of info
    std::cout << "Product of 4 and 6.2: " << pro2 << std::endl;

    auto pro3 = product4<double>(4, 6.2); // explict type only for return type, no loss of info
    std::cout << "Product of 4 and 6.2: " << pro3 << std::endl;

    auto pro4 = product5(4, 6.2); // c++11 decltype, no loss of info
    std::cout << "Product of 4 and 6.2: " << pro4 << std::endl;

    auto pro5 = product6(4, 6.2); // c++14 auto return type deduction, no loss of info
    std::cout << "Product of 4 and 6.2: " << pro5 << std::endl;

    auto pro6 = product7(4, 6.2); // common_type type trait, no loss of info
    std::cout << "Product of 4 and 6.2: " << pro6 << std::endl;

    auto pro7 = product8(4, 6.2); // default template parameter for return type, no loss of info
    std::cout << "Product of 4 and 6.2: " << pro7 << std::endl;

    auto pro8 = product9(4, 6.2); // default template parameter for return type using common_type, no loss of info
    std::cout << "Product of 4 and 6.2: " << pro8 << std::endl;

    return 0;

}