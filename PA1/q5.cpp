#include <iostream>
using namespace std;

int main(){
    string input;
    bool alnum = true;
    cout << "Enter char, operation" << endl;
    cin >> input;
    if (input.length() > 2){
        cout << "Too long!" << endl;
        return 0;
    }
    for (int i = 0; i < input.length(); i++){
        if (!isalnum(input[i])){
            cout << "Invalid Input!" << endl;
            return 0;
        }
    }
    char letter = input[0];
    char output;
    int num = input[1] - '0';
    if (num == 1){
        if (isupper(letter)){
            output = tolower(letter);
        }
        else if (islower(letter)){
            output = toupper(letter);
        }
    }
    else if (num ==2){
        if (isupper(letter)){
            output = tolower(letter);
            output = 'z' - output + 'a';
        }
        else if (islower(letter)){
            output = toupper(letter);
            output = 'Z' - output + 'A';

        }
    }
    else if (num == 3){
        if (letter >= 'a' && letter <= 't'){
            output = letter + 6;
        }
        else if(letter >= 'u' && letter <= 'z'){
            output = letter - 52;
        }
        else if (letter >= 'A' && letter <= 'T'){
            output = letter + 6;
        }
        else if(letter >= 'U' && letter <= 'Z'){
            output = letter + 12;
        }   
    }
    cout << "Result: " << output << endl;
}