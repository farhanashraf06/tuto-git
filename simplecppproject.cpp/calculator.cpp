#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

void addition (double num[],int count);
void subtraction (double num[],int count);
void multiplication (double num [],int count);
void division (double num[], int count);

int main (){
    char continueorno;
    int count;
    do{
    cout << "-----Simple Calculator-----" << endl;
     double num[50];
     cout << "Enter the numbers to be operated on (enter 0 to stop) : " << endl;
                for (int i=0 ; i < 50 ;i++){
                    cout << i+1 << ":";
                    cin >> num[i];
                    if ((num[i]== 0) && i== 0){
                        count = 0;
                        break;
                    }
                    if (num[i]==0){
                        break;
                    }
                    count++;
                }
    if (count == 0 ){
        cout << "No number were entered or only ) was entered. " <<endl;
    }
    cout << "a. Addition , b. Subtraction , c. Multiplication , d. Division "<<endl;
    char choice;
    cout << "Choose your desired choice. " << endl;
    cin >> choice;
    if (isupper(choice)){
        choice = tolower (choice);
    }

    switch (choice){
        case 'a':
                addition(num,count);
                break;
        case 'b':
                subtraction(num, count);
                break;
        case 'c':
                multiplication(num, count);
                break;
        case 'd':
                division(num, count);
                break;
        default :
            cout << "Invalid choice!" << endl;
            break;      
    }
    cin.ignore();
    cout << "Do you wish to continue? (y/n) "<< endl;
    cin >> continueorno;
    }while ((continueorno == 'Y')||(continueorno == 'y'));
    cout << "Program ended, Thank you so much! " << endl;
    return 0;
}

void addition (double num[], int count){
    double sum=0;
    for (int i=0 ; i <count ;i++){
        sum += num[i];
    }
    cout << "The sum of your numbers are : " << sum << endl; 
}
void subtraction (double num[], int count){
    double difference=num[0];
    for (int i=0 ; i <count  ;i++){
        difference -= num[i];
    }
    cout << "The difference of your numbers are : " << difference << endl;
}
void multiplication (double num [], int count){
    double product=1;
    for (int i=0; i<count;i++){
        product *=num[i];
    }
    cout << "The product of your numbers are : " << product  << endl;
}
void division (double num[], int count){
    double quotient=num[0];
    for (int i =0; i<count ; i++){
        quotient /= num[i];
    }
    cout << "The quotient of your numbers are : "<< quotient << endl;
}