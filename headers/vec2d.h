#ifndef VEC2D_H
#define VEC2D_H

class Vec2D
{
public:
    Vec2D(float x, float y);
    Vec2D operator+(Vec2D const &rhs);
    Vec2D operator-(Vec2D const &rhs);
    Vec2D operator*(float rhs);

    float x, y;
};

#endif