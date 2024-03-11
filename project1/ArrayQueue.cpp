#include "ArrayQueue.hpp"

ArrayQueue::ArrayQueue() {
    _data = new int[_capacity];
}

ArrayQueue::ArrayQueue(int capacity) {
    _capacity = capacity;
    _data = new int[_capacity];
}

ArrayQueue::~ArrayQueue() {
    delete[] _data;
}

int ArrayQueue::getCapacity() const {
    return _capacity;
}

int ArrayQueue::getSize() const {
    return _sz;
}

bool ArrayQueue::isEmpty() const {
    return _sz == 0;
}

void ArrayQueue::enqueue(int e) {
    if (_sz == _capacity) {
        throw std::overflow_error("Queue is full");
    }
    int avail = (_f + _sz) % _capacity;
    _data[avail] = e;
    _sz++;
}

int ArrayQueue::first() const {
    if (isEmpty()) return -1;
    return _data[_f];
}

int ArrayQueue::dequeue() {
    if (isEmpty()) return -1;
    int answer = _data[_f];
    _f = (_f + 1) % _capacity;
    _sz--;
    return answer;
}

void ArrayQueue::addRandomElement() {
    int randomElement = rand() % 100;
    enqueue(randomElement);
}

void ArrayQueue::printQueue() const {
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }
    std::cout << "Queue contents: ";
    int idx = _f;
    for (int i = 0; i < _sz; ++i) {
        std::cout << _data[idx] << " ";
        idx = (idx + 1) % _capacity;
    }
    std::cout << std::endl;
}