#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int maxCourse = 5;
const string courseName[maxCourse]= {"AutoCAD Basic" , "Microsoft Excel Basic" , "Android Studio" , "E-Invoice Strategic Implementing" ,"Analyzing Data"};
const double coursePrice[maxCourse]= {1470.00,525.00,1570,850.00, 1890.00};

int main (){
    int courseStorage[maxCourse];
    int peopleStorage[maxCourse];
    double fees [maxCourse];
    double discount [maxCourse];
    string name;
    int courseCode , amountCourse , people; 

    cout << "-----IT UTM CONSULTANCY COURSE REGISTRATION-----" << endl;
    cout << "Please enter your name : ";
    getline(cin , name);
    cout << "Course offered : " << endl;
    for (int i=0 ; i < maxCourse; i++){
        cout << i+1 <<". "<< courseName[i] << " - RM " << fixed << setprecision(2) << coursePrice [i] << endl;
    }
    
    do{
    cout << "How many course would you like to register? : ";
    cin >> amountCourse;
    if ( (cin.fail()) || (amountCourse <= 0 ) || (amountCourse > 5 )){ 
        cout << "Invalid Input! Please enter a number between 1 and 5. " <<endl;
        cin.clear();
        cin.ignore (10000, '\n');   
    }
    }while ((amountCourse <= 0 )||(amountCourse > 5 ));
    



    return 0;

}