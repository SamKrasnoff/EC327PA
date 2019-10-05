#include <math.h>
#include <iostream>
using namespace std;

int main(){
    float sq1 [3] = {};
    float sq2 [3] = {};
    cout << "Enter the information for the first square:" << endl;
    cout << "X coordinate: " << endl;
    cin >> sq1[0];
    cout << "Y coordinate: " << endl;
    cin >> sq1[1];
    cout << "Area: " << endl;
    cin >> sq1[2];
    cout << "Enter the information for the second square: " << endl;
    cout << "X coordinate: " << endl;
    cin >> sq2[0];
    cout << "Y coordinate: " << endl;
    cin >> sq2[1];
    cout << "Area: " << endl;
    cin >> sq2[2];
    float sq1coor [4] = {sq1[0],sq1[0]+sqrt(sq1[2]),sq1[1],sq1[1]-sqrt(sq1[2])};
    float sq2coor [4] = {sq2[0],sq2[0]+sqrt(sq2[2]),sq2[1],sq2[1]-sqrt(sq2[2])};
    cout << sq1coor[0] << " and " << sq1coor[1] << " and y=" << sq1coor[2] << " and " << sq1coor[3] << endl;
    cout << sq2coor[0] << " and " << sq2coor[1] << " and y=" << sq2coor[2] << " and " << sq2coor[3] << endl;
    if ((sq2coor[0] > sq1coor[0] && sq2coor[0] < sq1coor[1]) && (sq2coor[2] < sq1coor[2] && sq2coor[2] > sq1coor[3])){
        cout << "THE SQUARES INTERSECT" << endl;
    }
    else if ((sq2coor[1] < sq1coor[1] && sq2coor[1] > sq1coor[0]) && (sq2coor[2] < sq1coor[2] && sq2coor[2] > sq1coor[3])){
        cout << "THE SQUARES INTERSECT" << endl;
    }
    else if((sq1coor[0] > sq2coor[0] && sq1coor[0] < sq2coor[1]) && (sq1coor[2] < sq2coor[2] && sq1coor[2] > sq2coor[3])){
        cout << "THE SQUARES INTERSECT" << endl;
    }
    else if ((sq1coor[1] < sq2coor[1] && sq1coor[1] > sq2coor[0]) && (sq1coor[2] < sq2coor[2] && sq1coor[2] > sq2coor[3])){
        cout << "THE SQUARES INTERSECT" << endl;
    }
    else{
        cout << "THE SQUARES DO NOT INTERSECT" << endl;
    }
}