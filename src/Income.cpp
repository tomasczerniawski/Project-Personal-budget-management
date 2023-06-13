#include "Income.h"

void Income::setIncomeId(int newIncomeId)
{
    incomeId = newIncomeId;
}

int Income::getEntryId() const
{
    return incomeId;
}

void Income::setDescription(const std::string& newDescription)
{
    description = newDescription;
}

const std::string& Income::getDescription() const
{
    return description;
}

void Income::setDateInteger(int newDateInteger)
{
    dateInteger = newDateInteger;
}

int Income::getDateInteger() const
{
    return dateInteger;
}
