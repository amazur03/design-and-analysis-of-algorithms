#include "Upload.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

Upload::Upload(int size)
{
    _size = size;
    ranking = new Ranking[_size];
    dataFromFile(); // Call function to read data from file
}

Upload::~Upload()
{
    delete[] ranking; // Deallocate memory
}

void Upload::dataFromFile()
{
    std::ifstream file;
    file.open("project2_data.csv"); // Open the file

    if (file.is_open())
    {
        std::string title;
        std::string pos;
        std::string tmpIndex;
        std::string tmpString;
        std::getline(file, tmpString); // Read and discard the first line (header)

        int index = 0;
        while (std::getline(file, tmpString) && index < _size) // Read data until size limit or end of file
        {
            std::stringstream tmp(tmpString);
            std::getline(tmp, tmpIndex, ','); // Extract index
            std::getline(tmp, title, ','); // Extract title
            while (title.front() == '"') // Handle titles enclosed in double quotes
            {
                std::string tmpTmpName;
                if (title.back() == '"')
                    break;
                std::getline(tmp, tmpTmpName, ',');
                title = title + ',' + tmpTmpName;
            }
            std::getline(tmp, pos, ','); // Extract position
            if (!pos.empty())
            {
                ranking[index] = { stoi(tmpIndex), title, stoi(pos) }; // Store data in Ranking array
                index++;
            }
        }
    }
    file.close(); // Close the file
}

void Upload::show()
{
    for (int i = 0; i < _size; i++)
    {
        std::cout << ranking[i].index << " " << ranking[i].title << " " << ranking[i].pos << std::endl; // Display index, title, and position
    }
}
