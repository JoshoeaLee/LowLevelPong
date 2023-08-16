#ifndef BALL_H
#define BALL_H

#include "vec2d.h"
#include "../include/SDL2/SDL.h"

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