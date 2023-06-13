#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "AdjuvantMethods.h"
#include "Date.h"

using namespace std;

class XmlFile
{
    const string FILENAME;

public:
    Date date;
    XmlFile(string filename) : FILENAME(filename) {}
    bool fileExist(CMarkup& xml);
    string getFilename();
};

#endif // XMLFILE_H
