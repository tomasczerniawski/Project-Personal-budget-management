#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>

#include "User.h"
#include "XmlFile.h"


using namespace std;

class UsersFile : public XmlFile
{

public:
    UsersFile(string usersFilename):XmlFile(usersFilename)
    {};
    vector<User> loadUsersFromXmlFile();
    bool addUserToXmlFile(User user);

};

#endif // USERSFILE_H
