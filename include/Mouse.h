#pragma once
#include "Vector2.h"

namespace sdl {
namespace mouse {
inline Vector2i GetPosition() {
    Vector2i ret;
    SDL_GetMouseState(&ret.x, &ret.y);
    return ret;
}
}
}
