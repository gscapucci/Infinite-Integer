#include "infinite.h"
#include <iostream>
#include <limits>

int main()
{
    Infinite inf = ULLONG_MAX;
    for (size_t i = 0; i < 10000; i++)
    {
        inf *= ULLONG_MAX;
    }
    
    std::cout << inf << std::endl;
    std::cout << "Number of digits = " << inf.numberOfDigits() << std::endl;
}