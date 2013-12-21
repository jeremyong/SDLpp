#pragma once
#include <SDL2/SDL.h>
#include <string>

namespace sdl {
class Texture;
class Surface {
    friend class Texture;
private:
    SDL_Surface *_surface;
public:
    Surface () : _surface(nullptr) {}
    void LoadBMP(const std::string &image) {
        _surface = SDL_LoadBMP(image.c_str());
        if (_surface == nullptr) {
            throw SDL_GetError();
        }
    }

    Surface(const Surface &other) = delete;
    Surface &operator=(const Surface &other) = delete;

    ~Surface() {
        if (_surface != nullptr) SDL_FreeSurface(_surface);
    }
};
}
