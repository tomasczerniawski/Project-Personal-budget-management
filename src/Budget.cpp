#include "Budget.h"

void Budget::userSignUp()
{
    userManager.userSignUp();
}

void Budget::userSignIn()
{
    userManager.userSignIn();
    if (userManager.isUserLoggedIn())
    {
        financeManager = new FinanceManager(userManager.getCurrentUserId(), INCOMES_FILENAME, EXPENSES_FILENAME);
    }
}

void Budget::userSignOut()
{
    userManager.userSignOut();
    delete financeManager;
    financeManager = nullptr;
}

bool Budget::isUserLoggedIn()
{
    return userManager.isUserLoggedIn();
}

char Budget::selectFromMainMenu()
{
    return userManager.selectFromMainMenu();
}

char Budget::selectFromUserMenu()
{
    return userManager.selectFromUserMenu();
}

void Budget::addIncome()
{
    financeManager->addIncome();
}

void Budget::addExpense()
{
    financeManager->addExpense();
}

void Budget::viewCurrentMonthBalance()
{
    financeManager->viewCurrentMonthBalance();
}

void Budget::viewBalanceOfSelectedPeriod()
{
    financeManager->viewBalanceOfSelectedPeriod();
}

void Budget::viewAllIncomes()
{
    financeManager->viewAllIncomes();
}

void Budget::viewAllExpenses()
{
    financeManager->viewAllExpenses();
}

void Budget::searchIncomesAndExpenses()
{
    financeManager->searchIncomesAndExpenses();
}

void Budget::generateMonthlyIncomeChart()
{
    financeManager->generateMonthlyIncomeChart();
}
void Budget::insertRandomIncomeToTree()
{
    financeManager->insertRandomIncomeToTree();
}