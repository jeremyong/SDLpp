#include "Sprite.h"
#include "View.h"
#include <tuple>
#include <iostream>

namespace sdl {
Sprite::Sprite(const Texture &tex)
    : _texture(tex) {
    Vector2i size = tex.GetSize();
    _dest.w = size.x;
    _dest.h = size.y;
    _src = _dest;
    _src.x = 0;
    _src.y = 0;
}

Sprite::Sprite(const Texture &tex, const Rect &src, const Vector2f &origin)
    : _texture(tex), _src(src), _origin(origin) {
    Vector2i size = tex.GetSize();
    _dest.w = size.x;
    _dest.h = size.y;
}

void Sprite::Draw(Texture &texture) {
    _dest.x = _position.x;
    _dest.y = _position.y;
    SDL_RenderCopy(_texture._ren, _texture._tex, &_src, &_dest);
}

void Sprite::Draw(const View &view) {
    const Vector2i dest = view.WorldToRaster(_position);
    _dest.x = dest.x;
    _dest.y = dest.y;
    SDL_RenderCopy(_texture._ren, _texture._tex, &_src, &_dest);
}
}
