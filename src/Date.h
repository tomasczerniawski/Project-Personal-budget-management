#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <sstream>
#include <windows.h>
#include <ctime>

#include "AdjuvantMethods.h"

using namespace std;

class Date
{
    int dateInteger;
    int year, month, day;
    string dateString;
    string syear, smonth, sday;

    string createDate();
    bool isYearLeap(int year);
    bool isDateInProperRange();
    bool isDateCorrect();

public:
    Date(){
        dateInteger = 0;
        year = 0;
        month = 0;
        day = 0;
        dateString = "";
        syear = "";
        smonth = "";
        sday = "";
    }
    string getDateString();
    int getDateInteger();
    string getCurrentDateFromSystem();
    int changeDateToIntNumber(string sdate);
    void getDateFromUser();
    string changeDateTostring(int date);
};

#endif // DATE_H
