// Rebu.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Created by Logan and Sherwin.
// Version : 1.4
// start date : 08/06/2021
//current date : 01/07/2021
#include<algorithm>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <limits>
#include <conio.h>
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

struct Booking {
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

    Booking(bool stat = false)
    {
        paymentStatus = stat;
    }
};
//*************************************


//prototyping functions Level 1 - For Main Menu
void newDriver(fstream& driverReg);
void existingDriver(fstream& driverReg);
void adminMenu(fstream& driverReg, fstream& customerReg, fstream& bookingInfo);
void newCustomer(fstream& customerReg);
void existingCustomer(fstream& customerReg, fstream& bookingInfo);
//void bookTrip(fstream &bookingInfo);
void printLine();

//function for Administrator
void adminLogin();

//Functions for Driver
int getUniqueDriverID();//unique id for drivers
bool driverLogin(fstream& driverReg);
void driverMenu(fstream& driverReg);

//Function for Customers
int getUniqueCustID();//unique id for customer
bool customerLogin(fstream& customerReg);
void customerMenu(fstream& customerReg, fstream& bookInfo);

//Function for Booking
int getUniqueBookingID();

//prototyping functions Level 2 - For Driver Menu
//void dailyTripReport();
//void availableTrips();
//void viewPayment();
//void cancelTrip();

//prototyping functions Level 2 - For Customer Menu
void bookingTrip(fstream& bookingInfo, fstream& customerReg);
//void tripPayment(fstream& bookingInfo, fstream& customerReg);

//prototyping functions Level 2 - For Admin Menu

int main()
{
    //seed rand function
    srand(time(nullptr));
    //local variable
    int choice = 0;

    //struct variables
//    DriverReg DR;
 //   CustomerReg CR;
 //   Booking Book;

    //creating file object and open file handles
    fstream driverReg;
    fstream customerReg;
    fstream bookingInfo;

    while (true)
    {
        system("CLS");
        printLine();

        cout << "\t\nWelcome to Rebu Ride Sharing!\n";

        printLine();

        cout << "\n\tMenu.\n1. Register as a Driver\n2. Driver Login\n3. New Customer\n4. Customer Login\n5. Administrator\n6. Exit\n";

        printLine();

        cout << "Enter Option Number : ";
        //checking if user entered char instaed of int
        while (true)
        {
            cin >> choice;
            if (!cin)
            {
                cout << "\n[Please select an option on the list]\n";
                cout << "Enter Option Number : ";
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
            newDriver(driverReg);
            break;
        case 2:
            existingDriver(driverReg);
            break;
        case 3:
            newCustomer(customerReg);
            break;
        case 4:
            existingCustomer(customerReg, bookingInfo);
            break;
        case 5:
            adminMenu(driverReg, customerReg, bookingInfo);
            break;
        case 6:
            cout << "[Exiting Program...]";
            exit(0);
        default:
            cout << "\n[Please select an option on the list...]";
            cin.get();
            break;
        }
    }
    return 0;
}

//General Aesthetic Functions
void printLine()
{
    cout << "\n";

    for (int i = 0; i < 30; i++)
    {
        cout << "~~";
    }

    cout << "\n";
}

//Driver Functions**************************

void newDriver(fstream& driverReg)
{
    //local variable
    char input;

    //local temp varialbes for input checks
    char answer = ' ';
    int tempVehicleModel;
    int tempDriverAge;
    //Structures
    DriverReg DR;

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
        cin.getline(DR.driverUser, CSIZE);
        cout << "Please enter a password : ";
        cin.getline(DR.driverPassword, CSIZE);


        //entering driver details

        cout << "Enter First Name : ";
        cin.getline(DR.firstName, CSIZE);

        cout << "Enter Last Name : ";
        cin.getline(DR.lastName, CSIZE);

        cout << "Enter Pronouns E.G (He,Him or She,Her) : ";
        cin.getline(DR.pronouns, CSIZE);

        cout << "Enter Age : ";
        //checking for numeric value... input validation
        while (true)
        {
            cin >> tempDriverAge;
            if (!cin)
            {
                cout << "\n[Please enter an interger for Driver Age]" << endl;
                cout << "Enter Age : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            else {
                break;
            }
        }

        if (tempDriverAge >= 21)
        {
            DR.age = tempDriverAge;
        }
        else {
            cin.ignore();
            cout << "\n[Uneligeble to be a driver. Driver Age must be above 21 years old.]\n";
            cin.get();
            main();
        }
        cin.ignore();
        cout << "Enter Nationality : ";
        cin.getline(DR.nationality, CSIZE);

        cout << "Enter License Number : ";
        cin.getline(DR.licenseNum, CSIZE);

        cout << "Enter Licence Date of Expiry : ";
        cin.getline(DR.dateofExp, CSIZE);

        cout << "Do you have a Full Drivers License? (y/n) : ";
        cin >> answer;
        while (!(answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N'))
        {
            if (answer == 'Y' || answer == 'y')
            {
                break;
            }
            else if (answer == 'N' || answer == 'n')
            {
                cin.ignore();
                cout << "\n[Uneligible to be a driver. Required FULL License.]\n";
                cin.get();
                main();
            }
            else {
                cout << "\nPlease enter 'Y' for yes or 'N' for no : ";
                cin >> answer;
            }
        }

        cin.ignore();
        cout << "Enter Contact Number : ";
        cin.getline(DR.contactNo, CSIZE);

        cout << "Enter Email : ";
        cin.getline(DR.email, CSIZE);

        cout << "Enter Home Address : ";
        cin.getline(DR.homeAdd, CSIZE);

        cout << "Enter Bank Account Number : ";
        cin.getline(DR.bankAccNo, CSIZE);

        cout << "Enter Bank Name : ";
        cin.getline(DR.bankName, CSIZE);

        cout << "Enter Vehicle Rego : ";
        cin.getline(DR.vehicleRego, CSIZE);

        cout << "Enter Year of Vehicle Model was manufactured E.G. \"2016\" (Must be within the last 10 years) : ";
        //checking for numeric value... input validation
        while (true)
        {
            cin >> tempVehicleModel;
            if (!cin)
            {
                cout << "\n[Please enter an interger for Vehicle Model Year]" << endl;
                cout << "Enter Year of Vehicle Model was manufactured E.G. \"2016\" (Must be within the last 10 years) : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            else {
                break;
            }
        }
        if (tempVehicleModel <= 2021 && tempVehicleModel >= 2011)
        {
            *DR.vehicleModel = tempVehicleModel;
        }
        else {
            cin.ignore();
            cout << "\n[Uneligible to be a Driver. Vehicle model needs to be within the specified date range.]\n";
            cin.get();
            main();
        }
        cout << "Enter Vehicle Capacity : ";
        //checking for numeric value... input validation
        while (true)
        {
            cin >> DR.vehicleCap;
            if (!cin)
            {
                cout << "\n[Please enter an interger for Vehicle Capacity]" << endl;
                cout << "Enter Vehicle Capacity : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            else if (DR.vehicleCap < 2 || DR.vehicleCap > 7)
            {
                cout << "\n[vehicle must have atleast 2 seats and maximum 7 seats]\n";
                cout << "Enter Vehicle Capacity : ";
                cin.clear();
                continue;
            }
            else {
                break;
            }
        }
        //assigning driver id with function
        DR.driverID = getUniqueDriverID();

        //write input into Driver file
        driverReg.write(reinterpret_cast<char*>(&DR), sizeof(DR));
        driverReg.close();
    }
    else {
        cin.ignore();
        cout << "\n[Exiting Driver Signup...]\n";
        cin.get();
    }

}

void existingDriver(fstream& driverReg)
{
    //have a login form, have 3 tries, if correct then go to menu if fail then print error and return to main menu
    int attempt = 3;
    bool accountFound = false;
    while (accountFound == false)
    {
        accountFound = driverLogin(driverReg);


        if (accountFound == true)
        {
            driverMenu(driverReg);
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

//asigning ID - Iterating starting from 0 - Using size of binary file to iterate
int getUniqueDriverID()
{
    DriverReg DR;
    fstream driverReg;
    driverReg.open("driverReg.dat", ios::in | ios::binary);
    int i = 0;

    driverReg.read(reinterpret_cast<char*>(&DR), sizeof(DR));
    while (!driverReg.eof())
    {
        i++;
        driverReg.read(reinterpret_cast<char*>(&DR), sizeof(DR));
    }
    return i;
}

bool driverLogin(fstream& driverReg)
{
    //Buffer used for reading
    DriverReg DR;

    //local variables

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

    driverReg.read(reinterpret_cast<char*>(&DR), sizeof(DR));

    while (!driverReg.eof())
    {
        if ((strcmp(user, DR.driverUser) == 0) && (strcmp(pass, DR.driverPassword) == 0))
        {
            flag = true;
            driverAccPosition = driverReg.tellp();

        }
        driverReg.read(reinterpret_cast<char*>(&DR), sizeof(DR));
    }
    if (flag == false)
    {
        cout << "\n[Login Failed...]\n";
    }
    driverReg.close();
    return flag;
}

void driverMenu(fstream& driverReg)
{
    DriverReg DR;

    //user login tries
    int choice = 0;

    //opening file for reading
    driverReg.open("driverReg.dat", ios::in | ios::binary);
    //filer error check
    if (!driverReg)
    {
        cout << "Error, could not open driver files.";
        exit(1);
    }
    driverReg.seekg(driverAccPosition - sizeof(DR), ios::beg);
    driverReg.read(reinterpret_cast<char*>(&DR), sizeof(DR));
    //driver menu
    while (true)
    {
        system("CLS");//clear screen everytime it loops
        printLine();
        cout << "\tDriver Information";
        printLine();
        cout << "Driver Availability Status : " << DR.driverStatus << endl;
        cout << "Driver ID : " << DR.driverID << endl;
        cout << "First Name : " << DR.firstName << endl;
        cout << "Last Name : " << DR.lastName << endl;
        cout << "Age : " << DR.age << endl;
        cout << "Driver Licence : Full" << endl;
        cout << "Username : " << DR.driverUser << endl;
        cout << "Password : " << DR.driverPassword << endl;
        printLine();
        cout << "\tDriver Menu.";
        printLine();
        cout << "1. Daily Trip Report\n2. Available Trips\n3. View Payments\n4. Cancel Trip\n5. Exit\n";//Menu Display for drivers
        printLine();
        cout << "Enter Option Number : ";//user input for menu
        //checking if user entered char instaed of int
        while (true)
        {
            cin >> choice;
            if (!cin)
            {
                cout << "\n[Please select an option on the list]\n";
                cout << "Enter Option Number :";
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
            cout << "[Returning to Main Menu...]";
            cin.get();
            main();
        default:
            cout << "\n[Please select an option on the list...]";
            cin.get();
            break;
        }
    }
}
//*********************************************
//Customer Functions***************************

void newCustomer(fstream& customerReg)
{
    char input;
    CustomerReg CR;

    cout << "Would you like to make a new customer account? (Y/N) ";
    cin >> input;

    if (toupper(input) == 'Y')
    {
        customerReg.open("customerReg.dat", ios::out | ios::app | ios::binary);

        if (!customerReg)
        {
            cout << "[Error, file not found.]";
            exit(1);
        }

        cin.ignore();
        cout << "Please enter a new username : ";
        cin.getline(CR.custUser, CSIZE);
        cout << "Please enter a new password : ";
        cin.getline(CR.custPassword, CSIZE);

        cout << "Enter first name : ";
        cin.getline(CR.firstName, CSIZE);
        cout << "Enter last name : ";
        cin.getline(CR.lastName, CSIZE);
        cout << "Enter contact phone number : ";
        cin.getline(CR.custContactNo, CSIZE);
        cout << "Enter email : ";
        cin.getline(CR.custEmail, CSIZE);
        cout << "Enter what Zone you are in (Zone 1 | Zone 2 | Zone 3) : ";
        //checking for numeric value... input validation
        while (true)
        {
            cin >> CR.custZone;
            if (!cin)
            {
                cout << "[Please enter an interger for Zone]" << endl;
                cout << "\nEnter Zone (Zone [1] | Zone [2] | Zone [3]) : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            else if (CR.custZone < 1 || CR.custZone > 3)
            {
                cout << "[Please Enter within the given zone range.]" << endl;
                cout << "\nEnter Zone (Zone 1 | Zone 2 | Zone 3) : ";
                cin.clear();
                continue;
            }
            else {
                break;
            }
        }
        cout << "Enter home address : ";
        cin.getline(CR.custAdd, CSIZE);
        cout << "Enter preferred payment method : ";
        cin.getline(CR.custPayment, CSIZE);

        CR.custID = getUniqueCustID();//assigning customer unique id


        customerReg.write(reinterpret_cast<char*>(&CR), sizeof(CR));
        customerReg.close();
    }
    else
    {
        cin.ignore();
        cout << "Exiting customer signup...\n";
        cin.get();
    }
}

void existingCustomer(fstream& customerReg, fstream& bookingInfo)
{

    //have a login form, have 3 tries, if correct then go to menu if fail then print error and return to main menu
    int attempt = 3;
    bool accountFound = false;
    while (accountFound == false)
    {
        accountFound = customerLogin(customerReg);


        if (accountFound == true)
        {
            customerMenu(customerReg, bookingInfo);
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

int getUniqueCustID()
{
    DriverReg CR;
    fstream customerReg;
    customerReg.open("customerReg.dat", ios::in | ios::binary);
    int i = 0;

    customerReg.read(reinterpret_cast<char*>(&CR), sizeof(CR));
    while (!customerReg.eof())
    {
        i++;
        customerReg.read(reinterpret_cast<char*>(&CR), sizeof(CR));
    }
    return i;
}

bool customerLogin(fstream& customerReg)
{
    CustomerReg CR;

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

    customerReg.read(reinterpret_cast<char*>(&CR), sizeof(CR));

    while (!customerReg.eof())
    {
        if ((strcmp(user, CR.custUser) == 0) && (strcmp(pass, CR.custPassword) == 0))
        {
            flag = true;
            customerAccPosition = customerReg.tellp();
        }
        customerReg.read(reinterpret_cast<char*>(&CR), sizeof(CR));
    }
    if (flag == false)
    {
        cout << "\nLogin Failed.\n";
    }
    customerReg.close();
    return flag;
}

void customerMenu(fstream& customerReg, fstream& bookingInfo)
{
    CustomerReg CR;

    int choice = 0;
    bool flag = false;

    customerReg.open("customerReg.dat", ios::in | ios::binary);
    if (!customerReg)
    {
        cout << "[Error, file not found]";
        exit(1);
    }

    customerReg.seekg(customerAccPosition - sizeof(CR), ios::beg);
    customerReg.read(reinterpret_cast<char*>(&CR), sizeof(CR));
    while (true)
    {
        cin.ignore();
        system("CLS");//clear screen everytime it loops
        printLine();
        cout << "Welcome to the customer menu" << endl;
        cout << "Customer ID : " << CR.custID << endl;
        cout << "Customer Name : " << CR.firstName << " " << CR.lastName << endl;
        cout << "Address : " << CR.custAdd << endl;
        cout << "Username : " << CR.custUser << endl;
        cout << "Password : " << CR.custPassword << endl;
        printLine();
        cout << "\tCustomer Menu";
        printLine();
        cout << "1. Book a Trip \n2. Payments \n3. Cancel a Trip \n4. Exit";
        printLine();
        cout << "\nEnter Option Number : ";
        //user input for menu
        //checking if user entered char instaed of int
        while (true)
        {
            cin >> choice;
            if (!cin)
            {
                cout << "\n[Please select an option on the list]\n";
                cout << "Enter Option Number : ";
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
            customerReg.close();
            bookingTrip(bookingInfo, customerReg);
            break;
        case 2:
            // viewPayment(customerReg);
            break;
        case 3:
            // cancelTrip(customerReg);
            break;
        case 4:
            cout << "[Exiting to main menu...]";
            main();
        default:
            cout << "\n[Please choose an option from the menu.]\n";
            break;
        }
    }
    flag = true;
    customerReg.read(reinterpret_cast<char*>(&CR), sizeof(CR));

    if (flag == false)
    {
        cout << "\n\n[Login Failed]\n";
        cin.get();
    }
    customerReg.close();
}


//*********************************************
//Administrator Functions
void adminMenu(fstream& driverReg, fstream& customerReg, fstream& bookingInfo)
{
    int choice;

    adminLogin();
    while (true)
    {
        system("CLS");//clear screen everytime it loops
        printLine();
        cout << "\tAdmin Menu.";
        printLine();
        cout << "\n1. Driver register \n2. Customer register \n3. Daily Report \n4. Weekly report \n5. Cancelled bookings \n6. Return to main menu\n";
        printLine();
        cout << "Please choose an option from the menu : ";
        while (true)
        {
            cin >> choice;
            if (!cin)
            {
                cout << "\n[Please select an option on the list]\n";
                cout << "Enter Option Number : ";
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
            cout << "[Exiting to main menu...]";
            main();
            break;
        default:
            cout << "\n[Please enter an option from the menu.]\n";
        }
    }
}

void adminLogin()
{
    string adminUser, adminPass;
    int attempts = 1;

    while (attempts < 4)
    {
        cout << "Enter username : ";
        cin >> adminUser;
        cin.ignore();
        cout << "Enter password : ";
        cin >> adminPass;

        if (adminUser != "Admin" && adminPass != "Password123" && attempts < 3)
        {
            cout << "Please enter correct login information.\n";
        }
        else if (adminUser != "Admin" && adminPass != "Password123" && attempts == 3)
        {
            cin.ignore();
            cout << "\n[You entered the wrong information too many times. Please try again later.]\n";
            cin.get();
            main();
        }
        else if (adminUser == "Admin" && adminPass == "Password123")
        {
            break;
        }
        attempts++;
    }
}

//Booking Function
void bookingTrip(fstream& bookingInfo, fstream& customerReg)
{

    // variables
    CustomerReg CR;
    Booking BK;
    int price = 0;
    int z1 = 1, z2 = 2, z3 = 3, zoneStart, zoneEnd; // zone variables for destination.
    int choice;

    
    customerReg.open("customerReg.dat", ios::in | ios::binary);
    if (!customerReg)
    {
        cout << "Error, file Customer not found.";
        exit(1);
    }
    bookingInfo.open("bookingInfo.dat", ios::out | ios::app | ios::binary);
    if (!bookingInfo)
    {
        cout << "Error, file Booking not found.";
        exit(1);
    }

    

    cout << "\tTravel Zone Information\n";
    cout << "\nZone 1: within Christchurch. \nZone 2: Prebbleton, Belfast, Sumner, Kaiapoi. \nZone 3: Rolleston, Rangiora, Remaining of Banks Peninsula.\n";

    cout << "\n\tBook a trip";

    //getting customer id from CR.custID and assign it to BK.custID
    customerReg.seekg(customerAccPosition - sizeof(CR), ios::beg);
    customerReg.read(reinterpret_cast<char*>(&CR), sizeof(CR));
    BK.custID = CR.custID;

    BK.tripNo = getUniqueBookingID();//getting unique trip number
    //getting time
    time_t now = time(NULL);
    //char *str = ctime(&now);
    *BK.bookingDateTime = {};
    ctime_s(BK.bookingDateTime, 26, &now);

    //input for booking details
    
    cin.ignore();
    
    cout << "\nEnter Starting Location Address: ";
    cin.getline(BK.startDestination, CSIZE);
    cin.ignore();
    cout << "\nEnter Starting Location Zone Number (1, 2, 3) : ";
    while (true)
    {
        cin >> zoneStart;
        if (!cin)
        {
            cout << "\n[Please enter an interger for Starting Zone]" << endl;
            cout << "Enter Starting Location Zone Number (1, 2, 3) : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else if (zoneStart <= 0 || zoneStart >= 4)
        {
            cout << "\n[Please Enter a valid Starting Zone]" << endl;
            cout << "Enter Starting Zone Number (1, 2, 3) : ";
            cin.clear();
            continue;
        }
        else {
            break;
        }
    }
    cin.ignore();
    cout << "\nEnter Destination Address: ";
    cin.getline(BK.endDestination, CSIZE);
    cout << "\nEnter Destination Zone Number (1, 2, 3) : ";
    while (true)
    {
        cin >> zoneEnd;
        if (!cin)
        {
            cout << "\n[Please enter an interger for Destination Zone]" << endl;
            cout << "Enter Destination Zone Number (1, 2, 3) : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else if (zoneEnd <= 0 || zoneEnd >= 4)
        {
            cout << "\n[Please Enter a valid Destination Zone]" << endl;
            cout << "Enter Destination Zone Number (1, 2, 3) : ";
            cin.clear();
            continue;
        }
        else {
            break;
        }
    }
    cout << "\nEnter Luggage size ([0]None | [1]Small | [2]Medium | [3]Large) : ";
    while (true)
    {
        cin >> BK.luggage;
        if (!cin)
        {
            cout << "\n[Please enter an interger for Luggage]" << endl;
            cout << "Enter Luggage size ([0]None | [1]Small | [2]Medium | [3]Large) : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else if (BK.luggage < 0 || BK.luggage > 3)
        {
            cout << "\n[Please Select from the options given]\n";
            cout << "Enter Luggage size ([0]None | [1]Small | [2]Medium | [3]Large) : ";
            cin.clear();
            continue;
        }
        else {
            break;
        }
    }
    cout << "\nEnter Number of Passengers (1-7) : ";
    while (true)
    {
        cin >> BK.numberPassengers;
        if (!cin)
        {
            cout << "\n[Please enter an interger for Number of Passengers]" << endl;
            cout << "Enter Number of Passengers (1-7) : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else if (BK.numberPassengers < 1 || BK.numberPassengers > 7)
        {
            cout << "\n[Please input from within range. Max passengers is 7]\n";
            cout << "Enter Number of Passengers (1-7) : ";
            cin.clear();
            continue;
        }
        else {
            break;
        }
    }
    cin.ignore();
    cout << "Please Enter any Special Requirements : ";
    cin.getline(BK.specialReqs, CSIZE);
    //determining price for luggage size and passenger number
    if (BK.luggage == 0)
    {
        price += 0;
    }
    else if (BK.luggage == 1)
    {
        price += 3;
    }
    else if (BK.luggage == 2)
    {
        price += 4;
    }
    else if (BK.luggage == 3)
    {
        price += 5;
    }

    if (BK.numberPassengers == 1)
    {
        price += 0;
    }
    else if (BK.numberPassengers <= 3)
    {
        price += 3;
    }
    else if (BK.numberPassengers >= 4)
    {
        price += 4;
    }
    //determining price of booking for start and end destination
    if (strcmp(BK.startDestination, CR.custAdd) == 0)
    {
        if (CR.custZone == z1 || zoneStart == z1)
        {
            if (zoneEnd == z1)
            {
                price += 30;
            }
            else if (zoneEnd == z2)
            {
                price += 40;
            }
            else if (zoneEnd == z3)
            {
                price += 70;
            }
        }
        else if (CR.custZone == z2 || zoneStart == z2)
        {
            if (zoneEnd == z1)
            {
                price += 40;
            }
            else if (zoneEnd == z2)
            {
                price += 50;
            }
            else if (zoneEnd == z3)
            {
                price += 60;
            }
        }
        else if (CR.custZone == z3 || zoneStart == z3)
        {
            if (zoneEnd == z1)
            {
                price += 70;
            }
            else if (zoneEnd == z2)
            {
                price += 60;
            }
            else if (zoneEnd == z3)
            {
                price += 50;
            }
        }
    }

    //determining price of booking
    else if (strcmp(BK.startDestination, CR.custAdd) != 0)
    {
        if (zoneStart == z1)
        {
            if (zoneEnd == z1)
            {
                price += 30;
            }
            else if (zoneEnd == z2)
            {
                price += 40;
            }
            else if (zoneEnd == z3)
            {
                price += 70;
            }
        }
        else if (zoneStart == z2)
        {
            if (zoneEnd == z1)
            {
                price += 40;
            }
            else if (zoneEnd == z2)
            {
                price += 50;
            }
            else if (zoneEnd == z3)
            {
                price += 60;
            }
        }
        else if (zoneStart == z3)
        {
            if (zoneEnd == z1)
            {
                price += 70;
            }
            else if (zoneEnd == z2)
            {
                price += 60;
            }
            else if (zoneEnd == z3)
            {
                price += 50;
            }
        }
    }
    
    //display extimated price for enter trip and details...
    printLine();
    cout << "\n\tTrip Details\n";
    cout << "Date and Time : " << BK.bookingDateTime;
    cout << "\nStarting Destination : " << BK.startDestination << endl;
    cout << "\nEnding Destination : " << BK.endDestination << endl;
    cout << "\nZone Transfers : From " << zoneStart << " to " << zoneEnd << endl;
    cout << "\nSpecial Requirements : " << BK.specialReqs << endl;
    cout << "\nCurrent estimated Price is $" << price << "NZD\n";
    printLine();
    cin.ignore();
    cin.clear();
    cout << "Would you like to confirm this booking? (y/n) : ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        BK.totalPrice = price;// assigning temp variable price to totalPrice stucture member
        cin.ignore();
        cin.clear();
        cout << "\n[Your Booking is now being processed. Awaiting for Driver Response]";
        cin.get();
        bookingInfo.write(reinterpret_cast<char*>(&BK), sizeof(BK));
        bookingInfo.close();
        customerReg.close();
    }
    else {
        bookingInfo.close();
        customerReg.close();
        customerMenu(customerReg, bookingInfo);
    }
    //tripPayment(bookingInfo, customerReg);
}

int getUniqueBookingID()
{
    Booking BK;
    fstream bookingInfo;
    bookingInfo.open("bookingInfo.dat", ios::in | ios::binary);
    int i = 0;

    bookingInfo.read(reinterpret_cast<char*>(&BK), sizeof(BK));
    while (!bookingInfo.eof())
    {
        i++;
        bookingInfo.read(reinterpret_cast<char*>(&BK), sizeof(BK));
    }
    return i;
}

//void tripPayment(fstream& bookingInfo, fstream& customerReg)
//{
//
//}