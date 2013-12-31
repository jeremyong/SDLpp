#pragma once

#include <iostream>
#include "Vector2.h"
#include <cmath>

namespace sdl {
class Vector2f : public Vector2<float> {
public:
    Vector2f() : Vector2<float>(0.f, 0.f) {}

    Vector2f(const float x_, const float y_) : Vector2<float>(x_, y_) {}

    Vector2f& operator/=(const float k) {
        const float k_inv = 1.f / k;
        x *= k_inv;
        y *= k_inv;
        return *this;
    }

    float LengthSquared() const {
        return (x*x + y*y);
    }

    float Length() const {
        return sqrt(LengthSquared());
    }

    void Normalize() {
        const float length_inv = 1.f / Length();
        x *= length_inv;
        y *= length_inv;
    }

    Vector2f operator/(const float k) const {
        float k_inv = 1.f / k;
        return Vector2f{x * k_inv, y * k_inv};
    }

    Vector2f operator+(const Vector2f &v) const {
        return Vector2f{x + v.x, y + v.y};
    }

    Vector2f operator-(const Vector2f &v) const {
        return Vector2f{x - v.x, y - v.y};
    }

    Vector2f operator-() const {
        return Vector2f{-x, -y};
    }

    Vector2f operator*(const float k) const {
        return Vector2f{x * k, y * k};
    }
};

inline float Dot(const Vector2f &v1, const Vector2f &v2) {
    return (v1.x * v2.x + v1.y * v2.y);
}
}
