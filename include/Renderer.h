#pragma once
#include <SDL2/SDL.h>
#include "Window.h"
#include <stdint.h>
#include "Texture.h"
#include "View.h"
#include "Util.h"
#include <set>

namespace sdl {
class Sprite;
class Surface;
class Text;
class Vector2f;
class Renderer {
private:
    typedef std::unique_ptr<Texture> texture_ptr;
    SDL_Renderer *_ren;
    std::set<texture_ptr> _textures;
    View _view;
public:
    Renderer(SDL_Window *win, const uint32_t flags)
        : _ren(nullptr) {
        _ren = SDL_CreateRenderer(win, -1, flags);
        if (_ren == nullptr) {
            Throw();
        }
    }

    Renderer(const Renderer &other) = delete;
    Renderer &operator=(const Renderer &other) = delete;

    ~Renderer() {
        if (_ren != nullptr) SDL_DestroyRenderer(_ren);
    }

    Texture *CreateTexture(const int w, const int h);
    Texture *CreateTexture(const int w, const int h, const int access);
    Texture *CreateTexture(const Surface &surface);
    Texture *CreateTexture(const std::string &file);

    void Clear() const;
    void Draw(Sprite &sprite) const;
    void Draw(Text &text) const;
    void Present() const;

    View *GetView() { return &_view; }
    void SetView(const View &view) { _view = view; }
private:
    Texture *AddTexture(texture_ptr texture);
};
}
