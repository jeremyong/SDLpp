#pragma once

#include "Clock.h"
#include "Duration.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Surface.h"
#include "Texture.h"
#include "Window.h"

namespace sdl {
void Init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        throw 0;
    }
}
}
