#pragma once
#include "Color.h"
#include "Font.h"
#include "Vector2f.h"
#include "Util.h"
#include <string>
#include <SDL2/SDL.h>

namespace sdl {
class View;
class Text {
private:
    std::string _text;
    Vector2f _position;
    SDL_Surface *_surface;
    SDL_Texture *_texture;
    Rect _dest;
public:
    Text(const Font &font, const std::string &text)
        : Text(font, text, Vector2f{0.f, 0.f}) {}
    Text(const Font &font, const std::string &text, const Vector2f &position)
        : Text(font, text, position, Colors::White) {}
    Text(const Font &font, const std::string &text, const Color &color)
        : Text(font, text, Vector2f{0.f, 0.f}, color) {}
    Text(const Font &font, const std::string &text,
         const Vector2f &position, const Color &color)
        : _text(text), _position(position), _texture(nullptr) {
        _surface = TTF_RenderUTF8_Solid(font._font, text.c_str(), color.GetColor());
    }

    void Draw(SDL_Renderer *renderer, const View &view);

    ~Text() {
        if (_surface != nullptr) SDL_FreeSurface(_surface);
        if (_texture != nullptr) SDL_DestroyTexture(_texture);
    }
};
}
