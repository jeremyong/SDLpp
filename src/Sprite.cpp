#include "Sprite.h"
#include "View.h"
#include <tuple>
#include <iostream>

namespace sdl {
Sprite::Sprite(const Texture &tex, const Vector2f &origin)
    : _texture(tex), _origin(origin) {
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

void Sprite::SetTextureColor() {
    if (_color_set) {
        SDL_SetTextureColorMod(_texture._tex, _color.R(), _color.G(), _color.B());
        SDL_SetTextureAlphaMod(_texture._tex, _color.A());
    }
}

void Sprite::ResetTextureColor() {
    if (_color_set) {
        SDL_SetTextureColorMod(_texture._tex, 255, 255, 255);
        SDL_SetTextureAlphaMod(_texture._tex, 255);
    }
}

void Sprite::Draw(Texture &texture) {
    SetTextureColor();
    _dest.x = _position.x - _origin.x;
    _dest.y = _position.y - _origin.y;
    SDL_RenderCopy(_texture._ren, _texture._tex, &_src, &_dest);
    ResetTextureColor();
}

void Sprite::Draw(Texture &texture, const View &view) {
    SetTextureColor();
    const Vector2i dest = view.WorldToRaster(_position);
    _dest.x = dest.x - _origin.x;
    _dest.y = dest.y - _origin.y;
    SDL_RenderCopy(_texture._ren, _texture._tex, &_src, &_dest);
    ResetTextureColor();
}

void Sprite::Draw(const View &view) {
    SetTextureColor();
    const Vector2i dest = view.WorldToRaster(_position);
    _dest.x = dest.x - _origin.x;
    _dest.y = dest.y - _origin.y;
    SDL_RenderCopy(_texture._ren, _texture._tex, &_src, &_dest);
    ResetTextureColor();
}
}
