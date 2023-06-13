#include "FinanceManager.h"
#include <stack>
#include <iostream>
#include <vector>
#include <iomanip>
#include <random>
//<-------------->\\
//Adding new income
//<-------------->\\

void FinanceManager::addIncome()
{
    Income income;
    income = provideNewIncomeData();
    bool isIncomeAdded = false;
   
    incomesBinaryTree.insertNode(income);

    isIncomeAdded = incomesFile.addIncomeToXmlFile(income, date);

    if (isIncomeAdded)
        cout << endl << "The income has been successfully added." << endl;

    system("pause");

}

Income FinanceManager::provideNewIncomeData()
{
    string item = "";
    float amount = 0;
  

    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    date.getDateFromUser();
    cout << "Enter item: ";
    cin.sync();
    item = AdjuvantMethods::getLine();
    cout << "Enter amount: ";
    amount = AdjuvantMethods::getFloatNumber();

    income.setIncomeId(incomesFile.getLastIncomeId() + 1);
    income.setUserId(CURRENT_USER_ID);
    income.setDate(date.getDateInteger());
    income.setItem(item);
    income.setAmount(amount);

    return income;
}

int FinanceManager::calculateIncomeId(BinaryTreeNode<Income>* node, int currentMaxId) {
    if (node == nullptr) {
        return currentMaxId;
    }

    int maxId = max(node->data.getEntryId(), currentMaxId);
    maxId = calculateIncomeId(node->left, maxId);
    maxId = calculateIncomeId(node->right, maxId);

    return maxId;
}

//<-------------->\\
//Adding expense function
//<-------------->\\

void FinanceManager::addExpense()
{
    Expense expense;
    expense = provideNewExpenseData();
    bool isExpenseAdded = false;
   
    expensesBinaryTree.insertNode(expense);
    isExpenseAdded = expensesFile.addExpenseToXmlFile(expense, date);
    cout << endl << "The expense has been successfully added." << endl;
    system("pause");
}

Expense FinanceManager::provideNewExpenseData()
{
    string item = "";
    float amount = 0;
  

    Expense expense;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    date.getDateFromUser();
    cout << "Enter item: ";
    cin.sync();
    item = AdjuvantMethods::getLine();
    cout << "Enter amount: ";
    amount = AdjuvantMethods::getFloatNumber();

    expense.setExpenseId(expensesFile.getLastExpenseId() + 1);
    expense.setUserId(CURRENT_USER_ID);
    expense.setDate(date.getDateInteger());
    expense.setItem(item);
    expense.setAmount(amount);

    return expense;
}

//<-------------->\\
//View All Incomes And diffrent sorting functions
//<-------------->\\

void FinanceManager::viewAllIncomes()
{
    viewIncome(incomesBinaryTree.getRoot());
    system("pause");
}

BinaryTreeNode<Income>* FinanceManager::copyBinaryTree(BinaryTreeNode<Income>* node) {
    if (node == nullptr) {
        return nullptr;
    }

    BinaryTreeNode<Income>* newNode = new BinaryTreeNode<Income>(node->data);
    newNode->left = copyBinaryTree(node->left);
    newNode->right = copyBinaryTree(node->right);

    return newNode;
}

void FinanceManager::deleteBinaryTree(BinaryTreeNode<Income>* node) {
    if (node == nullptr) {
        return;
    }

    deleteBinaryTree(node->left);
    deleteBinaryTree(node->right);
    delete node;
}

void FinanceManager::viewIncome(BinaryTreeNode<Income>* node) {

    BinaryTreeNode<Income>* originalTree = copyBinaryTree(incomesBinaryTree.getRoot()); // Create a copy of the original binary tree

    char choice;

    do {
        cin.sync();
        system("cls");

        cout << "Select sorting for incomes option:" << endl;
        cout << "1. Sort by date (newest first)" << endl;
        cout << "2. Sort by date (oldest first)" << endl;
        cout << "3. Sort by price (cheapest first)" << endl;
        cout << "4. Sort by price (most expensive first)" << endl;
        cout << "0. Go back to the main menu" << endl;
        cout << "Enter your choice: ";
        choice = AdjuvantMethods::getChar();

        switch (choice) {
        case '1':
            system("cls");
            cout << "Sorting by date (newest first):" << endl;
            viewIncomeByDateNewest(originalTree); // Pass the original tree instead of the modified tree
            break;
        case '2':
            system("cls");
            cout << "Sorting by date (oldest first):" << endl;
            viewIncomeByDateOldest(originalTree); // Pass the original tree instead of the modified tree
            break;
        case '3':
            system("cls");
            cout << "Sorting by price (cheapest first):" << endl;
            sortIncomesByAmount(incomesBinaryTree.getRoot());
            displayIncomesByAmount(incomesBinaryTree.getRoot());
            break;
        case '4':
            system("cls");
            cout << "Sorting by price (most expensive first):" << endl;
            viewIncomeByPriceMostExpensive(incomesBinaryTree.getRoot());
            break;
        case '0':
            break;
        default:
            cout << endl << "There is no such option in the menu." << endl << endl;
            system("pause");
            break;
        }

        if (choice != '0') {
            cout << endl;
            system("pause");
        }
    } while (choice != '0');

    deleteBinaryTree(originalTree); // Delete the original tree after viewing incomes

}
void FinanceManager::viewIncomeByDateNewest(BinaryTreeNode<Income>* node) {
    if (node == nullptr) {
        return;
    }

    // Create an empty stack
    std::stack<BinaryTreeNode<Income>*> stack;
    BinaryTreeNode<Income>* current = node;

    // Traverse the tree in reverse order (right, root, left) and store incomes in a stack
    while (current != nullptr || !stack.empty()) {
        // Reach the rightmost node of the current subtree
        while (current != nullptr) {
            stack.push(current);
            current = current->right;
        }

        // Pop the node from the stack
        current = stack.top();
        stack.pop();

        // Store the income in a container
        sortedIncomes.push_back(current->data);

        // Move to the left subtree
        current = current->left;
    }

    // Sort the incomes by date (newest first)
    std::sort(sortedIncomes.begin(), sortedIncomes.end(), []( Income& income1, Income& income2) {
        return income1.getDate() > income2.getDate();
        });

    // Display the sorted incomes
    for (Income& income : sortedIncomes) {
        displayIncome(income);
    }

    // Clear the container
    sortedIncomes.clear();
}

void FinanceManager::viewIncomeByDateOldest(BinaryTreeNode<Income>* node) {
    if (node == nullptr) {
        return;
    }

    // Create a container to store the incomes
    std::vector<Income> sortedIncomes;

    // Traverse the tree in order (left, root, right) and add incomes to the container
    std::stack<BinaryTreeNode<Income>*> stack;
    BinaryTreeNode<Income>* current = node;

    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        stack.pop();

        sortedIncomes.push_back(current->data);

        current = current->right;
    }

    // Sort the incomes by date (oldest first)
    std::sort(sortedIncomes.begin(), sortedIncomes.end(), [](Income& income1, Income& income2) {
        return income1.getDate() < income2.getDate();
        });

    // Display the sorted incomes
    for ( Income& income : sortedIncomes) {
        displayIncome(income);
    }
}

int FinanceManager::countNodes(BinaryTreeNode<Income>* node) {
    if (node == nullptr) {
        return 0;
    }

    return 1 + countNodes(node->left) + countNodes(node->right);
}

void FinanceManager::sortIncomesByAmount(BinaryTreeNode<Income>* node) {
    if (node == nullptr) {
        return;
    }

    // Count the number of nodes in the subtree
    int count = countNodes(node);

    // Perform bubble sort
    for (int i = 0; i < count - 1; ++i) {
        BinaryTreeNode<Income>* current = node;

        // Traverse the subtree and compare adjacent nodes by amount
        while (current->right != nullptr) {
            if (current->data.getAmount() > current->right->data.getAmount()) {
                // Swap the incomes
                Income temp = current->data;
                current->data = current->right->data;
                current->right->data = temp;
            }
            current = current->right;
        }
    }
}

void FinanceManager::displayIncomesByAmount(BinaryTreeNode<Income>* node) {
    if (node == nullptr) {
        return;
    }

    displayIncomesByAmount(node->left);
    displayIncome(node->data);
    displayIncomesByAmount(node->right);
}

void FinanceManager::viewIncomeByPriceCheapest() {
    sortIncomesByAmount(incomesBinaryTree.getRoot());
    displayIncomesByAmount(incomesBinaryTree.getRoot());
}

void FinanceManager::viewIncomeByPriceMostExpensive(BinaryTreeNode<Income>* node) {
    if (node == nullptr) {
        return;
    }

    viewIncomeByPriceMostExpensive(node->right);

    displayIncome(node->data);

    viewIncomeByPriceMostExpensive(node->left);
}

void FinanceManager::displayIncome( Income& income) {
    cout << endl;
    cout << "Income ID:   " << income.getEntryId() << endl;
    cout << "User ID:     " << income.getUserId() << endl;
    cout << "Date:        " << date.changeDateTostring(income.getDate()) << endl;
    cout << "Item:        " << income.getItem() << endl;
    cout << "Amount:      " << income.getAmount() << endl;
}


//<-------------->\\
//View All Expenses And diffrent sorting functions
//<-------------->\\


void FinanceManager::viewAllExpenses()
{
    viewExpense(expensesBinaryTree.getRoot());
    system("pause");
  

}

BinaryTreeNode<Expense>* FinanceManager::copyBinaryTree(BinaryTreeNode<Expense>* node) {
    if (node == nullptr) {
        return nullptr;
    }

    BinaryTreeNode<Expense>* newNode = new BinaryTreeNode<Expense>(node->data);
    newNode->left = copyBinaryTree(node->left);
    newNode->right = copyBinaryTree(node->right);

    return newNode;
}

void FinanceManager::deleteBinaryTree(BinaryTreeNode<Expense>* node) {
    if (node == nullptr) {
        return;
    }

    deleteBinaryTree(node->left);
    deleteBinaryTree(node->right);
    delete node;
}

void FinanceManager::viewExpense(BinaryTreeNode<Expense>* node) {
    char chooice = 0;
    BinaryTreeNode<Expense>* originalTree = copyBinaryTree(expensesBinaryTree.getRoot()); // Create a copy of the original binary tree

    do {
        cin.sync();
        system("cls");

        cout << "Select sorting for expense option:" << endl;
        cout << "1. Sort by date (newest first)" << endl;
        cout << "2. Sort by date (oldest first)" << endl;
        cout << "3. Sort by price (cheapest first)" << endl;
        cout << "4. Sort by price (most expensive first)" << endl;
        cout << "0. Go back to the main menu" << endl;
        cout << "Enter your choice: ";
        chooice = AdjuvantMethods::getChar();

        switch (chooice) {
        case '1':
            system("cls");
            cout << "Sorting by date (newest first):" << endl;
            viewExpenseByDateNewest(originalTree); // Pass the original tree instead of the modified tree
            break;
        case '2':
            system("cls");
            cout << "Sorting by date (oldest first):" << endl;
            viewExpenseByDateOldest(originalTree); // Pass the original tree instead of the modified tree
            break;
        case '3':
            system("cls");
            cout << "Sorting by price (cheapest first):" << endl;
            sortExpenseByAmount(expensesBinaryTree.getRoot());
            displayExpenseByAmount(expensesBinaryTree.getRoot());
            break;
        case '4':
            system("cls");
            cout << "Sorting by price (most expensive first):" << endl;
            viewExpenseByPriceMostExpensive(expensesBinaryTree.getRoot());
            break;
        case '0':
            break;
        default:
            cout << endl << "There is no such option in the menu." << endl << endl;
            system("pause");
            break;
        }

        if (chooice != '0') {
            cout << endl;
            system("pause");
        }
    } while (chooice != '0');

    deleteBinaryTree(originalTree); // Delete the original tree after viewing expenses
}

void FinanceManager::viewExpenseByDateNewest(BinaryTreeNode<Expense>* node) {
    if (node == nullptr) {
        return;
    }

    // Create an empty stack
    std::stack<BinaryTreeNode<Expense>*> stack;
    BinaryTreeNode<Expense>* current = node;

    // Traverse the tree in reverse order (right, root, left) and store expenses in a stack
    while (current != nullptr || !stack.empty()) {
        // Reach the rightmost node of the current subtree
        while (current != nullptr) {
            stack.push(current);
            current = current->right;
        }

        // Pop the node from the stack
        current = stack.top();
        stack.pop();

        // Store the expenses in a container
        sortedExpense.push_back(current->data);

        // Move to the left subtree
        current = current->left;
    }

    // Sort the expenses by date (newest first)
    std::sort(sortedExpense.begin(), sortedExpense.end(), [](Expense& expense1, Expense& expense2) {
        return expense1.getDate() > expense2.getDate();
        });

    // Display the sorted expenses
    for (Expense& expense : sortedExpense) {
        displayExpense(expense);
    }

    // Clear the container
    sortedExpense.clear();
}

void FinanceManager::viewExpenseByDateOldest(BinaryTreeNode<Expense>* node) {
    if (node == nullptr) {
        return;
    }

    // Create a container to store the expenses
    std::vector<Expense> sortedExpense;

    // Traverse the tree in order (left, root, right) and add expenses to the container
    std::stack<BinaryTreeNode<Expense>*> stack;
    BinaryTreeNode<Expense>* current = node;

    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        stack.pop();

        sortedExpense.push_back(current->data);

        current = current->right;
    }

    // Sort the expenses by date (oldest first)
    std::sort(sortedExpense.begin(), sortedExpense.end(), [](Expense& expense1, Expense& expense2) {
        return expense1.getDate() < expense2.getDate();
        });

    // Display the sorted expenses
    for (Expense& Expense : sortedExpense) {
        displayExpense(Expense);
    }
}

int FinanceManager::countNodes(BinaryTreeNode<Expense>* node) {
    if (node == nullptr) {
        return 0;
    }

    return 1 + countNodes(node->left) + countNodes(node->right);
}

void FinanceManager::sortExpenseByAmount(BinaryTreeNode<Expense>* node) {
    if (node == nullptr) {
        return;
    }

    // Count the number of nodes in the subtree
    int count = countNodes(node);

    // Perform bubble sort
    for (int i = 0; i < count - 1; ++i) {
        BinaryTreeNode<Expense>* current = node;

        // Traverse the subtree and compare adjacent nodes by amount
        while (current->right != nullptr) {
            if (current->data.getAmount() > current->right->data.getAmount()) {
                // Swap the expenses
                Expense temp = current->data;
                current->data = current->right->data;
                current->right->data = temp;
            }
            current = current->right;
        }
    }
}

void FinanceManager::displayExpenseByAmount(BinaryTreeNode<Expense>* node) {
    if (node == nullptr) {
        return;
    }

    displayExpenseByAmount(node->left);
    displayExpense(node->data);
    displayExpenseByAmount(node->right);
}

void FinanceManager::viewExpenseByPriceCheapest() {
    sortExpenseByAmount(expensesBinaryTree.getRoot());
    displayExpenseByAmount(expensesBinaryTree.getRoot());
}

void FinanceManager::viewExpenseByPriceMostExpensive(BinaryTreeNode<Expense>* node) {
    if (node == nullptr) {
        return;
    }

    viewExpenseByPriceMostExpensive(node->right);

    displayExpense(node->data);

    viewExpenseByPriceMostExpensive(node->left);
}

void FinanceManager::displayExpense(Expense& expense)
{
    cout << endl;
    cout << "Expense ID:  " << expense.getEntryId() << endl;
    cout << "User ID:     " << expense.getUserId() << endl;
    cout << "Date:        " << date.changeDateTostring(expense.getDate()) << endl;
    cout << "Item:        " << expense.getItem() << endl;
    cout << "Amount:      " << expense.getAmount() << endl;
}


//<-------------->\\
//View Budget Functions
//<-------------->\\


void FinanceManager::viewSelectedIncomes(int minDate, int maxDate, const BinaryTree<Income>& incomesBinaryTree) {
    BinaryTreeNode<Income>* root = incomesBinaryTree.getRoot();

    if (root == nullptr) {
        return;
    }

    std::stack<BinaryTreeNode<Income>*> stack;
    BinaryTreeNode<Income>* current = root;

    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        stack.pop();

        if (current->data.getDate() >= minDate && current->data.getDate() <= maxDate) {
            // Display the selected income (e.g., print its details to the console)
            cout << current->data.getItem() << " - " << current->data.getAmount() << " $" << endl;
        }

        current = current->right;
    }
}


void FinanceManager::viewSelectedExpenses(int minDate, int maxDate, BinaryTree<Expense>& expensesBinaryTree) {
    BinaryTreeNode<Expense>* root = expensesBinaryTree.getRoot();

    if (root == nullptr) {
        return;
    }

    std::stack<BinaryTreeNode<Expense>*> stack;
    BinaryTreeNode<Expense>* current = root;

    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        stack.pop();

        if (current->data.getDate() >= minDate && current->data.getDate() <= maxDate) {
            // Display the selected expense (e.g., print its details to the console)
            cout << current->data.getItem() << " - " << current->data.getAmount() << " $" << endl;
        }

        current = current->right;
    }
}

float FinanceManager::calculateTotalIncome(BinaryTreeNode<Income>* node, int minDate, int maxDate) {
    if (node == nullptr) {
        return 0.0f;
    }

    float total = 0.0f;
    if (node->data.getDate() >= minDate && node->data.getDate() <= maxDate) {
        total += node->data.getAmount();
    }

    total += calculateTotalIncome(node->left, minDate, maxDate);
    total += calculateTotalIncome(node->right, minDate, maxDate);

    return total;
}

float FinanceManager::calculateTotalExpense(BinaryTreeNode<Expense>* node, int minDate, int maxDate) {
    if (node == nullptr) {
        return 0.0f;
    }

    float total = 0.0f;
    if (node->data.getDate() >= minDate && node->data.getDate() <= maxDate) {
        total += node->data.getAmount();
    }

    total += calculateTotalExpense(node->left, minDate, maxDate);
    total += calculateTotalExpense(node->right, minDate, maxDate);

    return total;
}

void FinanceManager::viewCurrentMonthBalance()
{
    int currentDate = date.changeDateToIntNumber(date.getCurrentDateFromSystem());
    int minDate = (currentDate / 100) * 100 + 1;
    int maxDate = (currentDate / 100 + 1) * 100;

    system("cls");

    cout << ">>> INCOMES OF CURRENT MONTH  <<<\n" << endl;
    viewSelectedIncomes(minDate, maxDate, incomesBinaryTree);

    cout << ">>> EXPENSES OF CURRENT MONTH <<<\n" << endl;
    viewSelectedExpenses(minDate, maxDate, expensesBinaryTree);

    cout << ">>>   CURRENT MONTH SUMMARY   <<<\n" << endl;
    cout << "\nTotal income:     " << calculateTotalIncome(incomesBinaryTree.getRoot(), minDate, maxDate) << " $" << endl;
    cout << "Total expense:    " << calculateTotalExpense(expensesBinaryTree.getRoot(), minDate, maxDate) << " $" << endl;
    cout << "Month Balance:    " << showpos << calculateTotalIncome(incomesBinaryTree.getRoot(), minDate, maxDate) - calculateTotalExpense(expensesBinaryTree.getRoot(), minDate, maxDate) << " $" << endl << endl;
    cout << noshowpos;

    system("pause");
}

void FinanceManager::viewBalanceOfSelectedPeriod()
{
    system("cls");

    int date1 = 0, date2 = 0, minDate = 0, maxDate = 0;
    cout << "Enter a start date and an end date of the period that you want to review: " << endl;
    cout << "\nEnter a start date: " << endl;
    date.getDateFromUser();
    date1 = date.getDateInteger();
    cout << "\nEnter an end date: " << endl;
    date.getDateFromUser();
    date2 = date.getDateInteger();

    if (date1 < date2)
    {
        minDate = date1;
        maxDate = date2;
    }
    else
    {
        minDate = date2;
        maxDate = date1;
    }

    system("cls");

    cout << ">>> INCOMES OF SELECTED PERIOD  <<<\n" << endl;
    viewSelectedIncomes(minDate, maxDate, incomesBinaryTree);

    cout << ">>> EXPENSES OF SELECTED PERIOD <<<\n" << endl;
    viewSelectedExpenses(minDate, maxDate, expensesBinaryTree);

    float totalIncome = calculateTotalIncome(incomesBinaryTree.getRoot(), minDate, maxDate);
    float totalExpense = calculateTotalExpense(expensesBinaryTree.getRoot(), minDate, maxDate);

    cout << ">>>   SELECTED PERIOD SUMMARY   <<<\n" << endl;
    cout << "\nTotal income:     " << totalIncome << " $" << endl;
    cout << "Total expense:    " << totalExpense << " $" << endl;
    cout << "Month Balance:    " << showpos << totalIncome - totalExpense << " $" << endl << endl;
    cout << noshowpos;

    system("pause");
}

//<-------------->\\
//Search functions
//<-------------->\\

void FinanceManager::searchIncomesAndExpenses()
{
    system("cls");
    cout << ">>> SEARCH <<<" << endl << endl;
    cout << "Enter an item to search: ";
    string keyword;
    cin >> keyword;

   

    bool resultsFound = false;

    cout << ">>> INCOME RESULTS <<<" << endl;
    searchIncomeByItemRecursive(incomesBinaryTree.getRoot(), keyword, resultsFound);

    cout << ">>> EXPENSE RESULTS <<<" << endl;
    searchExpenseByItemRecursive(expensesBinaryTree.getRoot(), keyword, resultsFound);

    if (!resultsFound)
        cout << "No results found for the item: " << keyword << endl;

    system("pause");
}

void FinanceManager::searchIncomeByItemRecursive(BinaryTreeNode<Income>* node, const string& keyword, bool& resultsFound)
{
    if (node == nullptr)
        return;

    searchIncomeByItemRecursive(node->left, keyword, resultsFound);

    if (node->data.getItem() == keyword) {
        displayIncome(node->data);
        // Output other income details as needed
        resultsFound = true;
    }

    searchIncomeByItemRecursive(node->right, keyword, resultsFound);
}

void FinanceManager::searchExpenseByItemRecursive(BinaryTreeNode<Expense>* node, const string& keyword, bool& resultsFound)
{
    if (node == nullptr)
        return;

    searchExpenseByItemRecursive(node->left, keyword, resultsFound);

    if (node->data.getItem() == keyword) {
        displayExpense(node->data);
        resultsFound = true;
    }

    searchExpenseByItemRecursive(node->right, keyword, resultsFound);
}








void FinanceManager::generateMonthlyIncomeChart()
{
    system("cls");

    int date1 = 0, date2 = 0, minDate = 0, maxDate = 0;
    std::cout << "Enter a start date and an end date of the period that you want to review:" << std::endl;
    std::cout << "Enter a start date: " << std::endl;
    date.getDateFromUser();
    date1 = date.getDateInteger();
    std::cout << "Enter an end date: " << std::endl;
    date.getDateFromUser();
    date2 = date.getDateInteger();

    if (date1 < date2)
    {
        minDate = date1;
        maxDate = date2;
    }
    else
    {
        minDate = date2;
        maxDate = date1;
    }

    system("cls");

    cout << ">>> INCOMES OF SELECTED PERIOD  <<<\n" << endl;
    viewSelectedIncomes(minDate, maxDate, incomesBinaryTree);

    cout << ">>> EXPENSES OF SELECTED PERIOD <<<\n" << endl;
    viewSelectedExpenses(minDate, maxDate, expensesBinaryTree);

    float totalIncome = calculateTotalIncome(incomesBinaryTree.getRoot(), minDate, maxDate);
    float totalExpense = calculateTotalExpense(expensesBinaryTree.getRoot(), minDate, maxDate);

    cout << ">>>   SELECTED PERIOD SUMMARY   <<<\n" << endl;
    cout << "\nTotal income:     " << totalIncome << " $" << endl;
    cout << "Total expense:    " << totalExpense << " $" << endl;
    cout << "Month Balance:    " << std::showpos << totalIncome - totalExpense << " $" << std::noshowpos << endl << endl;


    // Calculate monthly incomes within the given period
    std::vector<int> monthlyIncomes(12 * (maxDate / 10000 - minDate / 10000 + 1), 0); // Vector to store the income amount for each month

    // Iterate over the income nodes and sum the income amount for each month
    countMonthlyIncomes(incomesBinaryTree.getRoot(), minDate, maxDate, monthlyIncomes);

    std::cout << ">>>   SELECTED PERIOD INCOME SUMMARY   <<<\n" << std::endl;

    int startMonth = (minDate % 10000) / 100;
    int endMonth = (maxDate % 10000) / 100;
    int startYear = minDate / 10000;
    int endYear = maxDate / 10000;

    bool hasIncomes = false; // Flag to track if there are any incomes in the selected period

    int maxIncomeAmount = *std::max_element(monthlyIncomes.begin(), monthlyIncomes.end()); // Get the maximum income amount

    for (int year = endYear; year >= startYear; year--)
    {
        std::cout << ">>>   INCOME SUMMARY " << year << "   <<<\n" << std::endl; // Print the new line with the income summary for the current year

        // Print the "#" representing income and "---" representing month labels in the same loop
        for (int i = maxIncomeAmount; i >= 100; i -= 100)
        {
            bool monthHasIncomes = false; // Flag to track if the month has any incomes

            for (int month = 1; month <= 12; month++)
            {
                if ((year == endYear && month <= endMonth) || (year > startYear && year < endYear) || (year == startYear && month >= startMonth))
                {
                    int incomeAmount = monthlyIncomes[(endYear - year) * 12 + (month - 1)];
                    int numLines = (incomeAmount + 99) / 100; // Number of lines of "#" to represent the income amount

                    if (numLines >= i / 100)
                    {
                        monthHasIncomes = true;
                        hasIncomes = true;
                        std::cout << "### ";
                    }
                    else
                    {
                        std::cout << "    "; // Print empty space if no income or below the current height level
                    }
                }
            }
            std::cout << std::endl;
        }

        // Print month labels below each column
        for (int month = 1; month <= 12; month++)
        {
            if ((year == endYear && month <= endMonth) || (year < endYear && year > startYear) || (year == startYear && month >= startMonth))
            {
                std::cout << "--- ";
            }
        }
        std::cout << std::endl;

        // Print month numbers below each column
        for (int month = 1; month <= 12; month++)
        {
            if ((year == endYear && month <= endMonth) || (year < endYear && year > startYear) || (year == startYear && month >= startMonth))
            {
                std::cout << " " << month << "  ";
            }
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }

    if (!hasIncomes)
    {
        std::cout << "No incomes found in the selected period." << std::endl;
    }

    // Calculate monthly expenses within the given period
    std::vector<int> monthlyExpenses(12 * (maxDate / 10000 - minDate / 10000 + 1), 0); // Vector to store the expense amount for each month

    // Iterate over the expense nodes and sum the expense amount for each month
    countMonthlyExpenses(expensesBinaryTree.getRoot(), minDate, maxDate, monthlyExpenses);

    std::cout << ">>>   SELECTED PERIOD EXPENSE SUMMARY   <<<\n" << std::endl;

    int maxExpenseAmount = *std::max_element(monthlyExpenses.begin(), monthlyExpenses.end()); // Get the maximum expense amount

    for (int year = endYear; year >= startYear; year--)
    {
        std::cout << ">>>   EXPENSE SUMMARY " << year << "   <<<\n" << std::endl; // Print the new line with the expense summary for the current year

        // Print the "#" representing expense and "---" representing month labels in the same loop
        for (int i = maxExpenseAmount; i >= 100; i -= 100)
        {
            bool monthHasExpenses = false; // Flag to track if the month has any expenses

            for (int month = 1; month <= 12; month++)
            {
                if ((year == endYear && month <= endMonth) || (year > startYear && year < endYear) || (year == startYear && month >= startMonth))
                {
                    int expenseAmount = monthlyExpenses[(endYear - year) * 12 + (month - 1)];
                    int numLines = (expenseAmount + 99) / 100; // Number of lines of "#" to represent the expense amount

                    if (numLines >= i / 100)
                    {
                        monthHasExpenses = true;
                        std::cout << "### ";
                    }
                    else
                    {
                        std::cout << "    "; // Print empty space if no expense or below the current height level
                    }
                }
             
            }
            std::cout << std::endl;
        }

        // Print month labels below each column
        for (int month = 1; month <= 12; month++)
        {
            if ((year == endYear && month <= endMonth) || (year < endYear && year > startYear) || (year == startYear && month >= startMonth))
            {
                std::cout << "--- ";
            }
        }
        std::cout << std::endl;

        // Print month numbers below each column
        for (int month = 1; month <= 12; month++)
        {
            if ((year == endYear && month <= endMonth) || (year < endYear && year > startYear) || (year == startYear && month >= startMonth))
            {
                std::cout << " " << month << "  ";
            }
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }

    if (maxExpenseAmount == 0)
    {
        std::cout << "No expenses found in the selected period." << std::endl;
    }

    system("pause");
}






void FinanceManager::countMonthlyIncomes(BinaryTreeNode<Income>* node, int minDate, int maxDate, std::vector<int>& monthlyIncomes)
{
    if (node == nullptr)
        return;

    countMonthlyIncomes(node->left, minDate, maxDate, monthlyIncomes);

    int incomeDate = node->data.getDate();
    std::string incomeDateStr = std::to_string(incomeDate); // Convert the date integer to string

    int year = std::stoi(incomeDateStr.substr(0, 4)); // Extract the year from the date string
    int month = std::stoi(incomeDateStr.substr(4, 2)); // Extract the month from the date string

    if (incomeDate >= minDate && incomeDate <= maxDate && year >= minDate / 10000 && year <= maxDate / 10000 && month >= 1 && month <= 12)
    {
        int incomeAmount = node->data.getAmount();
        int yearOffset = (maxDate / 10000) - year;
        int monthIndex = (yearOffset * 12) + month - 1;
        monthlyIncomes[monthIndex] += incomeAmount;
    }

    countMonthlyIncomes(node->right, minDate, maxDate, monthlyIncomes);
}

void FinanceManager::countMonthlyExpenses(BinaryTreeNode<Expense>* node, int minDate, int maxDate, std::vector<int>& monthlyExpenses)
{
    if (node == nullptr)
        return;

    countMonthlyExpenses(node->left, minDate, maxDate, monthlyExpenses);

    int expenseDate = node->data.getDate();
    std::string expenseDateStr = std::to_string(expenseDate); // Convert the date integer to string

    int year = std::stoi(expenseDateStr.substr(0, 4)); // Extract the year from the date string
    int month = std::stoi(expenseDateStr.substr(4, 2)); // Extract the month from the date string

    if (expenseDate >= minDate && expenseDate <= maxDate && year >= minDate / 10000 && year <= maxDate / 10000 && month >= 1 && month <= 12)
    {
        int expenseAmount = node->data.getAmount();
        int yearOffset = (maxDate / 10000) - year;
        int monthIndex = (yearOffset * 12) + month - 1;
        monthlyExpenses[monthIndex] += expenseAmount;
    }

    countMonthlyExpenses(node->right, minDate, maxDate, monthlyExpenses);
}





void FinanceManager::insertRandomIncomeToTree() {
    std::string Item[] = { "Salary", "Bonus", "Investment", "Gift" };
    std::string ItemExp[] = { "Car", "Rent", "Food", "Morgage" };
    double minAmount;
    double maxAmount;

    system("cls");

    std::cout << "Enter a start date and an end date of the period that you want to review: " << std::endl;
    Date startDate, endDate;

    std::cout << "\nEnter a start date: " << std::endl;
    startDate.getDateFromUser();
    int date1 = startDate.getDateInteger();

    std::cout << "\nEnter an end date: " << std::endl;
    endDate.getDateFromUser();
    int date2 = endDate.getDateInteger();

 

    std::cout << "Enter the minimum amount: ";
    std::cin >> minAmount;

    std::cout << "Enter the maximum amount: ";
    std::cin >> maxAmount;

    int numIncomes = 0;
    std::cout << "Enter the number of random incomes/expenses to generate: ";
    std::cin >> numIncomes;

    int lastIncomeId = 0;
    int lastExpenseId = 0;

    for (int i = 0; i < numIncomes * 2; ++i) {
        // Generate a random amount within the given range
        double amount = minAmount + static_cast<double>(rand()) / (RAND_MAX / (maxAmount - minAmount));

        // Generate a random date within the given range
        int minYear = date1 / 10000;
        int minMonth = (date1 % 10000) / 100;
        int minDay = date1 % 100;

        int maxYear = date2 / 10000;
        int maxMonth = (date2 % 10000) / 100;
        int maxDay = date2 % 100;

        // Generate a random year between minYear and maxYear
        int year = minYear + rand() % (maxYear - minYear + 1);

        
        int month;
        if (year == minYear && year == maxYear) {
           
            month = minMonth + rand() % (maxMonth - minMonth + 1);
        }
        else if (year == minYear) {
          
            month = minMonth + rand() % (13 - minMonth);
        }
        else if (year == maxYear) {
            
            month = 1 + rand() % (maxMonth + 1);
        }
        else {

            month = 1 + rand() % 12;
        }

        int day = 1 + rand() % 30;
        
        std::string name = Item[rand() % 4];
        std::string nameExp = ItemExp[rand() % 4];
        int date = year * 10000 + month * 100 + day;

        // Generate a random type (income or expense)
        bool isIncome = rand() % 2 ;

        if (isIncome) {
            Income income;
            income.setIncomeId(++lastIncomeId);
            income.setUserId(CURRENT_USER_ID);
            income.setDate(date);
            income.setItem(name);
            income.setAmount(amount);

            incomesBinaryTree.insertNode(income);
        }
        else {
            Expense expense;
            expense.setExpenseId(++lastExpenseId);
            expense.setUserId(CURRENT_USER_ID);
            expense.setDate(date);
            expense.setItem(nameExp);
            expense.setAmount(amount);

            expensesBinaryTree.insertNode(expense);
        }
    }
}




