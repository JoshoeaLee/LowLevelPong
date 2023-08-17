#include "../headers/paddle.h"
#include "../headers/vec2d.h"
#include "../include/SDL2/SDL.h"

Paddle::Paddle(int paddleWidth, int paddleHeight, Vec2D startingPoint)
    : paddleWidth(paddleWidth), paddleHeight(paddleHeight), currentPosition(startingPoint)
{
    this->paddleObject.w = paddleWidth;
    this->paddleObject.h = paddleHeight;
    this->paddleObject.x = static_cast<int>(currentPosition.x);
    this->paddleObject.y = static_cast<int>(currentPosition.y);
}

void Paddle::Draw(SDL_Renderer *renderer)
{
    this->paddleObject.x = static_cast<int>(currentPosition.x);
    this->paddleObject.y = static_cast<int>(currentPosition.y);

    SDL_RenderFillRect(renderer, &this->paddleObject);
}