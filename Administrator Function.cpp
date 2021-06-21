// admin function

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

using namespace std;

const int SIZE = 51;

struct Admin
{
    char adminLogin[SIZE];
    char adminPassword[SIZE];
};

// function prototypes
void adminLogin();
void adminMenu();
void printLine();
//void adminMenu();

int main()
{
    system("CLS");
    int choice;
    cout << "Would you like to: \n1. Login as admin. \n2. Exit. \n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        adminMenu();
        break;
    case 2:
        cout << "Returning to menu.";
        exit(0);
    default:
        cout << "Please select an option from the menu.";
    }

    return 0;
}

void adminMenu()
{
    int choice;

    adminLogin();

    cout << "\tAdmin Menu.";
    cout << "\n1. Driver register \n2. Customer register \n3. Daily Report \n4. Weekly report \n5. Cancelled bookings \n6. Return to main menu\n";
    cout << "Please choose an option from the menu: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        // driverReg();
        break;
    case 2:
        // customerReg();
        break;
    case 3:
        // dailyReport();
        break;
    case 4:
        // weeklyReport();
        break;
    case 5:
        // cancelledBookings();
        break;
    case 6:
        cout << "Exiting to main menu.";
        main();
        break;
    default:
        cout << "Please enter an option from the menu.";
    }

    return;
}

void adminLogin()
{
    Admin a;
    string adminUser, adminPass;
    int attempts = 1;

    while (attempts < 4)
    {
        cout << "Enter username: ";
        cin >> adminUser;
        cin.ignore();
        cout << "Enter password: ";
        cin >> adminPass;

        if (adminUser != "Admin" || adminPass != "Password123" && attempts < 3)
        {
            cout << "Please enter correct login information.\n";
        }
        else if (adminUser != "Admin" || adminPass != "Password123" && attempts == 3)
        {
            cout << "You entered the wrong information too many times. Please try again later.\n";
            main();
        }
        else if (adminUser == "Admin" && adminPass == "Password123")
        {
            cout << "Welcome.\n";
            return;
        }
        attempts++;
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