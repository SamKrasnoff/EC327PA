#ifndef MODEL_H
#define MODEL_H
#include <stdio.h>
#include "GameObject.h"
#include "Pokemon.h"
#include "PokemonGym.h"
#include "PokemonCenter.h"
#include "View.h"
class Model{
    private:
        int time;
        GameObject* object_ptrs[10];
        int num_objects;
        Pokemon* pokemon_ptrs[10];
        int num_pokemon;
        PokemonGym* gym_ptrs[10];
        int num_centers;
        PokemonCenter* center_ptrs[10];
        int num_gyms;
        int beaten_gyms;
        int exhausted_pokemon;
        //time is to show progression
        //object,pokemon,gym,center pointers to allow for use of various objects
        //num_(objects) are to allow for varying number and loop if neccesary
        //beaten_gyms, exhausted_pokemon to check for win/lose condition
    public:
        Model();
        ~Model();
        Model(const Model&);
        Pokemon* GetPokemonPtr(int id);
        PokemonCenter* GetPokemonCenterPtr(int id);
        PokemonGym* GetPokemonGymPtr(int id);
        bool Update();
        void Display(View& view);
        void ShowStatus();
};
#endif