#include "../headers/ball.h"
#include "../headers/paddle.h"
#include "../headers/collisiondetector.h"
#include "../include/SDL2/SDL.h"

CollisionDetector::CollisionDetector()
{
    // Empty Constructor
}

CollisionDetector &CollisionDetector::GetCollisionDetectorInstance()
{
    static CollisionDetector collisionDetectorInstance;
    return collisionDetectorInstance;
}

bool CollisionDetector::CheckForBallPaddleCollision(Ball const &ball, Paddle const &paddle)
{
    // Enter code here
}