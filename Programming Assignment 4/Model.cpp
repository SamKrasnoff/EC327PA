#include "Model.h"
//default constructor for model, instantiates all 6 objects
Model::Model(){
    time = 0;
    Point2D* p = new Point2D(5,1);
    // pokemon_ptrs[0] = new Pokemon("Pikachu",1,6,3,23,12,'P',2,*p);
    Pokemon* Pptr = new Pokemon("Pikachu",1,6,3,23,12,'P',2,*p);
    pokemon_ptrs.push_back(Pptr);
    object_ptrs.push_back(Pptr);
    active_ptrs.push_back(Pptr);
    //object_ptrs[0] = pokemon_ptrs[0];

    Point2D* p1 = new Point2D(10,1);
    // pokemon_ptrs[1] = new Pokemon("Bulbasaur",2,3.7,4,26,16,'P',1,*p1);
    Pokemon* Pptr2 = new Pokemon("Bulbasaur",2,3.7,4,26,16,'P',1,*p1);
    pokemon_ptrs.push_back(Pptr2);
    object_ptrs.push_back(Pptr2);
    active_ptrs.push_back(Pptr2);
    // object_ptrs[1] = pokemon_ptrs[1];

    Point2D* p2 = new Point2D(1,20);
    PokemonCenter* PCptr = new PokemonCenter(1, 1,100, *p2);
    center_ptrs.push_back(PCptr);
    object_ptrs.push_back(PCptr);
    active_ptrs.push_back(PCptr);
    // center_ptrs[0] = new PokemonCenter(1, 1,100, *p2);
    // object_ptrs[2] = center_ptrs[0];

    Point2D* p3 = new Point2D(10,20);
    PokemonCenter* PCptr2 = new PokemonCenter(2,2,200, *p3);
    center_ptrs.push_back(PCptr2);
    object_ptrs.push_back(PCptr2);
    active_ptrs.push_back(PCptr2);
    // center_ptrs[1] = new PokemonCenter(2,2,200, *p3);
    // object_ptrs[3] = center_ptrs[1];

    // gym_ptrs[0] = new PokemonGym();
    PokemonGym* PGptr = new PokemonGym();
    gym_ptrs.push_back(PGptr);
    object_ptrs.push_back(PGptr);
    active_ptrs.push_back(PGptr);
    // object_ptrs[4] = gym_ptrs[0];

    Point2D* p4 = new Point2D(5,5);
    PokemonGym* PGptr2 = new PokemonGym(20,5,7.5,8,2,*p4);
    gym_ptrs.push_back(PGptr2);
    object_ptrs.push_back(PGptr2);
    active_ptrs.push_back(PGptr2);
    // gym_ptrs[1] = new PokemonGym(20,5,7.5,8,2,*p4);
    // object_ptrs[5] = gym_ptrs[1];

    Rival* R = new Rival("burhack",1,16,3,7.2,12,1,Point2D(15,12));
    rival_ptrs.push_back(R);
    object_ptrs.push_back(R); 
    active_ptrs.push_back(R);

    Rival* R1 = new Rival("Allen",1,29,4,5.2,12,2,Point2D(15,12));
    rival_ptrs.push_back(R1);
    object_ptrs.push_back(R1); 
    active_ptrs.push_back(R1); 

    Rival* R2 = new Rival("Densmore(aka BIGBOSS)",1,41,6,8.2,18,3,Point2D(15,12));
    rival_ptrs.push_back(R2);
    object_ptrs.push_back(R2); 
    active_ptrs.push_back(R2); 
    // rival_ptrs[0] = new Rival("burhack",1,16,3,7.2,12,1,Point2D(15,12));
    // object_ptrs[6] = rival_ptrs[0];

    BattleArena* BA = new BattleArena(3,3,2.5,1,Point2D(15,12));
    battle_ptrs.push_back(BA);
    object_ptrs.push_back(BA);
    active_ptrs.push_back(BA);
    // battle_ptrs[0] = new BattleArena(3,3,2.5,1,Point2D(15,12));
    // object_ptrs[7] = battle_ptrs[0];

    num_objects = 8;
    num_pokemon = 2;
    num_centers = 2;
    num_gyms = 2;
    num_arenas = 1;
    cout << "Model default constructed" << endl;
}
//destructor for model
Model::~Model(){
    list<GameObject*> :: iterator it;
    cout << "Model destructed" << endl;
    for(it = object_ptrs.begin(); it != object_ptrs.end(); ++it){
        it = object_ptrs.erase(it);
    }
    // for(int i = 0; i < num_objects; i++){
    //     delete object_ptrs[i];
    // }
}
//gets pokemon pointer at index id
Pokemon* Model::GetPokemonPtr(int id){
    list<Pokemon*> :: iterator it;
    it = pokemon_ptrs.begin();
    if (pokemon_ptrs.size() > id){
        advance(it,id);
    }
    return *it;
    ///return pokemon_ptrs[id];
}
Rival* Model::GetRivalPtr(int id){
    list<Rival*> :: iterator it;
    it = rival_ptrs.begin();
    if (rival_ptrs.size() > id){
        advance(it,id);
    }
    return *it;
    //return rival_ptrs[id];
}
//gets pokemon center pointer at index id
PokemonCenter* Model::GetPokemonCenterPtr(int id){
    list<PokemonCenter*> :: iterator it;
    it = center_ptrs.begin();
    if (center_ptrs.size() > id){
        advance(it,id);
    }
    return *it;
    //return center_ptrs[id];
}
//gets pokemon gym pointer at index id
PokemonGym* Model::GetPokemonGymPtr(int id){
    list<PokemonGym*> :: iterator it;
    it = gym_ptrs.begin();
    if (gym_ptrs.size() > id){
        advance(it,id);
    }
    return *it;
    //return gym_ptrs[id];
}
BattleArena* Model::GetBattleArenaPtr(int id){
    list<BattleArena*> :: iterator it;
    it = battle_ptrs.begin();
    if (battle_ptrs.size() > id){
        advance(it,id);
    }
    return *it;
    //return battle_ptrs[id];
}
//updates each member, using polymorphic function
bool Model::Update(){
    list<GameObject*>::iterator it;
    this->time++;
    for(it = active_ptrs.begin(); it != active_ptrs.end(); ++it){
        (*it)->Update();
        if((*it)->ShouldBeVisible() == false){
            it = active_ptrs.erase(it);
        }
    }
    // for (int i = 0; i < this->num_objects; i++){
    //     bool x = object_ptrs[i] -> Update();
    //     if (x){
    //         return true;
    //     }
    // }
    //checks for win condition
    beaten_gyms = 0;
    // for (int i = 0; i < this->num_gyms; i++){
    //     if (gym_ptrs[i] -> IsBeaten()){
    //         beaten_gyms++;
    //     }
    // }
    list<PokemonGym*>::iterator itg;
    for(itg = gym_ptrs.begin(); itg != gym_ptrs.end(); ++itg){
        if ((*itg)->IsBeaten()){
            beaten_gyms++;
        }
    }
    if (beaten_gyms == gym_ptrs.size()){
        cout << "GAME OVER:You win! All Pokemon Gyms beaten. " << endl;
        exit(EXIT_FAILURE);
    }
    //checks for lose condition
    exhausted_pokemon = 0;
    // for (int i = 0; i < this->num_pokemon; i++){
    //     if (pokemon_ptrs[i] -> IsExhausted()){
    //         exhausted_pokemon++;
    //     }
    // }
    list<Pokemon*>::iterator itp;
    for(itp = pokemon_ptrs.begin(); itp != pokemon_ptrs.end(); ++itp){
        if ((*itp)->IsExhausted()){
            exhausted_pokemon++;
        }
    }
    if (exhausted_pokemon == pokemon_ptrs.size()){
        cout << "GAME OVER: You lose! All of your Pokemon are tired!" << endl;
        exit(EXIT_FAILURE);
    }
}
void Model::CreateNewObject(char c,int id, double x, double y){
    list<PokemonGym*>::iterator itg;
    list<PokemonCenter*>::iterator itc;
    list<Pokemon*>::iterator itp;
    list<Rival*>::iterator itr;
    switch(c)
    {
    case 'g':
        {
        PokemonGym* PG = new PokemonGym(10,1,1.0,2,id,Point2D(x,y));
        for(itg = gym_ptrs.begin(); itg != gym_ptrs.end(); ++itg){
            if((*itg)->GetId() == id){
                cout << "ID number already exists!" << endl;
                return;
            }
        }
        active_ptrs.push_back(PG);
        gym_ptrs.push_back(PG);
        break;
    }
    case 'c':
        {
        for(itc = center_ptrs.begin(); itc != center_ptrs.end(); ++itc){
            if((*itc)->GetId() == id){
                cout << "ID number already exists!" << endl;
                return;
            }
        }
        PokemonCenter* PC = new PokemonCenter(id,5,100,Point2D(x,y));
        active_ptrs.push_back(PC);
        center_ptrs.push_back(PC);
        break;
        }
    case 'p':
        {
        for(itp = pokemon_ptrs.begin(); itp != pokemon_ptrs.end(); ++itp){
            if((*itp)->GetId() == id){
                cout << "ID number already exists!" << endl;
                return;
            }
        }
        Pokemon* P = new Pokemon("Cthulu",id,4.5,5.5,25,5,'P',2,Point2D(x,y));
        active_ptrs.push_back(P);
        pokemon_ptrs.push_back(P);
        break;
        }
    case 'r':
        {
        for(itr = rival_ptrs.begin(); itr != rival_ptrs.end(); ++itr){
            if((*itr)->GetId() == id){
                cout << "ID number already exists!" << endl;
                return;
            }
        }
        Rival* R = new Rival("Red",1.0,20,3,4,4,id,Point2D(x,y));
        active_ptrs.push_back(R);
        rival_ptrs.push_back(R);
        break;
        }
    default:
        break;
    }
}
//uses view to clear, plot, draw everything correctly
void Model::Display(View& view){
    view.Clear();
    list<GameObject*>::iterator it;
    // for (int i = 0; i < this->num_objects; i++){
    //     view.Plot(object_ptrs[i]);
    // }
    for(it = active_ptrs.begin(); it != active_ptrs.end(); ++it){
        view.Plot(*it);
    }
    view.Draw();
}
//uses polymorphic showstatus to display respective data for each class
void Model::ShowStatus(){
    list<GameObject*>::iterator it;
    list<Pokemon*>::iterator itp;
    cout << "Time: " << time << endl;
    // for (int x = 0; x < this->num_pokemon; x++){
    //     if (pokemon_ptrs[x] ->GetState() == pokemon_ptrs[x] -> MOVING || pokemon_ptrs[x] ->GetState() == pokemon_ptrs[x] -> MOVING_TO_CENTER || pokemon_ptrs[x] ->GetState() == pokemon_ptrs[x] -> MOVING_TO_GYM){
    //         cout << pokemon_ptrs[x]->GetDisplayCode() << pokemon_ptrs[x]->GetId() << ": step..." << endl;
    //     }
    // }
    for(itp = pokemon_ptrs.begin(); itp != pokemon_ptrs.end(); ++itp){
        if ((*itp) ->GetState() == (*itp) -> MOVING || (*itp) ->GetState() == (*itp) -> MOVING_TO_CENTER || (*itp) ->GetState() == (*itp) -> MOVING_TO_GYM){
            cout << (*itp)->GetDisplayCode() << (*itp)->GetId() << ": step..." << endl;
        }
    }
    // for (int i = 0; i < this->num_objects; i++){
    //     object_ptrs[i] -> ShowStatus();
    // }
    for(it = active_ptrs.begin(); it != active_ptrs.end(); ++it){
        (*it)->ShowStatus();
    }    
}