#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <stdint.h>
#include <memory>
#include <set>
#include <functional>

namespace sdl {
class Renderer;
class Window {
private:
    typedef std::unique_ptr<Renderer> renderer_ptr;
    SDL_Window *_win;
    std::set<renderer_ptr> _renderers;
public:
    Window(const std::string name)
        : Window(name, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP) {}

    Window(const std::string name, const int width, const int height)
        : Window(name, width, height, SDL_WINDOW_SHOWN) {}

    Window(const std::string name,
           const uint32_t flags)
        : Window(name, 0, 0, flags & SDL_WINDOW_FULLSCREEN_DESKTOP) {}

    Window(const std::string name,
           const int width,
           const int height,
           const uint32_t flags)
        : _win(nullptr) {
        _win = SDL_CreateWindow(name.c_str(),
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                width, height,
                                flags);
        if (_win == nullptr) {
            throw SDL_GetError();
        }
    }

    Window(const Window &other) = delete;
    Window &operator=(const Window &other) = delete;

    ~Window() {
        if (_win != nullptr) SDL_DestroyWindow(_win);
    }

    Renderer *CreateRenderer();
    Renderer *CreateRenderer(const uint32_t flags);
};
}
