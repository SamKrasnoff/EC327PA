#include <sstream>
#include "Vector2D.h"
using namespace std;
//vector constructor to input location
Vector2D::Vector2D(double in_x, double in_y){
    x = in_x;
    y = in_y;
}
//default constructor
Vector2D::Vector2D(){
    x = 0.0;
    y = 0.0;
}
//overloaded multiplication operator
Vector2D operator *(Vector2D vec, double d) { 
    Vector2D res; 
    res.x = vec.x * d; 
    res.y = vec.y * d; 
    return res; 
}
//overloaded division operator
Vector2D operator /(Vector2D vec, double d) { 
    Vector2D res; 
    res.x = vec.x / d; 
    res.y = vec.y / d; 
    return res; 
}
//overloaded print operator
ostream& operator <<( ostream &output, Vector2D V ) { 
        output << "<" << V.x << ", " << V.y << ">";
        return output;            
}