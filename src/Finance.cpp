#include "Finance.h"

void Finance::setUserId(int newUserId)
{
    userId = newUserId;
}
void Finance::setDate(int newDate)
{
    date = newDate;
}
void Finance::setItem(string newItem)
{
    item = newItem;
}
void Finance::setAmount(float newAmount)
{
    amount = newAmount;
}
int Finance::getUserId()
{
    return userId;
}
int Finance::getDate()
{
    return date;
}
string Finance::getItem()
{
    return item;
}
float Finance::getAmount()
{
    return amount;
}