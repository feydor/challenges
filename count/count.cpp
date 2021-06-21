/* count.cpp - counts the number of lines in a file */
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

#define PROJECT_NAME "count"

int count(const char* fname);

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cout << "Usage: " << PROJECT_NAME << " [file]\n";
        return 1;
    }

    try {
        std::cout << count(argv[1]) << std::endl;
    } catch (const std::ifstream::failure& err) {
        std::cout << err.what() << std::endl;
    }

    return 0;
}

int
count(const char* fname)
{
    int nlines = 0;
    std::string line("");
    std::ifstream file(fname);

    if (!file.is_open())
        throw std::ifstream::failure("Error opening file: " + std::string(fname));
    while (std::getline(file, line)) {
        nlines++;
    }

    return nlines;
}