#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_ttf.h"

#include <iostream>
#include <chrono>
#include "../headers/vec2d.h"
#include "../headers/ball.h"
#include "../headers/paddle.h"
#include "../headers/scoreboard.h"
#include "../headers/Enums.h"


#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 700
#define FONT_PATH "Minecraft.ttf"
#define FONT_SIZE 32
#define BALL_SIZE 15
#define BALL_SPEED 16
#define PADDLE_WIDTH BALL_SIZE
#define PADDLE_HEIGHT BALL_SIZE * 8
#define PADDLE_SPEED 0.3f

SDL_Renderer *renderer;
SDL_Window *window;
SDL_Color color;

TTF_Font *font;

using std::cout;
using std::endl;
using std::string;
using std::chrono::time_point;
using Clock = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point<Clock>;

bool running;
bool buttonDown[4] = {};

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    font = TTF_OpenFont(FONT_PATH, FONT_SIZE);

    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);

    SDL_Color ColourUsed = {0xFF, 0xFF, 0xFF, 0xFF};


    Ball ball(BALL_SIZE, BALL_SIZE, Vec2D((WINDOW_WIDTH / 2.0f), (WINDOW_HEIGHT / 2.0f)));

    Paddle leftPaddle(PADDLE_WIDTH, PADDLE_HEIGHT, Vec2D(100.0f, (WINDOW_HEIGHT / 2.0f)), Vec2D(0.0f, 0.0f));
    Paddle rightPaddle(PADDLE_WIDTH, PADDLE_HEIGHT, Vec2D(WINDOW_WIDTH - 100.0f, (WINDOW_HEIGHT / 2.0f)), Vec2D(0.0f, 0.0f));

    Scoreboard leftScore(renderer, font, Vec2D(WINDOW_WIDTH / 4, 10), ColourUsed);
    Scoreboard rightScore(renderer, font, Vec2D(3 * WINDOW_WIDTH / 4, 10), ColourUsed);

    Scoreboard leftScore(renderer, font, Vec2D(WINDOW_WIDTH / 4, 10), ColourUsed);
    Scoreboard rightScore(renderer, font, Vec2D(3 * WINDOW_WIDTH / 4, 10), ColourUsed);

    running = true;
    float timeMoved = 0.0f;

    while (running)
    {
        TimePoint startMoving = Clock::now();

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_1:
                    running = false;
                    break;

                case SDLK_UP:
                    buttonDown[Buttons::RightPaddleUp] = true;
                    break;

                case SDLK_DOWN:
                    buttonDown[Buttons::RightPaddleDown] = true;
                    break;

                case SDLK_w:
                    buttonDown[Buttons::LeftPaddleUp] = true;
                    break;

                case SDLK_s:
                    buttonDown[Buttons::LeftPaddleDown] = true;
                    break;

                default:
                    break;
                }
            }
            else if (event.type == SDL_KEYUP)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_UP:
                    buttonDown[Buttons::RightPaddleUp] = false;
                    break;

                case SDLK_DOWN:
                    buttonDown[Buttons::RightPaddleDown] = false;
                    break;

                case SDLK_w:
                    buttonDown[Buttons::LeftPaddleUp] = false;
                    break;

                case SDLK_s:
                    buttonDown[Buttons::LeftPaddleDown] = false;
                    break;

                default:
                    break;
                }
            }
            else if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        if (buttonDown[Buttons::LeftPaddleUp])
        {
            leftPaddle.currentVelocity.y = -PADDLE_SPEED;
        }
        else if (buttonDown[Buttons::LeftPaddleDown])
        {
            leftPaddle.currentVelocity.y = PADDLE_SPEED;
        }
        else
        {
            leftPaddle.currentVelocity.y = 0;
        }

        if (buttonDown[Buttons::RightPaddleUp])
        {
            rightPaddle.currentVelocity.y = -PADDLE_SPEED;
        }
        else if (buttonDown[Buttons::RightPaddleDown])
        {
            rightPaddle.currentVelocity.y = PADDLE_SPEED;
        }
        else
        {
            rightPaddle.currentVelocity.y = 0;
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

        leftPaddle.Update(timeMoved, WINDOW_HEIGHT);
        rightPaddle.Update(timeMoved, WINDOW_HEIGHT);

        ball.Draw(renderer);

        leftPaddle.Draw(renderer);
        rightPaddle.Draw(renderer);

        leftScore.Draw();
        rightScore.Draw();

        SDL_RenderPresent(renderer);

        TimePoint endMoving = Clock::now();
        timeMoved = std::chrono::duration<float, std::chrono::milliseconds::period>(endMoving - startMoving).count();
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}