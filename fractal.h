#ifndef FRACTAL_H
#define FRACTAL_H

enum generationRule {CIRCLE, NOISE, RANDOM};
enum colorRule {MONO, PARENT, TYPE};

struct Vec2
{
    Vec2(float x=0, float y=0);
    float x, y;
    void Move(const Vec2& arg, double weight=0.5);
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
    void setCurrentPoint(float x, float y);
    void generateFirstPoint();
    void setupAttractors(float radius = 1, generationRule gRule = CIRCLE);
public:
    Fractal(int pointNum = 3, int stepSize = 1, int offset = 0);
    ~Fractal();
    void generateNextPoint(float weight=0.5);
    void updateParams(int pointNum, int stepSize, int offset);
    int getCurrentAttractor();
    float getX();
    float getY();

};

#endif // FRACTAL_H
