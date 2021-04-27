#include "fractal.h"
#include <cmath>
#include <ctime>
#include <cstdlib>

Fractal::Fractal(int pointNum, int stepSize, int offset)
    :pointNum(pointNum), stepSize(stepSize), offset(offset), currentAttractor(0)
{
    setCurrentPoint(0,0);
    attractorPoints = new Vec2[1];
}

Fractal::~Fractal()
{
    delete[] attractorPoints;
}

void Fractal::generateNextPoint()
{
    int chosenIndex = (currentAttractor + offset + stepSize*rand()%pointNum)%pointNum;
    Vec2 chosenPoint = attractorPoints[chosenIndex];
    this->currentPoint.Move(chosenPoint - currentPoint, 0.2);
}

void Fractal::UpdateParams(int pointNum, int stepSize, int offset)
{
    currentAttractor = 0;
    this->stepSize = stepSize;
    this->offset = offset;
    if(this->pointNum == pointNum)
    {
        this->pointNum = pointNum;
        setupAttractors();
    }
    else this->pointNum = pointNum;
}

void Fractal::setCurrentPoint(int x, int y)
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

int Fractal::getX()
{
    return this->currentPoint.x;
}

int Fractal::getY()
{
    return this->currentPoint.y;
}

Vec2::Vec2(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Vec2::Move(const Vec2 &arg, double percent)
{
    this->x += arg.x*percent;
    this->y += arg.y*percent;
}

Vec2 Vec2::operator-(const Vec2 &arg)
{
    return Vec2(this->x - arg.x, this->y - arg.y);
}
