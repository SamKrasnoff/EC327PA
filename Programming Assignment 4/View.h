#ifndef VIEW_H
#define VIEW_H
#include "GameObject.h"
#include "string.h"
//this is the bounds for the grid
const int view_maxsize = 20;
class View{
    private:
        int size;
        double scale;
        Point2D origin;
        char grid[view_maxsize][view_maxsize][2];
        //size depends on scale
        //scale is how many dots
        //origin is always 0,0
        //grid is actual grid, 3 dimentions for arrray with display_code, id
        bool GetSubscripts(int &out_x,int &out_y, Point2D location);
    public:
        View();
        void Clear();
        void Plot(GameObject* ptr);
        void Draw();
};
#endif