#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;
const int NUM_BRANCHES = 5;
const int NUM_MONTHS = 12;
const string monthName[NUM_MONTHS] = {"Jan","Feb","Mar","Apr","May","Jun",
                        "Jul","Aug","Sep","Oct","Nov","Dec"};


void readFile (float sales[][NUM_MONTHS] , string storeName[] , string x);
float grandTotalSales (float sales[][NUM_MONTHS]);
float averageMonthlySales (float sales[][NUM_MONTHS]);
float monthTotalSales (float sales[][NUM_MONTHS] , int index);
float storeTotalSales (float sales[][NUM_MONTHS] , int index);
void indicesOfHighestSales (float sales[][NUM_MONTHS] , int &indexrow , int &indexcolumn);


int main (){
    string inputFile , outputFile , storeName[NUM_BRANCHES];
    float sales[NUM_BRANCHES][NUM_MONTHS], grandtotalsales , avgmonthlysale, monthtotalsale , storetotalsale;
    int row ,col;

    cout << "Enter the input file name : ";
    cin >> inputFile;

    readFile (sales ,storeName , inputFile );
    cout << "Enter the output file name : ";
    cin >> outputFile;

    ofstream outFile;
    outFile.open (outputFile);

    grandtotalsales = grandTotalSales (sales)*1000;
    avgmonthlysale = averageMonthlySales (sales)*1000;
    indicesOfHighestSales (sales , row , col);

    outFile << setprecision(2) << fixed;
    outFile << "Grand total sales over all stores : RM " << setw(10) <<grandtotalsales << endl;
    outFile << "Average sales per month :           RM " << setw(10) << avgmonthlysale << endl;
    outFile << endl;
    outFile << "The highest sales : " << endl;
    outFile << "---------------------" << endl;
    outFile << "Store : " << storeName[row] << endl;
    outFile << "Month : " << monthName [col] << endl;
    outFile << "Sales : RM " << sales[row][col] *1000 << endl;
    outFile << endl;
    outFile << "Total Sales by Month :"<< endl;
    outFile << "Month   Sales" << endl;
    outFile << "-----   -----" << endl;
    for ( int i=0 ; i < NUM_MONTHS; i++){
        monthtotalsale = monthTotalSales (sales , i) *1000;
        outFile << left << setw(5) <<monthName[i] << right << setw(5) << "RM"<< monthtotalsale << endl;
    }
    outFile << endl << "Total sales by store: " << endl;
    outFile << "Store               Total Sales" << endl;
    outFile << "-----               -----------" << endl;
    for ( int i=0 ; i < NUM_BRANCHES; i++){
        storetotalsale = storeTotalSales ( sales , i)*1000;
        outFile << left << setw(12) << storeName[i] << right << setw(10) << "RM"<< storetotalsale << endl;

    }
    outFile << endl <<"Profitable stores:" << endl;
    outFile << "------------------" << endl;
    for ( int i=0; i < NUM_BRANCHES; i++){
        storetotalsale = storeTotalSales ( sales , i)*1000;
        if (storetotalsale > 600000){
            outFile << storeName[i] << endl;
        }
    }

    return 0;
}


void readFile (float sales[][NUM_MONTHS] , string storeName[] , string x){
    ifstream inFile;
    inFile.open (x);

    if (!inFile.is_open()){
        cout << "Error to find the file ! Exiting the program...." << endl;
        exit(1);
    }
    
    cout << "Reading......" << endl;
    for ( int i=0; i < NUM_BRANCHES; i++){
        for ( int j=0; j < NUM_MONTHS; j++){
            inFile >> sales [i][j];
        }
        inFile.ignore ();
        getline ( inFile , storeName[i]);
    }
}


float grandTotalSales (float sales[][NUM_MONTHS]){
    float sum=0;
    for ( int i = 0; i < NUM_BRANCHES; i++){
        for ( int j =0 ; j < NUM_MONTHS; j++){
            sum+=sales[i][j];
        }
    }
    return sum;
}


float averageMonthlySales (float sales[][NUM_MONTHS]){
    float sum=0;
    for ( int i = 0; i < NUM_BRANCHES; i++){
        for ( int j =0 ; j < NUM_MONTHS; j++){
            sum+=sales[i][j];
        }
    }
    return sum/NUM_MONTHS;
}


float monthTotalSales (float sales[][NUM_MONTHS] , int index){
    float sum=0;
    for ( int i=0 ; i < NUM_BRANCHES; i++){
        sum += sales[i][index];
    }
    return sum;
}


float storeTotalSales (float sales[][NUM_MONTHS] , int index){
    float sum=0;
    for ( int i=0 ; i < NUM_MONTHS; i++){
        sum += sales[index][i];
    }
    return sum;
}


void indicesOfHighestSales (float sales[][NUM_MONTHS] , int &indexrow , int &indexcolumn){
    int highest = sales[0][0];
    for ( int i = 0; i < NUM_BRANCHES; i++){
        for ( int j=0; j < NUM_MONTHS; j++){
            if (sales[i][j] > highest){
                highest = sales[i][j];
                indexrow = i;
                indexcolumn = j;
            }
        }
    }
}




