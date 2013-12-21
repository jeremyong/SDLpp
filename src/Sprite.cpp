#include "Sprite.h"
#include <tuple>

namespace sdl {
Sprite::Sprite(const Texture &tex)
    : _texture(tex) {
    int w, h;
    std::tie(w, h) = tex.GetDimensions();
    _dest.w = w;
    _dest.h = h;
    _dest.x = 0;
    _dest.y = 0;
    _src = _dest;
}

void Sprite::Draw() const {
    SDL_RenderCopy(_texture.GetRenderer(), _texture._tex, &_src, &_dest);
}
}
