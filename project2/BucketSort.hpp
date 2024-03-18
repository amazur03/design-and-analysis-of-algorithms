#ifndef BUCKETSORT_HPP
#define BUCKETSORT_HPP

#include "Upload.hpp"

class BucketSort : public Upload {
public:
    using Upload::Upload; // Inherit constructors

    void sort(); // Default sort in ascending order

    void show(); // Override show method to display after sorting

public:
    void bucketSort();
};

#endif // BUCKETSORT_HPP
