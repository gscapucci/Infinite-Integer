#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <iostream>

struct Timer
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::chrono::duration<float> duration;
    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "Timer took " << duration.count() << "s" << std::endl;
    }
};

#endif /* TIMER_H */