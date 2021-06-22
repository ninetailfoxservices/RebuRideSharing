void existingDriver(fstream& driverReg)//this is the function called from MAIN MENU
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
int getUniqueID()//called from the creation of new driver account
{
    DriverReg DR1;
    fstream driverReg;
    driverReg.open("driverReg.dat", ios::in | ios::binary);
    int i = 0;

    driverReg.read(reinterpret_cast<char*>(&DR1), sizeof(DR1));
    while (!driverReg.eof())
    {
        i++;
        driverReg.read(reinterpret_cast<char*>(&DR1), sizeof(DR1));
    }
    return i;
}


bool driverLogin(fstream& driverReg)//called from existingDriver() function
{
    //Buffer used for reading
    DriverReg DR2;

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

    driverReg.read(reinterpret_cast<char*>(&DR2), sizeof(DR2));

    while (!driverReg.eof())
    {
        if ((strcmp(user, DR2.driverUser) == 0) && (strcmp(pass, DR2.driverPassword) == 0))
        {
            flag = true;
            driverAccPosition = driverReg.tellp();

        }
        driverReg.read(reinterpret_cast<char*>(&DR2), sizeof(DR2));
    }
    if (flag == false)
    {
        cout << "\nLogin Failed...\n";
    }
    driverReg.close();
    return flag;
}


void driverMenu(fstream& driverReg)//called from existingDriver() function if bool returned true.
{
    DriverReg DR;

    //user login tries
    int input = 0;

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
        cout << "\nCongratulations! this is driver menu\n";
        cout << "\nDriver ID : " << DR.driverID;
        cout << "\nFirst Name : " << DR.firstName;
        cout << "\nLast Name : " << DR.lastName;
        cout << "\nDate Of Birth : " << DR.dob;
        cout << "\nUsername : " << DR.driverUser;
        cout << "\nPassword : " << DR.driverPassword;
        printLine();

        cout << "\n\tDriver Menu.\n1. Daily Trip Report\n2. Available Trips\n3. View Payments\n4. Cancel Trip\n5. Exit\n";//Menu Display for drivers

        printLine();

        cout << "Enter Option Number : ";//user input for menu
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
    }
}