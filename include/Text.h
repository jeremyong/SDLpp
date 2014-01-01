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
    Text() : _surface(nullptr), _texture(nullptr) {}
    Text(const Font &font, const std::string &text)
        : Text(font, text, Vector2f{0.f, 0.f}) {}
    Text(const Font &font, const std::string &text, const Vector2f &position)
        : Text(font, text, position, Colors::White) {}
    Text(const Font &font, const std::string &text, const Color &color)
        : Text(font, text, Vector2f{0.f, 0.f}, color) {}
    Text(const Font &font, const std::string &text,
         const Vector2f &position, const Color &color)
        : _text(text), _position(position), _surface(nullptr), _texture(nullptr) {
        _surface = TTF_RenderUTF8_Solid(font._font, text.c_str(), color.GetColor());
    }

    Text(Text &&other)
        : _text(other._text),
          _surface(other._surface),
          _texture(other._texture),
          _dest(other._dest) {
        other._surface = nullptr;
        other._texture = nullptr;
    }

    Text(const Text &other) = delete;

    Text operator=(Text &&other) {
        Text ret;
        ret._text = other._text;
        ret._surface = other._surface;
        ret._texture = other._texture;
        ret._dest = other._dest;
        other._surface = nullptr;
        other._texture = nullptr;
        return ret;
    }

    void Draw(SDL_Renderer *renderer, const View &view);

    Vector2f GetPosition() const { return _position; }
    void SetPosition(Vector2f pos) { _position = pos; }

    ~Text() {
        if (_surface != nullptr) SDL_FreeSurface(_surface);
        if (_texture != nullptr) SDL_DestroyTexture(_texture);
    }
};
}
