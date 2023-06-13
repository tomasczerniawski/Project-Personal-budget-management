#include "AdjuvantMethods.h"

char AdjuvantMethods::getChar()
{
    string choice = "";

    while (true)
    {
        getline(cin, choice);

        if (choice.length())
        {
            return choice[0];
        }
        cout << "This is not a single character. Enter the character again." << endl;
    }
}
string AdjuvantMethods::getLine()
{
    string input = "";
    getline(cin, input);
    return input;
}
string AdjuvantMethods::intToStringConversion(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
int AdjuvantMethods::stringToIntConversion(string snumber)
{
    int number;
    istringstream iss(snumber);
    iss >> number;
    return number;
}
bool AdjuvantMethods::isLetter(char choice)
{
    if(isdigit(choice))
        return false;
    return true;
}
float AdjuvantMethods::getFloatNumber()
{
    string input = "";
    float number = 0;

    while (true)
    {
        getline(cin, input);
        if(isFloatNumber(input))
        {
            input = changeCommaToDot(input);
            break;
        }

        cout << "It is not a number. Enter again." << endl;
    }
    number = stringToFloatConversion(input);
    return number;
}
string AdjuvantMethods::floatToStringConversion(float fnumber)
{
    ostringstream ss;
    ss << fnumber;
    string str = ss.str();
    return str;
}
float AdjuvantMethods::stringToFloatConversion(string snumber)
{
    float number;
    istringstream iss(snumber);
    iss >> number;
    return number;
}
bool AdjuvantMethods::isFloatNumber(string input)
{
    if(input == "")
        return false;
    else
    {
        size_t found = input.find_first_not_of("1234567890.,");

        if (found == string::npos)
        {
            found = input.find_first_not_of("1234567890");

            if(found == string::npos)
                return true;
            else if(found == input.find_last_not_of("1234567890"))
                return true;
        }
        return false;
    }
}
string AdjuvantMethods::changeCommaToDot(string input)
{
    size_t foundComma = input.find(",");
    if(foundComma != string::npos)
    {
        input.replace(foundComma, 1, ".");
    }
    return input;
}
string AdjuvantMethods::convertFirstLetterToUppercaseRestLower(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}
