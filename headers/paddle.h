#ifndef PADDLE_H
#define PADDLE_H

#include "vec2d.h"
#include "../include/SDL2/SDL.h"

class Paddle
{
public:
    Paddle(int paddleWidth, int paddleHeight, Vec2D startingPoint);
    void Draw(SDL_Renderer *renderer);

private:
    SDL_Rect paddleObject;
    int paddleWidth, paddleHeight;
    Vec2D currentPosition;
};

#endif