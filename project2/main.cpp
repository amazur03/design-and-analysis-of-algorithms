#include "MergeSort.hpp"
#include "QuickSort.hpp"
#include "BucketSort.hpp"
#include <iostream>
#include <chrono>
#include <vector>

int main() {
    std::vector<int> sizes = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000}; // Specify the sizes of the ranking arrays

    for (int size : sizes) {
        MergeSort mergeSortObj(size);
        QuickSort quickSortObj(size);
        BucketSort bucketSortObj(size);

        std::cout << "For " << size << " data elements:" << std::endl;

        // Measure time for MergeSort
        auto start = std::chrono::steady_clock::now();
        mergeSortObj.sort(); // Sort the data
        auto end = std::chrono::steady_clock::now();
        mergeSortObj.test();
        std::chrono::duration<double> mergeSortTime = end - start;
        std::cout << "MergeSort time: " << mergeSortTime.count() << " seconds" << std::endl;

        // Measure time for QuickSort
        start = std::chrono::steady_clock::now();
        quickSortObj.sort(); // Sort the data
        end = std::chrono::steady_clock::now();
        quickSortObj.test();
        std::chrono::duration<double> quickSortTime = end - start;
        std::cout << "QuickSort time: " << quickSortTime.count() << " seconds" << std::endl;

        // Measure time for BucketSort
        start = std::chrono::steady_clock::now();
        bucketSortObj.sort(); // Sort the data
        end = std::chrono::steady_clock::now();
        bucketSortObj.test();
        std::chrono::duration<double> bucketSortTime = end - start;
        std::cout << "BucketSort time: " << bucketSortTime.count() << " seconds" << std::endl;

        std::cout << std::endl;
    }

    return 0;
}
