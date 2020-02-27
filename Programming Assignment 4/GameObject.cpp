#include <iostream>
#include "GameObject.h"
//constructor with just display code
GameObject::GameObject(char incode){
        display_code = incode;
        id_num = 1;
        state = '0';
        cout << "GameObject construted" <<  endl;
}
//full constructor with all values
GameObject::GameObject(Point2D in_loc,int in_id, char in_code){
    location = in_loc;
    id_num = in_id;
    display_code = in_code;
    state = '0';
    cout << "GameObject construted" <<  endl;
}
//destructor for gameobject
GameObject::~GameObject(){
    cout << "GameObject Destructed" << endl;
}
//returns location
Point2D GameObject::GetLocation(){
    return location;
}
//returns id
int GameObject::GetId(){
    return id_num;
}
//returns state
char GameObject::GetState(){
    return state;
}
//returns display_code
char GameObject::GetDisplayCode(){
    return display_code;
}
//shows basic status 
void GameObject::ShowStatus(){
    cout << display_code << id_num << " at " << location;
}
//assign display code and id to correct place in grid
void GameObject::DrawSelf(char* ptr){
    ptr[0] = this->display_code;
    ptr[1] = (char) this->id_num;
}
//pure virtual impelementation
bool GameObject::Update(){

}
bool GameObject::ShouldBeVisible(){

}