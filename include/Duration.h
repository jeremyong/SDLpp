#pragma once
#include <chrono>

namespace sdl {
typedef std::chrono::microseconds microseconds;
typedef std::chrono::milliseconds milliseconds;
typedef std::chrono::seconds seconds;
class Duration {
private:
    std::chrono::steady_clock::duration _duration;
public:
    Duration(seconds s) : _duration(s) {}
    Duration(milliseconds ms) : _duration(ms) {}
    Duration(microseconds us) : _duration(us) {}

    Duration(const std::chrono::steady_clock::duration &d) : _duration(d) {}

    int GetMicroseconds() {
        return std::chrono::duration_cast<microseconds>(_duration).count();
    }

    int GetMilliseconds() {
        return std::chrono::duration_cast<milliseconds>(_duration).count();
    }

    int GetSeconds() {
        return std::chrono::duration_cast<seconds>(_duration).count();
    }
};
}
