#ifndef RIVAL_H
#define RIVAL_H
#include "GameObject.h"
#include "BattleArena.h"
class Rival: public GameObject{
    protected:
        double rival_health = 20;
        double rival_physical_damage = 5;
        double rival_magic_damage = 4;
        double rival_defense;
        double stamina_cost_per_fight;
        bool is_in_arena;
        string rival_name;
        double rival_speed;
        BattleArena* current_arena;
    public:
        enum RivalStates{
            ALIVE_RIVAL = 0,
            FAINTED_RIVAL = 1
        };
        Rival(string in_name, double in_speed, double hp, double phys_dmg,double magic_dmg, double def, int id, Point2D in_loc);
        void TakeHit(int physical_damage, int magical_damage, int defense);
        ~Rival();
        double get_phys_dmg();
        double get_magic_dmg();
        string getName();
        double get_defense();
        double get_health();
        bool Update();
        bool isAlive();
        void ShowStatus();
        bool ShouldBeVisible();
};
#endif
