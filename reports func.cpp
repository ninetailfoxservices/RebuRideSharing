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

void driverReport(fstream& driverReg);
void customerReport(fstream& customerReg);
// void weeklyTripReport(fstream& driverReg, fstream& customerReg, fstream& bookingInfo);
void printLine();

fstream driverReg;
fstream customerReg;
fstream bookingInfo;

int main()
{
    int choice;

    // struct variables
      // DriverReg DR2;
      // CustomerReg CR2;
      // Booking book;

    // variables for other functions
      // char date[CSIZE];

    cout << "Either:" << endl;
    cout << "1. Driver Report \n2. Customer Report \n3. Weekly \n4. Exit";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
        driverReport(driverReg);
        break;
    case 2:
        customerReport(customerReg);
        break;
    case 3:
        exit(0);
    default:
        cout << "Please choose an option from the menu.";
        break;
    }

    return 0;
}

void driverReport(fstream& driverReg)
{
    DriverReg DR2;

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
        cout << "Would you like to search by driver name or ID number? (N: name/D: ID Number) ";
        cin >> choice;

        if (toupper(choice) == 'N')
        {
            cout << "Enter a driver name: ";
            cin.getline(driverName, CSIZE);

            while (!driverReg.eof())
            {
                if ((strcmp(driverName, DR2.firstName) == 0) || (strcmp(driverName, DR2.lastName) == 0))
                {
                    cout << "\tDriver Information" << endl;
                    cout << "Driver Name                : " << DR2.firstName << " " << DR2.lastName << endl;
                    cout << "Driver Pronouns            : " << DR2.pronouns << endl;
                    cout << "Driver ID No.              : " << DR2.driverID << endl;
                    cout << "Driver Phone No.           : " << DR2.contactNo << endl;
                    cout << "Driver Email               : " << DR2.email << endl;
                    cout << "Driver Bank                : " << DR2.bankName << endl;
                    cout << "Driver Username            : " << DR2.driverUser << endl;
                    cout << "Driver Address             : " << DR2.homeAdd << endl;
                    cout << "Vehicle Model & Capacity   : " << DR2.vehicleModel << ", " <<DR2.vehicleCap << endl;
                    cout << "Driver Nationality         : " << DR2.nationality << endl;
                    cout << "Driver Date of Birth       : " << DR2.dob << endl;
                    cout << "License Number             : " << DR2.licenseNum << endl;
                    cout << "License Exipration Date    : " << DR2.dateofExp << endl;
                    cout << "Driver Experience (Years)  : " << DR2.driverXP << endl;
                }
            }
        }
        else if (toupper(choice) == 'D')
        {
            cout << "Enter a driver ID number: ";
            cin >> ID;

            while (!driverReg.eof())
            {
                if (ID == DR2.driverID)
                {
                    cout << "\tDriver Information" << endl;
                    cout << "Driver Name                : " << DR2.firstName << " " << DR2.lastName << endl;
                    cout << "Driver Pronouns            : " << DR2.pronouns << endl;
                    cout << "Driver ID                  : " << DR2.driverID << endl;
                    cout << "Driver Phone No.           : " << DR2.contactNo << endl;
                    cout << "Driver Email               : " << DR2.email << endl;
                    cout << "Driver Bank                : " << DR2.bankName << endl;
                    cout << "Driver Username            : " << DR2.driverUser << endl;
                    cout << "Driver Address             : " << DR2.homeAdd << endl;
                    cout << "Vehicle Model & Capacity   : " << DR2.vehicleModel << ", " << DR2.vehicleCap << endl;
                    cout << "Driver Nationality         : " << DR2.nationality << endl;
                    cout << "Driver Date of Birth       : " << DR2.dob << endl;
                    cout << "License Number             : " << DR2.licenseNum << endl;
                    cout << "License Exipration Date    : " << DR2.dateofExp << endl;
                    cout << "Driver Experience (Years)  : " << DR2.driverXP << endl;
                }
            }
        }
    }
}

void customerReport(fstream& customerReg)
{
    CustomerReg CR2;

    char choice;
    char customerName[CSIZE];
    char customerUser[CSIZE];

    customerReg.open("customerReg.dat", ios::in | ios::binary);
    if (!customerReg)
    {
        cout << "Error, file not found.";
        exit(1);
    }
    else
    {
        cout << "Would you like to search by customer name or username? (N: name/U: username) ";
        cin >> choice;
        
        if (toupper(choice) == 'N')
        {
            cout << "Enter a name: ";
            cin.getline(customerName, CSIZE);

            while (!customerReg.eof())
            {
                if ((strcmp(customerName, CR2.firstName) == 0) || (strcmp(customerName, CR2.lastName) == 0))
                {
                    cout << "\tCustomer Information" << endl;
                    cout << "Customer Name                : " << CR2.firstName << " " << CR2.lastName << endl;
                    cout << "Customer Username            : " << CR2.custUser << endl;
                    cout << "Customer Contact No.         : " << CR2.custContactNo << endl;
                    cout << "Customer Email               : " << CR2.custEmail << endl;
                    cout << "Customer Address             : " << CR2.custAdd << endl;
                    cout << "Customer Payment Method      : " << CR2.custPayment << endl;
                }
            }
        }
        else if (toupper(choice) == 'U')
        {
            cout << "Enter a username: ";
            cin.getline(customerUser, CSIZE);

            while (!customerReg.eof())
            {
                if (strcmp(customerUser, CR2.custUser) == 0)
                {
                    cout << "\tCustomer Information" << endl;
                    cout << "Customer Name                : " << CR2.firstName << " " << CR2.lastName << endl;
                    cout << "Customer Username            : " << CR2.custUser << endl;
                    cout << "Customer Contact No.         : " << CR2.custContactNo << endl;
                    cout << "Customer Email               : " << CR2.custEmail << endl;
                    cout << "Customer Address             : " << CR2.custAdd << endl;
                    cout << "Customer Payment Method      : " << CR2.custPayment << endl;
                }
            }
        }
    }
}