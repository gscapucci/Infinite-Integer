#include "infinite.h"
#include <iostream>
#include <limits>

void fac(const Infinite& inf)
{
    Timer t;
    Infinite result = 1;
    for (Infinite i = 2; i <= inf; i++)
    {
        result *= i;
    }
    std::cout << "Fact of " << inf << " = ";
    std::cout << result << std::endl;
    std::cout << "Number of digits: " << result.numberOfDigits() << std::endl;
}

int main()
{
    Infinite inf = 5000;
    fac(inf);
}