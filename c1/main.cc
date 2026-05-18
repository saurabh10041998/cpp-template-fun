#include <cstdlib>
#include <iostream>

int compare(const void* a, const void *b) {
    auto a1 = *static_cast<const int*>(a); // need correct type casting here
    auto b1 = *static_cast<const int*>(b); // need correct type casting here
    if (a1 < b1) {
        return -1;
    } else if (a1 > b1) {
        return 1;
    } else {
        return 0;
    }
}

void printArray(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int numbers[] = {5, 6, 4, 2, 1, 3};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printArray(numbers, size);

    // while calling, sizeof data type is needed
    qsort(numbers, size, sizeof(int), compare);

    std::cout << "After sorting: " << std::endl;
    printArray(numbers, size);

    // reverse order
    qsort(numbers, size, sizeof(int), [](const void* a, const void* b) {
        auto a1 = *static_cast<const int*>(a); // need correct type casting here
        auto b1 = *static_cast<const int*>(b); // need correct type casting here
        if (a1 < b1) {
            return 1;
        } else if (a1 > b1) {
            return -1; // do not swap
        } else {
            return 0; // equal ??
        }
    });

    std::cout << "After reverse sorting: " << std::endl;
    printArray(numbers, size);

    return 0;
}