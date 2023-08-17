#include "../headers/scoreboard.h"
#include "../headers/vec2d.h"
#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_ttf.h"

Scoreboard::Scoreboard(SDL_Renderer *renderer, TTF_Font *font, Vec2D startingPosition, SDL_Color pointColour)
    : renderer(renderer), font(font), currentPosition(startingPosition), pointColour(pointColour)
{
    // Yoinking this part from a guide.
    // A Surface and Texture are both representations of images.
    // A surface is what is used to render text, but can't be used for efficient rendering
    surface = TTF_RenderText_Solid(font, "0", pointColour);
    // Takes the surface and then makes it into an image which IS optimized for rendering
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    // Surfaces are kind of like the intermediate stage here?

    // We now take our texture and assign variables representing its format, access point, width and height
    // Since I don't care about format or access point a null pointer is used
    SDL_QueryTexture(texture, nullptr, nullptr, &scoreBoardWidth, &scoreBoardHeight);

    this->scoreBoardObject.w = scoreBoardWidth;
    this->scoreBoardObject.h = scoreBoardHeight;
    this->scoreBoardObject.x = static_cast<int>(currentPosition.x);
    this->scoreBoardObject.y = static_cast<int>(currentPosition.y);
}

Scoreboard::~Scoreboard()
{
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void Scoreboard::Draw()
{
    // You can specify what part of your texture you want to render in srcrect section
    // I use nullptr here because I want to just render it all
    SDL_RenderCopy(renderer, texture, nullptr, &scoreBoardObject);
}