#pragma once
#include <SDL2/SDL_ttf.h>
#include "Util.h"
#include <string>

namespace sdl {
class Font {
    friend class Text;
private:
    TTF_Font *_font;
    std::string _file;
    int _size;

public:
    Font(std::string file, int pt_size)
        : _font(nullptr), _file(file), _size(pt_size) {
        _font = TTF_OpenFont(file.c_str(), pt_size);
        if (_font == nullptr) Throw();
    }

    Font(Font &&font) {
        _font = font._font;
        font._font = nullptr;
    }
    Font(const Font &font) {
        _font = TTF_OpenFont(font._file.c_str(), font._size);
        if (_font == nullptr) Throw();
    }

    Font &operator=(const Font &font) {
        _font = TTF_OpenFont(font._file.c_str(), font._size);
        if (_font == nullptr) Throw();
        return *this;
    }

    ~Font() {
        if (_font != nullptr) TTF_CloseFont(_font);
    }
};
}
