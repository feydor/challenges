#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cstdint>

#define PROJECT_NAME "pascal"
#define MAXINPUT 22

std::vector<uint64_t> pascal(int row);
uint64_t bin_coef(int n, int k);
uint64_t fact(int n);

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cout << "usage: " << PROJECT_NAME <<  " [row <= " << MAXINPUT << "].\n";
        return 1;
    }
    
    assert(fact(12) == 479001600 && "fact is not accurate.");
    auto row = std::atoi(argv[1]);
    if (row > MAXINPUT) {
        std::cout << "usage: " << PROJECT_NAME <<  " [row <= " << MAXINPUT << "].\n";
        return 1;
    }
    auto coefs = pascal(row);
    for (auto i : coefs)
        std::cout << i << std::endl;

    return 0;
}

std::vector<uint64_t> pascal(int row) {
    std::vector<uint64_t> coefs;
    for (int i = 0; i <= row; ++i)
        coefs.push_back(bin_coef(row, i));
    return coefs;
}

uint64_t fact(int n) {
    if (n < 2) return 1;
    uint64_t sum = 1;
    for (int i = 0; i < n-1; ++i)
        sum *= (n-i);
    return sum;
}

uint64_t bin_coef(int n, int k) {
    return fact(n) / (fact(k) * fact(n-k));
}
