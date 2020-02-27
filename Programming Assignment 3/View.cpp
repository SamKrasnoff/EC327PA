#include "View.h"
//default and only constructor, sets scale size, origin
View::View(){
    this->size = 11;
    this->scale = 2;
    this->origin = Point2D(0,0);
}
//uses scale to get points for graphing
bool View::GetSubscripts(int &out_x,int &out_y, Point2D location){
    out_x = (location.x - origin.x)/scale;
    out_y = (location.y - origin.y)/scale;
    //checks if in bounds
    if (out_x < size || out_y < size){
        return true;
    }
    else{
        cout << "An Object is outside the display." << endl;
        return false;
    }
}
//clears graph to all dots and spaces
void View::Clear(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            grid[i][j][0] = '.';
            grid[i][j][1] = ' ';
        }
    }
}
//puts codes and ids on graph
void View::Plot(GameObject* ptr){
    int a, b;
    int& x = a;
    int& y = b;
    //gets subscripts into x, y
    bool exists = GetSubscripts(x,y,ptr -> GetLocation());
    //checks if only . in given subscript space
    if(grid[x][y][0] == '.'){
        ptr -> DrawSelf(grid[x][y]);
        //only display code was working so hard coded this sorry
        char achar = '0' + ptr->GetId();
        grid[x][y][1] = achar;
    }
    else{
        //if multiple objects put *
        grid[x][y][0] = '*';
        grid[x][y][1] = ' ';
    }
}
//draws actual grid
void View::Draw(){
    for(int i = size-1; i >= 0; i--){
        // this is numbers on left/y-axis
        if(i % 2 == 0){
            cout << i*2;
            if(i*2 < 10){
                cout << " ";    
            }
        }
        else{
            cout << "  ";
        }
        //plots actual values
        for(int j = 0; j < size; j++){
            cout << grid[j][i][0];
            cout << grid[j][i][1];
        }
        cout << endl;
    }
    cout << "  ";
    //puts numbers on x-axis
    for (int x = 0; x < size; x++){
        if(x % 2 == 0){
            cout << x*2 << "  ";
            if(x*2 < 10){
                cout << " ";
            }
        }
    }
    cout << endl;
}
