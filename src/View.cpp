#include "View.h"

namespace sdl {
Vector2f View::RasterToWorld(const Vector2i &vec) const {
    return Vector2f{_pos.x + vec.x, _pos.y + vec.y};
}

Vector2i View::WorldToRaster(const Vector2f &vec) const {
    return Vector2i{int(-_pos.x + vec.x), int(-_pos.y + vec.y)};
}
}
