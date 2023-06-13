#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>

#include "UsersFile.h"

using namespace std;

class UserManager
{
    int currentUserId;
    vector<User> users;
    UsersFile usersFile;

    User provideNewUserData();
    int getNewUserId();
    bool isUsernameAvailable(string login);

public:
    UserManager(string usersFilename):usersFile(usersFilename)
    {
        currentUserId = 0;
        users = usersFile.loadUsersFromXmlFile();
    };
    void userSignUp();
    void userSignIn();
    void userSignOut();
 
    bool isUserLoggedIn();
    char selectFromMainMenu();
    char selectFromUserMenu();
    int getCurrentUserId();
};

#endif // USERMANAGER_H
