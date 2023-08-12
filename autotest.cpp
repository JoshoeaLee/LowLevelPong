#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#define WIDTH 800
#define HEIGHT 800
#define FONT_PATH "Peepo.ttf"
#define FONT_SIZE 32

SDL_Renderer *renderer;
SDL_Window *window;
SDL_Color color;

TTF_Font *font;

using std::cerr, std::endl;

int main()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        cerr << "Failed at SDL_Init()" << endl;
        return 1;
    }

    if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0)
    {
        cerr << "Failed at SDL_CreateWindowAndRenderer()" << endl;
        return 1;
    }
    if (TTF_Init() < 0)
    {
        cerr << "Failed at TTF_Init()" << endl;
        return 1;
    }

    font = TTF_OpenFont(FONT_PATH, FONT_SIZE);

    if (font == NULL)
    {
        cerr << "Invalid font being used" << endl;
        return 1;
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
