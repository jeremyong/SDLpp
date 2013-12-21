#pragma once
#include "Texture.h"
#include "Util.h"

namespace sdl {
class Sprite {
private:
    Rect _src;
    Rect _dest;
    const Texture &_texture;
public:
    Sprite(const Texture &tex);

    void Draw() const;
};
}
