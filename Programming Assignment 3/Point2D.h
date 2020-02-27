#ifndef POINT2D_H
#define POINT2D_H
#include "Vector2D.h"
#include <iostream>
using namespace std;
class Point2D{
    //coords for a point
    public:
        double x, y;
    Point2D(double, double);
    Point2D();
};

Vector2D operator -(Point2D, Point2D);
Point2D operator +(Point2D, Vector2D);
ostream& operator <<(ostream&, Point2D);
double getDistanceBetween(Point2D, Point2D);
#endif