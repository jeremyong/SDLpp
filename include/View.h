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

    Vector2f GetSize() const { return _size; }

    Vector2f GetPosition() const { return _pos; }

    Vector2f GetCenter() const {
        Vector2f ret;
        ret.x = _pos.x + _size.x * 0.5f;
        ret.y = _pos.y + _size.y * 0.5f;
        return ret;
    }

    void SetPosition(const Vector2f &pos) { _pos = pos; }

    void SetPosition(const float x, const float y) {
        _pos.x = x;
        _pos.y = y;
    }

    void Move(const Vector2f &vec) { _pos += vec; }

    void Move(const float x, const float y) {
        _pos.x += x;
        _pos.y += y;
    }

    Vector2f RasterToWorld(const Vector2i &pos) const;

    Vector2i WorldToRaster(const Vector2f &pos) const;
};
}
