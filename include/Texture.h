#pragma once
#include <SDL2/SDL.h>
#include "Surface.h"
#include "Vector2.h"
#include "Util.h"

#include <tuple>

namespace sdl {
class Sprite;
class Texture {
    friend class Sprite;
    friend class Text;
private:
    SDL_Texture *_tex;
    SDL_Renderer *_ren;
public:
    Texture(SDL_Renderer *ren, const std::string file)
        : _tex(nullptr), _ren(ren) {
        Surface s{file};
        _tex = SDL_CreateTextureFromSurface(ren, s._surface);
        if (_tex == nullptr) {
            Throw();
        }
    }

    Texture(SDL_Renderer *ren, const Surface &surf)
        : _tex(nullptr), _ren(ren) {
        _tex = SDL_CreateTextureFromSurface(ren, surf._surface);
        if (_tex == nullptr) {
            Throw();
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
