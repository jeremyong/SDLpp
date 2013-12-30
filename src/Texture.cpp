#include "Sprite.h"
#include "Texture.h"
#include "Vector2.h"
#include "View.h"

namespace sdl {
void Texture::Draw(Sprite &sprite) {
    SDL_SetRenderTarget(_ren, _tex);
    sprite.Draw(*this);
    SDL_SetRenderTarget(_ren, NULL);
}

void Texture::Draw(Sprite &sprite, const View &view) {
    SDL_SetRenderTarget(_ren, _tex);
    sprite.Draw(*this, view);
    SDL_SetRenderTarget(_ren, NULL);
}

int Texture::GetWidth() const {
    int ret;
    SDL_QueryTexture(_tex, nullptr, nullptr, &ret, nullptr);
    return ret;
}

int Texture::GetHeight() const {
    int ret;
    SDL_QueryTexture(_tex, nullptr, nullptr, nullptr, &ret);
    return ret;
}

Vector2i Texture::GetSize() const {
    Vector2i ret;
    SDL_QueryTexture(_tex, nullptr, nullptr, &ret.x, &ret.y);
    return ret;
}
}
