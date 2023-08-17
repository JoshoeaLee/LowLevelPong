#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_ttf.h"
#include "vec2d.h"

class Scoreboard
{
public:
    Scoreboard(SDL_Renderer *renderer, TTF_Font *font, Vec2D startingPosition, SDL_Color pointColour);
    ~Scoreboard();

    void Draw();

private:
    SDL_Renderer *renderer;
    TTF_Font *font;
    SDL_Surface *surface;
    SDL_Color pointColour;
    SDL_Texture *texture;
    SDL_Rect scoreBoardObject;
    int scoreBoardWidth, scoreBoardHeight;
    Vec2D currentPosition;
};

#endif