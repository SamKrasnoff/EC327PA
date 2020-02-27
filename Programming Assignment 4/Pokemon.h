#ifndef POKEMON_H
#define POKEMON_H
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "BattleArena.h"
#include "Rival.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>
class Pokemon: public GameObject{
    public:
        enum PokemonStates{
            STOPPED = 0,
            MOVING = 1,
            EXHAUSTED = 2,
            IN_GYM = 3,
            IN_CENTER = 4,
            MOVING_TO_GYM = 5,
            MOVING_TO_CENTER = 6,
            TRAINING_IN_GYM = 7,
            RECOVERING_STAMINA = 8,
            IN_ARENA = 9,
            MOVING_TO_ARENA = 10,
            BATTLE = 11,
            FAINTED = 12
        };
        Pokemon();
        Pokemon(char in_code);
        Pokemon(string in_name, int in_id,char in_code, unsigned int in_speed, Point2D in_loc);
        Pokemon(string in_name, int in_id, double magic_dmg, double phys_dmg, double hp, double def, char in_code, unsigned int in_speed, Point2D in_loc);
        virtual ~Pokemon();
        void StartMoving(Point2D dest);
        void StartMovingToCenter(PokemonCenter* center);
        void StartMovingToGym(PokemonGym* gym);
        void StartMovingToArena(BattleArena* arena);
        void StartTraining(unsigned int num_training_units);
        void StartRecoveringStamina(unsigned int num_stamina_points);
        void Stop();
        bool IsExhausted();
        bool ShouldBeVisible();
        void ShowStatus();
        bool Update();
        string getName();
        PokemonCenter* GetCurrentCenter();
        PokemonGym* GetCurrentGym();
        BattleArena* GetCurrentArena();
        Rival* GetCurrentRival();
        bool isAlive();
        void TakeHit(int physical_damage, int magical_damage, int defense);
        void ReadyBattle(Rival* in_target);
        bool StartBattle();
    protected:
        double health;
        double store_health;
        double physical_damage;
        double magic_damage;
        double defense;
        Rival* target;
        bool is_in_arena;
        BattleArena* current_arena;
        bool UpdateLocation();
        void SetupDestination(Point2D dest);
    private:
        double speed;
        bool is_in_gym;
        bool is_in_center;
        unsigned int stamina = 20;
        unsigned int experience_points = 0;
        double pokemon_dollars;
        unsigned int training_units_to_buy;
        unsigned int stamina_points_to_buy;
        string name;
        PokemonCenter* current_center;
        PokemonGym* current_gym;
        Point2D destination;
        Vector2D delta;
        //speed determines step for pokemon
        //is_in_gym, is_in_center bools to help determine location
        /* stamina is pokemons ability to move and train, exp is number of experience points
        dollars is num dollars pokemon has, training/stamina to buy is input and given to a function
        name is the pokemon's name, current_gym/center allow program to follow through with center
        destination and delta are there to give point to reach and step, respectively. */
};
static double getRandomAmountOfPokemonDollars();
#endif