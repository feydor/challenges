#include <iostream>
#include <string>

constexpr int GAPWIDTH = 10;
constexpr int LOWER = 0;
constexpr int UPPER = 50000;
constexpr int FRACTIONAL = 5;
constexpr int LETTERS_IN_CELFAHREN = 17;
constexpr int WIDTH = GAPWIDTH + LETTERS_IN_CELFAHREN;

void print_celtofahren(int startc, int endc, int step_size);
std::string var_gap_width(double n1, double n2);
int num_digits(int x);

int
main()
{
    int startc = -1, endc = UPPER + 1, step_size = -1;

    while (startc < LOWER || startc > UPPER) {
        std::cout << "Please input a lower limit, limit >= " << LOWER << ": ";
        std::cin >> startc;
    }

    while (endc > UPPER || endc < startc) {
        std::cout << "Please input an upper limit, " << UPPER << " >= limit > " << startc << ": ";
        std::cin >> endc;
    }

    while (step_size <= 0 || step_size > endc) {
        std::cout << "Please input a step size, " << LOWER << " < step <= " << endc << ": ";
        std::cin >> step_size;
    }

    print_celtofahren(startc, endc, step_size);
    return 0;
}

void
print_celtofahren(int startc, int endc, int step_size)
{
    std::cout << "Celsius" << std::string(GAPWIDTH, ' ') << "Fahrenheit" << std::endl;
    std::cout << "-------" << std::string(GAPWIDTH, ' ') << "----------" << std::endl;
    std::cout.precision(FRACTIONAL);
    for (double cel = startc; cel < endc; cel += step_size) {
        double fahren = (cel * 1.8) + 32;
        std::cout << std::fixed << cel << var_gap_width(cel, fahren) << fahren << std::endl;
    }
}

std::string
var_gap_width(double n1, double n2)
{
    constexpr int DECIMAL = 1;

    int width_n1 = num_digits(n1) + DECIMAL + FRACTIONAL;
    int width_n2 = num_digits(n2) + DECIMAL + FRACTIONAL;
    return std::string(WIDTH - width_n1 - width_n2, ' ');
}

/* drops decimals */
int
num_digits(int x)
{
    int digits = 0;
    while (x != 0) {
        x /= 10;
        digits++;
    }
    return digits;
}
