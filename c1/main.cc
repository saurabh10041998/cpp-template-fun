#include <cstdlib>
#include <iostream>
#include <chrono>
#include <string>


struct Profiler {
    using Clock = std::chrono::high_resolution_clock;

    Clock::time_point start;
    std::string label;
    int comparisons = 0;

    Profiler(const std::string& label):
        label(label),
        start(Clock::now()) {}

    void stop() {
        auto end = Clock::now();
        auto duration =
            std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        std::cout << "[profiler] " << label << "\n"
                  << "  Time: " << duration.count() << " microseconds\n"
                  << "  Comparisions: " << comparisons << "\n\n";
    }
};

static Profiler* active_profiler = nullptr;

int compare(const void* a, const void *b) {
    active_profiler->comparisons++;
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
    std::cout << std::endl;
}

int main() {
    int numbers[] = {5, 6, 4, 2, 1, 3};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printArray(numbers, size);

    // while calling, sizeof data type is needed
    {
        Profiler profiler("Sorting");
        active_profiler = &profiler;

        qsort(numbers, size, sizeof(int), compare);

        profiler.stop();

        active_profiler = nullptr;
    }


    std::cout << "After sorting: " << std::endl;
    printArray(numbers, size);

    {
        Profiler profiler("Reverse Sorting");
        active_profiler = &profiler;
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
        profiler.stop();
        active_profiler = nullptr;
    }

    std::cout << "After reverse sorting: " << std::endl;
    printArray(numbers, size);

    return 0;
}