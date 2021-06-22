// ConsoleApplication66.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <time.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <limits>
#include <conio.h>

using namespace std;

const int CSIZE = 51;

struct DriverReg
{
    char driverUser[CSIZE];
    char driverPassword[CSIZE];
    char firstName[CSIZE];
    char lastName[CSIZE];
    char pronouns[CSIZE];
    char dob[CSIZE];
    char nationality[CSIZE];
    char licenseNum[CSIZE];
    char dateofExp[CSIZE];
    char driverXP[CSIZE];
    char contactNo[CSIZE];
    char email[CSIZE];
    char homeAdd[CSIZE];
    char bankAccNo[CSIZE];
    char bankName[CSIZE];
    char vehicleRego[CSIZE];
    char WOF[CSIZE];
    char vehicleModel[CSIZE];
    int driverID;
    int vehicleCap;
};

struct CustomerReg
{
    char custUser[CSIZE];
    char custPassword[CSIZE];
    char firstName[CSIZE];
    char lastName[CSIZE];
    char custContactNo[CSIZE];
    char custEmail[CSIZE];
    char custAdd[CSIZE];
    char custPayment[CSIZE];
};

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

void dailyTripReport(fstream& driverReg, fstream& customerReg, fstream& bookingInfo);
void weeklyTripReport(fstream& driverReg, fstream& customerReg, fstream& bookingInfo);

fstream driverReg;
fstream customerReg;
fstream bookingInfo;

int main()
{
    int choice;
    DriverReg DR2;
    CustomerReg CR2;
    Booking book;

    cout << "Either:" << endl;
    cout << "1. Daily \n2. Weekly \n3. Exit";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
        dailyTripReport(driverReg, customerReg, bookingInfo);
        break;
    case 2:
        weeklyTripReport(driverReg, customerReg, bookingInfo);
        break;
    case 3:
        exit(0);
    default: 
        cout << "Please choose an option from the menu.";
        break;
    }

    return 0;
}

void dailyTripReport(fstream& bookingInfo, fstream& driverReg, fstream& customerReg)
{
    DriverReg DR2;
    CustomerReg CR2;
    Booking book;

    char choice;
    char driverName[CSIZE];
    int ID;
    
    driverReg.open("driverReg.dat", ios::in | ios::binary);
    if (!driverReg)
    {
        cout << "Error, file not found.";
        exit(1);
    }
    else
    {
        cout << "Would you like to search by driver name or ID number? (N: name/D: ID number)";
        cin >> choice;

        if (toupper(choice) == 'N')
        {
            cout << "Enter a driver name: ";
            cin.getline(driverName, CSIZE);
        }
        else if (toupper(choice) == 'D')
        {
            cout << "Enter a driver ID number: ";
            cin >> ID;
        }
    }
}