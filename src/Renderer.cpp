#include "Renderer.h"
#include "Surface.h"
#include "Texture.h"

namespace sdl {
Texture *Renderer::CreateTexture(const Surface &surface) {
    texture_ptr tmp{new Texture(_ren, surface)};
    std::set<texture_ptr>::iterator ret;
    std::tie(ret, std::ignore) = _textures.insert(std::move(tmp));
    return ret->get();
}

void Renderer::Clear() {
    SDL_RenderClear(_ren);
}

void Renderer::Present() {
    SDL_RenderPresent(_ren);
}
}
