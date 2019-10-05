#include <iostream>
#include <string>
using namespace std;
int main(){
    float sum = 0;
    string courses [5] = {};
    for (int i = 0; i < 5; i++){
            cout << "Enter your grade!" << endl;
            cin >> courses[i];
            if (isdigit(courses[i][0])){
                cout << "Incorrect Input!" << endl;
                return 0;
            }
    }
    for (int j = 0; j < 5; j++) {
        if (courses[j] == "A"){
            sum += 4.0;
        }
        else if (courses[j] == "A-"){
            sum += 3.7;
        }
        else if (courses[j] == "B"){
            sum += 3.3;
        }
        else if(courses[j] == "B-"){
            sum += 3.0;
        }
        else if(courses[j] == "C+"){
            sum += 2.3;
        }
        else if(courses[j] == "C"){
            sum += 2.0;
        }
        else if(courses[j] == "C-"){
            sum += 1.7;
        }
        else if(courses[j] == "D"){
            sum += 1.0;
        }
        else if (courses[j] == "F"){
            sum += 0.0;
        }
    }
    float avg = (float)sum/5.0;
    cout << "GPA: " << avg << endl;
    return 0;
}
