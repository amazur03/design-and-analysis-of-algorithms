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

int QuickSort::partition(int start, int end) {
    int pivot = ranking[start].grade; // Choose the first element as the pivot

    // Left index
    int i = start - 1;

    // Right index
    int j = end + 1;

    while (true) {
        // Move the left index to the right at least once and while the element at
        // the left index is less than the pivot
        do {
            i++;
        } while (ranking[i].grade < pivot);

        // Move the right index to the left at least once and while the element at
        // the right index is greater than the pivot
        do {
            j--;
        } while (ranking[j].grade > pivot);

        // If the indices crossed, return
        if (i >= j) {
            return j;
        }

        // Swap the elements at the left and right indices
        swap(&ranking[i], &ranking[j]);
    }
}

void QuickSort::quickSort(int start, int end) {
    if (start >= 0 && end >= 0 && start < end) {
        int p = partition(start, end);
        quickSort(start, p);
        quickSort(p + 1, end);
    }
}