#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include "XmlFile.h"

#include "Income.h"

using namespace std;

class IncomesFile : public XmlFile
{
    int lastIncomeId;
    BinaryTree<Income> incomesBinaryTree;
    int getLastIncomeIdFromFile();

public:
    IncomesFile(string incomesFilename) : XmlFile(incomesFilename)
    {
        lastIncomeId = getLastIncomeIdFromFile();
    }
    BinaryTree<Income> loadIncomesOfCurrentUserFromXmlFile(int CURRENT_USER_ID);

    bool addIncomeToXmlFile(Income income, Date date);
    int getLastIncomeId();

};

#endif