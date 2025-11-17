#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

void checkBalance (double balance);
double withdrawMoney (double balance);
double depoMoney (double balance);

int main(){
    char choice;
    double balance=0;
    do{
    cout << "----- Banking Program -----" << endl;
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
            break;
        case 'b':
            balance -= withdrawMoney (balance);
            checkBalance (balance);
            break;
        case 'c':
            balance += depoMoney (balance);
            checkBalance (balance);
            break;
        case 'd':
            cout << " Thank you for visiting us! " << endl;
            return 0;
            break;
        default :
            cout << "Invlaid choice! " << endl;
    }
    
    }while ( choice != 'd');
}

void checkBalance (double balance){
    cout << "Your current balance is : RM " << setprecision(2) << fixed << balance << endl; 
}

double withdrawMoney (double balance){
    double amount;
    cout << "How much would you like to withdraw? : RM " << endl;
    cin >> amount;
    if (cin.fail()){
        cin.clear();
        cin.ignore (10000 ,'\n');
        cout << "Invalid Input!" << endl;
        return 0;
    }
    if (amount > balance ){
        cout << "Sorry , Insufficient Balance. " << endl;
        return 0;
    }
    if (amount < 0) {
        cout << "Sorry , The amout cannot be negative. " << endl;
        return 0;
    }

        return amount;
}

double depoMoney (double balance){
    double amount;
    cout << "How much would you like to deposit? : RM " << endl;
    cin >> amount;
     if (cin.fail()){
        cin.clear();
        cin.ignore (10000 ,'\n');
        cout << "Invalid Input!" << endl;
        return 0;
    }
    if (amount < 0){
        cout << "Sorry, The amount cannot be negative. " << endl;
        return 0;
    }
        return amount;
}