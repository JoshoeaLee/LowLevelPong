#ifndef BALL_H
#define BALL_H

#include "../include/SDL2/SDL.h"
#include "vec2d.h"

class Ball
{
public:
    Ball(int ballWidth, int ballHeight, Vec2D startingPoint);
    void Draw(SDL_Renderer *renderer);

    int ballWidth, ballHeight;
    Vec2D currentPosition;

private:
    SDL_Rect ballObject;
};

#endif