#include "BucketSort.hpp"
#include <iostream>

void BucketSort::sort() {
    bucketSort();
}

void BucketSort::show() {
    std::cout << "Bucket sort data:\n";
    Upload::show();
}

void BucketSort::bucketSort() {
    // Find the maximum grade to determine the range of buckets
    int maxGrade = 0;
    for (int i = 0; i < _size; ++i) {
        maxGrade = std::max(maxGrade, ranking[i].grade);
    }

    // Create buckets dynamically
    Ranking** buckets = new Ranking * [maxGrade + 1];
    for (int i = 0; i <= maxGrade; ++i) {
        buckets[i] = new Ranking[_size];
    }

    // Count elements in each bucket
    int* bucketCounts = new int[maxGrade + 1] {0};
    for (int i = 0; i < _size; ++i) {
        int bucketIndex = ranking[i].grade;
        buckets[bucketIndex][bucketCounts[bucketIndex]++] = ranking[i];
    }


    // Concatenate sorted buckets back into ranking array
    int index = 0;
    for (int i = 0; i <= maxGrade; ++i) {
        for (int j = 0; j < bucketCounts[i]; ++j) {
            ranking[index++] = buckets[i][j];
        }
    }

    // Clean up memory
    delete[] bucketCounts;
    for (int i = 0; i <= maxGrade; ++i) {
        delete[] buckets[i];
    }
    delete[] buckets;
}
