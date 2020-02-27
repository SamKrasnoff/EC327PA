#ifndef BATTLEARENA_H
#define BATTLEARENA_H

class BattleArena: public Building{
    public:
        enum BattleArenaStates{
            RIVALS_AVAILABLE = 0,
            NO_RIVALS_AVAILABLE = 1
        };
        BattleArena();
        BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_id, Point2D loc):Building('A',in_id, loc);
        unsigned int GetNumRivalsRemaining();
        bool
    private:
        unsigned int max_num_rivals;
        unsigned int num_rivals_remaining;
        double dollar_cost_per_fight;
        unsigned int stamina_cost_per_fight;
        unsigned int pokemon_count;
}