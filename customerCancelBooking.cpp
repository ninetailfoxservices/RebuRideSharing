//  : This file contains the 'main' function. Program execution begins and ends there.
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

void cancelTrip(fstream& bookingInfo, fstream& customerReg);
CustomerReg CR;
Booking BK;

fstream bookingInfo, customerReg;

int main()
{
    cancelTrip(bookingInfo, customerReg);
}

void cancelTrip(fstream& bookingInfo, fstream& customerReg)
{
    // calling variables
    char choice;
    char passwordConfirm[CSIZE];
    int tripNoCheck;
    bool cancel = false;

    // checking for cancellation
    cout << "Would you like to cancel a booking? (Y/N) ";
    cin >> choice;

    if (toupper(choice) == 'Y')
    {
        //opening customer binary file
        customerReg.open("customerReg.dat", ios::out | ios::app | ios::binary);
        if(!customerReg)
        {
            cout << "Error, file not found.";
        }
        //opening booking binary file
        bookingInfo.open("bookingInfo.dat", ios::out | ios::app | ios::binary);
        if(!bookingInfo)
        {
            cout << "Error, file not found.";
        }

        cout << "Enter booking number for the trip you wish to cancel: ";
        cin >> tripNoCheck;

        //while loop for checking the 
        while (cancel = false)
        {
            if (tripNoCheck == BK.tripNo)
            {
                cout << "Enter password to confirm cancellation: ";
                cin >> passwordConfirm[CSIZE];

                    if(strcmp(passwordConfirm, CR.custPassword) == 0)
                    {
                        cout << "Booking cancelled, returning to booking menu.";
                        cancel = true;
                        // bookingTrip(bookingInfo, customerReg);
                    }
                    else if(strcmp(passwordConfirm, CR.custPassword) != 0)
                    {
                        cout << "Please enter correct password";
                    }
            }
        }

        customerReg.close();
        bookingInfo.close();
    }
    // returning no answer to booking function
    else if (toupper(choice) == 'N')
    {
        cout << "Returning to booking menu.";
        //bookingTrip(bookingInfo, customerReg);
    }
}