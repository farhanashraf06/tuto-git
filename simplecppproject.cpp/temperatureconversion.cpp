#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>
#define  abszerooffset 273.15
using namespace std;

void KtoF(double temp);
void FtoC(double temp);
void FtoK(double temp);
void CtoF(double temp);


int main (){
    char continueorno;
   do{
     cout << "-----Temperature Conversion Program-----" << endl;
    cout << "K-Kelvin , " << "F=Fahrenheit , " << "C-Celcius. " << endl;
    char unit; // unit that the user currently uses
    char unit2; // unit that the user want to convert to
    double temp;
    cout << "Enter the temperature : " << endl;
    cin >> temp;
    if (cin.fail()){ // cehcking if the input temp fails
        while (!(cin >> temp)){ 
        cout << "You entered an invalid temperature, please enter again a valid temperature : " << endl;
        cin.clear();
        cin.ignore(100000,'\n');
    }
    }
    cout << "What unit are you currently using? " << endl;
    cin >> unit;
    unit = toupper(unit);

    switch (unit) {

    case 'K':
        cout << "What unit would you like to change to?" << endl;
        cin >> unit2;
        unit2 = toupper(unit2);
        if (unit2=='C'){
            temp = temp - abszerooffset;
            cout << "The converted temperature is : " << temp << endl;  
        }
        else if (unit2 == 'F'){
        KtoF (temp);
        }
        else if (unit2 =='K'){
            cout << "The temperature is already in that unit. " << endl;
        }
        else {
            cout << "Invalid unit! " << endl;
        }
        break;

    case 'F':
        cout << "What unit would you like to change to?" << endl;
        cin >> unit2;
        unit2 = toupper (unit2);
        if (unit2 == 'C'){
            FtoC(temp);
        }
        else if (unit2 == 'K'){
            FtoK(temp);
        }
        else if (unit2 =='F'){
            cout << "The temperature is already in that unit. " << endl;
        }
        else {
            cout << "Invalid unit! " << endl;
        }
        break;

    case 'C':
        cout << "What unit would you like to change to?" << endl;
        cin >> unit2;
        unit2 = toupper (unit2);
        if (unit2 == 'K'){
           temp = temp + abszerooffset;
           cout << "The converted temperature is : " << temp << endl; 
        }
        else if (unit2 == 'F'){
            CtoF(temp);
        }
        else if (unit2 =='C'){
            cout << "The temperature is already in that unit. " << endl;
        }
        else {
            cout << "Invalid unit! " << endl;
        }
        break;
    default :
        cout << "Invalid unit!" << endl;      break;    
    }
    cout << "Would you like to repeat the program?(y/n)" << endl;
    cin >> continueorno;
   }while ((continueorno == 'Y')||(continueorno == 'y') );
    cout << "Thank you for using my program, see you again ! " << endl;
    return 0;
}
void KtoF(double temp) {
    double converted;
    converted = (temp - abszerooffset) * 9/5 + 32;
    cout << "The converted temperature is : " << converted << endl;
}
void FtoC(double temp){
    double converted;
    converted = (temp-32) * 5/9;
    cout << "The converted temperature is : " << converted << endl;
}
void FtoK (double temp){
    double converted;
    converted = (temp-32) * 5/9 + abszerooffset;
    cout << "The converted temperature is : " << converted << endl;

}
void CtoF(double temp){
    double converted;
    converted = (temp *9/5) + 32;
    cout << "The converted temperature is : " << converted << endl;
}