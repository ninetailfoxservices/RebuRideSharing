// Rebu.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Created by Logan and Sherwin.
// Version: 0.1
// start date: 08/06/2021

#include <time.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <limits>
#include <conio.h>
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
    int driverID;
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
void existingDriver(fstream &driverReg);
//void administrator();
//void newCustomer();
//void existingCustomer();
//void bookTrip(fstream &bookingInfo);
void printLine();
//prototyping functions Level 2
//void dailyTripReport();
//void availableTrips();
//void viewPayment();
//void cancelTrip();

int main()
{
    //seed rand function
    srand(time(nullptr));
    //local variable
    int input = 0;

    //struct variables
//    DriverReg DR;
 //   CustomerReg CR;
 //   Booking Book;

    //creating file object and open file handles
    fstream driverReg;
  //  fstream customerReg;
 //   fstream bookingInfo;
    
    while (true)
    {
        system("CLS");
        printLine();

        cout << "\t\nWelcome to Rebu Ride Sharing!\n";

        printLine();

        cout << "\n\tMenu.\n1. Register as a Driver\n2. Driver Login\n3. New Customer\n4. Customer Login\n5. Administrator\n6. Book a Trip\n7. Exit\n";

        printLine();

        cout << "Enter Option Number : ";
        //checking if user entered char instaed of int
        while (true)
        {
            cin >> input;
            if (!cin)
            {
                cout << "Please select an option on the list : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            else {
                break;
            }
        }
        cin.ignore();
        switch (input)
        {
        case 1:
            newDriver(driverReg);
            break;
        case 2:
            existingDriver(driverReg);
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
            cout << "\nPlease select an option on the list...";
            cin.get();
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
        cin.ignore();
        cout << "Please enter a username : ";
        cin.getline(DR1.driverUser, CSIZE);
        cout << "Please enter a password : ";
        cin.getline(DR1.driverPassword, CSIZE);

        
        //entering driver details
        //assign driver id
        DR1.driverID = rand() % 1000 + 100;
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

        //checking for numeric value... input validation
        while (true)
        {
            cin >> DR1.vehicleCap;
            if (!cin)
            {
                cout << "Please enter an interger for Vehicle Capacity" << endl;
                cout << "Enter Vehicle Capacity : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            else {
                break;
            }
        }
        
        //have a confirmation on account details and chance to edit information maybe?

        driverReg.write(reinterpret_cast<char*>(&DR1), sizeof(DR1));
        driverReg.close();
    }
    else {
        cout << "Exiting Driver Signup...\n";
    }
    
}

void existingDriver(fstream& driverReg)
{
    //have a login form, have 3 tries, if correct then go to menu if fail then print error and return to main menu

    //Buffer used for reading
    DriverReg DR2;

    //local variables
    int input = 0;
    //used in strcmp function to compare variables
    
    char user[CSIZE];
    char pass[CSIZE];
    //check if there is a user and pass match
    bool flag = false;

    //opening file for reading
    driverReg.open("driverReg.dat", ios::in | ios::binary);
    //filer error check
    if (!driverReg)
    {
        cout << "Error, could not open driver files.";
        exit(1);
    }

    
    //getting username and password
    cout << "Enter Username : ";
    cin.getline(user, CSIZE);
    cout << "Enter Password : ";
    cin.getline(pass, CSIZE);
    driverReg.read(reinterpret_cast<char*>(&DR2), sizeof(DR2));

    while (!driverReg.eof())
    {
        if ((strcmp(user, DR2.driverUser) == 0) && (strcmp(pass, DR2.driverPassword) == 0))
        {
            //driver menu
            while (true)
            {
                system("CLS");
                printLine();
                cout << "\nCongratulations! this is driver menu\n";
                cout << "\nDriver ID : " << DR2.driverID;
                cout << "\nfisrt Name : " << DR2.fullName;
                cout << "\nDate Of Birth : " << DR2.dob;
                printLine();

                cout << "\n\tDriver Menu.\n1. Daily Trip Report\n2. Available Trips\n3. View Payments\n4. Cancel Trip\n5. Exit\n";

                printLine();

                cout << "Enter Option Number : ";
                //checking if user entered char instaed of int
                while (true)
                {
                    cin >> input;
                    if (!cin)
                    {
                        cout << "Please select an option on the list : ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    else {
                        break;
                    }
                }
                cin.ignore();
                

                switch (input)
                {
                case 1:
                 //   dailyTripReport();
                    break;
                case 2:
                 //   availableTrips();
                case 3:
                 //   viewPayment();
                    break;
                case 4:
                 //   cancelTrip();
                    break;
                case 5:
                    cout << "Returning to Main Menu...";
                    cin.get();
                    main();
                default:
                    cout << "\nPlease select an option on the list...";
                    cin.get();
                    break;
                }
                flag = true;
            }
            
        }
        driverReg.read(reinterpret_cast<char*>(&DR2), sizeof(DR2));
    }
    if (flag == false)
    {
        cout << "\n\n Login failed\n";
        cin.get();
    }
    driverReg.close();
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
