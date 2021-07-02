#include <iostream>
#include <vector>
#define PROJECT_NAME "permute"

int fact(int n);
void permute(const char* str, std::vector<std::string>& res);
std::string shiftr(const std::string& str);
std::string swap_chars(const std::string& str, int i, int j);
std::string swap(const std::string& str);

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cout << "usage: " << PROJECT_NAME << " [string]\n";
        return 1;
    }
    std::vector<std::string> permutations;
    permute(argv[1], permutations);
    for (auto str : permutations)
        std::cout << str << std::endl;
    return 0;
}

int
fact(int n)
{
    if (n == 1)
        return 1;
    else
        return n + fact(n - 1);
}

void
permute(const char* str, std::vector<std::string>& res)
{
    std::string in(str);
    std::string perm(str);

    // fix each character and swap the rest
    for (size_t i = 0; i < in.size(); ++i) {
        perm = swap(in.substr(i));
        res.push_back(perm);
    }
}

// shift right as in a circulur buffer
std::string
shiftr(const std::string& str)
{
    std::string out(str);
    char last = out.back();
    for (size_t i = 1; i < out.size() - 1; ++i) {
        char temp = out[i];
        out[i] = out[i-1];
        out[i+1] = temp;
    }
    out[0] = last;
    return out;
}

std::string
swap_chars(const std::string& str, int i, int j)
{
    std::string out{str};
    char temp = out[i];
    out[i] = out[j];
    out[j] = temp;
    return out;
}

std::string swap(const std::string& input, std::string& curr){ if (curr.size
() >= input.size()) return curr; else { for (size_t i = 0; i < input.size
(); ++i) { char c = input[i]; if (input.find(c)) continue; curr.push_back
(c);

        }
    }
    for (size_t i = 0; i < str.size() - 1; ++i) {
        out = swap_chars(str, i, i + 1);
    }
    return out;
}
