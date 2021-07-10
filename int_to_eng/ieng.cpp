#include <iostream>
#include <vector>
#include <string>
#include <deque>

#define PROJECT_NAME "ieng"
std::vector<std::string> to_eng(int n);
std::string single_digit(char d);
std::string leading_place(int itr);
std::string trailing_place(int itr);
std::string tenth_place(char next);
std::string middle_digit(char d);
bool iszero(char c);
bool rest_are_zeros(const std::string& n, int i);

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cout << "usage: " << PROJECT_NAME <<  "[number]\n";
        return 1;
    }

    for (const auto& str : to_eng(std::atoi(argv[1])))
        std::cout << str;
    return 0;
}

std::vector<std::string> to_eng(int n)
{
    std::deque<char> num;
    auto numstr = std::to_string(n);
    for (const auto& c : numstr) num.push_front(c);
    std::vector<std::string> out;

    // pad with zeros to make a minimum size of 3 digits
    // I.E. "2" => "002" and "12" => "012"
    if (num.size() % 3 == 1) {
        num.push_back('0');
        num.push_back('0');
    } else if (num.size() % 3 == 2) {
        num.push_back('0');
    }

    for (const auto& c : num) std::cout << c << " ";
    std::cout << "\n";

    // reverse iterate, from ones place to billions place, by groups of 3 digits
    auto itr = 1;
    for (size_t i = 0; i < num.size(); i += 3, ++itr) {
        // leftmost of 3-digit group
        if (num[i+2] != '0') {
            out.push_back(single_digit(num[i+2]));
            out.push_back(leading_place(itr));
        }

        // center digit of 3-digit group
        if (num[i+1] != '0') {
            if (num[i+1] == '1') {
                out.push_back(tenth_place(num[i]));
                // trailing thousand, million, billion
                if (itr > 1)
                    out.push_back(trailing_place(itr));
                continue;
            }
            else
                out.push_back(middle_digit(num[i+1]));
        }
    
        // rightmost digit of 3-digit group
        if (num[i] != '0')
            out.push_back(single_digit(num[i]));

        // trailing thousand, million, billion
        if (itr > 1)
            out.push_back(trailing_place(itr));

        out.push_back(" "); // trailing space
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
    }
}

std::string leading_place(int itr)
{
    switch (itr) {
        case 1: return " hundred";
        case 2: return " hundred thousand";
        case 3: return " hundred million";
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
