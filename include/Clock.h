#pragma once
#include <chrono>

namespace sdl {
class Duration;
class Clock {
private:
    std::chrono::steady_clock::time_point _time;
public:
    Clock() {
        _time = std::chrono::steady_clock::now();
    }

    Duration Reset();
};
}
