#include "Renderer.h"
#include "Sprite.h"
#include "Surface.h"
#include "Text.h"
#include "Texture.h"
#include "Vector2f.h"

namespace sdl {
Texture *Renderer::CreateTexture(const int w, const int h) {
    texture_ptr tmp{new Texture(_ren, w, h)};
    return AddTexture(std::move(tmp));
}

Texture *Renderer::CreateTexture(const int w, const int h, const int access) {
    texture_ptr tmp{new Texture(_ren, w, h, access)};
    return AddTexture(std::move(tmp));
}

Texture *Renderer::CreateTexture(const std::string &file) {
    texture_ptr tmp{new Texture(_ren, file)};
    return AddTexture(std::move(tmp));
}

Texture *Renderer::CreateTexture(const Surface &surface) {
    texture_ptr tmp{new Texture(_ren, surface)};
    return AddTexture(std::move(tmp));
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

Texture *Renderer::AddTexture(texture_ptr texture) {
    std::set<texture_ptr>::iterator ret;
    std::tie(ret, std::ignore) = _textures.insert(std::move(texture));
    return ret->get();
}
}
