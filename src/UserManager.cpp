#include "UserManager.h"

void UserManager::userSignUp()
{
    User user = provideNewUserData();
    bool isUserAdded = false;

    users.push_back(user);
    isUserAdded = usersFile.addUserToXmlFile(user);
    if(isUserAdded)
        cout << endl << "Your account was successfully created." << endl;
    system("pause");
}
User UserManager::provideNewUserData()
{
    User user;
    user.setUserId(getNewUserId());

    string login;
    do
    {
        system("cls");
        cout << "    >>> SIGN UP <<<" << endl;
        cout << endl <<"Enter username: ";
        cin >> login;
        user.setLogin(login);
    }
    while (isUsernameAvailable(user.getLogin()) == false);

    string password;
    cout << "Enter password: ";
    cin >> password;
    user.setPassword(password);

    string name;
    cout << "Enter name: ";
    cin.sync();
    name = AdjuvantMethods::getLine();
    user.setName(AdjuvantMethods::convertFirstLetterToUppercaseRestLower(name));


    string surname;
    cout << "Enter surname: ";
    cin.sync();
    surname = AdjuvantMethods::getLine();
    user.setSurname(AdjuvantMethods::convertFirstLetterToUppercaseRestLower(surname));

    return user;
}
int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}
bool UserManager::isUsernameAvailable(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Username unavailable" << endl << endl;
            system("pause");
            return false;
        }
    }
    return true;
}
void UserManager::userSignIn()
{
    system("cls");
    cout << "    >>> SIGN IN <<<" << endl;
    string login = "", password = "";
    cout << endl << "Enter username: ";
    cin >> login;
    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                if (numberOfAttempts!=1)
                {
                    cout << "Enter password (" << numberOfAttempts << " attempts left): ";
                }
                else
                {
                    cout << "Enter password (" << numberOfAttempts << " attempt left): ";
                }
                cin >> password;

                if (itr -> getPassword() == password)
                {
                    currentUserId = itr -> getUserId();
                    cout << endl << "You have successfully signed in." << endl << endl;
                    system("pause");
                    return;

                }
            }
            cout << endl << "3 unsuccessful login attempts." << endl;
            system("pause");
            return;
        }
        itr++;

    }
    cout << "Username does not exist" << endl << endl;
    system("pause");
    return;
}

bool UserManager::isUserLoggedIn()
{
    if(currentUserId>0)
        return true;
    else
        return false;
}
char UserManager::selectFromMainMenu()
{
    char choice;
    system("cls");
    cout << "\t\t\t     =======================================\n";
    cout << "\t\t\t\t\t    MAIN MENU \n";
    cout << "\t\t\t     =======================================\n\n";
    cout << "\t\t\t\t----------------------------------\n";
    cout << "\t\t\t\t||\t1. Sign up     \t\t||\n";
    cout << "\t\t\t\t||\t2. Sign in     \t\t||\n";
    cout << "\t\t\t\t||\t3. Exit        \t\t||\n";
    cout << "\t\t\t\t----------------------------------\n";
    choice = AdjuvantMethods::getChar();

    return choice;
}
char UserManager::selectFromUserMenu()
{
    char choice;
    system("cls");
   
    cout << "\t\t\t     ==================================================\n";
    cout << "\t\t\t\t\t PERSONAL BUDGET MANAGMENT \n";
    cout << "\t\t\t     ==================================================\n\n";
    cout << "\t\t\t----------------------------------------------------------\n";
    cout << "\t\t\t||\t1. Add income                          \t\t||\n";
    cout << "\t\t\t||\t2. Add expense                         \t\t||\n";
    cout << "\t\t\t||\t3. View current month's balance        \t\t||\n";
    cout << "\t\t\t||\t4. View balance of the selected period \t\t||\n";
    cout << "\t\t\t||\t5. View all incomes                    \t\t||\n";
    cout << "\t\t\t||\t6. View all expenses                   \t\t||\n";
    cout << "\t\t\t||\t7. Search in budget                    \t\t||\n";
    cout << "\t\t\t||\t8. Generate report                     \t\t||\n";
    cout << "\t\t\t||\t9. Generate random budget              \t\t||\n";
    cout << "\t\t\t||\t0. Sign out                           \t\t||\n";
    cout << "\t\t\t----------------------------------------------------------\n";
                 
    cout << "\nEnter Choice: ";
    choice = AdjuvantMethods::getChar();

    return choice;
}

void UserManager::userSignOut()
{
    currentUserId = 0;
   
}
int UserManager::getCurrentUserId()
{
    return currentUserId;
}

