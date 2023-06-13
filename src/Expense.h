#ifndef EXPENSE_H
#define EXPENSE_H

#include "Finance.h"
#include <iostream>

class Expense : public Finance
{
    int expenseId;
    std::string description;

public:
    void setExpenseId(int newExpenseId);
    int getEntryId() const;
    void setDescription(const std::string& newDescription);
    const std::string& getDescription() const;
};

#endif // EXPENSE_H
