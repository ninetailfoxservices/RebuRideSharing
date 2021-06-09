// Rebu.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Created by Logan and Sherwin.
// Version: 0.1
// start date: 08/06/2021

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// struct initialising
struct DriverLogin
{
    string driverUser;
    string driverPassword;
};

struct DriverReg
{
    string fullName;
    string pronouns;
    string dob;
    string nationality;
    string licenseNum;
    string dateofExp;
    string driverXP;
    string contactNo;
    string email;
    string homeAdd;
    string bankAccNo;
    string bankName;
    string vehicleRego;
    string WOF;
    string vehicleModel;
    string driverID;
    struct DriverLogin driver;
};

struct CustomerLogin
{
    string custUser;
    string custPassword;
};

struct CustomerReg
{
    string custName;
    string custContactNo;
    string custEmail;
    string custAdd;
    string custPayment;
    struct CustomerLogin customer;
};

struct Booking{
    string tripNo;
    string startDestination;
    string endDestination;
    string bookingDate;
    string bookingTime;
    string noPassengers;
    string specialReqs;
    string luggage;
    string paymentStatus;
    string cancelBooking;
};

int newDriver(int answer);
int existingDriver(int answer);
int administrator(int answer);
int newCustomer(int answer);
int existingCustomer(int answer);
int bookTrip(int answer);
void printLine();
int menu(int answer);

DriverLogin d1;
DriverReg d2;
CustomerLogin c1;
CustomerReg c2;
Booking b;

int main()
{
    int answer = 0;
    
    printLine();
    
    cout << "\tWelcome to Rebu Ride Sharing!\n";
    
    printLine();

    cout << "\tMenu.\n1. Register as a Driver\n2. Driver Login\n3. New Customer\n4. Customer Login\n5. Administrator\n6. Book a Trip";
    
    printLine();

    cout << "Enter Option Number: ";
    cin >> answer;

    menu(answer);

    return 0;
}

int menu(int answer)
{
    int attempts = 0;
    while (answer <= 0 || answer > 6)
    {
        switch (answer)
        {
        case 1:
            newDriver(answer);
            break;
        case 2:
            existingDriver(answer);
            break;
        case 3:
            newCustomer(answer);
            break;
        case 4:
            existingCustomer(answer);
            break;
        case 5:
            administrator(answer);
            break;
        case 6:
            bookTrip(answer);
            break;
        default:
            cout << "Please select an option on the list: ";
            attempts++;
        }
    }

    return answer;
}

int newDriver(int answer)
{
    fstream input;
    input.open("driverLogin.dat", ios::out | ios::binary);

    if (!input)
    {
        cout << "Error, could open driver login information.";
        return 1;
    }

    cout << "Please enter a username: " << endl;
    getline(cin, d1.driverUser);
    cout << "Please enter a password: " << endl;
    getline(cin, d1.driverPassword);
    
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
