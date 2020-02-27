#include "Pokemon.h"
#include "GameCommand.h"
#include "Model.h"
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
    char c;
    double x,y;
    unsigned int stamina_amount, unit_amount;
    Model M;
    //GameCommand Game;
    View V;
    //shows griid and status to start
    V.Clear();
    M.ShowStatus();
    //do while so it runs at least once
    do{
        //displays first
        M.Display(V);
        cout << "Enter Command: ";
        cin >> c;
        //switch for input, can put all in at once into input buffer
        switch (c)
        {
        //moves normally
        case 'm':
            cin >> ID1 >> x >> y;
            DoMoveCommand(M,ID1-1,Point2D(x,y));
            break;
        //moves towards gym
        case 'g':
            cin >> ID1 >> ID2;
            DoMoveToGymCommand(M,ID1-1,ID2-1);
            break;
        //moves towards center
        case 'c':
            cin >> ID1 >> ID2;
            DoMoveToCenterCommand(M,ID1-1,ID2-1);
            break;
        //stops pokemon
        case 's':
            cin >> ID1;
            DoStopCommand(M,ID1-1);
            break;
        //recovers
        case 'r':
            cin >> ID1 >> stamina_amount;
            DoRecoverInCenterCommand(M,ID1-1, stamina_amount);
            break;
        //trains in gym
        case 't':
            cin >> ID1 >> unit_amount;
            DoTrainInGymCommand(M,ID1-1, unit_amount);
            break;
        //moves in a given direction
        case 'v':
            DoGoCommand(M,V);
            break;
        //moves multiples times towards a given point
        case 'x':
            DoRunCommand(M,V);
            break;
        // default:
        //     cout <<"Invalid Entry" << endl;
        //     break;
        }
    }while(c != 'q');
    cout << "Program Terminated!" << endl;    
}