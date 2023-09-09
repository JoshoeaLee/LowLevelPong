#ifndef PADDLE_H
#define PADDLE_H

#include "vec2d.h"
#include "../include/SDL2/SDL.h"

class Paddle
{
public:
    Paddle(int paddleWidth, int paddleHeight, Vec2D startingPoint, Vec2D startingVelocity);
    void Draw(SDL_Renderer *renderer);
    void Update(float timeMoved, int windowHeight);
    Vec2D currentVelocity;
    int paddleWidth, paddleHeight;
    Vec2D currentPosition;

private:
    SDL_Rect paddleObject;
};

#endif