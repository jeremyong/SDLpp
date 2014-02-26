#pragma once
#include "SDL.h"

namespace sdl {
class Color {
private:
    SDL_Color _color;

public:
    Color() : Color(255, 255, 255, 255) {}
    Color(const int r, const int g, const int b) : Color(r, g, b, 255) {}
    Color(const int r, const int g, const int b, const int a) {
        _color.r = r;
        _color.g = g;
        _color.b = b;
        _color.a = a;
    }

    SDL_Color GetColor() const { return _color; }
    int R() { return _color.r; }
    int G() { return _color.g; }
    int B() { return _color.b; }
    int A() { return _color.a; }

};
namespace Colors {
static Color White{255, 255, 255, 255};
static Color Red{255, 0, 0, 255};
static Color Green{0, 255, 0, 255};
static Color Blue{0, 0, 255, 255};
}
}
