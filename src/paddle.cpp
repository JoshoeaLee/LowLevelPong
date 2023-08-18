#include "../headers/paddle.h"
#include "../headers/vec2d.h"
#include "../include/SDL2/SDL.h"

Paddle::Paddle(int paddleWidth, int paddleHeight, Vec2D startingPoint, Vec2D startingVelocity)
    : paddleWidth(paddleWidth), paddleHeight(paddleHeight), currentPosition(startingPoint), currentVelocity(startingVelocity)
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

void Paddle::Update(float timeMoved, int windowHeight)
{
    this->currentPosition = this->currentPosition + (currentVelocity * timeMoved);

    if (this->currentPosition.y < 0)
    {
        this->currentPosition.y = 0;
    }
    else if (this->currentPosition.y > windowHeight - this->paddleHeight)
    {
        this->currentPosition.y = windowHeight - this->paddleHeight;
    }
}