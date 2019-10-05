#include <iostream>
#include <string>
using namespace std;

int main(){
    int num1, num2;
    string numstring1, numstring2;
    int maxtern1 = 1;
    int maxtern2 = 1;
    int hamming = 0;
    cout << "Enter two numbers: " << endl;
    cin >> num1;
    cin >> num2;
    int n1 = num1;
    int n2 = num2;
    int output = num1 - num2;
    if (output == 0){
        cout << "Hamming distance between " << num1 << " and " << num2 << " when numbers are in ternary format is: 0" << endl;
        return 0;
    }
    else if (output < 0)
    {
        output *= -1;
    }
    while ((num1/maxtern1) >= 1){
        maxtern1 *= 3;
    }
    while ((num2/maxtern2) >= 1){
        maxtern2 *= 3;
    }
    maxtern1 /=3;
    maxtern2 /=3;
    cout << maxtern1 << " " << output << endl;
    while (num1 > 0){
        if ((num1 - (2 * maxtern1)) >= 0){
            num1 -= 2*maxtern1;
            numstring1.append("2");
            maxtern1 /= 3;
        }
        else if((num1 - maxtern1) >= 0){
            num1 -= maxtern1;
            numstring1.append("1");
            maxtern1 /= 3;
        }
        else{
            numstring1.append("0");
            maxtern1 /= 3;
        }
    }
    while (num2 > 0){
        if ((num2 - (2 * maxtern2)) >= 0){
            num2 -= 2*maxtern2;
            numstring2.append("2");
            maxtern2 /= 3;
        }
        else if((num2 - maxtern2) >= 0){
            num2 -= maxtern2;
            numstring2.append("1");
            maxtern2 /= 3;
        }
        else{
            numstring2.append("0");
            maxtern2 /= 3;
        }
    }
    if (numstring1.length() < numstring2.length()){
        while (numstring1.length() < numstring2.length()){
            numstring1.append("0");
        }
    }
    if (numstring2.length() < numstring1.length()){
        while (numstring2.length() < numstring1.length()){
            numstring2.append("0");
        }
    }
    for(int i = 0; i < numstring1.length(); i++){
        if (numstring1[i] != numstring2[i]){
            hamming++;
        }
    }
    cout << "Hamming distance between " << n1 << " and " << n2 << " when numbers are in ternary format is: "<< hamming << endl;

}