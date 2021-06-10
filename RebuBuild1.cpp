// Rebu.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Created by Logan and Sherwin.
// Version: 0.1
// start date: 08/06/2021

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;


//Global Const
const int CSIZE = 51;

// struct declaration
struct DriverReg
{
    char driverUser[CSIZE];
    char driverPassword[CSIZE];
    char fullName[CSIZE];
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
    char driverID[CSIZE];
    int vehicleCap;
};

struct CustomerReg
{
    char custUser[CSIZE];
    char custPassword[CSIZE];
    char custName[CSIZE];
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
//*************************************

//prototyping functions Level 1
void newDriver(fstream &driverReg);
//void existingDriver();
//void administrator();
//void newCustomer();
//void existingCustomer();
//void bookTrip();
void printLine();
//prototyping functions Level 2


int main()
{
    //local variable
    int input = 0;

    //struct variables
    DriverReg DR;
    CustomerReg CR;
    Booking Book;

    //creating file object and open file handles
    fstream driverReg;
    fstream customerReg;
    fstream bookingInfo;
    
    while (true)
    {

        printLine();

        cout << "\tWelcome to Rebu Ride Sharing!\n";

        printLine();

        cout << "\tMenu.\n1. Register as a Driver\n2. Driver Login\n3. New Customer\n4. Customer Login\n5. Administrator\n6. Book a Trip";

        printLine();

        cout << "Enter Option Number : ";
        cin >> input;

        switch (input)
        {
        case 1:
            newDriver(driverReg);
            break;
        case 2:
           // existingDriver(driverReg);
            break;
        case 3:
           // newCustomer(customerReg);
            break;
        case 4:
          //  existingCustomer(customerReg);
            break;
        case 5:
          //  administrator(driverReg,customerReg,bookingInfo);
            break;
        case 6:
          //  bookTrip(bookingInfo);
            break;
        case 7:
            cout << "Exiting Program...";
            exit(0);
        default:
            cout << "Please select an option on the list : ";
            break;
        }
    }
    return 0;
}

void newDriver(fstream &driverReg)
{
    //local variable
    char input;
    //Structures
    DriverReg DR1;

    cout << "Would you like to make a new Driver Account? (Y/N) : ";
    cin >> input;
    if (input == 'y' || input == 'Y')
    {
        //opening binary files
        driverReg.open("driverReg.dat", ios::out | ios::app | ios::binary);

        //checking if binary files exist
        if (!driverReg)
        {
            cout << "Error, could not open driver files.";
            exit(1);
        }

        //entering new driver username and password
        cout << "Please enter a username : ";
        cin.getline(DR1.driverUser, CSIZE);
        cout << "Please enter a password : ";
        cin.getline(DR1.driverPassword, CSIZE);

        

        cout << "Enter First and Last Name : ";
        cin.getline(DR1.fullName, CSIZE);
        cout << "Enter Pronouns E.G (He,Him or She,Her) : ";
        cin.getline(DR1.pronouns, CSIZE);
        cout << "Enter Date of Birth : ";
        cin.getline(DR1.dob, CSIZE);
        cout << "Enter Nationality : ";
        cin.getline(DR1.nationality, CSIZE);
        cout << "Enter License Number : ";
        cin.getline(DR1.licenseNum, CSIZE);
        cout << "Enter Licence Date of Expiry : ";
        cin.getline(DR1.dateofExp, CSIZE);
        cout << "Enter Years of Driving Experience : ";
        cin.getline(DR1.driverXP, CSIZE);
        cout << "Enter Contact Number : ";
        cin.getline(DR1.contactNo, CSIZE);
        cout << "Enter Email : ";
        cin.getline(DR1.email, CSIZE);
        cout << "Enter Home Address : ";
        cin.getline(DR1.homeAdd, CSIZE);
        cout << "Enter Bank Account Number : ";
        cin.getline(DR1.bankAccNo, CSIZE);
        cout << "Enter Bank Name : ";
        cin.getline(DR1.bankName, CSIZE);
        cout << "Enter Vehicle Rego : ";
        cin.getline(DR1.vehicleRego, CSIZE);
        cout << "Enter Warrent Of Fitness : ";
        cin.getline(DR1.vehicleModel, CSIZE);
        cout << "Enter Vehicle Capacity : ";
        cin >> DR1.vehicleCap;


        //assign driver id
        //have a confirmation on account details and chance to edit information maybe?

        driverReg.write(reinterpret_cast<char*>(&driverReg), sizeof(driverReg));
    }
    else {
        cout << "Exiting Driver Signup...\n";
    }
    
}

void printLine()
{
    cout << "\n";

    for (int i = 0; i < 30; i++)
    {
        cout << "~~";
    }

    cout << "\n";
}
