#ifndef ADJUVANTMETHODS_H
#define ADJUVANTMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AdjuvantMethods
{
    static bool isFloatNumber(string input);
    static string changeCommaToDot(string input);

public:
    static char getChar();
    static string getLine();
    static string intToStringConversion(int number);
    static int stringToIntConversion(string snumber);
    static string floatToStringConversion(float fnumber);
    static float stringToFloatConversion(string snumber);
    static bool isLetter(char choice);
    static float getFloatNumber();
    static string convertFirstLetterToUppercaseRestLower(string text);
};

#endif // ADJUVANTMETHODS_H
