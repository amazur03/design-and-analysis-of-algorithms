#include "QuickSort.hpp"
#include <iostream>

void QuickSort::sort() {
    quickSort(0, _size - 1);
}

void QuickSort::show() {
    std::cout << "QuickSort data:\n";
    Upload::show();
}

void QuickSort::swap(Ranking* from, Ranking* to) {
    Ranking tmp = *from;
    *from = *to;
    *to = tmp;
}


void QuickSort::quickSort(int start, int end) {
    if (start < end) {
        // Find pivot index and partition the array
        int pivotIndex = partition(start, end);

        // Recursively sort elements before and after pivot
        quickSort(start, pivotIndex - 1);
        quickSort(pivotIndex + 1, end);
    }
}

int QuickSort::partition(int start, int end) {
    // Choosing the middle element as pivot
    int pivot = ranking[(start + end) / 2].grade;
    int i = start - 1;
    int j = start;
    while (j < end) {
        if (ranking[j].grade < pivot) {
            ++i;
            swap(&ranking[i], &ranking[j]);
        }
        ++j;
    }
    swap(&ranking[i + 1], &ranking[end]);
    return i + 1;
}


