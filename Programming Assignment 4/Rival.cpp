#include "Rival.h"
Rival::Rival(string in_name, double in_speed, double hp, double phys_dmg,double magic_dmg, double def, int id, Point2D in_loc):GameObject(in_loc,id,'R'){
    rival_name = in_name;
    rival_speed = in_speed;
    rival_health = hp;
    rival_physical_damage = phys_dmg;
    rival_magic_damage = magic_dmg;
    rival_defense = def;
    location = in_loc;
    state = ALIVE_RIVAL;
    cout << "Rival Constructed" << endl;
}
Rival::~Rival(){
    cout << "Rival Deconstructed" << endl;
}
void Rival::TakeHit(int physical_damage, int magical_damage, int defense){
    int x = rand() % 2;
    double damage = 0.0;
    if (x == 0){
        cout << "Physical damage hurts, doesn't it! " << endl;
        damage = (100.0-defense)/100.0 * physical_damage;
        rival_health -= damage;
    }
    else if (x == 1){
        cout << "Magic damage it is!" << endl;
        damage = (100.0-defense)/100.0 * magical_damage;
        rival_health -= damage;
    }
    cout << "Damage: " << damage << endl;
    cout << "Rival health: " << rival_health << endl;
}
double Rival::get_phys_dmg(){
    return rival_physical_damage;
}
string Rival::getName(){
    return rival_name;
} 
double Rival::get_magic_dmg(){
    return rival_magic_damage;
}
double Rival::get_defense(){
    return rival_defense;
}
double Rival::get_health(){
    return rival_health;
}
bool Rival::Update(){
    if (state == ALIVE_RIVAL){
        return false;
    }
    else{
        return true;
    }
}
bool Rival::isAlive(){
    if (this->rival_health <= 0){
        state = FAINTED_RIVAL;
        current_arena->RemoveOneRival();
        return false;
    }
    else{
        return true;
    }
}
bool Rival::ShouldBeVisible(){
    if (state == ALIVE_RIVAL){
        return true;
    }
    else if (state == FAINTED_RIVAL){
        return false;
    }
}
void Rival::ShowStatus(){
    cout << rival_name << " Status: ";
    GameObject::ShowStatus();
    if (state == ALIVE_RIVAL){
        cout << " alive" << endl;
    }
    else if (state == FAINTED_RIVAL){
        cout << " dead, RIP..." << endl;
    }
    cout << "\tHealth: " << rival_health << endl;
    cout << "\tPhysical Damage: " << rival_physical_damage << endl;
    cout << "\tMagical Damage: " << rival_magic_damage << endl;
    cout << "\tDefense: " << rival_defense << endl; 
}