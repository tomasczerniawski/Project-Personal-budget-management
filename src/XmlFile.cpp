#include "XmlFile.h"

bool XmlFile::fileExist(CMarkup& xml)
{
    return xml.Load(getFilename().c_str());
}

std::string XmlFile::getFilename()
{
    return FILENAME;
}
