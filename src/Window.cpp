#include "Window.h"
#include "Renderer.h"

namespace sdl {
Renderer *Window::CreateRenderer() {
    return CreateRenderer(SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

Renderer *Window::CreateRenderer(const uint32_t flags) {
    renderer_ptr tmp{new Renderer{_win, flags}};
    std::set<renderer_ptr>::iterator ret;
    std::tie(ret, std::ignore) = _renderers.insert(std::move(tmp));
    return ret->get();
}
}
