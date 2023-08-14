#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#define WIDTH 800
#define HEIGHT 800
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

SDL_Rect left_paddle, right_paddle, ball, scoreboard;
float x_velocity, y_velocity;
string score;
int left_score, right_score;
bool turn;

void serve()
{
    left_paddle.y = (HEIGHT / 2) - (left_paddle.h / 2);
    right_paddle.y = left_paddle.y;

    if (turn)
    {
        ball.x = left_paddle.x + (left_paddle.w * 4);
    }
    else
    {
        ball.x = right_paddle.x + (left_paddle.w * 4);
    }
    ball.y = HEIGHT / 2 - (BALLSIZE / 2);
    x_velocity = BALL_SPEED / 2;
    y_velocity = 0;
    turn = !turn;
}

void write(string text, int x, int y)
{
    SDL_Surface *surface;
    SDL_Texture *texture;
    const char *t = text.c_str();
    surface = TTF_RenderText_Solid(font, t, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    scoreboard.w = surface->w;
    scoreboard.h = surface->h;
    scoreboard.x = x - scoreboard.w;
    scoreboard.y = y - scoreboard.h;
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, NULL, &scoreboard);
    SDL_DestroyTexture(texture);
}

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

    write(score, WIDTH / 2 + FONT_SIZE, FONT_SIZE * 2);

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);

    SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);
    TTF_Init();
    font = TTF_OpenFont(FONT_PATH, FONT_SIZE);

    running = 1;

    static int lastTime = 0;

    color.r = color.g = color.b = 255;

    left_score = 0;
    left_paddle.x = 32;
    left_paddle.h = HEIGHT / 4;
    left_paddle.y = (HEIGHT / 2) - (left_paddle.h / 2);
    right_score = 0;
    right_paddle = left_paddle;
    right_paddle.x = WIDTH - right_paddle.w - 32;
    ball.w = ball.h = BALLSIZE;

    serve();

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