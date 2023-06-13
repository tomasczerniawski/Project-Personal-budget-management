#include "Date.h"

string Date::getDateString()
{
    return dateString;
}
int Date::getDateInteger()
{
    return dateInteger;
}
void Date::getDateFromUser()
{
    char choice;
    cout << "Do you want to use today's date? (Y/N)" << endl;
    while(true)
    {
        choice = AdjuvantMethods::getChar();
        if (AdjuvantMethods::isLetter(choice))
        {
            if (tolower(choice)=='y')
            {
                dateString = getCurrentDateFromSystem();
                dateInteger = changeDateToIntNumber(dateString);
                break;
            }
            else if (tolower(choice)=='n')
            {
                cout << "Enter date (yyyy-mm-dd): ";

                while (true)
                {
                    dateString = AdjuvantMethods::getLine();
                    dateInteger = changeDateToIntNumber(dateString);
                    if(isDateCorrect())
                    {
                        break;
                    }
                    else
                        cout << "Date is not valid. Enter the date again." << endl;
                }
                break;
            }
            else
            {
                cout << "There is no such option. Try again.";
                Sleep(1500);
            }
        }
        else
        {
            cout << "It is not a letter. Try again.";
            Sleep(1500);
        }
    }
}
bool Date::isDateCorrect()
{
    int year = AdjuvantMethods::stringToIntConversion(syear);
    int month = AdjuvantMethods::stringToIntConversion(smonth);
    int day = AdjuvantMethods::stringToIntConversion(sday);

    if(isDateInProperRange())
    {
        if(month < 1 || month > 12)
            return false;

        if(day < 1 || day > 31)
            return false;

        if(month == 2)
        {
            if (isYearLeap(year))
                return day <= 29;
            else
                return day <= 28;
        }
        if(month == 4 || month == 6 || month == 9 || month == 11)
            return day <= 30;
        return true;
    }
    return false;
}
bool Date::isYearLeap (int year)
{
    if ((year%4==0 && year%100!=0) || year%400==0)
        return true;
    else
        return false;
}
int Date::changeDateToIntNumber(string sdate)
{
    string date;
    stringstream ss(sdate);

    getline(ss, syear, '-');
    getline(ss, smonth, '-');
    getline(ss, sday);

    date = syear + smonth + sday;

    return AdjuvantMethods::stringToIntConversion(date);
}
string Date::getCurrentDateFromSystem()
{
    string sdate;
    time_t t = time(0);
    tm now;
    localtime_s(&now, &t);
    year = now.tm_year + 1900;
    month = now.tm_mon + 1;
    day = now.tm_mday;

    sdate = createDate();

    return sdate;
}

string Date::createDate()
{
    string sdate = "";

    syear = AdjuvantMethods::intToStringConversion(year);
    smonth = AdjuvantMethods::intToStringConversion(month);
    sday = AdjuvantMethods::intToStringConversion(day);

    if (month > 0 && month < 10)
        smonth = "0" + smonth;
    if (day > 0 && day < 10)
        sday = "0" + sday;

    sdate = syear + "-" + smonth + "-" + sday;

    return sdate;
}
bool Date::isDateInProperRange()
{
    int minDate = 20000101; // 2000-01-01
    int maxDate = (changeDateToIntNumber(getCurrentDateFromSystem())/100 + 1) * 100; // yyyy-nextMonth-00

    if (dateInteger >= minDate && dateInteger < maxDate)
        return true;
    return false;
}
string Date::changeDateTostring(int date)
{
    string sdate = AdjuvantMethods::intToStringConversion(date);

    sdate.insert(4,"-");
    sdate.insert(7, "-");

    return sdate;
}
