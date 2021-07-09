#include <iostream>
#include <vector>
#include <string>

#define PROJECT_NAME "ieng"
std::vector<std::string> to_eng(int n);
bool iszero(char c);

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
    std::string num = std::to_string(n);
    std::vector<std::string> out;

    for (size_t i = 0; i < num.size(); ++i) {
        if (iszero(num[i])) continue;
        int digitsrem = num.size() - i - 1;

        // tens place of every group of 3 digits ie fourty, eighty, seventy, etc
        if (digitsrem == 7 || digitsrem == 4 || digitsrem == 1) {
            switch (num[i]) {
                case '1': out.push_back("eleven"); break;
                case '2': out.push_back("twenty"); break;
                case '3': out.push_back("thirty"); break;
                case '4': out.push_back("fourty"); break;
                case '5': out.push_back("fivety"); break;
                case '6': out.push_back("sixty"); break;
                case '7': out.push_back("seventy"); break;
                case '8': out.push_back("eighty"); break;
                case '9': out.push_back("ninety"); break;
            }
            i++;
            out.push_back(" ");
        }
       // } else {
            switch (num[i]) {
                case '1': out.push_back("one"); break;
                case '2': out.push_back("two"); break;
                case '3': out.push_back("three"); break;
                case '4': out.push_back("four"); break;
                case '5': out.push_back("five"); break;
                case '6': out.push_back("six"); break;
                case '7': out.push_back("seven"); break;
                case '8': out.push_back("eight"); break;
                case '9': out.push_back("nine"); break;
            }
        // }

        if (digitsrem != 0) out.push_back(" ");

        // max for signed 32bit integer is 2,147,483,647
        switch (digitsrem) {
            case 9: out.push_back("billion"); break;
            case 8: out.push_back("hundred million"); break;
            case 7: out.push_back("million"); break;
            case 6: out.push_back("million"); break;
            case 5: out.push_back("hundred thousand"); break;
            case 4: out.push_back("thousand"); break;
            case 3: out.push_back("thousand"); break;
            case 2: out.push_back("hundred"); break;
            case 1: case 0: /* already taken care of above */break;
        }

        if (digitsrem == 7 || digitsrem == 4)
            out.push_back(" and");
        out.push_back(" ");
    }

    return out;
}

bool iszero(char c)
{
    return c == '0';
}

