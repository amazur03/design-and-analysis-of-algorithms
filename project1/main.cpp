#include <iostream>
#include "ArrayQueue.hpp"

int main() {

    int capacity;
    std::cout << "Enter the capacity of the queue: ";
    std::cin >> capacity;
    ArrayQueue queue(capacity);

    int choice;
    do {
        std::cout << "\n========== MENU ==========\n";
        std::cout << "1. Check the capacity of the queue\n";
        std::cout << "2. Check the size of the queue\n";
        std::cout << "3. Check if the queue is empty\n";
        std::cout << "4. Add an element to the queue\n";
        std::cout << "5. Add a random element to the queue\n";
        std::cout << "6. Display the first element of the queue\n";
        std::cout << "7. Remove the first element from the queue\n";
        std::cout << "8. Display the contents of the queue\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Queue capacity: " << queue.getCapacity() << std::endl;
            break;
        case 2:
            std::cout << "Queue size: " << queue.getSize() << std::endl;
            break;
        case 3:
            if (queue.isEmpty())
                std::cout << "The queue is empty." << std::endl;
            else
                std::cout << "The queue is not empty." << std::endl;
            break;
        case 4:
            int element;
            std::cout << "Enter the element to add: ";
            std::cin >> element;
            try {
                queue.enqueue(element);
                std::cout << "Element added to the queue." << std::endl;
            }
            catch (const std::overflow_error& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            break;
        case 5:
            try {
                queue.addRandomElement();
                std::cout << "Random element added to the queue." << std::endl;
            }
            catch (const std::overflow_error& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            break;
        case 6:
            if (!queue.isEmpty()) {
                std::cout << "First element of the queue: " << queue.first() << std::endl;
            }
            else {
                std::cout << "The queue is empty." << std::endl;
            }
            break;
        case 7:
            if (!queue.isEmpty()) {
                std::cout << "Removed element: " << queue.dequeue() << std::endl;
            }
            else {
                std::cout << "The queue is empty, cannot remove element." << std::endl;
            }
            break;
        case 8:
            queue.printQueue();
            break;
        case 0:
            std::cout << "Thank you! Goodbye." << std::endl;
            break;
        default:
            std::cout << "Invalid option! Please try again." << std::endl;
        }
    } while (choice != 0);

    return 0;
}