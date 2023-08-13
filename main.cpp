#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#define WIDTH 800
#define HEIGHT 800
#define FONT_PATH "Minecraft.ttf"
#define FONT_SIZE 32

SDL_Renderer *renderer;
SDL_Window *window;
SDL_Color color;

TTF_Font *font;

bool running;
int frameCount, timerFPS, lastFrame, fps;

void update() {}
void input()
{
    SDL_Event event;
    const Uint8 *keypresses = SDL_GetKeyboardState(NULL);

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            running = false;
        }

        if (keypresses[SDL_SCANCODE_ESCAPE])
        {
            running = false;
        }

        if (keypresses[SDL_SCANCODE_UP])
        {
            // Do later
        }

        if (keypresses[SDL_SCANCODE_DOWN])
        {
            // Do later
        }
    }
}

void render()
{

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255);
    SDL_RenderClear(renderer);

    frameCount++;
    timerFPS = SDL_GetTicks() - lastFrame;

    if (timerFPS < (1000 / 60))
    {
        SDL_Delay((1000 / 60) - timerFPS);
    }

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);

    SDL_RenderPresent(renderer);
}

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);
    TTF_Init();
    font = TTF_OpenFont(FONT_PATH, FONT_SIZE);

    running = 1;

    static int lastTime = 0;

    color.r = color.g = color.b = 255;

    while (running)
    {
        lastFrame = SDL_GetTicks();

        if (lastFrame >= (lastTime + 1000))
        {
            lastTime = lastFrame;
            fps = frameCount;
            frameCount = 0;
        }

        update();
        input();
        render();
    }
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}