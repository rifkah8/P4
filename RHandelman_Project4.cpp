/*
Class: CMSC140 CRN30178
Instructor: Grigoriy Gringerg
Project/HW<4>
This program shows the absences of employees.
Due Date : 04/19/2020
I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your name here: Rifka Handelman
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

//global ofstream
ofstream absences;

//prototypes
int numOfEmployees();
int totDaysAbsent(int);
double averageAbsent(int, int);

int main(){
    int employees, totDaysMissed;
    double avgAbsent;
    const string NAME = "Rifka Handelman", PROJECT = "CMSC140 Common Project 4", DUE_DATE = "04/19/2020";
    absences.open("employeeAbsences.txt");
    absences << "Employee Absence Report\nID   Days Missed\n";
//executing functions
    employees = numOfEmployees();
    totDaysMissed = totDaysAbsent(employees);
    avgAbsent = averageAbsent(employees, totDaysMissed);
    absences << "The average number of days missed was " << showpoint << setprecision(1) << fixed << avgAbsent << ".\n";
//project info
    absences << "--------------------------\n";
    absences << "Programmer: " << NAME << "\n";
    absences << "Project: " << PROJECT << "\n";
    absences << "Due Date: " << DUE_DATE << "\n";
    absences.close();
//console output
    cout << "--------------------------" << endl;
    cout << NAME << "\n" << PROJECT << "\n" << DUE_DATE << endl;
    return(0);
}

int numOfEmployees(){
    int x;
    cout << "Enter the number of employees: ";
    cin >> x;
    while (x < 1){
        cout << "Invalid input. Number must be greater than zero. \nEnter the number of employees: ";
        cin >> x;
    }
    return(x);
}

int totDaysAbsent(int employees){
    int totDaysMissed = 0;
    for(int employeeID, daysMissed, i = 0; i < employees; i++){
        cout << "ID: ";
        cin >> employeeID;
        cout << "Days Missed: ";
        cin >> daysMissed;
        while (daysMissed < 0){
            cout << "Invalid input. Number must not be less than zero.\nDays Missed: ";
            cin >> daysMissed;
        }
        totDaysMissed += daysMissed;
        absences << employeeID << "   " << daysMissed << "\n";
    }
    absences << "The total days missed by " << employees << " employees was " << totDaysMissed << ".\n";
    return(totDaysMissed);
}

double averageAbsent(int numEmployees, int totDaysMissed){
    return(static_cast<double>(totDaysMissed) / static_cast<double>(numEmployees));
}
