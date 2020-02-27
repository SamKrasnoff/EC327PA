#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>
#include "GameObject.h"
using namespace std;
class Building: public GameObject{
    private:
        unsigned int pokemon_count = 0;
        //stores num pokemon
    public:
    Building();
    Building(char in_code, int in_Id, Point2D in_loc);
    ~Building();
    unsigned int getPokemonCount();
    void AddOnePokemon();
    void RemoveOnePokemon();
    void ShowStatus();
    bool ShouldBeVisible();
    //bool Update();
};
#endif