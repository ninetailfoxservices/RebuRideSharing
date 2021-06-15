// administrator function.cpp : This file contains the 'main' function. Program execution begins and ends there.
// version 0.1
// created by Logan

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

const int CSIZE = 51;

struct Admin
{
    char adminLogin[CSIZE];
    char adminPassword[CSIZE];
};

// function prototypes
void printLine();
void adminMenu(fstream&);

int main()
{
    // initialising variables
    int attempts = 0;
    char choice;
    fstream handle;
    Admin a;

    printLine();

    cout << "\t\tAdministrator login" << endl;

    printLine();

    cout << "Would you like to create an Administrator login? (Y/N) ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') // if for checking if wanting to make new login
    {
        fstream input;
        handle.open("admin.dat", ios::out | ios::app | ios::binary); // opening the file

        if (!handle) // checking for file
        {
            cout << "ERROR. File not found. Aborting";
        }
        else // adding information to file
        {   
            do
            {
                cout << "\tAdmin Information" << endl;
                cout << "\nAdmin Username: ";
                cin.getline(a.adminLogin, CSIZE);
                cin.ignore();
                cout << "\nAdmin Password: ";
                cin.getline(a.adminPassword, CSIZE);
                cin.ignore();

                handle.write(reinterpret_cast<char*>(&a), sizeof(a));

                cout << "\nWould you like to add another admin login? (Y/N) ";
                cin >> choice;
                cin.ignore();
            } while (choice == 'y' || choice == 'Y');
        }
        handle.close();
    }
    else if (choice == 'n' || choice == 'N') // opening the file and logging in admin
    {
        char adName[CSIZE];
        char adPass[CSIZE];
        handle.open("admin.dat", ios::in | ios::binary);
        if (!handle) // checking for login information
        {
            cout << "Error, could not find admin login data." << endl;
        }
        else // else for logging in admin
        {
            cout << "Enter admin username: ";
            cin.getline(adName, CSIZE);
            cin.ignore();
            cout << "Enter admin password: ";
            cin.getline(adPass, CSIZE);
            cin.ignore();

            handle.read(reinterpret_cast<char*>(&a), sizeof(a));
            while (!handle.eof()) // checking for proper login information
            {     
                while (attempts <= 3)
                {
                    if ((strcmp(adName, a.adminLogin) != 0) && (strcmp(adPass, a.adminPassword) == 0))
                    {
                        cout << "Please enter a valid username.";
                        attempts + 1;
                    }
                    else if ((strcmp(adName, a.adminLogin) == 0) && (strcmp(adPass, a.adminPassword) != 0))
                    {
                        cout << "Please enter a valid password.";
                        attempts + 1;
                    }
                    else if ((strcmp(adName, a.adminLogin) == 0) && (strcmp(adPass, a.adminPassword) == 0))
                    {
                        adminMenu(handle);
                    }
                }

                
            }
        }
        handle.close();
    }
}

void adminMenu(fstream& handle)
{
    int choice;
    int n;

    printLine();
    cout << "\tWelcome to admin menu";
    printLine();

    cout << "\tOptions" << endl;
    cout << "1. Weekly reports" << endl;
    cout << "2. Daily reports" << endl;
    cout << "3. Registered drivers" << endl;
    cout << "4. Registered customers" << endl;
    cout << "5. Cancelled bookings" << endl;
    cout << "6. Exit admin menu" << endl;
    cout << "What would you like to check? ";
    cin >> choice;
    cin.ignore();

    printLine();

    while (true)
    {
        cin >> choice;
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
    switch (choice)
    {
    case 1:
        //weeklyReports();
        break;
    case 2:
        // dailyReports();
        break;
    case 3:
        //existingDriver(driverReg);
        break;
    case 4:
        //  existingCustomer(customerReg);
        break;
    case 5:
        //  bookTrip(bookingInfo);
        break;
    case 6:
        cout << "Exiting Program...";
        exit(0);
    default:
        cout << "\nPlease select an option on the list...";
        cin.get();
        break;
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