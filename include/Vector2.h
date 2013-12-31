#pragma once

namespace sdl {
template <typename T>
class Vector2 {
public:
    T x, y;

    Vector2() {}

    Vector2(const T k_x, const T k_y) : x(k_x), y(k_y) {}

    Vector2& operator+=(const Vector2 &vec) {
        x += vec.x;
        y += vec.y;
        return *this;
    }

    Vector2& operator-=(const Vector2 &vec) {
        x -= vec.x;
        y -= vec.y;
        return *this;
    }

    Vector2& operator*=(const T k) {
        x *= k;
        y *= k;
        return *this;
    }

    bool operator==(const Vector2<T> &v) const {
        return (x == v.x && y == v.y);
    }

    Vector2<T> operator+(const Vector2<T> &v) const {
        return Vector2<T>(x + v.x, y + v.y);
    }

    Vector2<T> operator-(const Vector2<T> &v) const {
        return Vector2<T>(x - v.x, y - v.y);
    }

    Vector2<T> operator-() const {
        return Vector2<T>{-x, -y};
    }

    Vector2<T> operator*(const T k) const {
        return Vector2<T>{x * k, y * k};
    }

    friend std::ostream& operator<<(std::ostream &os, const Vector2<T> &v) {
        os << std::string("<") << v.x << ", " << v.y << ">";
        return os;
    }
};

typedef Vector2<int> Vector2i;
}
