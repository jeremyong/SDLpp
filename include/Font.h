#pragma once
#include <SDL2/SDL_ttf.h>
#include "Util.h"
#include <string>

namespace sdl {
class Font {
    friend class Text;
private:
    TTF_Font *_font;

public:
    Font(std::string font_name, int pt_size) {
        _font = TTF_OpenFont(font_name.c_str(), pt_size);
        if (_font == nullptr) Throw();
    }

    Font(const Font &font) = delete;
    Font &operator=(const Font &font) = delete;

    ~Font() { TTF_CloseFont(_font); }
};
}
