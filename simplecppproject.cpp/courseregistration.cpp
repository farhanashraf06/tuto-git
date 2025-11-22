#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int maxCourse = 5;
const string courseName[maxCourse]= {"AutoCAD Basic" , "Microsoft Excel Basic" , "Android Studio" , "E-Invoice Strategic Implementing" ,"Analyzing Data"};
const double coursePrice[maxCourse]= {1470.00,525.00,1570,850.00, 1890.00};
bool confirmation (int courseCode , int courseStorage[],int amountCourse);
void calcFee (int courseStorage[], int peopleStorage[], double fees[], int amountCourse);
void disc (int peopleStorage[] , double fees[] , int amountCourse , double discount[]);
void receipt (string name, int courseStorage[], int peopleStorage[],double fees[],double discount[],int amountCourse);

int main (){
    int courseStorage[maxCourse];
    int peopleStorage[maxCourse];
    double fees [maxCourse];
    double discount [maxCourse];
    string name;
    int courseCode , amountCourse , people; 
    char choice;

    do{
         cout << "-----IT UTM CONSULTANCY COURSE REGISTRATION-----" << endl;
    cout << "Please enter your name : ";
    getline(cin , name);
    cout << "Course offered : " << endl;
    for (int i=0 ; i < maxCourse; ++i){
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

    for (int i=0; i < amountCourse ; ++i){
       do{
         cout << "Please enter course code : " << endl  << i+1 << ". #";
         cin >> courseCode;
        if (cin.fail()){
            cout << "Invalid Input ! Please enter a number !" << endl;
            cin.clear();
            cin.ignore (10000 ,'\n');
            continue;
        }
       }while (!confirmation(courseCode , courseStorage ,i));
       courseStorage[i] = courseCode;

       do{
        cout << "Please enter the number of participants to be registered (min 30) : " ;
       cin >> people;
       cout << endl;
       if (cin.fail()){
             cout << " Invalid Input ! Please enter a number ! " << endl;
            cin.clear();
            cin.ignore (10000 ,'\n');
            people = -1;
        }
        if(people < 30 ) {
            cout << "Minimum participants of 30 people is required . " <<endl;
        }
       }while (people < 30);
       peopleStorage[i]=people;
    }
    calcFee (courseStorage , peopleStorage , fees , amountCourse);
    disc (peopleStorage , fees , amountCourse , discount);
    receipt (name , courseStorage , peopleStorage , fees , discount , amountCourse);

    do {
    cout << "Thank you for registering! Would you like to register again? (Y - yes / N - no): ";
    cin >> choice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input! ";
        continue;
    }
    choice = toupper(choice);
    if (choice != 'Y' && choice != 'N') {
        cout << "Invalid choice! ";
    }
        } while (choice != 'Y' && choice != 'N');
    }while (choice == 'Y');

     return 0;
}

bool confirmation (int courseCode , int courseStorage[],int count){

    if ((courseCode < 1 ) || (courseCode > maxCourse)){
        cout << " Enter number between 1 and 5 only! " << endl;
        return false;
    }
    
    for (int i=0; i < count; ++i ){
        if (courseStorage[i]== courseCode){
            cout << "Duplicated course code. Each course can be only entered once. " <<endl;
            return false;
        }  
    }
    return true;
}

void calcFee (int courseStorage[], int peopleStorage[], double fees[], int amountCourse){
    double totalFees;
    for (int i =0 ; i < amountCourse ; i++){
        int x = courseStorage[i] - 1;
        fees[i] = coursePrice[x] * peopleStorage [i];
    }
}

void disc (int peopleStorage[] , double fees[] , int amountCourse , double discount[]){
    for (int i=0 ; i < amountCourse ; i++){
        discount [i] = (peopleStorage[i] > 50) ? 0.1*fees[i] : 0 ;
    }
}

void receipt (string name, int courseStorage[], int peopleStorage[],double fees[],double discount[],int amountCourse){
    ofstream    outfile ("receipt.txt");

    cout << "-----IT UTM CONSULTANCY COURSE - OFFICIAL RECEIPT -----" << endl;
    outfile << "-----IT UTM CONSULTANCY COURSE - OFFICIAL RECEIPT -----" << endl;
    
    cout <<  "Customer name : " << name << endl;
    outfile <<  "Customer name : " << name << endl;

    double totalFee=0;
    int totalPeople=0;

    for (int i=0; i < amountCourse ; i++){
        int x = courseStorage[i] - 1;
        double netfee = fees[i] - discount[i];
        totalFee += netfee;
        totalPeople += peopleStorage[i];

        cout << "Course  : " << courseName[x] << endl;
        cout << "Participants : " << peopleStorage[i] << endl;
        cout << "Total Fees : RM " << fees[i] << endl;
        cout << "Discount : RM " << discount[i] << endl;
        cout << "Fees after discount : RM " << netfee << endl << endl;


        outfile << "Course  : " << courseName[x] << endl;
        outfile << "Participants : " << peopleStorage[i] << endl;
        outfile << "Total Fees : RM " << fees[i] << endl;
        outfile << "Discount : RM " << discount[i] << endl;
        outfile << "Fees after discount : RM " << netfee << endl;
    }

    double tax = 0.6 * totalFee;
    double grandTotal = totalFee + tax;
    
    
    cout << "Subtotal Fee: RM " << totalFee << endl;
    cout << "Tax (6%): RM " << tax << endl;
    cout << "Grand Total Fee: RM " << grandTotal << endl;
    cout << "Total Participants: " << totalPeople << endl;
    cout << "Amount per Person: RM " << grandTotal / totalPeople << endl << endl;

    outfile << "Subtotal Fee: RM " << totalFee << endl;
    outfile << "Tax (6%): RM " << tax << endl;
    outfile << "Grand Total Fee: RM " << grandTotal << endl;
    outfile << "Total Participants: " << totalPeople << endl;
    outfile << "Amount per Person: RM " << grandTotal / totalPeople << endl;
    
    outfile.close();
}