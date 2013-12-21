#pragma once
#include <chrono>

namespace sdl {
class Duration {
private:
    std::chrono::steady_clock::duration _duration;
public:
    Duration(const std::chrono::steady_clock::duration &d) : _duration(d) {}

    int GetMicroseconds() {
        return std::chrono::duration_cast<std::chrono::microseconds>(_duration).count();
    }

    int GetMilliseconds() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(_duration).count();
    }

    int GetSeconds() {
        return std::chrono::duration_cast<std::chrono::seconds>(_duration).count();
    }
};
}
