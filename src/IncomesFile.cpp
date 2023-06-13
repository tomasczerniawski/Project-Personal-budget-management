#include "BinaryTree.h"
#include "IncomesFile.h"



BinaryTree<Income> IncomesFile::loadIncomesOfCurrentUserFromXmlFile(int CURRENT_USER_ID)
{
    CMarkup xml;
    BinaryTree<Income> incomesBinaryTree;

    if (fileExist(xml))
    {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Income"))
        {
            Income income;
            xml.IntoElem();
            xml.FindElem("IncomeId");
            int incomeId = atoi(xml.GetElemContent());
            xml.FindElem("UserId");
            int userId = atoi(xml.GetElemContent());
            if (userId == CURRENT_USER_ID)
            {
                income.setUserId(userId);
                income.setIncomeId(incomeId);
                xml.FindElem("Date");
                std::string dateStr(xml.GetElemContent().GetString());
                income.setDate(date.changeDateToIntNumber(dateStr));
                xml.FindElem("Item");
                income.setItem(static_cast<LPCTSTR>(xml.GetElemContent()));
                xml.FindElem("Amount");
                float amount = AdjuvantMethods::stringToFloatConversion(CStringA(xml.GetElemContent()).GetString());
                income.setAmount(amount);
                incomesBinaryTree.insertNode(income);  // Insert the income into the BinaryTree
            }
            xml.OutOfElem();
        }
    }
    return incomesBinaryTree;
}


bool IncomesFile::addIncomeToXmlFile(Income income, Date date)
{
    CMarkup xml;

    if (!fileExist(xml))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();

    // Generate a new and unique income ID
    int newIncomeId = getLastIncomeIdFromFile() + 1;

    // Add a new income entry
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", newIncomeId);  // Use the new income ID
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", date.getDateString().c_str());
    xml.AddElem("Item", income.getItem().c_str());
    xml.AddElem("Amount", AdjuvantMethods::floatToStringConversion(income.getAmount()).c_str());
    xml.OutOfElem();

    xml.Save(getFilename().c_str());

    if (!fileExist(xml))
    {
        std::cout << "Cannot open the " << getFilename() << " file." << std::endl;
        return false;
    }

    return true;
}

int IncomesFile::getLastIncomeIdFromFile()
{
    CMarkup xml;

    if (fileExist(xml))
    {
        int lastIncomeId = 0;
        std::string currentIncomeIdStr;

        xml.FindElem();  // Find the root element
        xml.IntoElem();  // Move into the root element

        while (xml.FindElem("Income"))  // Find each "Income" element
        {
            xml.FindChildElem("IncomeId");  // Find the "IncomeId" child element
            currentIncomeIdStr = xml.GetChildData();  // Get the value of "IncomeId" as a string
            int currentIncomeId = std::stoi(currentIncomeIdStr);  // Convert the string to an integer

            if (currentIncomeId > lastIncomeId)  // Update the last income ID if the current ID is greater
                lastIncomeId = currentIncomeId;
        }

        return lastIncomeId;
    }

    return 0;  // Return 0 if the file doesn't exist or no income entries are found
}


int IncomesFile::getLastIncomeId()
{
    CMarkup xml;
    int lastIncomeId = 0;

    if (fileExist(xml))
    {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Income"))
        {
            xml.FindChildElem("IncomeId");
            lastIncomeId = std::atoi(xml.GetChildData().GetString());
        }
    }

    return lastIncomeId;
}