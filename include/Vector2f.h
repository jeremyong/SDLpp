#pragma once

#include <iostream>
#include <cmath>

namespace sdl {
class Vector2f {
public:
    float u, v;

    Vector2f() {
        u = v = 0.f;
    }

    Vector2f(const float k_u, const float k_v) : u(k_u), v(k_v) {}

    Vector2f(const Vector2f &vec) {
        u = vec.u;
        v = vec.v;
    }

    Vector2f& operator+=(const Vector2f &vec) {
        u += vec.u;
        v += vec.v;
        return *this;
    }

    Vector2f& operator-=(const Vector2f &vec) {
        u -= vec.u;
        v -= vec.v;
        return *this;
    }

    Vector2f& operator*=(const float k) {
        u *= k;
        v *= k;
        return *this;
    }

    Vector2f& operator/=(const float k) {
        const float k_inv = 1.f / k;
        u *= k_inv;
        v *= k_inv;
        return *this;
    }

    float LengthSquared() const {
        return (u*u + v*v);
    }

    float Length() const {
        return sqrt(LengthSquared());
    }

    void Normalize() {
        const float length_inv = 1.f / Length();
        u *= length_inv;
        v *= length_inv;
    }

    friend std::ostream& operator<<(std::ostream &, const Vector2f &);
};

inline bool operator==(const Vector2f &v1, const Vector2f &v2) {
    return (v1.u == v2.u && v1.v == v2.v);
}

inline float Dot(const Vector2f &v1, const Vector2f &v2) {
    return (v1.u * v2.u + v1.v * v2.v);
}

inline Vector2f operator+(const Vector2f &v1, const Vector2f &v2) {
    return Vector2f(v1.u + v2.u, v1.v + v2.v);
}

inline Vector2f operator-(const Vector2f &v1, const Vector2f &v2) {
    return Vector2f(v1.u - v2.u, v1.v - v2.v);
}

inline Vector2f operator-(const Vector2f &vec) {
    return Vector2f(-1.f * vec.u, -1.f * vec.v);
}

inline Vector2f operator*(const Vector2f &vec, const float k) {
    return Vector2f(vec.u * k, vec.v * k);
}

inline Vector2f operator*(const float k, const Vector2f &vec) {
    return Vector2f(vec.u * k, vec.v * k);
}

inline Vector2f operator/(const Vector2f &vec, const float k) {
    const float k_inv = 1.f/k;
    return Vector2f(vec.u * k_inv, vec.v * k_inv);
}

inline float LengthSquared(const Vector2f &vec) {
    return vec.LengthSquared();
}

inline float Length(const Vector2f &vec) {
    return vec.Length();
}

inline Vector2f Normalize(const Vector2f &vec) {
    return (vec / Length(vec));
}
}
