#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

void checkBalance (double balance);
double withdrawMoney (double balance);

int main(){;
    cout << "----- Banking Program -----" << endl;
    char choice;
    double balance=0;
    cout << "----- Welcome to FarBank -----" << endl;
    cout <<  "What would you like to do? " << endl << "a. Check Balance" << endl <<"b. Withdraw Money " << endl;
    cout << "c. Deposit Money" << endl << "d. Exit" << endl;
    cin >> choice;
    if (isupper(choice)){
        choice = tolower (choice);
    }
    switch (choice){
        case 'a':
            checkBalance (balance);
        case 'b':
            withdrawMoney (balance);
            checkBalance (balance);
        case 'c':
        case 'd':
    }
    return 0;
}
void checkBalance (double balance){
    cout << "Your current balance is : RM " << setprecision(2) << fixed << balance << endl; 
}
double withdrawMoney (double balance){
    double amount;
    cout << "How much would you like to withdraw? : RM " << endl;
    cin >> amount;
    if (amount < balance ){
        cout << "Sorry , Insufficient Balance. " << endl;
    }
    else {
        balance -= amount;
    }
}