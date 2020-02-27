#include "Model.h"
//default constructor for model, instantiates all 6 objects
Model::Model(){
    time = 0;
    Point2D* p = new Point2D(5,1);
    pokemon_ptrs[0] = new Pokemon("Pikachu",1,'P',2,*p);
    object_ptrs[0] = pokemon_ptrs[0];

    Point2D* p1 = new Point2D(10,1);
    pokemon_ptrs[1] = new Pokemon("Bulbasaur",2,'P',1,*p1);
    object_ptrs[1] = pokemon_ptrs[1];

    Point2D* p2 = new Point2D(1,20);
    center_ptrs[0] = new PokemonCenter(1, 1,100, *p2);
    object_ptrs[2] = center_ptrs[0];

    Point2D* p3 = new Point2D(10,20);
    center_ptrs[1] = new PokemonCenter(2,2,200, *p3);
    object_ptrs[3] = center_ptrs[1];

    gym_ptrs[0] = new PokemonGym();
    object_ptrs[4] = gym_ptrs[0];

    Point2D* p4 = new Point2D(5,5);
    gym_ptrs[1] = new PokemonGym(20,5,7.5,8,2,*p4);
    object_ptrs[5] = gym_ptrs[1];

    num_objects = 6;
    num_pokemon = 2;
    num_centers = 2;
    num_gyms = 2;
    cout << "Model default constructed" << endl;
}
//destructor for model
Model::~Model(){
    cout << "Model destructed" << endl;
    for(int i = 0; i < num_objects; i++){
        delete object_ptrs[i];
    }
}
//gets pokemon pointer at index id
Pokemon* Model::GetPokemonPtr(int id){
    return pokemon_ptrs[id];
}
//gets pokemon center pointer at index id
PokemonCenter* Model::GetPokemonCenterPtr(int id){
    return center_ptrs[id];
}
//gets pokemon gym pointer at index id
PokemonGym* Model::GetPokemonGymPtr(int id){
    return gym_ptrs[id];
}
//updates each member, using polymorphic function
bool Model::Update(){
    this->time++;
    for (int i = 0; i < this->num_objects; i++){
        bool x = object_ptrs[i] -> Update();
        if (x){
            return true;
        }
    }
    //checks for win condition
    beaten_gyms = 0;
    for (int i = 0; i < this->num_gyms; i++){
        if (gym_ptrs[i] -> IsBeaten()){
            beaten_gyms++;
        }
    }
    if (beaten_gyms == num_gyms){
        cout << "GAME OVER:You win! All Pokemon Gyms beaten. " << endl;
        exit(EXIT_FAILURE);
    }
    //checks for lose condition
    exhausted_pokemon = 0;
    for (int i = 0; i < this->num_pokemon; i++){
        if (pokemon_ptrs[i] -> IsExhausted()){
            exhausted_pokemon++;
        }
    }
    if (exhausted_pokemon == num_pokemon){
        cout << "GAME OVER: You lose! All of your Pokemon are tired!" << endl;
        exit(EXIT_FAILURE);
    }
}
//uses view to clear, plot, draw everything correctly
void Model::Display(View& view){
    view.Clear();
    for (int i = 0; i < this->num_objects; i++){
        view.Plot(object_ptrs[i]);
    }
    view.Draw();
}
//uses polymorphic showstatus to display respective data for each class
void Model::ShowStatus(){
    cout << "Time: " << time << endl;
    for (int x = 0; x < this->num_pokemon; x++){
        if (pokemon_ptrs[x] ->GetState() == pokemon_ptrs[x] -> MOVING || pokemon_ptrs[x] ->GetState() == pokemon_ptrs[x] -> MOVING_TO_CENTER || pokemon_ptrs[x] ->GetState() == pokemon_ptrs[x] -> MOVING_TO_GYM){
            cout << pokemon_ptrs[x]->GetDisplayCode() << pokemon_ptrs[x]->GetId() << ": step..." << endl;
        }
    }
    for (int i = 0; i < this->num_objects; i++){
        object_ptrs[i] -> ShowStatus();
    }
}