// trpPayment.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Created by Logan and Sherwin.
// Version : 1.
// start date : 08/06/2021
//current date : 01/07/2021
#include<algorithm>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <limits>
#include <ctime>
using namespace std;


//Global Const
const int CSIZE = 51;

//Global Variable
long driverAccPosition = 0;
long customerAccPosition = 0;

// struct declaration

struct DriverReg
{
    char driverUser[CSIZE];
    char driverPassword[CSIZE];
    char firstName[CSIZE];
    char lastName[CSIZE];
    char pronouns[CSIZE];
    int age;
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
    bool driverStatus;

    DriverReg(bool stat = true)
    {
        driverStatus = stat;
    }
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
    int custZone;
    int custID;
};

struct Booking 
{
    int tripNo;//id for booking
    int custID;//foreign id for customer
    int driverID;//foreign id for driver
    char startDestination[CSIZE];
    char endDestination[CSIZE];
    char bookingDateTime[CSIZE];
    char specialReqs[CSIZE];
    int luggage;
    int numberPassengers;
    char cancelBooking[CSIZE];
    bool paymentStatus;
    double totalPrice;
    bool tripAccept;

    Booking(bool stat = false)
    {
        paymentStatus = stat;
        tripAccept = stat;
    }
};

bool tripPayment(fstream& bookingInfo, fstream& customerReg);
Booking BK;
CustomerReg CR;
bool paid;

fstream bookingInfo, customerReg;

int main()
{
    tripPayment(bookingInfo, customerReg);
}

bool tripPayment(fstream& bookingInfo, fstream& customerReg)
{
    char choice;
    char passwordConfirm[CSIZE];
    char payChoice;

    if (BK.tripAccept = true)
    {
        cout << "Would you like to complete your booking? (Y/N) ";
        cin >> choice;
        while (toupper(choice) == 'Y')
        {
            cout << "Please confirm your password: ";
            cin >> passwordConfirm;

            if (strcmp(passwordConfirm, CR.custPassword) == 0)
            {
                cout << "Would you like to use " << CR.custPayment << "? (Y/N)";
                cin >> payChoice;

                if (toupper(payChoice) == 'Y')
                {
                    cout << "Payment Complete!";
                    cout << "\nReturning to customer menu.";
                    paid = true;
                }
                else if (toupper(payChoice) == 'N')
                {
                    cout << "Cancelling payment, returning to booking menu.";
                    paid = false;
                    //bookTrip(bookingInfo, customerReg);
                }
                else
                {
                    cout << "Please choose a valid payment method.";
                }
            }
            else if (strcmp(passwordConfirm, CR.custPassword) != 0)
            {
                cout << "Incorrect password.";
                system("CLS");
            }
        }
    }
    else if (BK.tripAccept = false)
    {
        paid = false;
        //customerMenu();
    }

    return paid;
}