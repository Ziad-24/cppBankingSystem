/*

	Author : Ziad Sherif
		Release date : 24 / 7 / 2021
			Project name : Banking system																																				*/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

//Struct
struct The_Admin
{
    string username;
    string password;

}Admin;
struct The_Client
{
    string username;
    string password;
    string balance;
}Client;
//Global variables
int Endcounter = 0;
int logorsign;
int adm_or_cli;
string line1;
//Functions

//start
void Welcoming();
void Start();
void Admin_or_client();

//admin
void Admin_Log_in();
void Admin_Sign_up();
void Admin_Menu();
void Create_Client_Account();
void Admin_Modify();
void Close_Account();
void View_All_Accounts();

//client
void Client_Log_in();
void Client_Menu();
void Client_View();
void Client_Deposit();
void Client_Withdraw();
void Client_Transfer();

//End
int End();

int main()
{
    Welcoming();
}

// start functions
void Welcoming()
{
    cout << "\t\t\tHello and welcome to Ziad's Banking system , Always at your serve \n";
    Start();
}
void Start()//run the program
{
    cout << "Please make a choice \n";
    cout << "1 - Log in \n2 - Sign up\n3 - Close\n";

    cin >> logorsign;
    if (logorsign == 1 || logorsign == 2)
    {
        Admin_or_client();
    }
    else if (logorsign == 3)
    {
        End();
    }
    else
    {
        cout << "Please choose a correct choice\n";
        Start();
    }
}
void Admin_or_client()
{
    cout << "Are you an Admin or a Client\n 1 for Admin , 2 for Client \n";

    cin >> adm_or_cli;
    cin.ignore();
    if (logorsign == 1 && adm_or_cli == 1)
    {
        Admin_Log_in();
    }
    else if (logorsign == 1 && adm_or_cli == 2)
    {
        Client_Log_in();
    }
    else if (logorsign == 2 && adm_or_cli == 1)
    {
        Admin_Sign_up();
    }
    else if (logorsign == 2 && adm_or_cli == 2)
    {
        cout << "sorry , only admins can create new accounts for client \n";
        cout << "You will be returned to the start menu \n";
        Start();
    }
    else if (adm_or_cli != 1 && adm_or_cli != 2)
    {
        cout << "Please choose a correct choice sir\n";
        Admin_or_client();
    }
}
int End()
{
    while (::Endcounter ==0)
    {
        cout << "\n\n \t\t\t\tThank you for choosing Ziad's banking system \n";
        ::Endcounter++;
    }
    return 0;
    system("Pause");
}

//Admin
void Admin_Sign_up() //working perfect
{
    ofstream outtofile;
    ifstream infromfile;
    outtofile.open("Files/Admin.txt", ios::app);
    infromfile.open("Files/Admin.txt");
    cout << "Enter your Username : ";
    getline(cin, Admin.username);
    string linecheck;
    while (getline(infromfile, linecheck))
    {
        if (linecheck == Admin.username)
        {
            cout << "Username already exists , Enter you username again\n";
            infromfile.close();
            outtofile.close();
            Admin_Sign_up();
        }
    }
    cout << "enter your password : ";
    getline(cin, Admin.password);
    outtofile << Admin.username << endl << Admin.password << endl << "----------" << endl;
    infromfile.close();
    outtofile.close();
    cout <<  "\nWelcome " << Admin.username << endl;
    Admin_Menu();
}
void Admin_Menu()
{
    cout << "What would you like to do:\n\n";
    cout << "Press 1 to create a new client account\n";
    cout << "Press 2 to modifiy an account\n";
    cout << "Press 3 to Close an account\n";
    cout << "Press 4 to View all the available accounts for Clients\n";
    cout << "Press 5 to Log out\n";
    cout << "Press 6 to close the system\n";
    int admin_menu_choice;
    cin >> admin_menu_choice;
    if (admin_menu_choice == 1)
    {
        cin.ignore();
        Create_Client_Account();
    }
    else if (admin_menu_choice == 2)
    {
        cin.ignore();
        Admin_Modify();
    }
    else if (admin_menu_choice == 3)
    {
        Close_Account();
    }
    else if (admin_menu_choice == 4)
    {
        View_All_Accounts();
    }
    else if (admin_menu_choice == 5)
    {
        cout << "Logged out successfully\n\n";
        Start();
    }
    else if (admin_menu_choice == 6)
    {
        End();
    }
    else
    {
        cout << "Invalod option\n";
        Admin_Menu();
    }
}
void Admin_Log_in()
{
    ofstream outtofile;
    ifstream infromfile;
    infromfile.open("Files/Admin.txt");
    outtofile.open("Files/Admin.txt", ios::app);
    bool ufound = false, pfound = false;
    string line, passline;
    int wrongcount = 0;
    cout << "Enter your username : ";
    getline(cin, Admin.username);
    while (getline(infromfile, line))
    {
        if (line == Admin.username)
        {
            getline(infromfile, passline);
            ufound = true;
            cout << "Enter your password: ";
            getline(cin, Admin.password);
            if (Admin.password == passline)
            {
                pfound = true;
                cout << "Successfully logged in \n";
                cout << "Welcome " << Admin.username << "\n";
                infromfile.close();
                outtofile.close();
                Admin_Menu();
            }
            else
            {
                while (passline != Admin.password)
                {
                    cout << "Enter password again : ";
                    getline(cin, Admin.password);
                    if (Admin.password == passline)
                    {
                        pfound = true;
                        cout << "Welcome " << Admin.username << "\n";
                        infromfile.close();
                        outtofile.close();
                        Admin_Menu();
                    }
                    wrongcount++;
                    if (wrongcount == 3)
                    {
                        cout << "Too many wrong trials\nKindly check your info and start again\n";
                        Start();
                        break;
                    }
                }
            }
        }
    }
    if (ufound == false)
    {
        cout << "Username not found\n";
        cout << "Press 1 to sign up as admin \nPress 2 to log in as admin \nPress 3 to start from the beginning\nPress 4 to close the system\n";
        int choice;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
            case 1:Admin_Sign_up();
            case 2:Admin_Log_in();
            case 3: Start();
            case 4:End();
            default:
                cout << "Invalid choice \nSystem will close\n";
                End();
        }
    }
}
void Create_Client_Account()
{
    ofstream clienttofile;
    ifstream filetocode;
    clienttofile.open("Files/Client.txt", ios::app);
    filetocode.open("Files/Client.txt");
    string linecheck;
    ///////////////////////////
    cout << "Enter your Client username\n";
    getline(cin, Client.username);
    while (getline(filetocode, linecheck))
    {
        if (linecheck == Client.username)
        {
            cout << "Account already exists\n";
            while (true)
            {
                cout << "Press 1 to create a new account , Press 2 to log in as a client , Press 3 to return to menu\n";
                int choice;
                cin >> choice;
                cin.ignore();
                if (choice == 1)
                {
                    cin.ignore();
                    Create_Client_Account();
                }
                else if (choice == 2)
                {
                    cin.ignore();
                    Client_Log_in();
                }
                else if (choice == 3)
                {
                    Admin_Menu();
                }
                else
                {
                    cout << "Invalid choice... \n";
                }
            }

        }
    }
    cout << "Enter your client password\n";
    getline(cin, Client.password);
    cout << "Enter " << Client.username << "'s Balance\n";
    getline(cin, Client.balance);
    //
    int xxxx;
    bool num = true;
    xxxx = Client.balance.size();
    for (int i = 0; i <xxxx; i++)
    {
        if ((int)Client.balance[i] > 57 || (int)Client.balance[i] < 46)
        {
            num = false;
        }
    }
    if (num)
    {
        clienttofile << Client.username << endl << Client.password << endl << Client.balance << endl << "----------" << endl;
        clienttofile.close();
        filetocode.close();
        cout << "A new account has been created , you will be returned to the menu\n\n";
        Admin_Menu();
    }
    else
    {
        cout << "You didn't enter a number , please enter a correct number\n";
        while (num == false)
        {
            cout << "Enter " << Client.username << "'s Balance\n";
            getline(cin, Client.balance);
            xxxx = Client.balance.size();
            for (int i = 0; i < xxxx; i++)
            {
                if ((int)Client.balance[i] < 57 || (int)Client.balance[i] > 46)
                {
                    num = true;
                }
            }
            for (int i = 0; i < xxxx; i++)
            {
                if ((int)Client.balance[i] > 57 || (int)Client.balance[i] < 46)
                {
                    num = false;
                }
            }
            if (num == false)
            {
                cout << "Not a number , please enter a correct number\n";
            }
        }
    }
    //
    clienttofile << Client.username << endl << Client.password << endl << Client.balance << endl << "----------" << endl;
    clienttofile.close();
    filetocode.close();
    cout << "A new account has been created , you will be returned to the menu\n\n";
    Admin_Menu();



}
void Admin_Modify()
{
    ifstream filetocode;
    ofstream TempFile;
    filetocode.open("Files/Client.txt");
    TempFile.open("Files/Modify.txt", ios::out);
    string line, user, pass, newuser, newpass;
    cout << "Enter the username of the account you want to modify: ";
    getline(cin, user);
    while (getline(filetocode, line))
    {
        if (user == line)
        {
            filetocode.close();
            filetocode.open("Files/Client.txt");

            cout << "User found , what would you like to do\n";
            int choice;
            cout << "Press 1 to change the account username\nPress 2 to change the account password\n";
            cin >> choice;
            while (true)
            {
                if (choice == 1)//change account username
                {
                    cin.ignore();
                    cout << "Enter the new username: ";
                    getline(cin, newuser);
                    if (newuser != user)
                    {
                        while (getline(filetocode, line))
                        {
                            if (user == line)
                            {
                                TempFile << newuser << endl;
                                continue;
                            }
                            TempFile << line << endl;
                        }
                        filetocode.close();
                        TempFile.close();

                        cout << "Username changed successfully\n";
                        //
                        ifstream copymodified("Files/Modify.txt");
                        ofstream changed("Files/Client.txt", ios::out);
                        while (getline(copymodified, line))
                        {
                            changed << line << endl;
                        }
                        copymodified.close();
                        changed.close();
                        //


                        Admin_Menu();
                    }
                    else
                    {
                        cout << "You entered the same username , please enter a different username\n";
                        continue;
                    }
                }
                else if (choice == 2) //change passwordd
                {
                    cin.ignore();
                    while (true)
                    {
                        cout << "Enter your current password: ";
                        getline(cin, pass);
                        while (getline(filetocode, line))
                        {
                            if (line == user)
                            {
                                getline(filetocode, line);//current pass is assigned into line
                                while (true)
                                {
                                    if (pass == line)
                                    {
                                        cout << "Enter your new password: ";
                                        getline(cin, newpass);
                                        if (newpass == pass)
                                        {
                                            cout << "This is the same password , please enter a new password\n";
                                        }
                                        else
                                        {
                                            cout << "Your password has been changed successfully , you will be returned to the menu\n";
                                            //---------------------------->
                                            filetocode.close();
                                            TempFile.close();
                                            filetocode.open("Files/Client.txt");
                                            TempFile.open("Files/Modify.txt", ios::out);
                                            while (getline(filetocode, line))
                                            {
                                                if (line == user)
                                                {
                                                    TempFile << line << endl;
                                                    getline(filetocode, line);
                                                    TempFile << newpass << endl;
                                                    continue;
                                                }
                                                TempFile << line << endl;
                                            }
                                            filetocode.close();
                                            TempFile.close();
                                            //..
                                            ifstream copymodified("Files/Modify.txt");
                                            ofstream changed("Files/Client.txt", ios::out);
                                            while (getline(copymodified, line))
                                            {
                                                changed << line << endl;
                                            }
                                            copymodified.close();
                                            changed.close();
                                            //..
                                            Admin_Menu();
                                        }
                                    }
                                    else
                                    {
                                        cout << "Wrong password , please enter your password again: ";
                                        getline(cin, pass);
                                    }
                                }
                            }
                            getline(filetocode, line);
                            getline(filetocode, line);
                            getline(filetocode, line);
                        }
                    }

                }
                else
                {
                    cout << "Invalid option\n";
                    cout << "Press 1 to change the account username\nPress 2 to change the account password\n";
                    cin >> choice;
                }
            }
        }
        getline(filetocode, line);
        getline(filetocode, line);
        getline(filetocode, line);
    }
    filetocode.close();
    TempFile.close();
    cout << "Username not found , Press 1 to try again , press 2 to return to menu\n";
    int ask;
    while (true)
    {
        cin >> ask;
        if (ask == 1)
        {
            cin.ignore();
            Admin_Modify();
        }
        else if (ask == 2)
        {
            Admin_Menu();
        }
        else
        {
            cout << "Invalid choice, Press 1 to try again , press 2 to return to menu\n";
        }
    }
}
void Close_Account()
{
    ifstream filetocode;
    filetocode.open("Files/Client.txt");
    ofstream TempFile;
    TempFile.open("Files/Closing.txt");
    cin.ignore();
    string line, namesearch;
    bool entered = false;
    while (true)
    {
        cout << "What is the username of the account you want to close : ";
        getline(cin, namesearch);
        while (getline(filetocode, line))
        {
            if (namesearch == line)
            {
                entered = true;
                cout << "Username found , are you sure you want to delete the account ?\n";
                cout << "Type 'Y' for yes , Type 'N' for no : ";
                string confirmation;
                cin >> confirmation;
                if (confirmation[0] == 'Y' || confirmation[0] == 'y')
                {
                    filetocode.close();
                    filetocode.open("Files/Client.txt");
                    while (getline(filetocode, line))
                    {
                        if (namesearch == line)
                        {
                            getline(filetocode, line);
                            getline(filetocode, line);
                            getline(filetocode, line);
                            continue;
                        }
                        TempFile << line << endl;
                    }
                }
                else if (confirmation[0] == 'N' || confirmation[0] == 'n')
                {
                    cout << "Closing cancelled \n";
                    int c;
                    while (true)
                    {
                        cout << "Press 1 to close another account\nPress 2 to go back to menu\n";
                        cin >> c;
                        if (c == 1)
                        {
                            Close_Account();
                        }
                        else if (c == 2)
                        {
                            Admin_Menu();
                        }
                        else
                        {
                            cout << "Invalid input\n";
                        }
                    }
                }
                else
                {
                    cout << "Error , you will be returned to the menu \n";
                    Admin_Menu();
                }
            }
        }
        filetocode.close();
        TempFile.close();
        if (entered == false)
        {
            cout << "Username not found ";
            int choose;
            while (true)
            {
                cout << "Press 1 to go back to menu , press 2 to enter another username\n";
                cin >> choose;
                if (choose == 1)
                {
                    Admin_Menu();
                }
                else if (choose == 2)
                {
                    Close_Account();
                }
                else
                {
                    cout << "Invalid choice\n";
                }
            }
        }
        //retrieve data into Client file
        if (entered)
        {
            ofstream MovetoFile;
            MovetoFile.open("Files/Client.txt", ios::out);
            ifstream Temp;
            Temp.open("Files/Closing.txt");
            while (getline(Temp, line))
            {
                MovetoFile << line << endl;
            }
            MovetoFile.close();
            Temp.close();
            break;
        }
    }
    cout << "Account closed successfully \n";
    Admin_Menu();
}
void View_All_Accounts()
{
    cout << endl;
    ifstream filetocode;
    filetocode.open("Files/Client.txt");
    string line;
    while (getline(filetocode, line))
    {
        cout << "Username : " << line << endl;
        getline(filetocode, line);
        getline(filetocode, line);
        cout << "Balance : " << line << endl;
        getline(filetocode, line);
    }
    filetocode.close();
    cout << endl;
    Admin_Menu();
}

//Client
void Client_Log_in()
{
    ofstream clienttofile;
    ifstream filetocode;
    filetocode.open("Files/Client.txt");
    clienttofile.open("Files/Client.txt", ios::app);
    //
    bool ufound = false, pfound = false;
    string line, passline;
    int wrongcount = 0;
    cout << "Enter your username : ";
    getline(cin, Client.username);
    while (getline(filetocode, line))
    {
        if (line == Client.username)
        {
            getline(filetocode, passline);
            ufound = true;
            cout << "Enter your password: ";
            getline(cin, Client.password);
            if (Client.password == passline)
            {
                pfound = true;
                cout << "Successfully logged in \n";
                cout << "Welcome " << Client.username << "\n\n";
                filetocode.close();
                clienttofile.close();
                Client_Menu();
            }
            else
            {
                while (passline != Client.password)
                {
                    cout << "Enter password again : ";
                    getline(cin, Client.password);
                    if (Client.password == passline)
                    {
                        pfound = true;
                        cout << "Welcome " << Client.username << "\n\n";
                        filetocode.close();
                        clienttofile.close();
                        Client_Menu();
                    }
                    wrongcount++;
                    if (wrongcount == 3)
                    {
                        cout << "Too many wrong trials , Start again\n";
                        filetocode.close();
                        clienttofile.close();
                        Start();
                        break;
                    }
                }
            }
        }
        else
        {
            getline(filetocode, line);
            getline(filetocode, line);
            getline(filetocode, line);
        }


    }
    if (ufound == false)
    {
        cout << "Username not found , ";
        filetocode.close();
        clienttofile.close();
        cout << "Please ask an admin to create a new account for you in our banking system or log in again\n";
        int choice;
        while (true)
        {
            cout << "Press 1 to log in again , Press 2 to go back to start menu\n";
            cin >> choice;
            if (choice == 1)
            {
                cin.ignore();
                Client_Log_in();
            }
            else if (choice == 2)
            {
                Start();
            }
            else
            {
                cout << "Invalid choice \n";
            }
        }
    }

    //
}
void Client_Menu()
{
    cout << "What would you like to do\n";
    cout << "Press 1 to view your account balance\nPress 2 to Deposit cash into your bank account\nPress 3 to withdraw money from your bank account\nPress 4 to Transfer money to another account\n";
    cout << "Press 5 to log out\nPress 6 to close the system\n";
    int choice;
    cin >> choice;
    while (true)
    {
        if (choice == 1)
        {
            Client_View();
        }
        else if (choice == 2)
        {
            Client_Deposit();
        }
        else if (choice == 3)
        {
            Client_Withdraw();
        }
        else if (choice == 4)
        {
            cin.ignore();
            Client_Transfer();
        }
        else if(choice == 5)
        {
            cout << "\nLogged out successfully\n";
            Start();
        }
        else if (choice == 6)
        {
            End();
        }
        else
        {
            "Invalid choice\n";
            Client_Menu();
        }
    }
}
void Client_View()
{
    ifstream filetocode;
    filetocode.open("Files/Client.txt");
    string name, balance;
    while (getline(filetocode, name))
    {
        if (name == Client.username)
        {
            getline(filetocode, name);
            getline(filetocode, balance);
            filetocode.close();
            break;
        }
    }
    cout << "\tYour balance is:\n" << "\t" << fixed << setprecision(2) << balance << endl;
    cout << "Press 1 to return to menu\nPress 2 to Log out\n";
    int choice=1;
    while (true)
    {
        cin >> choice;
        if (choice == 1)
        {
            Client_Menu();
        }
        else if (choice == 2)
        {
            Start();
        }
        else
        {
            cout << "Invalid choice , please try again\n";
            cout << "Press 1 to return to menu\nPress 2 to Log out and close\n";
        }
    }
}
void Client_Deposit()
{
    string money;
    bool num = true;
    cout << "Enter the amount of money you want to deposit in your account : ";
    cin.ignore();
    cin >> money;
    int xxxx = money.size();
    for (int i = 0; i < xxxx; i++)
    {
        if ((int)money[i] > 57 || (int)money[i] < 46)
        {
            num = false;
        }
    }
    if (num == false)
    {
        cout << "You didn't enter a number \nPress 1 to deposit money\nPress 2 to go back to menu\n";
        int choice;
        cin >> choice;
        while (true)
        {
            if (choice == 1)
            {
                cin.ignore();
                Client_Deposit();
            }
            else if (choice == 2)
            {
                Client_Menu();
            }
            else
            {
                cout << "Invalid option\n";
            }
        }

    }
    else if(num)
    {
        ifstream filetocode;
        filetocode.open("Files/Client.txt");
        ofstream TempFile;
        TempFile.open("Files/Money.txt",ios::out);
        string line;
        while (getline(filetocode, line))
        {
            if (line == Client.username)
            {
                TempFile << line << endl;
                getline(filetocode, line);
                TempFile << line << endl;
                getline(filetocode, line);
                TempFile << fixed << setprecision(2) << stold(line) + stold(money) << endl;
                getline(filetocode, line);
                TempFile << line << endl;
                continue;
            }
            TempFile << line << endl;
        }
        filetocode.close();
        TempFile.close();
        ofstream MovetoFile;
        MovetoFile.open("Files/Client.txt", ios::out);
        ifstream Temp;
        Temp.open("Files/Money.txt");
        while (getline(Temp, line))
        {
            MovetoFile << line << endl;
        }
        MovetoFile.close();
        Temp.close();
    }
    cout << "Money has been successfully deposited in your bank account\nWould you like to do another interaction?\n";
    int choice;
    while (true)
    {
        cout << "Press 1 to go back to menu , Press 2 to log out\n";
        cin >> choice;
        if (choice == 1)
        {
            Client_Menu();
        }
        else if (choice == 2)
        {
            cout << "\nLogged out successfully\n\n";
            End();
        }
        else
        {
            cout << "Invalid option\n";
        }
    }
}
void Client_Withdraw()
{
    string money;
    bool num = true;
    cout << "Enter the amount of money you want to withdraw from your account : ";
    cin.ignore();
    cin >> money;
    int xxxx = money.size();
    for (int i = 0; i < xxxx; i++)
    {
        if ((int)money[i] > 57 || (int)money[i] < 46)
        {
            num = false;
        }
    }
    if (num == false)
    {
        cout << "You didn't enter a number \nPress 1 to withdraw money\nPress 2 to go back to menu\n";
        int choice;
        cin >> choice;
        while (true)
        {
            if (choice == 1)
            {
                cin.ignore();
                Client_Withdraw();
            }
            else if (choice == 2)
            {
                Client_Menu();
            }
            else
            {
                cout << "Invalid option\n";
            }
        }

    }
    else if (num)
    {

        ifstream filetocode;
        filetocode.open("Files/Client.txt");
        ofstream TempFile;
        TempFile.open("Files/Money.txt", ios::out);
        string line;
        while (getline(filetocode, line))
        {
            if (line == Client.username)
            {
                TempFile << line << endl;
                getline(filetocode, line);
                TempFile << line << endl;
                getline(filetocode, line);
                if ( stold(line)-stold(money) >= 0 )
                {
                    TempFile << fixed << setprecision(2) << stold(line) - stold(money) << endl;
                }
                else
                {
                    cout << "Insufficient funds \n";
                    int chooose;
                    while (true)
                    {
                        cout << "Press 1 to withdraw money \nPress 2 to go back menu\n";
                        cin >> chooose;
                        if (chooose == 1)
                        {
                            cin.ignore();
                            filetocode.close();
                            TempFile.close();
                            Client_Withdraw();
                        }
                        else if (chooose == 2)
                        {
                            Client_Menu();
                        }
                        else
                        {
                            cout << "Invalid choice\n";
                        }
                    }

                }
                getline(filetocode, line);
                TempFile << line << endl;
                continue;
            }
            TempFile << line << endl;
        }
        filetocode.close();
        TempFile.close();
        ofstream MovetoFile;
        MovetoFile.open("Files/Client.txt", ios::out);
        ifstream Temp;
        Temp.open("Files/Money.txt");
        while (getline(Temp, line))
        {
            MovetoFile << line << endl;
        }
        MovetoFile.close();
        Temp.close();
    }
    cout << "Money has been successfully withdrawn from your bank account\nWould you like to do another interaction?\n";
    int choice;
    while (true)
    {
        cout << "Press 1 to go back to menu , Press 2 to log out\n";
        cin >> choice;
        if (choice == 1)
        {
            Client_Menu();
        }
        else if (choice == 2)
        {
            cout << "\nLogged out successfully\n\n";
            Start();
        }
        else
        {
            cout << "Invalid option\n";
        }
    }
}
void Client_Transfer()
{
    ifstream filetocode;
    ofstream TempFile;
    TempFile.open("Files/Money.txt", ios::out);
    filetocode.open("Files/Client.txt");
    string CLIENT, money, line, TransFrom, TransTo;
    bool namefound = false;
    cout << "Enter the username of the client you want to transfer money to:";
    getline(cin, CLIENT);
    while (getline(filetocode, line))
    {
        if (line == CLIENT)
        {
            namefound = true;
            getline(filetocode, line);
            getline(filetocode, line);
            TransTo = line;
            getline(filetocode, line);
            continue;
        }
        else if (line == Client.username)
        {
            getline(filetocode, line);
            getline(filetocode, line);
            TransFrom = line;
            getline(filetocode, line);
            continue;
        }
        else if (CLIENT == Client.username)
        {
            cout << "You cannot transfer money to your own account\n";
            int choice;
            while (true)
            {
                cout << "Press 1 to transfer money again\nPress 2 to return to menu\n";
                cin >> choice;
                if (choice == 1)
                {
                    cin.ignore();
                    Client_Transfer();
                }
                else if (choice == 2)
                {
                    Client_Menu();
                }
                else
                {
                    cout << "Invalid option\n";
                }
            }
        }
        getline(filetocode, line);
        getline(filetocode, line);
        getline(filetocode, line);
    }

    filetocode.close();
    TempFile.close();

    if (!namefound)
    {
        cout << "Username not found\n";
        int choice;
        while (true)
        {
            cout << "Press 1 to transfer again , Press 2 to go back to menu\n";
            cin >> choice;
            if (choice == 1)
            {
                cin.ignore();
                Client_Transfer();
            }
            else if (choice == 2)
            {
                Client_Menu();
            }
            else
            {
                cout << "Invalid choice\n";
            }
        }
    }

    cout << "Username found \n";
    while (true)
    {
        bool num = true;
        cout << "Your balance is " << TransFrom << endl;
        cout << "Enter the amount of money you want to transfer: ";
        getline(cin, money);
        int xxxx = money.size();
        for (int i = 0; i < xxxx; i++)
        {
            if ((int)money[i] > 57 || (int)money[i] < 46)
            {
                num = false;
            }
        }
        if (num)
        {
            if (stold(TransFrom) - stold(money) >= 0)
            {
                break;
            }
            else
            {
                cout << "Insufficient funds\n";
            }
        }
        else
        {
            cout << "You didn't enter a number\n";
        }
    }
    filetocode.open("Files/Client.txt");
    TempFile.open("Files/Money.txt", ios::out);
    while (getline(filetocode, line))
    {
        if (line == Client.username)
        {
            TempFile << line << endl;
            getline(filetocode, line);
            TempFile << line << endl;
            getline(filetocode, line);
            TempFile << fixed << setprecision(2) << stold(TransFrom) - stold(money) << endl;
            getline(filetocode, line);
            TempFile << line << endl;
            continue;
        }
        else if (line == CLIENT)
        {
            TempFile << line << endl;
            getline(filetocode, line);
            TempFile << line << endl;
            getline(filetocode, line);
            TempFile << fixed << setprecision(2) << stold(TransTo) + stold(money) << endl;
            getline(filetocode, line);
            TempFile << line << endl;
            continue;
        }

        TempFile << line << endl;
        getline(filetocode, line);
        TempFile << line << endl;
        getline(filetocode, line);
        TempFile << line << endl;
        getline(filetocode, line);
        TempFile << line << endl;
    }
    TempFile.close();
    filetocode.close();
    ofstream MovetoFile;
    MovetoFile.open("Files/Client.txt", ios::out);
    ifstream Temp;
    Temp.open("Files/Money.txt");
    while (getline(Temp, line))
    {
        MovetoFile << line << endl;
    }
    TempFile.close();
    filetocode.close();
    cout << "\nMoney transferred successfully \n";
    Client_Menu();
}