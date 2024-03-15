#ifndef UPLOAD_HPP
#define UPLOAD_HPP

#include <string>

class Upload
{
protected:
    // Struct to store ranking data
    struct Ranking
    {
        int index;          // Index of the ranking
        std::string title;  // Title of the entry
        int pos;            // Position in the ranking
    };

public:
    Ranking* ranking; // Array to store ranking data
    int _size;         // Size of the ranking array

    // Constructor: Initializes the Upload object with given size and reads data from file
    Upload(int size);

    // Destructor: Deallocates memory
    ~Upload();

    // Function to read data from file and populate the ranking array
    void dataFromFile();

    // Function to display the ranking data
    void show();
};

#endif // UPLOAD_HPP
