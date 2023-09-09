#ifndef COLLISIONDETECTOR
#define COLLISIONDETECTOR

#include "ball.h"
#include "paddle.h"
#include "../include/SDL2/SDL.h"

class CollisionDetector
{
public:
    static CollisionDetector &GetCollisionDetectorInstance();
    bool CheckForBallPaddleCollision(Ball const &ball, Paddle const &paddle);

private:
    CollisionDetector();
};

#endif