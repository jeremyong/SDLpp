#include "Renderer.h"
#include "Sprite.h"
#include "Surface.h"
#include "Text.h"
#include "Texture.h"
#include "Vector2f.h"

namespace sdl {
Texture *Renderer::CreateTexture(const Surface &surface) {
    texture_ptr tmp{new Texture(_ren, surface)};
    std::set<texture_ptr>::iterator ret;
    std::tie(ret, std::ignore) = _textures.insert(std::move(tmp));
    return ret->get();
}

void Renderer::Clear() const {
    SDL_RenderClear(_ren);
}

void Renderer::Draw(Sprite &sprite) const {
    sprite.Draw(_view);
}

void Renderer::Draw(Text &text) const {
    text.Draw(_ren, _view);
}

void Renderer::Present() const {
    SDL_RenderPresent(_ren);
}
}
