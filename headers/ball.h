#ifndef BALL_H
#define BALL_H

#include "vec2d.h"
#include "../include/SDL2/SDL.h"

class Ball
{
public:
    Ball(int ballWidth, int ballHeight, Vec2D startingPoint, Vec2D startingVelocity);
    void Draw(SDL_Renderer *renderer);
    void Update(float timeMoved);
    Vec2D currentVelocity;

private:
    SDL_Rect ballObject;
    int ballWidth, ballHeight;
    Vec2D currentPosition;
};

#endif