#pragma once
#include <SDL2/SDL.h>
#include "Surface.h"
#include "Vector2.h"
#include "Util.h"

#include <tuple>

namespace sdl {
class Sprite;
class View;
class Texture {
    friend class Sprite;
    friend class Text;
private:
    SDL_Texture *_tex;
    SDL_Renderer *_ren;
public:
    Texture(SDL_Renderer *ren, const int w, const int h)
        : Texture(ren, w, h, SDL_TEXTUREACCESS_TARGET) {}

    Texture(SDL_Renderer *ren, const int w, const int h, const int access)
        : _tex(nullptr), _ren(ren) {
        _tex = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA8888, access, w, h);
        if (_tex == nullptr) {
            Throw();
        }
        SDL_SetRenderTarget(_ren, _tex);
        SDL_RenderClear(_ren);
        SDL_SetRenderTarget(_ren, NULL);
    }

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

    void Draw(Sprite &sprite);
    void Draw(Sprite &sprite, const View &view);

    int GetWidth() const;

    int GetHeight() const;

    Vector2i GetSize() const;
};
}
