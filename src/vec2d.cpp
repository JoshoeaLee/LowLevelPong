#include "../headers/vec2d.h"

Vec2D::Vec2D(float x, float y)
    : x(x), y(y)
{
}

Vec2D Vec2D::operator+(Vec2D const &rhs)
{
    return Vec2D(x + rhs.x,
                 y + rhs.y);
}

Vec2D Vec2D::operator-(Vec2D const &rhs)
{
    return Vec2D(x - rhs.x,
                 y - rhs.y);
}

Vec2D Vec2D::operator*(float rhs)
{
    return Vec2D(x * rhs,
                 y * rhs);
}
