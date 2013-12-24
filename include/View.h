#pragma once
#include "Vector2f.h"

namespace sdl {
class View {
private:
    Vector2f _pos;
    Vector2f _size;
public:
    View() {}

    View(const Vector2f &pos, const Vector2f &size)
        : _pos(pos), _size(size) {}

    Vector2f GetPosition() const { return _pos; }

    void SetPosition(const Vector2f &pos) { _pos = pos; }

    void Move(const Vector2f &vec) { _pos += vec; }

    Vector2f RasterToWorld(const Vector2i &pos) const;

    Vector2i WorldToRaster(const Vector2f &pos) const;
};
}
