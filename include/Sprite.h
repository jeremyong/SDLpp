#pragma once
#include "Texture.h"
#include "Util.h"
#include "Vector2f.h"

namespace sdl {
class View;
class Sprite {
private:
    const Texture &_texture;
    Rect _src;
    Rect _dest;

    Vector2f _origin;
    Vector2f _position;
public:
    Sprite(const Texture &tex);
    Sprite(const Texture &tex, const Rect &src)
        : Sprite(tex, src, Vector2f{0.f, 0.f}) {}
    Sprite(const Texture &tex, const Rect &src, const Vector2f &origin);

    void Draw(Texture &texture);
    void Draw(const View &view);

    Vector2f GetPosition() const {
        return _position;
    }

    void SetPosition(const Vector2f &pos) {
        _position = pos;
    }

    void Move(const Vector2f &delta) {
        _position += delta;
    }
};
}
