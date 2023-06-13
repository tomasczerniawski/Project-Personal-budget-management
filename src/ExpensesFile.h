#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include "XmlFile.h"
#include "Income.h"
#include "Expense.h"

class ExpensesFile : public XmlFile
{
    int lastExpenseId;
    BinaryTree<Expense> expensesBinaryTree;

    int getLastExpenseIdFromFile();

public:
    ExpensesFile(string expensesFilename) : XmlFile(expensesFilename)
    {
        lastExpenseId = getLastExpenseIdFromFile();
    }



    BinaryTree<Expense> loadExpensesOfCurrentUserFromXmlFile(int CURRENT_USER_ID);
    bool addExpenseToXmlFile(Expense expense, Date date);
    int getLastExpenseId();
};

#endif // EXPENSESFILE_H