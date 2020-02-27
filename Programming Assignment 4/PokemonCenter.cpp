#include "PokemonCenter.h"
//default constructor, extends building
PokemonCenter::PokemonCenter():Building(){
    display_code = 'C';
    stamina_capacity = 100;
    num_stamina_points_remaining = stamina_capacity;
    dollar_cost_per_stamina_point = 5;
    state = STAMINA_POINTS_AVAILABLE;
    cout << "PokemonCenter default constructed" << endl;
}
//constructor with id, stamina cost/cap, location extends building constructor
PokemonCenter::PokemonCenter(int in_Id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc):Building('C',in_Id,in_loc){
    display_code = 'C';
    id_num = in_Id;
    location = in_loc;
    state = STAMINA_POINTS_AVAILABLE;
    stamina_capacity = stamina_cap;
    num_stamina_points_remaining = stamina_capacity;
    dollar_cost_per_stamina_point = stamina_cost;
    cout << "PokemonCenter constructed" << endl;
}
//destructor
PokemonCenter::~PokemonCenter(){
    cout << "PokemonCenter Destructed" << endl;
}
//checks if stamina points are remaining, if yes then true else false
bool PokemonCenter::HasStaminaPoints(){
    if(num_stamina_points_remaining >= 1){
        return true;
    }
    else{

        return false;
    }
}
//returns number of stamina points remaining
unsigned int PokemonCenter::GetNumStaminaPointsRemaing(){
    return num_stamina_points_remaining;
}
//returns true if points can be afforded
bool PokemonCenter::CanAffordStaminaPoints(unsigned int stamina_points, double budget){
    return ((stamina_points * dollar_cost_per_stamina_point) > budget);
}
//returns dollar cost of stamina points
double PokemonCenter::GetDollarCost(unsigned int stamina_points){
    return stamina_points * dollar_cost_per_stamina_point;
}
//gives stamina to pokemon, removes from center
unsigned int PokemonCenter::DistributeStamina(unsigned int points_needed){
    if (num_stamina_points_remaining >= points_needed){
        num_stamina_points_remaining -= points_needed;
        return points_needed;
    }
    //will set to 0 and give rest to pokemon if num requested too large
    else{
        unsigned int current = num_stamina_points_remaining;
        num_stamina_points_remaining = 0;
        return current;
    }
}
//gives information about center
bool PokemonCenter::Update(){
    //checks if stamina remaining is 0, then returns true
    if (num_stamina_points_remaining == 0){
        state = NO_STAMINA_POINTS_AVAILABLE;
        display_code = 'c';
        cout << "PokemonCenter " << id_num << " has ran out of stamina points." << endl;
        return true;
    }
    else{
        return false;
    }
}
//shows status of pokemon cetner, calls building's showstatus
void PokemonCenter::ShowStatus(){
    cout << "Pokemon Center Status: ";
    Building::ShowStatus();
    cout << "\tPokemon dollar cost per stamina point: " << dollar_cost_per_stamina_point << endl;
    cout << "\tHas " << num_stamina_points_remaining << " stamina point(s) remaining." << endl;
}
//returns true bc building should always be visible
bool PokemonCenter::ShouldBeVisible(){
    return true;
}
