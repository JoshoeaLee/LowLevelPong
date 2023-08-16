#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

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

        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}