#include <cmath>

struct Vector2Df {
    float x;
    float y;

    Vector2Df() : x(0.0f), y(0.0f) {}

    Vector2Df(float xVal, float yVal) : x(xVal), y(yVal) {}

    Vector2Df operator+(const Vector2Df& other) const 
    {
        return Vector2Df(x + other.x, y + other.y);
    }

    Vector2Df operator-(const Vector2Df& other) const 
    {
        return Vector2Df(x - other.x, y - other.y);
    }

    Vector2Df operator*(float scalar) const 
    {
        return Vector2Df(x * scalar, y * scalar);
    }
    
    Vector2Df operator/(float scalar) const 
    {
        return Vector2Df(x / scalar, y / scalar);
    }

    float magnitude() const 
    {
        return std::sqrt(x * x + y * y);
    }

    Vector2Df normalized() const 
    {
        float mag = magnitude();
        return mag != 0 ? *this / mag : Vector2Df(0.0f, 0.0f);
    }
};
