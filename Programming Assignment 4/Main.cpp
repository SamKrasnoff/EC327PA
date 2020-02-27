#include "Pokemon.h"
#include "GameCommand.h"
#include "Model.h"
#include "Input_Handling.h"
#include <iostream>
using namespace std;

int main(){
    //displays basic onfo
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2019" << endl;
    cout << "Programming Assignment 3" << endl;
    //displays crappy pokemon logo
    cout << "                                     ,'\\ " << endl;
    cout << "      _.----.        ____         ,'  _\\   ___    ___     ____ " << endl;
    cout << "  _,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`." << endl;
    cout << "  \\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |" << endl;
    cout << "   \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  | " << endl;
    cout << "    \\    \\/   /,' _`.|      ,' / / / /    |         ,' _`.|     |  |" << endl;
    cout << "     \\     ,-'/  /   \\    ,'   | \\/ / ,`. |        /  /   \\  |     | " << endl;
    cout << "      \\    \\ |   \\/  |   `-.  \\    `'  /  |  |    ||   \\_/  | |\\    | " << endl;
    cout << "       \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   | " << endl;
    cout << "        \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   | "<< endl;
    cout << "         \\_.-'       |__|    `-._ |               '-.|     '-.| |   | " << endl;
    cout << "                            `'                                  '-._| " << endl;
    int ID1, ID2;
    int identification;
    char c;
    char type;
    double x,y;
    unsigned int stamina_amount, unit_amount;
    Model M;
    //GameCommand Game;
    View V;
    //shows griid and status to start
    V.Clear();
    M.ShowStatus();
    M.Display(V);
    //do while so it runs at least once
    do{
        //displays first
        cin.clear();
        //cin.ignore(INT32_MAX,'\n');
        cout << "Enter Command: ";
        cin >> c;
        try{
        //switch for input, can put all in at once into input buffer
        switch (c)
        {
        //moves normally
        case 'm':
            if (!(cin >> ID1)){
                throw Invalid_Input("Was expecting an integer");
                break;
            }
            if (!(cin >> x >> y)){
                throw Invalid_Input("Was expecting doubles");
                break;
            }
            DoMoveCommand(M,ID1-1,Point2D(x,y));
            M.Display(V);
            break;
        //moves towards gym
        case 'g':
            if (!(cin >> ID1)){
                throw Invalid_Input("Was expecting an integer");
                break;
            }
            if (!(cin >> ID2)){
                throw Invalid_Input("Was expecting an integer");
                break;
            }
            DoMoveToGymCommand(M,ID1-1,ID2-1);
            M.Display(V);
            cin.clear();
            cin.ignore(500,'\n');
            break;
        //moves towards center
        case 'c':
            if (!(cin >> ID1)){
                throw Invalid_Input("Was expecting an integer");
                break;
            }
            if (!(cin >> ID2)){
                throw Invalid_Input("Was expecting an integer");
                break;
            }
            DoMoveToCenterCommand(M,ID1-1,ID2-1);
            M.Display(V);
            cin.clear();
            cin.ignore(500,'\n');
            break;
        //stops pokemon
        case 's':
            if (!(cin >> ID1)){
                throw Invalid_Input("Was expecting an integer");
                break;
            }
            DoStopCommand(M,ID1-1);
            M.Display(V);
            cin.clear();
            cin.ignore(500,'\n');
            break;
        //recovers
        case 'r':
            if (!(cin >> ID1)){
                throw Invalid_Input("Was expecting an integer");
                break;
            }
            if (!(cin >> stamina_amount)){
                throw Invalid_Input("Was expecting an integer");
                break;
            }
            DoRecoverInCenterCommand(M,ID1-1, stamina_amount);
            M.Display(V);
            cin.clear();
            cin.ignore(500,'\n');
            break;
        //trains in gym
        case 't':
            if (!(cin >> ID1)){
                throw Invalid_Input("Was expecting an integer");
                break;
            }
            if (!(cin >> unit_amount)){
                throw Invalid_Input("Was expecting an integer");
                break;
            }
            DoTrainInGymCommand(M,ID1-1, unit_amount);
            M.Display(V);
            cin.clear();
            cin.ignore(500,'\n');
            break;
        //moves in a given direction
        case 'v':
            DoGoCommand(M,V);
            M.Display(V);
            cin.clear();
            cin.ignore(500,'\n');
            break;
        //moves multiples times towards a given point
        case 'x':
            DoRunCommand(M,V);
            M.Display(V);
            cin.clear();
            cin.ignore(500,'\n');
            break;
        case 'a':
            if (!(cin >> ID1)){
                throw Invalid_Input("Was expecting an integer");
                break;
            }
            if (!(cin >> ID2)){
                throw Invalid_Input("Was expecting an integer");
                break;
            }
            DoMoveToArenaCommand(M,ID1-1,ID2-1);
            M.Display(V);
            cin.clear();
            cin.ignore(500,'\n');
            break;
        case 'b':
            if (!(cin >> ID1)){
                throw Invalid_Input("Was expecting an integer");
                break;
            }
            if (!(cin >> ID2)){
                throw Invalid_Input("Was expecting an integer");
                break;
            }
            DoBattleInArenaCommand(M,ID1-1,ID2-1);
            M.Display(V);
            cin.clear();
            cin.ignore(500,'\n');
            break;
        case 'n':
            cin >> type >> identification >> x >> y;
            CreateNewObjectCommand(M,type,identification,x,y);
            M.Display(V);
            cin.clear();
            cin.ignore(500,'\n');
            break;
        // default:
        //     cout <<"Invalid Entry" << endl;
        //     break;
        }
        }
        catch(Invalid_Input& except){
            cout << "Invalid Input: " << except.msg_ptr << endl;
        }
    } while(c != 'q');
    cout << "\nProgram Terminated!" << endl;    
}