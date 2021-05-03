#include "fractal.h"
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <ctime>

Fractal::Fractal(int pointNum, int stepSize, int offset)
    :pointNum(pointNum), stepSize(stepSize), offset(offset), currentAttractor(0)
{
    srand(time(NULL));
    setCurrentPoint(0,0);
    attractorPoints = new Vec2[1];
    currentAttractor = 0;
}

Fractal::~Fractal()
{
    delete[] attractorPoints;
}

void Fractal::generateNextPoint(float weight)
{
    int chosenIndex = (currentAttractor + offset + stepSize*rand()%pointNum)%pointNum;
    Vec2 chosenPoint = attractorPoints[chosenIndex];
    this->currentPoint.Move(chosenPoint - currentPoint, weight);
}

void Fractal::UpdateParams(int pointNum, int stepSize, int offset)
{
    this->stepSize = stepSize;
    this->offset = offset;
    this->pointNum = pointNum;
    currentAttractor = 0;
    setupAttractors();
}

void Fractal::setCurrentPoint(float x, float y)
{
    this->currentPoint.x = x;
    this->currentPoint.y = y;
}

void Fractal::setupAttractors()
{
    delete[] attractorPoints;
    attractorPoints = new Vec2[pointNum];
    //TODO switch()
    int radius = 50;
    for(int i = 0; i < pointNum; ++i)
    {
        int newX = radius*cos(i/pointNum);
        int newY = radius*sin(i/pointNum);
        attractorPoints[i] = Vec2(newX, newY);
    }
}

float Fractal::getX()
{
    return this->currentPoint.x;
}

float Fractal::getY()
{
    return this->currentPoint.y;
}




Vec2::Vec2(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Vec2::Move(const Vec2 &arg, double weight)
{
    this->x += arg.x*weight;
    this->y += arg.y*weight;
}

Vec2 Vec2::operator-(const Vec2 &arg)
{
    return Vec2(this->x - arg.x, this->y - arg.y);
}
