#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <stdexcept>

#define PROJECT_NAME "i32toeng"
#define INT32MAX 2147483647
#define NDEBUG

std::deque<std::string> to_eng(int n);
std::string single_digit(char d);
std::string leading_place(int itr);
std::string trailing_place(int itr);
std::string tenth_place(char next);
std::string middle_digit(char d);
bool iszero(char c);
bool rest_are_zeros(const std::string& n, int i);
bool numerical(char c);

int main(int argc, char **argv) {
    // FIX: overflows atol (skips warning) if machine's long is 4B or less
    if(argc != 2 || std::atol(argv[1]) > INT32MAX) {
        std::cout << "usage: " << PROJECT_NAME <<  " [number <= " + std::to_string(INT32MAX) + "]\n";
        return 1;
    }

    try {
        for (const auto& str : to_eng(std::atoi(argv[1]))) std::cout << str;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

std::deque<std::string> to_eng(int n)
{
    std::deque<char> num;
    auto numstr = std::to_string(n);
    for (const auto& c : numstr) num.push_front(c);
    std::deque<std::string> out;

    // pad with zeros to make a minimum size of 3 digits
    // I.E. "2" => "002" and "12" => "012"
    if (num.size() % 3 == 1) {
        num.push_back('0');
        num.push_back('0');
    } else if (num.size() % 3 == 2) {
        num.push_back('0');
    }

    #ifndef NDEBUG
        for (const auto& c : num) std::cout << c << " ";
        std::cout << "\n";
    #endif

    // reverse iterate, from ones place to billions place, by groups of 3 digits
    auto itr = 1;
    std::string group;
    for (size_t i = 0; i < num.size(); i += 3, ++itr) {
        group = "";

        // leftmost of 3-digit group
        if (num[i+2] != '0') {
            group += single_digit(num[i+2]);
            group += leading_place(itr);
            group += " ";
        }

        // center digit of 3-digit group
        if (num[i+1] != '0') {
            if (num[i+1] == '1') {
                group += tenth_place(num[i]);
                goto trailing_place;
            }
            else {
                group += middle_digit(num[i+1]);
                group += " ";
            }
        }
    
        // rightmost digit of 3-digit group
        if (num[i] != '0')
            group += single_digit(num[i]);

trailing_place:
        // trailing thousand, million, billion
        if (itr > 1)
            group += trailing_place(itr);

        group += " "; // trailing space
        out.push_front(group);
    }
    return out;
}

std::string single_digit(char d)
{
    switch (d) {
        case '0': return "zero";
        case '1': return "one";
        case '2': return "two";
        case '3': return "three";
        case '4': return "four";
        case '5': return "five";
        case '6': return "six";
        case '7': return "seven";
        case '8': return "eight";
        case '9': return "nine";
        default: throw std::runtime_error("Input was non-numerical: " + std::to_string(d));
    }
}

std::string leading_place(int itr)
{
    switch (itr) {
        case 1: case 2: case 3: return " hundred";
        // case 2: return " hundred thousand";
        // case 3: return " hundred million";
        default: throw std::runtime_error("There were more than 3 iterations.");
        // case 4: return " hundred billion"; // not possible for 32bit digit
    }
}

std::string trailing_place(int itr)
{
    switch (itr) {
        case 1: return " hundred";
        case 2: return " thousand";
        case 3: return " million";
        case 4: return " billion";
        default: throw std::runtime_error("There were more than 4 iterations.");
    }
}

std::string tenth_place(char next)
{
    switch (next) {
        case '0': return "ten";
        case '1': return "eleven";
        case '2': return "twelve";
        case '3': return "thirteen";
        case '4': return "fourteen";
        case '5': return "fiveteen";
        case '6': return "sixteen";
        case '7': return "seventeen";
        case '8': return "eighteen";
        case '9': return "nineteen";
        default: throw std::runtime_error("Input was non-numerical: " + std::to_string(next));
    }
}

std::string middle_digit(char d)
{
    switch (d) {
        case '2': return "twenty";
        case '3': return "thirty";
        case '4': return "forty";
        case '5': return "fivty";
        case '6': return "sixty";
        case '7': return "seventy";
        case '8': return "eighty";
        case '9': return "ninety";
        default: throw std::runtime_error("Input was non-numerical: " + std::to_string(d));
    }
}

bool iszero(char c)
{
    return c == '0';
}

bool rest_are_zeros(const std::string& n, int i)
{
    for (size_t j = i; j < n.size(); j++)
        if (!iszero(n[i])) return false;
    return true;
}

bool numerical(char c)
{
    return c >= '0' && c <= '9';
}
