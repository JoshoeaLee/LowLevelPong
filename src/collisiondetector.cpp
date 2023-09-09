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
    float paddleTopPoint = paddle.currentPosition.y;
    float paddleBottomPoint = paddle.currentPosition.y + paddle.paddleHeight;
    float paddleLeftPoint = paddle.currentPosition.x;
    float paddleRightPoint = paddle.currentPosition.x + paddle.paddleWidth;

    float ballTopPoint = ball.currentPosition.y;
    float ballBottomPoint = ball.currentPosition.y + ball.ballHeight;
    float ballLeftPoint = ball.currentPosition.x;
    float ballRightPoint = ball.currentPosition.x + ball.ballWidth;

    if (ballTopPoint >= paddleBottomPoint || ballBottomPoint <= paddleTopPoint)
    {
        return false;
    }

    if (ballLeftPoint >= paddleRightPoint || ballRightPoint <= paddleLeftPoint)
    {
        return false;
    }

    return true;
}