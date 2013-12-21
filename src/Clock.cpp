#include "Clock.h"
#include "Duration.h"

namespace sdl {
Duration Clock::Reset() {
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    Duration ret{now - _time};
    _time = now;
    return ret;
}
}
