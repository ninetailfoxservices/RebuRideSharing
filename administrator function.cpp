// administrator function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const int SIZE = 51;

struct Admin
{
    char adminLogin[SIZE];
    char adminPassword[SIZE];
};

// function prototypes
void printLine();
//void adminMenu();

int main()
{
    int attempts = 0;
    char choice;
    fstream handle;
    Admin a;

    printLine();

    cout << "\t\tAdministrator login" << endl;

    printLine();

    cout << "Would you like to create an Administrator login? (Y/N) ";
    cin >> choice;

    if (choice == 'y' || choice == 'y')
    {
        fstream input;
        handle.open("admin.dat", ios::out | ios::app | ios::binary); // opening the file

        if (!handle)
        {
            cout << "ERROR. File not found. Aborting";
        }
        else
        {
            do // do while loop to write info to file
            {
                cout << "\tAdmin Information" << endl;
                cout << "\nAdmin USername: ";
                cin.getline(a.adminLogin, SIZE);
                cin.ignore();
                cout << "\nAdmin Password: ";
                cin.getline(a.adminPassword, SIZE);
                cin.ignore();

                handle.write(reinterpret_cast<char*>(&a), sizeof(a));

                cout << "\n\nWould you like to create another admin login? (Y/N) ";
                cin >> choice;
                
            } while (choice == 'y' || choice == 'Y');
        }
        handle.close();
    }
    else
    {
        char adName[SIZE];
        char adPass[SIZE];
        handle.open("admin.dat", ios::in | ios::binary);
        if (!handle)
        {
            cout << "Error, could not find admin login data." << endl;
        }
        else
        {
            cout << "Enter admin username: ";
            cin.getline(adName, SIZE);
            cin.ignore();
            cout << "Enter admin password: ";
            cin.getline(adPass, SIZE);
            cin.ignore();

            handle.read(reinterpret_cast<char*>(&a), sizeof(a));
            while (!handle.eof())
            {
                if (attempts <= 3)
                {
                    if (strcmp(adName, a.adminLogin) == 1 && strcmp(adPass, a.adminPassword) == 0)
                    {
                        cout << "Please enter a valid username.";
                    }
                    else if (strcmp(adName, a.adminLogin) == 1 && strcmp(adPass, a.adminPassword) == 0 && attempts == 3)
                    {
                        cout << "You entered the wrong information too many times. Please try again in 3 minutes.";
                    }
                    else if (strcmp(adName, a.adminLogin) == 0 && strcmp(adPass, a.adminPassword) == 1)
                    {
                        cout << "Please enter a valid password.";
                    }
                    else if (strcmp(adName, a.adminLogin) == 0 && strcmp(adPass, a.adminPassword) == 1 && attempts == 3)
                    {
                        cout << "Sorry, you enter the wrong info too many times. Please try again in 3 minutes.";
                    }
                }

                if (strcmp(adName, a.adminLogin) == 0 && strcmp(adPass, a.adminPassword) == 0)
                {
                    cout << "\nWelcome to admin menu";
                    printLine();
                    //adminMenu();
                }
            }
        }
        handle.close();
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