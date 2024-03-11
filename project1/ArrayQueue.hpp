#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <iostream>
#include <stdexcept>

class ArrayQueue {
private:
    int* _data;
    int _f = 0;
    int _sz = 0;
    int _capacity = 100;

public:
    ArrayQueue(); // Default constructor
    ArrayQueue(int capacity); // Constructor with capacity parameter
    ~ArrayQueue(); // Destructor
    int getCapacity() const; // Returns the capacity of the queue
    int getSize() const; // Returns the size of the queue
    bool isEmpty() const; // Returns true if the queue is empty, false otherwise
    void enqueue(int e); // Adds an element to the queue
    int first() const; // Returns the first element of the queue
    int dequeue(); // Removes and returns the first element of the queue
    void addRandomElement(); // Adds a random element to the queue
    void printQueue() const; // Prints the contents of the queue
};

#endif