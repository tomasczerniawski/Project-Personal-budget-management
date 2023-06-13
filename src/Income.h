#ifndef INCOME_H
#define INCOME_H

#include "Finance.h"
#include <iostream>

class Income : public Finance
{
    int incomeId;
    std::string description;
    int dateInteger;  // Date represented as an integer

public:
    void setIncomeId(int newIncomeId);
    int getEntryId() const;
    void setDescription(const std::string& newDescription);
    const std::string& getDescription() const;
    void setDateInteger(int newDateInteger);
    int getDateInteger() const;
};

#endif // INCOME_H
