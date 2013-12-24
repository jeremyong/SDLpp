#include "Texture.h"
#include "Vector2.h"

namespace sdl {
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

SDL_Renderer *Texture::GetRenderer() const {
    return _ren;
}
}
