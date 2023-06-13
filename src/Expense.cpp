#include "Expense.h"

void Expense::setExpenseId(int newExpenseId)
{
    expenseId = newExpenseId;
}

int Expense::getEntryId() const
{
    return expenseId;
}

void Expense::setDescription(const std::string& newDescription)
{
    description = newDescription;
}

const std::string& Expense::getDescription() const
{
    return description;
}
