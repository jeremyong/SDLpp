#pragma once
#include <SDL2/SDL.h>
#include <tuple>
#include "Surface.h"
#include "Vector2.h"
#include <iostream>

namespace sdl {
class Sprite;
class Texture {
    friend class Sprite;
    friend class Text;
private:
    SDL_Texture *_tex;
    SDL_Renderer *_ren;
public:
    Texture(SDL_Renderer *ren, const Surface &surf)
        : _tex(nullptr), _ren(ren) {
        _tex = SDL_CreateTextureFromSurface(ren, surf._surface);
        if (_tex == nullptr) {
            throw SDL_GetError();
        }
    }

    Texture(const Texture &tex) = delete;
    Texture &operator=(const Texture &tex) = delete;

    ~Texture() {
        if (_tex != nullptr) SDL_DestroyTexture(_tex);
    }

    int GetWidth() const;
    int GetHeight() const;
    SDL_Renderer *GetRenderer() const;
    Vector2i GetSize() const;
};
}
