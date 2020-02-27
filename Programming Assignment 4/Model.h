#ifndef MODEL_H
#define MODEL_H
#include <stdio.h>
#include <list>
#include <iterator>
#include "GameObject.h"
#include "Pokemon.h"
#include "PokemonGym.h"
#include "PokemonCenter.h"
#include "BattleArena.h"
#include "Rival.h"
#include "View.h"
class Model{
    private:
        int time;
        // GameObject* object_ptrs[10];
        list<GameObject*> object_ptrs;
        list<GameObject*> active_ptrs;
        int num_objects;
        //Pokemon* pokemon_ptrs[10];
        list<Pokemon*> pokemon_ptrs;
        int num_pokemon;
        //PokemonGym* gym_ptrs[10];
        list<PokemonGym*> gym_ptrs;
        int num_centers;
        //PokemonCenter* center_ptrs[10];
        list<PokemonCenter*> center_ptrs;
        int num_arenas;
        //BattleArena* battle_ptrs[10];
        list<BattleArena*> battle_ptrs;
        int num_rivals;
        // Rival* rival_ptrs[10];
        list<Rival*> rival_ptrs;
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
        BattleArena* GetBattleArenaPtr(int id);
        Rival* GetRivalPtr(int id);
        void CreateNewObject(char c, int id, double x, double y);
        bool Update();
        void Display(View& view);
        void ShowStatus();
};
#endif