#include "Pokemon.h"
//default pokemon constructor
Pokemon::Pokemon():GameObject('P'){
    speed = 5;
    name = "Default";
    cout << "Pokemon Default Constructed" << endl;

    is_in_gym = false;
    state = STOPPED;
    is_in_center = false;
    stamina = 20;
    experience_points = 0;
    pokemon_dollars = 0;
    training_units_to_buy = 0;
    stamina_points_to_buy = 0;
    current_center = NULL;
    current_gym = NULL;
}
//constructor with display_code input
Pokemon::Pokemon(char in_code):GameObject(in_code){
    speed = 5;
    state = STOPPED;
    display_code = in_code;

    name = "Default";
    state = STOPPED;
    is_in_gym = false;
    is_in_center = false;
    stamina = 20;
    experience_points = 0;
    pokemon_dollars = 0;
    training_units_to_buy = 0;
    stamina_points_to_buy = 0;
    current_center = NULL;
    current_gym = NULL;
    cout << "Pokemon Constructed" << endl;
}
//constructor with speed, name, idnum, displaycode, location
Pokemon::Pokemon(string in_name, int in_id,char in_code, unsigned int in_speed, Point2D in_loc):GameObject(in_loc, in_id, in_code){
    speed = in_speed;
    name = in_name;
    id_num = in_id;
    display_code = in_code;
    location = in_loc;
    
    state = STOPPED;
    is_in_gym = false;
    is_in_center = false;
    stamina = 20;
    experience_points = 0;
    pokemon_dollars = 0;
    training_units_to_buy = 0;
    stamina_points_to_buy = 0;
    current_center = NULL;
    current_gym = NULL;
    cout << "Pokemon Constructed" << endl;
}
Pokemon::Pokemon(string in_name, int in_id, double magic_dmg, double phys_dmg, double hp, double def, char in_code, unsigned int in_speed, Point2D in_loc):GameObject(in_loc, in_id, in_code){
    speed = in_speed;
    name = in_name;
    id_num = in_id;
    display_code = in_code;
    location = in_loc;
    
    magic_damage = magic_dmg;
    physical_damage = phys_dmg;
    
    state = STOPPED;
    is_in_gym = false;
    is_in_center = false;
    stamina = 20;
    experience_points = 0;
    pokemon_dollars = 0;
    training_units_to_buy = 0;
    stamina_points_to_buy = 0;
    current_center = NULL;
    current_gym = NULL;
    cout << "Pokemon Constructed" << endl;
}
//returns name
string Pokemon::getName(){
    return name;
} 
//destructor
Pokemon::~Pokemon(){
    cout << "Pokemon destructed" << endl;
}
//returns pointer to current center
PokemonCenter* Pokemon::GetCurrentCenter(){
    return current_center;
}
//returns pointer to current gym
PokemonGym* Pokemon::GetCurrentGym(){
    return current_gym;
}
//sets desination and delta values
void Pokemon::SetupDestination(Point2D dest){
    destination = dest;
    delta = (dest-location)*(speed/getDistanceBetween(dest, location));
}
//updates location of pokemon
bool Pokemon::UpdateLocation(){
    //checks if close to destination
    if (fabs((destination-location).x) <= fabs(delta.x) || fabs((destination-location).y) <= fabs(delta.y)){
        location = destination;
        cout << "Arrived." << endl;
        return true;
    }
    else{
        //limits stamina loss for overflow, stops movement
        if (stamina >= 1){
            stamina -= 1;
        }
        else{
            cout << display_code << id_num << ": Out of Stamina" << endl;
            return false;
        }
        //updates location, adds money, prints out info
        location = location + delta;
        pokemon_dollars += getRandomAmountOfPokemonDollars();
        return false;
    }
}
//updates based on state
bool Pokemon::Update(){
    //if state is stopped, return flase
    if (state == STOPPED){
        return false;
    }
    //checks if close enough, if not then false
    if (state == MOVING){
        bool x = UpdateLocation();
        if (x){
            state = STOPPED;
            return true;
        }
        return false;
    }
    //checks if near center, if so then true else false
    if (state == MOVING_TO_CENTER){
        this->is_in_center = false;
        bool x = UpdateLocation();
        if (x){
            state = IN_CENTER;
            is_in_center = true;
            current_center -> AddOnePokemon();
            return true;
        }
        return false;
    }
    //checks if near gym, if so then true else false
    if (state == MOVING_TO_GYM){
        is_in_gym = false;
        if (UpdateLocation()){
            state = IN_GYM;
            is_in_gym = true;
            current_gym -> AddOnePokemon();
            return true;
        }
        return false;
    }
    //checks if in center or gym, then returns false
    if (state == IN_CENTER){
        return false;
    }
    if (state == IN_GYM){
        return false;
    }
    //if training in gym, remove stamina, dollars, increase experience
    if (state == TRAINING_IN_GYM){
        stamina =  stamina - (current_gym->GetStaminaCost(training_units_to_buy));
        pokemon_dollars -= current_gym->getDollarCost(training_units_to_buy);
        experience_points += current_gym->TrainPokemon(training_units_to_buy);
        cout << "** " << name << " completed "  << training_units_to_buy << " training unit(s)! **" << endl;
        cout << "** " << name << " gained "  << experience_points << " experience point(s)! **" << endl;
        state = IN_GYM;
        return true;
    }
    //if recovering stamina, stamina increase, dollars decrease
    if (state == RECOVERING_STAMINA){
        cout << "** " << name << " recovered " << stamina_points_to_buy << " stamina point(s)! **" << endl;
        state = IN_CENTER;
        return true;
    }
    return false;
}
//prints out information depending on state
void Pokemon::ShowStatus(){
    cout << name << " Status: ";
    //always calls gameobject.showstatus
    GameObject::ShowStatus();
    //prints if stopped
    if (state == STOPPED){
        cout << "\tStopped" << endl;
        cout << "\tStamina: " << stamina << endl;
        cout << "\tPokemon Dollars: " << pokemon_dollars << endl;
        cout << "\tExperience Points: " << experience_points << endl;
    }
    //prints if moving
    else if(state == MOVING){
        cout << "\tMoving at a speed of " << speed <<  " to destination " << destination <<" at each step of " << delta << "." << endl;
        cout << "\tStamina: " << stamina << endl;
        cout << "\tPokemon Dollars: " << pokemon_dollars << endl;
        cout << "\tExperience Points: " << experience_points << endl;
    }
    //prints if moving to center
    else if(state == MOVING_TO_CENTER){
        cout << "\tHeading to Pokemon Center " << current_center->GetId()<<  " at a speed of " << speed << " at each step of " << delta << "." << endl;
        cout << "\tStamina: " << stamina << endl;
        cout << "\tPokemon Dollars: " << pokemon_dollars << endl;
        cout << "\tExperience Points: " << experience_points << endl;
    }
    //prints if moving to gym
    else if(state == MOVING_TO_GYM){
        cout << "\tHeading to Pokemon Gym " << current_gym->GetId() <<  " at a speed of " << speed << " at each step of " << delta << "." << endl;
        cout << "\tStamina: " << stamina << endl;
        cout << "\tPokemon Dollars: " << pokemon_dollars << endl;
        cout << "\tExperience Points: " << experience_points << endl;
    }
    //prints if in center
    else if(state == IN_CENTER){
        cout << "\tInside Pokemon Center " << current_center ->GetId() << endl;
        cout << "\tStamina: " << stamina << endl;
        cout << "\tPokemon Dollars: " << pokemon_dollars << endl;
        cout << "\tExperience Points: " << experience_points << endl;
    }
    //prints if in gym
    else if(state == IN_GYM){
        cout << "\tInside Pokemon Gym " << current_gym ->GetId() << endl;
        cout << "\tStamina: " << stamina << endl;
        cout << "\tPokemon Dollars: " << pokemon_dollars << endl;
        cout << "\tExperience Points: " << experience_points << endl;
    }
    //prints if training in gym
    if(state == TRAINING_IN_GYM){
        cout << "\tTraining in Pokemon Gym " << current_gym ->GetId() << endl;
        cout << "\tStamina: " << stamina << endl;
        cout << "\tPokemon Dollars: " << pokemon_dollars << endl;
        cout << "\tExperience Points: " << experience_points << endl;
    }
    //prints if recovering stamina
    else if (state == RECOVERING_STAMINA){
        cout << "\tRecovering stamina in Pokemon Center " << current_center->GetId() << endl;
        cout << "\tStamina: " << stamina << endl;
        cout << "\tPokemon Dollars: " << pokemon_dollars << endl;
        cout << "\tExperience Points: " << experience_points << endl;
    }
}
//starts the pokemon moving
void Pokemon::StartMoving(Point2D dest){
    //sets up destionation
    SetupDestination(dest);
    state = MOVING;
    bool x = Update();
    //checks if update is true
    if(x){
        cout << this -> display_code << this -> GetId() << ": I'm already there. See?" << endl;
    }
    //checks if exhausted
    else if (state == EXHAUSTED){
        cout << this -> display_code << this -> GetId() << ": I am exhausted. I may move but you cannot see me." << endl;
    }
    //does if everything else is not true
    else{
        cout << this -> display_code << this -> GetId() << ": On my way." << endl;
    }
}
void Pokemon::StartMovingToCenter(PokemonCenter* center){
    current_center = center;
    is_in_center = false;
    is_in_gym = false;
    SetupDestination((*center).GetLocation());
    bool x = Update();
    //checks if exhausted
    if (state == EXHAUSTED){
        cout << this -> display_code << this -> GetId() << ": I am exhausted, so I can’t move to recover stamina..." << endl;
    }
    //checks if update is true
    else if(x){
        is_in_center = true;
        state = IN_CENTER;
        cout << this -> display_code << this -> GetId() << ": I am already at the Pokemon Center!" << endl;
    }
    //does if everything else is not true
    else{ 
        state = MOVING_TO_CENTER;
        cout << this -> display_code << this -> GetId() << ": On my way to center " << center->GetId() << endl;
    }
}
void Pokemon::StartMovingToGym(PokemonGym* gym){
    current_gym = gym;
    is_in_center = false;
    is_in_gym = false;
    SetupDestination((*gym).GetLocation());
    //checks if exhausted
    if (state == EXHAUSTED){
        cout << this -> display_code << this -> GetId() << " I am exhausted so I can’t move to recover stamina..." << endl;
    }
    //checks if update is true
    else if(Update()){
        is_in_gym = true;
        state = IN_GYM;
        cout << this -> display_code << this -> GetId() << ": I am already at the Pokemon Gym!" << endl;
    }
    //do if everything else isnt true
    else{
        state = MOVING_TO_GYM;
        cout << this->display_code << this -> GetId() << ": On my way to gym " << gym->GetId() << endl;
    }
}
//trains pokemon
void Pokemon::StartTraining(unsigned int num_training_units){
    //checks if exhausted
    if (state == EXHAUSTED){
        cout << this -> display_code << this -> GetId() << ": I am exhausted so no more training for me..." << endl;
    }
    //checks if not in gym
    else if(!is_in_gym){
        cout << this -> display_code << this -> GetId() << " I can only train in a Pokemon Gym!" << endl;
    }
    //checks if enough stamina or money
    else if (stamina < 1 || !(current_gym-> IsAbleToTrain(num_training_units,pokemon_dollars,stamina))){
        cout << "Not enough stamina and/or money for training" << endl;
    }
    //checks if gym is beaten
    else if(current_gym -> IsBeaten()){
        cout << this -> display_code << this -> GetId() << "Cannot train! This Pokemon Gym is already beaten" << endl;
    }
    //do else, buying training units, removing a pokemon, prints
    else{
        state = TRAINING_IN_GYM;
        training_units_to_buy = min(num_training_units, current_gym->GetNumTrainingUnitsRemaining());
        cout << this -> display_code << id_num << " :Started to train at Pokemon Gym " << this->current_gym->GetId() << " with " << num_training_units << " training units." << endl;
        if (current_gym -> getPokemonCount() >= 1){
            current_gym -> RemoveOnePokemon();
        }
        Update();
    }
}
//starts recovering stamina
void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points){
    //checks if stamina can be afforded
    if ((current_center->CanAffordStaminaPoints(num_stamina_points, pokemon_dollars))){
        cout << this -> display_code << this -> GetId() << " Not enough money to recover stamina." << endl;
    }
    //checks if stamina is left in center
    else if ((current_center->GetNumStaminaPointsRemaing() < 1)){
        cout << this -> display_code << this -> GetId() << " Cannot recover! No stamina points remaining in this Pokemon Center" << endl;
    }
    //checks if in center at all
    else if((!is_in_center)){
        cout << this -> display_code << this -> GetId() << " Can only recover stamina at a Pokemon Center!" << endl;
    }
    //else, remvoes pokemon, updates, prints
    else{
        state = RECOVERING_STAMINA;
        cout << this -> display_code << this -> GetId() << " started recovering " << num_stamina_points << " stamina point(s) at Pokemon center " << this->current_center -> GetId() << endl;
        stamina_points_to_buy = num_stamina_points;
        stamina += current_center->DistributeStamina(stamina_points_to_buy);
        pokemon_dollars -= current_center->GetDollarCost(stamina_points_to_buy);
        if (current_center -> getPokemonCount() >= 1){
            current_center -> RemoveOnePokemon();
        }
        Update();
    }
    stamina_points_to_buy = min(num_stamina_points, current_center->GetNumStaminaPointsRemaing());
}
//stops pokemon
void Pokemon::Stop(){
    state = STOPPED;
    cout << this -> GetDisplayCode() << this -> GetId() << ": Stopping..." << endl;
}
//checks if pokemon is exhaused
bool Pokemon::IsExhausted(){
    if (stamina == 0){
        state == EXHAUSTED;
    }
    return (stamina == 0);
}
//checks if pokemon is exhausted, therefore if visible
bool Pokemon::ShouldBeVisible(){
    return !(this->IsExhausted());
}
//gets random number of pokemon dollars- adds
static double getRandomAmountOfPokemonDollars(){
    srand(time(NULL));
    double d = 2 * ((double)rand()/(double)RAND_MAX);
    return d;
}
