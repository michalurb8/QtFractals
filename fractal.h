#ifndef FRACTAL_H
#define FRACTAL_H

struct Vec2
{
    Vec2(int x=0, int y=0);
    int x, y;
    void Move(const Vec2& arg, double percent);
    Vec2 operator-(const Vec2& arg);
};

class Fractal
{
    int pointNum;
    int stepSize;
    int offset;
    Vec2 currentPoint;
    Vec2* attractorPoints;
    int currentAttractor;
    void setCurrentPoint(int x, int y);
    void generateFirstPoint();
    void setupAttractors();
public:
    Fractal(int pointNum = 3, int stepSize = 0, int offset = 0);
    ~Fractal();
    void generateNextPoint();
    void UpdateParams(int pointNum, int stepSize, int offset);
    int getX();
    int getY();

};

#endif // FRACTAL_H
