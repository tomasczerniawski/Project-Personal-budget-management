#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>

#include "BinaryTree.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"
#include <map>
using namespace std;

class FinanceManager
{
 
    const int CURRENT_USER_ID;
    BinaryTree<Income> incomesBinaryTree;
    BinaryTree<Expense> expensesBinaryTree;  

    IncomesFile incomesFile;
    ExpensesFile expensesFile;

    Date date;
    float totalIncome;
    float totalExpense;
    Income provideNewIncomeData();
    Expense provideNewExpenseData();

//<-------------->\\
   //Functions for sorting incomes
//<-------------->\\

    std::vector<Income> sortedIncomes;
    void viewIncome(BinaryTreeNode<Income>* node);
    void displayIncome(Income& income);

    BinaryTreeNode<Income>* copyBinaryTree(BinaryTreeNode<Income>* node);
    void deleteBinaryTree(BinaryTreeNode<Income>* node);

    void viewIncomeByDateNewest(BinaryTreeNode<Income>* node); 
    void viewIncomeByDateOldest(BinaryTreeNode<Income>* node); 

    void viewIncomeByPriceMostExpensive(BinaryTreeNode<Income>* node);
    void viewIncomeByPriceCheapest(); 

    void sortIncomesByAmount(BinaryTreeNode<Income>* node);
    void displayIncomesByAmount(BinaryTreeNode<Income>* node);
    int countNodes(BinaryTreeNode<Income>* node);

//<-------------->\\
  //Functions for sorting expenses
//<-------------->\\

    std::vector<Expense> sortedExpense;
    void viewExpense(BinaryTreeNode<Expense>* node);
    void displayExpense(Expense& expense);
   

    BinaryTreeNode<Expense>* copyBinaryTree(BinaryTreeNode<Expense>* node);
    void deleteBinaryTree(BinaryTreeNode<Expense>* node);

    void viewExpenseByDateNewest(BinaryTreeNode<Expense>* node);
    void viewExpenseByDateOldest(BinaryTreeNode<Expense>* node);
    void viewExpenseByPriceMostExpensive(BinaryTreeNode<Expense>* node);
    void viewExpenseByPriceCheapest();

    void sortExpenseByAmount(BinaryTreeNode<Expense>* node);
    void displayExpenseByAmount(BinaryTreeNode<Expense>* node);
    int countNodes(BinaryTreeNode<Expense>* node);
    
//<-------------->\\
   //functions for viewing
//<-------------->\\

    void viewSelectedIncomes(int minDate, int maxDate, const BinaryTree<Income>& incomesBinaryTree);
    void viewSelectedExpenses(int minDate, int maxDate, BinaryTree<Expense>& expensesBinaryTree);


    float calculateTotalIncome(BinaryTreeNode<Income>* node, int minDate, int maxDate);
    float calculateTotalExpense(BinaryTreeNode<Expense>* node, int minDate, int maxDate);
    

public:
    FinanceManager(int currentUserId, string incomesFilename, string expensesFilename)
        : CURRENT_USER_ID(currentUserId), incomesFile(incomesFilename), expensesFile(expensesFilename)
    {
        incomesBinaryTree = incomesFile.loadIncomesOfCurrentUserFromXmlFile(CURRENT_USER_ID);
        expensesBinaryTree = expensesFile.loadExpensesOfCurrentUserFromXmlFile(CURRENT_USER_ID);

        int currentDate = date.changeDateToIntNumber(date.getCurrentDateFromSystem());
        int minDate = (currentDate / 100) * 100 + 1; 
        int maxDate = (currentDate / 100 + 1) * 100;

        totalIncome = calculateTotalIncome(incomesBinaryTree.getRoot(), minDate, maxDate);
        totalExpense = calculateTotalExpense(expensesBinaryTree.getRoot(), minDate, maxDate);
    }

 //<-------------->\\
 //functions for adding
//<-------------->\\

    void addIncome();
    void addExpense();


    void viewAllIncomes();
    void viewAllExpenses();

    int calculateIncomeId(BinaryTreeNode<Income>* node, int currentMaxId);
    int calculateExpenseId(BinaryTreeNode<Expense>* node, int currentMaxId);

//<-------------->\\
 //functions for Searching
//<-------------->\\

    void searchIncomesAndExpenses();
    void searchIncomeByItemRecursive(BinaryTreeNode<Income>* node, const string& keyword, bool& resultsFound);
    void searchExpenseByItemRecursive(BinaryTreeNode<Expense>* node, const string& keyword, bool& resultsFound);

    void viewBalanceOfSelectedPeriod();
    void viewCurrentMonthBalance(); 

    void countMonthlyExpenses(BinaryTreeNode<Expense>* node, int minDate, int maxDate, std::vector<int>& monthlyExpenses);
    void countMonthlyIncomes(BinaryTreeNode<Income>* node, int minDate, int maxDate, std::vector<int>& monthlyIncomes);

    // Function to generate the monthly income chart
    void generateMonthlyIncomeChart();




    void insertRandomIncomeToTree();

};
#endif // FINANCEMANAGER_H
