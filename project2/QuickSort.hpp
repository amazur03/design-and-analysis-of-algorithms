#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include "Upload.hpp"

class QuickSort : public Upload {
public:
    using Upload::Upload; // Inherit constructors

    void sort(); // Default sort in ascending order

    void show(); // Display full array

private:
    void swap(Ranking* from, Ranking* to);
    void quickSort(int start, int end);
    int partition(int start, int end);
};

#endif // QUICKSORT_HPP
