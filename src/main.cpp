#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "../headers/vec2d.h"
#include "../headers/ball.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define FONT_PATH "Minecraft.ttf"
#define FONT_SIZE 32
#define BALLSIZE 16
#define BALL_SPEED 16
#define PADDLE_SPEED 9

SDL_Renderer *renderer;
SDL_Window *window;
SDL_Color color;

TTF_Font *font;

using std::cout;
using std::endl;
using std::string;

bool running;
int frameCount, timerFPS, lastFrame, fps;

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);
    Ball ball(15, 15, Vec2D((WINDOW_WIDTH / 2.0f), (WINDOW_HEIGHT / 2.0f)));
    TTF_Init();
    font = TTF_OpenFont(FONT_PATH, FONT_SIZE);

    running = true;

    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_1)
                {
                    running = false;
                }
            }
            else if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

        for (int i = 0; i < WINDOW_HEIGHT; i++)
        {
            if (i % 10 == 0)
            {
                SDL_RenderDrawPoint(renderer, WINDOW_WIDTH / 2, i);
            }
        }

        ball.Draw(renderer);

        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}