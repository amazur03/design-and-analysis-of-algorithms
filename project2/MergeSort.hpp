#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include "Upload.hpp"

class MergeSort : public Upload {
public:
    using Upload::Upload; // Inherit constructors

    void sort(); // Default sort in ascending order

    void show(); // Override show method to display after sorting

private:
    void mergeSort(int start, int end);
    void merge(int start, int mid, int end);
};

#endif // MERGESORT_HPP
