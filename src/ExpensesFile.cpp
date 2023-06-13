#include "BinaryTree.h"
#include "ExpensesFile.h"


BinaryTree<Expense> ExpensesFile::loadExpensesOfCurrentUserFromXmlFile(int CURRENT_USER_ID)
{
    CMarkup xml;
    BinaryTree<Expense> expensesBinaryTree;

    if (fileExist(xml))
    {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Expense"))
        {
            Expense expense;
            xml.IntoElem();
            xml.FindElem("ExpenseId");
            int expenseId = atoi(xml.GetElemContent());
            xml.FindElem("UserId");
            int userId = atoi(xml.GetElemContent());
            if (userId == CURRENT_USER_ID)
            {
                expense.setUserId(userId);
                expense.setExpenseId(expenseId);
                xml.FindElem("Date");
                std::string dateStr(xml.GetElemContent().GetString());
                expense.setDate(date.changeDateToIntNumber(dateStr));
                xml.FindElem("Item");
                expense.setItem(static_cast<LPCTSTR>(xml.GetElemContent()));
                xml.FindElem("Amount");
                float amount = AdjuvantMethods::stringToFloatConversion(CStringA(xml.GetElemContent()).GetString());
                expense.setAmount(amount);
                expensesBinaryTree.insertNode(expense);  // Insert the expenses into the BinaryTree
            }
            xml.OutOfElem();
        }
    }
    return expensesBinaryTree;
}





bool ExpensesFile::addExpenseToXmlFile(Expense expense, Date date)
{
    CMarkup xml;

    if (!fileExist(xml))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getEntryId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", date.getDateString().c_str());
    xml.AddElem("Item", expense.getItem().c_str());
    xml.AddElem("Amount", AdjuvantMethods::floatToStringConversion(expense.getAmount()).c_str());
    xml.OutOfElem();

    xml.Save(getFilename().c_str());
   

    if (!fileExist(xml))
    {
        cout << "Cannot open the " << getFilename() << " file." << endl;
        return false;
    }

    return true;
}


int ExpensesFile::getLastExpenseIdFromFile()
{
    CMarkup xml;
    BinaryTree<Expense> expensesBinaryTree;
    if (fileExist(xml))
    {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Expense"))
        {
            xml.FindChildElem("ExpenseId");
        }
        return lastExpenseId = AdjuvantMethods::stringToIntConversion(std::string(CT2A(xml.GetChildData())));

    }
    else
        return 0;
}

int ExpensesFile::getLastExpenseId()
{
    return lastExpenseId;
}