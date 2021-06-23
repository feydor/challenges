#include <iostream>
#include <fstream>

#define PROJECT_NAME "fsize"

int fsize(const char* fname);

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cout << "usage: " << PROJECT_NAME << " [file]\n";
        return 1;
    }

    try {
        std::cout << fsize(argv[1]) << std::endl;
    } catch (const std::ifstream::failure& err) {
        std::cout << err.what() << std::endl;
    }
    return 0;
}

int
fsize(const char* fname)
{
    std::ifstream file(fname);

    if (!file.is_open())
        throw std::ifstream::failure("Error opening file.");

    int beg = file.tellg();
    file.seekg(0, file.end);
    int end = file.tellg();
    return end - beg;
}
