#include "fractal.h"
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <ctime>

#define PI 3.141

Fractal::Fractal(int pointNum, int stepSize, int offset)
    :pointNum(pointNum), stepSize(stepSize), offset(offset), currentAttractor(0)
{
    srand(time(NULL));
    setCurrentPoint(0,0);
    attractorPoints = nullptr;
    setupAttractors();
    currentAttractor = 0;
}

Fractal::~Fractal()
{
    if(attractorPoints) delete[] attractorPoints;
}

void Fractal::generateNextPoint(float weight)
{
    int chosenIndex = (currentAttractor + offset + stepSize*rand()%pointNum)%pointNum;
    Vec2 chosenPoint = attractorPoints[chosenIndex];
    currentPoint.Move(chosenPoint - currentPoint, weight);
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
    currentPoint.x = x;
    currentPoint.y = y;
}

void Fractal::setupAttractors(float radius)
{
    if(attractorPoints) delete[] attractorPoints;
    attractorPoints = new Vec2[pointNum];
    //TODO switch()
    for(int i = 0; i < pointNum; ++i)
    {
        int newX = radius*cos(2.0*PI*i/pointNum);
        int newY = radius*sin(2.0*PI*i/pointNum);
        attractorPoints[i] = Vec2(newX, newY);
    }
}

float Fractal::getX()
{
    return currentPoint.x;
}

float Fractal::getY()
{
    return currentPoint.y;
}




Vec2::Vec2(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Vec2::Move(const Vec2 &arg, double weight)
{
    x += arg.x*weight;
    y += arg.y*weight;
}

Vec2 Vec2::operator-(const Vec2 &arg)
{
    return Vec2(x - arg.x, y - arg.y);
}
