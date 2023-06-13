#ifndef FINANCE_H
#define FINANCE_H

#include <iostream>
#include <string>
using namespace std;

class Finance
{
    int userId;
    int date;
    string item;
    float amount;

public:
    bool operator () (Finance a, Finance b)
    {
        if (a.getDate() < b.getDate())
            return true;
    }
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);
    int getUserId();
    int getDate();
    string getItem();
    float getAmount();
};

#endif // FINANCE_H