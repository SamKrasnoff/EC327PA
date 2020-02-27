#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Vector2D.h"
#include "Point2D.h"
using namespace std;
class GameObject
{
protected:
    Point2D location;
    int id_num;
    char display_code;
    char state;
    //location is location of object, id_num and display code
    //give unique identifiers based on class and number of others in class
public:
    GameObject(char);
    GameObject(Point2D, int, char);
    virtual ~GameObject();
    Point2D GetLocation();
    int GetId();
    char GetDisplayCode();
    char GetState();
    void DrawSelf(char* ptr);
    virtual void ShowStatus();
    //update, shouldbevisible pure virtual
    virtual bool Update() = 0;
    virtual bool ShouldBeVisible() = 0;
};
#endif