#include "Text.h"
#include "View.h"

namespace sdl {
void Text::Draw(SDL_Renderer *renderer, const View &view) {
    if (_texture == nullptr) {
        _texture = SDL_CreateTextureFromSurface(renderer, _surface);
        if (_texture == nullptr) {
            throw SDL_GetError();
        }
        SDL_QueryTexture(_texture, nullptr, nullptr, &_dest.w, &_dest.h);
    }
    const Vector2i dest = view.WorldToRaster(_position);
    _dest.x = dest.x;
    _dest.y = dest.y;
    SDL_RenderCopy(renderer, _texture, NULL, &_dest);
}
}
