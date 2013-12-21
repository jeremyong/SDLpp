#pragma once

#include "Window.h"
#include "Renderer.h"
#include "Surface.h"
#include "Texture.h"
#include "Sprite.h"

namespace sdl {
void Init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        throw 0;
    }
}
}
