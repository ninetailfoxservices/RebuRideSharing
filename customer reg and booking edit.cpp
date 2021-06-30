// customer reg and booking edit.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    int custZones;
    char custPayment[CSIZE];
};

struct Booking {
    int tripNo;
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

void newCustomer(fstream& customerReg);
void existingCustomer(fstream& customerReg);
bool customerLogin(fstream& customerReg);
void customerMenu(fstream& customerReg);
void bookTrip(fstream& bookingInfo, fstream& customerReg);
void tripPayment(fstream& bookingInfo, fstream& customerReg);
void printLine();

fstream customerReg;
CustomerReg CR;
fstream bookingInfo;
Booking book;
int customerAccPosition = 0;

int main()
{
    int choice;
    cout << "1. new customer \n2.existing driver \n3. exit";
    cin >> choice;

    switch (choice)
    {
    case 1:
        newCustomer(customerReg);
        break;
    case 2:
        existingCustomer(customerReg);
        break;
    case 3:
        exit(0);
    default:
        cout << "Please choose and option from the menu.";
    }
}

void newCustomer(fstream& customerReg)
{
    char input;
    CustomerReg CR1;

    cout << "Would you like to make a new customer account? (Y/N) ";
    cin >> input;

    if (toupper(input) == 'Y')
    {
        customerReg.open("customerReg.dat", ios::out | ios::app | ios::binary);

        if (!customerReg)
        {
            cout << "Error, file not found.";
            exit(1);
        }

        cin.ignore();
        cout << "Please enter a new username: ";
        cin.getline(CR1.custUser, CSIZE);
        cout << "Please enter a new password: ";
        cin.getline(CR1.custPassword, CSIZE);

        cout << "\n";
        cout << "\tTravel Zone Information";
        cout << "Zone 1: within Christchurch. \nZone 2: Prebbleton, Belfast, Sumner, Kaiapoi. \nZone 3: Rolleston, Rangiora, Remaining of Banks Peninsula.";
        cout << "\n";

        cout << "Enter first name: ";
        cin.getline(CR1.firstName, CSIZE);
        cout << "Enter last name: ";
        cin.getline(CR1.lastName, CSIZE);
        cout << "Enter contact phone number: ";
        cin.getline(CR1.custContactNo, CSIZE);
        cout << "Enter email: ";
        cin.getline(CR1.custEmail, CSIZE);
        cout << "Enter street address: ";
        cin.getline(CR1.custAdd, CSIZE);
        cout << "Enter zone number: ";
        cin >> CR1.custZones;
        cout << "Enter preferred payment method: ";
        cin.getline(CR1.custPayment, CSIZE);

        customerReg.write(reinterpret_cast<char*>(&CR1), sizeof(CR1));
        customerReg.close();
    }
    else
    {
        cout << "Exiting customer signup...\n";
    }
}

void existingCustomer(fstream& customerReg)
{
    CustomerReg CR2;

    //have a login form, have 3 tries, if correct then go to menu if fail then print error and return to main menu
    int attempt = 3;
    bool accountFound = false;
    while (accountFound == false)
    {
        accountFound = customerLogin(customerReg);


        if (accountFound == true)
        {
            customerMenu(customerReg);
        }
        else {
            attempt--;
            cout << "\nYou have " << attempt << " attempts left...\n";

        }
        if (attempt == 0)
        {
            break;
        }
    }
}

bool customerLogin(fstream& customerReg)
{
    CustomerReg CR2;

    char user[CSIZE];
    char pass[CSIZE];
    bool flag = false;

    customerReg.open("customerReg.dat", ios::in | ios::binary);
    if (!customerReg)
    {
        cout << "Error, file not found";
        exit(1);
    }

    cout << "Enter username: ";
    cin.getline(user, CSIZE);
    cout << "Enter password: ";
    cin.getline(pass, CSIZE);

    customerReg.read(reinterpret_cast<char*>(&CR2), sizeof(CR2));

    while (!customerReg.eof())
    {
        if ((strcmp(user, CR2.custUser) == 0) && (strcmp(pass, CR2.custPassword) == 0))
        {
            flag = true;
            customerAccPosition = customerReg.tellp();
        }
        customerReg.read(reinterpret_cast<char*>(&CR2), sizeof(CR2));
    }
    if (flag == false)
    {
        cout << "\nLogin Failed.\n";
    }
    customerReg.close();
    return flag;
}

void customerMenu(fstream& customerReg)
{
    CustomerReg CR2;

    int choice = 0;
    bool flag = false;

    customerReg.open("customerReg.dat", ios::in | ios::binary);
    if (!customerReg)
    {
        cout << "Error, file not found";
        exit(1);
    }

    customerReg.seekg(customerAccPosition - sizeof(CR), ios::beg);
    customerReg.read(reinterpret_cast<char*>(&CR2), sizeof(CR2));
    while (true)
    {
        printLine();
        cout << "Welcome to the customer menu" << endl;
        cout << "Customer Name: " << CR2.firstName << " " << CR2.lastName << endl;
        cout << "Address: " << CR2.custAdd << endl;
        cout << "Username: " << CR2.custUser << endl;
        cout << "Password: " << CR2.custPassword << endl;
        printLine();

        cout << "\tCustomer Menu";
        printLine();
        cout << "1. Book a Trip \n2. Payments \n3. Cancel a Trip \n4. Exit";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bookTrip(bookingInfo, customerReg);
            break;
        case 2:
            // viewPayment(customerReg);
            break;
        case 3:
            // cancelTrip(customerReg);
            break;
        case 4:
            cout << "Exiting to main menu...";
            main();
        default:
            cout << "Please choose an option from the menu.";
            break;
        }
    }
    flag = true;
    customerReg.read(reinterpret_cast<char*>(&CR2), sizeof(CR2));

    if (flag == false)
    {
        cout << "\n\nLogin Failed\n";
        cin.get();
    }
    customerReg.close();
}

void bookTrip(fstream& bookingInfo, fstream& customerReg)
{
    // variables
    CustomerReg CR2;
    int z1 = 1, z2 = 2, z3 = 3, zoneStart, zoneEnd; // zone variables for destination.
    int choice;

    cout << "\tTravel Zone Information";
    cout << "Zone 1: within Christchurch. \nZone 2: Prebbleton, Belfast, Sumner, Kaiapoi. \nZone 3: Rolleston, Rangiora, Remaining of Banks Peninsula.";

    bookingInfo.open("bookingInfo.dat", ios::out | ios::app | ios::binary);
    if (!bookingInfo)
    {
        cout << "Error, file not found.";
        exit(1);
    }

    customerReg.open("customerReg.dat", ios::in | ios::binary);
    if (!customerReg)
    {
        cout << "Error, file not found.";
        exit(1);
    }

    cout << "\tBook a trip";
    cout << "Enter starting destination: ";
    cin.getline(book.startDestination, CSIZE);
    cout << "Enter starting location zone number: ";
    cin >> zoneStart;
    cout << "Enter destination: ";
    cin.getline(book.endDestination, CSIZE);
    cout << "Enter destination zone number: ";
    cin >> zoneEnd;

    if (strcmp(book.startDestination, CR2.custAdd) == 0)
    {
        if (CR2.custZones == z1 || zoneStart == z1)
        {
            if (zoneEnd == z1)
            {
                cout << "Cost: $30";
            }
            else if (zoneEnd == z2)
            {
                cout << "Cost: $40";
            }
            else if (zoneEnd == z3)
            {
                cout << "Cost: $70";
            }
        }
        else if (CR2.custZones == z2 || zoneStart == z2)
        {
            if (zoneEnd == z1)
            {
                cout << "Cost: $40";
            }
            else if (zoneEnd == z2)
            {
                cout << "Cost: $50";
            }
            else if (zoneEnd == z3)
            {
                cout << "Cost: $60";
            }
        }
        else if (CR2.custZones == z3 || zoneStart == z3)
        {
            if (zoneEnd == z1)
            {
                cout << "Cost: $70";
            }
            else if (zoneEnd == z2)
            {
                cout << "Cost: $60";
            }
            else if (zoneEnd == z3)
            {
                cout << "Cost: $50";
            }
        }
        tripPayment(bookingInfo, customerReg);
    }
    else if (strcmp(book.startDestination, CR2.custAdd) != 0)
    {
        if (zoneStart == z1)
        {
            if (zoneEnd == z1)
            {
                cout << "Cost: $30";
            }
            else if (zoneEnd == z2)
            {
                cout << "Cost: $40";
            }
            else if (zoneEnd == z3)
            {
                cout << "Cost: $70";
            }
        }
        else if (zoneStart == z2)
        {
            if (zoneEnd == z1)
            {
                cout << "Cost: $40";
            }
            else if (zoneEnd == z2)
            {
                cout << "Cost: $50";
            }
            else if (zoneEnd == z3)
            {
                cout << "Cost: $60";
            }
        }
        else if (zoneStart == z3)
        {
            if (zoneEnd == z1)
            {
                cout << "Cost: $70";
            }
            else if (zoneEnd == z2)
            {
                cout << "Cost: $60";
            }
            else if (zoneEnd == z3)
            {
                cout << "Cost: $50";
            }
        }
        tripPayment(bookingInfo, customerReg);
    }
}

void tripPayment(fstream& bookingInfo, fstream& customerReg)
{

}

void printLine()
{
    cout << "\n";
    for (int i = 0; i < 30; i++)
    {
        cout << "~~";
    }
    cout << "\n\n";
}