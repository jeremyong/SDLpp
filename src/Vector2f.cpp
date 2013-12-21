#include "Vector2f.h"

namespace sdl {
std::ostream& operator<<(std::ostream &os, const Vector2f &vec) {
    os << "<" << vec.u << ", " << vec.v << ">";
    return os;
}
}
