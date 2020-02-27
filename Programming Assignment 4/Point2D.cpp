#include <math.h>
#include "Point2D.h"
//constructor to put in coords
Point2D::Point2D(double in_x, double in_y){
    x = in_x;
    y = in_y;
}
//default constructor
Point2D::Point2D(){
    x = 0.0;
    y = 0.0;
}
//overloaded plus operator
Point2D operator +(Point2D obj, Vector2D obj1) { 
    Point2D res; 
    res.x = obj.x + obj1.x; 
    res.y = obj.y + obj1.y; 
    return res; 
    }
//overloaded - operator
Vector2D operator -(Point2D obj, Point2D obj1) { 
    Vector2D res; 
    res.x = obj.x - obj1.x; 
    res.y = obj.y - obj1.y; 
    return res; 
}
//overloaded print operator
ostream& operator << (ostream& output, Point2D P) { 
    output << "(" << P.x << ",  " << P.y << ")";
    return output;            
}
//returns distance between points
double getDistanceBetween(Point2D P1, Point2D P2){
    return sqrt(pow(P2.x-P1.x,2)+pow(P2.y-P1.y,2));
}

