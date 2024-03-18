#include "MergeSort.hpp"
#include <iostream>

void MergeSort::sort() {
    mergeSort(0, _size - 1);
}

void MergeSort::show() {
    std::cout << "MergeSort data:\n";
    Upload::show();
}

void MergeSort::mergeSort(int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(start, mid);
        mergeSort(mid + 1, end);
        merge(start, mid, end);
    }
}

void MergeSort::merge(int start, int mid, int end) {
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    // Create temporary arrays
    Ranking* left = new Ranking[leftSize];
    Ranking* right = new Ranking[rightSize];

    // Copy data to temporary arrays
    for (int i = 0; i < leftSize; ++i)
        left[i] = ranking[start + i];
    for (int j = 0; j < rightSize; ++j)
        right[j] = ranking[mid + 1 + j];

    int i = 0, j = 0, k = start;
    // Merge the temporary arrays back into the main array
    while (i < leftSize && j < rightSize) {
        if (left[i].grade <= right[j].grade) {
            ranking[k] = left[i];
            ++i;
        }
        else {
            ranking[k] = right[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of left and right arrays if any
    while (i < leftSize) {
        ranking[k] = left[i];
        ++i;
        ++k;
    }
    while (j < rightSize) {
        ranking[k] = right[j];
        ++j;
        ++k;
    }

    delete[] left; // Clean up memory
    delete[] right;
}
