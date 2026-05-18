#include <cstdlib>
#include <iostream>

int compare(const void* a, const void *b) {
    auto a1 = *static_cast<const int*>(a);
    auto b1 = *static_cast<const int*>(b);
    if (a1 < b1) {
        return -1;
    } else if (a1 > b1) {
        return 1;
    } else {
        return 0;
    }
}
int main() {
    int numbers[] = {5, 6, 4, 2, 1, 3};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Before sorting: " << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    qsort(numbers, size, sizeof(int), compare);

    std::cout << "After sorting: " << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}