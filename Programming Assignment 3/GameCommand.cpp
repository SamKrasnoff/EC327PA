#include "GameCommand.h"
//starts the pokemon moving
void DoMoveCommand(Model& model, int pokemon_id, Point2D p1){
    Pokemon* P = (model).GetPokemonPtr(pokemon_id);
    //checks for validity
    if (P != NULL){
        cout << "Moving " << P->getName() << " to " << p1 << endl;
        P -> StartMoving(p1);
    }
    else{
        cout << "Error: Please enter a valid command!" << endl;
    }
}
//tells the pokemon to move to a center
void DoMoveToCenterCommand(Model& model, int pokemon_id, int center_id){
    Pokemon* P = (model).GetPokemonPtr(pokemon_id);
    //checks for validity of pokemon and center
    if (P != NULL && (model.GetPokemonCenterPtr(center_id) != NULL)){
        P -> StartMovingToCenter(model.GetPokemonCenterPtr(center_id));
        cout << "Moving " << P->getName() << " to center " << model.GetPokemonCenterPtr(center_id) ->GetId() << endl;
    }
    else{
        cout << "Error: Please enter a valid command!" << endl;
    }
}
//tells the pokemon to move to a gym
void DoMoveToGymCommand(Model& model, int pokemon_id, int gym_id){
    Pokemon* P = (model).GetPokemonPtr(pokemon_id);
    //checks for validity of pokemon and gym
    if (P != NULL && (model.GetPokemonGymPtr(gym_id) != NULL)){
        cout << "Moving " << P->getName() << " to gym " << model.GetPokemonGymPtr(gym_id) ->GetId() << endl;
        P -> StartMovingToGym(model.GetPokemonGymPtr(gym_id));
    }
    else{
        cout << "Error: Please enter a valid command!" << endl;
    }
}
//tells the pokemon to stop
void DoStopCommand(Model& model, int pokemon_id){
    Pokemon* P = (model).GetPokemonPtr(pokemon_id);
    if (P != NULL){
        cout << "Stoppping " << P->getName() << " " << P->GetDisplayCode() << P->GetId() << endl;
        P -> Stop();
    }
    else{
        cout << "Error: Please enter a valid command!" << endl;
    }
}
//checks if pokemon is in gym, starts training
void DoTrainInGymCommand(Model& model, int pokemon_id, unsigned int training_units){
    Pokemon* P = (model).GetPokemonPtr(pokemon_id);
    if (P != NULL){
        cout << "Training " <<  P->getName() << endl;
        if(P -> GetCurrentGym() != NULL){
            P -> StartTraining(training_units);
        }
        else{
            cout << "Error: Not in a Gym!" << endl;
            return;
        }
    }
    else{
        cout << "Error: Please enter a valid command!" << endl;
    }
}
//checks if pokemon is in center, starts recovering
void DoRecoverInCenterCommand(Model& model, int pokemon_id, unsigned int stamina_points){
    Pokemon* P = (model).GetPokemonPtr(pokemon_id);
    if (P != NULL){
        cout << "Recovering " <<  P->getName() << "'s stamina" << endl; 
        if(P -> GetCurrentCenter() != NULL){
            P -> StartRecoveringStamina(stamina_points); 
        }
        else{
            cout << "Error: Not in a Center!" << endl;
            return;
        }
    }
    else{
        cout << "Error: Please enter a valid command!" << endl;
    }
}
//moves once towardsa a given location
void DoGoCommand(Model& model, View& view){
    cout << "Advancing one tick." << endl;
    bool x = model.Update();
    view.Clear();
    model.ShowStatus();
    //model.Display(view);
 }
 //moves five times or until update returns true
 void DoRunCommand(Model& model, View& view){
    int maximum = 0;
    bool update = false;
    while (maximum < 5){
        update = model.Update();
        cout << "Advancing one tick." << endl;
        maximum++;
        model.ShowStatus();
        //model.Display(view);
    } 
 }
