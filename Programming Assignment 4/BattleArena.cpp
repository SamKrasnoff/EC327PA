#include "BattleArena.h"
BattleArena::BattleArena(){
    display_code = 'A';
    pokemon_count = 0;
    max_num_rivals = 3;
    num_rivals_remaining = max_num_rivals;
    dollar_cost_per_fight = 4;
    stamina_cost_per_fight = 3;
    state = RIVALS_AVAILABLE;
    cout << "BattleArena Default Constructed"<< endl;
}
BattleArena::BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_id, Point2D loc):Building('A',in_id,loc){
    id_num = in_id;
    location = loc;
    max_num_rivals = max_rivals;
    num_rivals_remaining = max_num_rivals;
    stamina_cost_per_fight  = stamina_cost;
    state = RIVALS_AVAILABLE;
    dollar_cost_per_fight = dollar_cost;
    cout << "BattleArena Constructed"<< endl;
}
BattleArena::~BattleArena(){
    cout << "Battle Arena deconstructed" << endl;
}
unsigned int BattleArena::GetNumRivalsRemaining(){
    return num_rivals_remaining;
}
bool BattleArena::HasEnoughRivals(){
    return num_rivals_remaining >= 1;
}
double BattleArena::GetDollarCost(){
    return dollar_cost_per_fight;
}
unsigned int BattleArena::GetStaminaCost(){
    return stamina_cost_per_fight;
}
bool BattleArena::IsAbleToFight(double budget, unsigned int stamina){
    return (budget >= dollar_cost_per_fight && stamina >= stamina_cost_per_fight);
}
bool BattleArena::Update(){
    if ((state == NO_RIVALS_AVAILABLE || !HasEnoughRivals()) && first_time == 0){
        first_time++;
        return true;
    }
    else{
        return false;
    }
}
bool BattleArena::IsBeaten(){
    return (num_rivals_remaining == 0);
}
void BattleArena::RemoveOneRival(){
    num_rivals_remaining--;
}
bool BattleArena::ShouldBeVisible(){
    return true;
}
void BattleArena::ShowStatus(){
    cout << "Battle Arena Status: ";
    Building::ShowStatus();
    cout << "\tMax number of rivals: " << max_num_rivals << endl;
    cout << "\tStamina cost per fight: " << stamina_cost_per_fight << endl;
    cout << "\tPokemon dollars per fight: " << dollar_cost_per_fight << endl;
    cout << "\t" << num_rivals_remaining << " rival(s) are remaining for this arena" << endl;
}