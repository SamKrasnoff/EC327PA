#include "PokemonGym.h"
//Default constructor for gym that extends building
PokemonGym::PokemonGym():Building(){
    display_code = 'G';
    state = NOT_BEATEN;
    max_number_of_training_units = 10;
    num_training_units_remaining = max_number_of_training_units;
    stamina_cost_per_training_unit = 1;
    dollar_cost_per_training_unit = 1.0;
    experience_points_per_training_unit = 2;
    cout << "PokemonGym default constructed" << endl;
}
//constructor for gym with max training units, stamina cost, dollar cost, exp point ratio, id, and location
PokemonGym::PokemonGym(unsigned int max_training_units,unsigned int stamina_cost, double dollar_cost,unsigned int exp_points_per_unit,int in_id,Point2D in_loc):Building('G',in_id,in_loc){
    id_num = in_id;
    max_number_of_training_units = max_training_units;
    num_training_units_remaining = max_number_of_training_units;
    stamina_cost_per_training_unit = stamina_cost;
    experience_points_per_training_unit = exp_points_per_unit;
    dollar_cost_per_training_unit = dollar_cost;
    location = in_loc;
    cout << "PokemonGym constructed" << endl;
}
//destructor
PokemonGym::~PokemonGym(){
    cout << "PokemonGym destructed" << endl;
}
//gets dollar cost for training
double PokemonGym::getDollarCost(unsigned int unit_qty){
    return unit_qty * dollar_cost_per_training_unit;
}
//gets stamina cost for training
unsigned int PokemonGym::GetStaminaCost(unsigned int unit_qty){
    return unit_qty * stamina_cost_per_training_unit;
}
//gets num training units remaining
unsigned int PokemonGym::GetNumTrainingUnitsRemaining(){
    return num_training_units_remaining;
}
//returns true if pokemon can train, false if not
bool PokemonGym::IsAbleToTrain(unsigned int unit_qty, double budget, unsigned int stamina){
    if((getDollarCost(unit_qty) < budget && GetStaminaCost(unit_qty) < stamina)){
        return true;
    }
    else{
        return false;
    }
}
//returns experience points requested, or max if less available than requested
unsigned int PokemonGym::TrainPokemon(unsigned int training_units){
    if (training_units < num_training_units_remaining){
        num_training_units_remaining -= training_units;
        return training_units * experience_points_per_training_unit;
    }
    else{
        return num_training_units_remaining * experience_points_per_training_unit;
    }
}
//updates information about gym
bool PokemonGym::Update(){
    if (num_training_units_remaining == 0 && state == NOT_BEATEN){
        state = BEATEN;
        display_code = 'g';
        cout << display_code << " " << id_num << " has been beaten." << endl;
        return true;
    }
    else{
        return false;
    }
}
//returns true if no more training units
bool PokemonGym::IsBeaten(){
    if (num_training_units_remaining == 0){
        return true;
    }
    else{
        return false;
    }
}
//prints information about gym
void PokemonGym::ShowStatus(){
    cout << "Pokemon Gym Status: ";
    Building::ShowStatus();
    cout << "\tMax number of training units: " << max_number_of_training_units << endl;
    cout << "\tStamina cost per training unit: " << stamina_cost_per_training_unit << endl;
    cout << "\tPokemon dollar per training unit: " << dollar_cost_per_training_unit << endl;
    cout << "\tExperience Points per training unit: " << experience_points_per_training_unit << endl;
    cout << "\t" << num_training_units_remaining << " training unit(s) are remaining for this gym" << endl;
}
//should always be true, shows gym
bool PokemonGym::ShouldBeVisible(){
    return true;
}