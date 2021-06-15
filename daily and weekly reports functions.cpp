// daily and weekly reports functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
// version 0.1
// created by Logan

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

const int CSIZE = 51;

struct Booking {
    char tripNo[CSIZE];
    char startDestination[CSIZE];
    char endDestination[CSIZE];
    char bookingDate[CSIZE];
    char bookingTime[CSIZE];
    char noPassengers[CSIZE];
    char specialReqs[CSIZE];
    char luggage[CSIZE];
    char paymentStatus[CSIZE];
    char cancelBooking[CSIZE];
};

// function prototypes
void dailyReport();
void weeklyReport();

int main()
{
    char choice;

    cout << "Choose one";
    cout << "\n1. Daily report \n2. Weekly report \n3. Exit \n";
    cin >> choice;

    cin.ignore();

    switch (choice)
    {
    case 1:
        dailyReport();
    case 2:
        weeklyReport();
    case 3:
        cout << "Exiting...";
        exit(0);
    }
}

void dailyReport()
{
    cout << "Yes";
}

void weeklyReport()
{
    cout << "No";
}