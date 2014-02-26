#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "Clock.h"
#include "Duration.h"
#include "Font.h"
#include "Mouse.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Surface.h"
#include "Text.h"
#include "Texture.h"
#include "Vector2.h"
#include "Vector2f.h"
#include "View.h"
#include "Window.h"

namespace sdl {
inline void Quit() {
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

inline void Init() {
    // Initialize sdl
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        throw 0;
    }

    // Initialize sdl_ttf
    if (TTF_Init() == -1) {
        throw 1;
    }

    // Initialize sdl_image
    const int image_flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
    const int initialized_flags = IMG_Init(image_flags);
    if ((initialized_flags & image_flags) != image_flags) {
        throw 2;
    }

    atexit(Quit);
}
}
