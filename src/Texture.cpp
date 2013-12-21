#include "Texture.h"

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

std::tuple<int, int> Texture::GetDimensions() const {
    int w, h;
    SDL_QueryTexture(_tex, nullptr, nullptr, &w, &h);
    return std::make_tuple(w, h);
}

SDL_Renderer *Texture::GetRenderer() const {
    return _ren;
}
}
