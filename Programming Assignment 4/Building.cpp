#include "Building.h"
//Default constructor for building
Building::Building():GameObject(display_code){
    this->display_code = 'B';
    cout << "Building default constructed" << endl;
}
//constructor with displayc ode, id, location
Building::Building(char in_code,int in_Id, Point2D in_loc):GameObject(in_loc, in_Id, in_code){
    this->id_num = in_Id;
    this->location = in_loc;
    this->display_code = in_code;
    cout << "Building constructed" << endl;
}
//building destructor
Building::~Building(){
    cout << "Building Destructed" << endl;
}
//adds one pokemon to the given building
void Building::AddOnePokemon(){
    pokemon_count += 1;
}
//removes one pokemon from the given building
void Building::RemoveOnePokemon(){
    pokemon_count -= 1;
}
//I created this to get pokemon_count, a private int
unsigned int Building::getPokemonCount(){
    return pokemon_count;
}
//displays information about building (num pokemon)
void Building::ShowStatus(){
    cout << display_code << this -> GetId() << " located at " << location << endl;
    cout << "\t" << pokemon_count << " pokemon ";
    if (pokemon_count == 1){
        cout << "is";
    }
    else{
        cout << "are";
    }
    cout << " in the building" << endl;
}
//test function for polymorphism
bool Building::ShouldBeVisible(){
    return true;
}