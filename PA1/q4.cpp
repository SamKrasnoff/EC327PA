#include <iostream>
#include <sstream>
using namespace std;

int main(){
    bool isNum = true;
    bool isPal = true;
    int palindrome;
    ostringstream convert;
    string pal;
    do{
        cout << "Enter a number: " << endl;
        cin >> palindrome;
        convert << palindrome;
        pal = convert.str();
        for (int i = 0; i < pal.length(); i++){
            if (!isdigit(pal[i])){
                isNum = false;
            }
        }
    } while (isNum == false);
    for (int j = pal.length()-1; j > 0; j--){
        if (pal[j] != pal[pal.length()-1-j]){
            isPal = false;
        }
    }
    if (isPal == true && isNum == true){
        cout << "The number " << pal << " is a palindrome." << endl;
    }
    if (isPal == false || isNum == false){
        cout << "The number " << pal << " is not a palindrome." << endl;
    }
}