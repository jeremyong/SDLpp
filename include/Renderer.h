#pragma once
#include <SDL2/SDL.h>
#include "Window.h"
#include <stdint.h>
#include "Texture.h"
#include <set>

namespace sdl {
class Surface;
class Renderer {
private:
    typedef std::unique_ptr<Texture> texture_ptr;
    SDL_Renderer *_ren;
    std::set<texture_ptr> _textures;
public:
    Renderer(SDL_Window *win, const uint32_t flags)
        : _ren(nullptr) {
        _ren = SDL_CreateRenderer(win, -1, flags);
        if (_ren == nullptr) {
            throw SDL_GetError();
        }
    }

    Renderer(const Renderer &other) = delete;
    Renderer &operator=(const Renderer &other) = delete;

    ~Renderer() {
        if (_ren != nullptr) SDL_DestroyRenderer(_ren);
    }

    Texture *CreateTexture(const Surface &surface);
    void Clear();
    void Present();
};
}
