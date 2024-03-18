#include "Upload.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"
#include "BucketSort.hpp"
#include <iostream>
#include <chrono>

int main() {
    int size = 10; // Specify the size of the ranking array
    MergeSort mergeSortObj(size);
    QuickSort quickSortObj(size);
    BucketSort bucketSortObj(size);

    std::cout << "Dla " << size << " danych" << std::endl;
    // Measure time for MergeSort
    auto start = std::chrono::steady_clock::now();
    //mergeSortObj.show();
    mergeSortObj.sort(); // Sort the data
    //mergeSortObj.show();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> mergeSortTime = end - start;

    std::cout << "MergeSort time: " << mergeSortTime.count() << " seconds" << std::endl;

    // Measure time for QuickSort
    start = std::chrono::steady_clock::now();
    //quickSortObj.show();
    quickSortObj.sort(); // Sort the data
    //quickSortObj.show();
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> quickSortTime = end - start;

    std::cout << "QuickSort time: " << quickSortTime.count() << " seconds" << std::endl;

    // Measure time for BucketSort
    start = std::chrono::steady_clock::now();
    //bucketSortObj.show();
    bucketSortObj.sort(); // Sort the data
    //bucketSortObj.show();
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> bucketSortTime = end - start;

    std::cout << "BucketSort time: " << bucketSortTime.count() << " seconds" << std::endl;

    return 0;
}
