#ifndef POKEMONGYM_H
#define POKEMONGYM_H
#include <iostream>
#include "Building.h"
using namespace std;
class PokemonGym: public Building{
    enum PokemonGymStates{
        NOT_BEATEN = 1,
        BEATEN = 0
    };
    //enum shows if beaten or not beaten
    private:
        double num_training_units_remaining;
        unsigned int max_number_of_training_units;
        unsigned int stamina_cost_per_training_unit;
        double dollar_cost_per_training_unit;
        unsigned int experience_points_per_training_unit;
        /* training units remaining shows what variable name explains.
        Honestly, all of these variables are pretty self explanitory. */
    public:
        PokemonGym();
        PokemonGym(unsigned int max_training_units,unsigned int stamina_cost, double dollar_cost,unsigned int exp_points_per_unit,int in_id,Point2D in_loc);
        ~PokemonGym();
        double getDollarCost(unsigned int);
        unsigned int GetStaminaCost(unsigned int unit_qty);
        unsigned int GetNumTrainingUnitsRemaining();
        bool IsAbleToTrain(unsigned int unit_qty, double budget, unsigned int stamina);
        unsigned int TrainPokemon(unsigned int training_units);
        bool Update();
        bool IsBeaten();
        void ShowStatus();
        bool ShouldBeVisible();
};
#endif