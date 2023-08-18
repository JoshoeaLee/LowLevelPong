#include "../headers/ball.h"
#include "../headers/vec2d.h"
#include "../include/SDL2/SDL.h"

Ball::Ball(int ballWidth, int ballHeight, Vec2D startingPoint, Vec2D startingVelocity)
    : ballWidth(ballWidth), ballHeight(ballHeight), currentPosition(startingPoint), currentVelocity(startingVelocity)
{
    this->ballObject.x = static_cast<int>(startingPoint.x);
    this->ballObject.y = static_cast<int>(startingPoint.y);
    this->ballObject.w = ballWidth;
    this->ballObject.h = ballHeight;
}

void Ball::Draw(SDL_Renderer *renderer)
{
    this->ballObject.x = static_cast<int>(currentPosition.x);
    this->ballObject.y = static_cast<int>(currentPosition.y);

    SDL_RenderFillRect(renderer, &this->ballObject);
}

void Ball::Update(float timeMoved)
{
    this->currentPosition = this->currentPosition + (this->currentVelocity * timeMoved);
}
