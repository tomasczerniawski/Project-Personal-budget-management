#include "UsersFile.h"

vector <User> UsersFile::loadUsersFromXmlFile()
{
    vector <User> users;
    CMarkup xml;

    if (fileExist(xml))
    {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("User"))
        {
            User user;
            xml.IntoElem();
            xml.FindElem("UserId");
            user.setUserId(AdjuvantMethods::stringToIntConversion(std::string(CT2A(xml.GetElemContent()))));
            xml.FindElem("Name");
            user.setName(static_cast<const char*>(xml.GetElemContent()));
            xml.FindElem("Surname");
            user.setSurname(static_cast<const char*>(xml.GetElemContent()));
            xml.FindElem("Login");
            user.setLogin(static_cast<const char*>(xml.GetElemContent()));
            xml.FindElem("Password");
            user.setPassword(static_cast<const char*>(xml.GetElemContent()));
            xml.OutOfElem();
            users.push_back(user);
        }
    }
    return users;
}
bool UsersFile::addUserToXmlFile(User user)
{
    CMarkup xml;

    if (!fileExist(xml))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("Name", MCD_T(user.getName().c_str()));
    xml.AddElem("Surname", MCD_T(user.getSurname().c_str()));
    xml.AddElem("Login", MCD_T(user.getLogin().c_str()));
    xml.AddElem("Password", MCD_T(user.getPassword().c_str()));
    xml.OutOfElem();

    std::string filename = getFilename();

    // Convert the std::string to MCD_CSTR
    MCD_CSTR convertedFilename = MCD_T(filename.c_str());

    // Call the Save function with the converted filename
    xml.Save(convertedFilename);
    if (!fileExist(xml))
    {
        cout << "Cannot open the " << getFilename() << " file." << endl;
        return false;
    }
    return true;
}

