#ifndef MAGICCONVERTER_H
#define MAGICCONVERTER_H

#include "filemanager.h"

#include <string>

using namespace std;

class MagicConverter
{
public:
    MagicConverter(FileManager *pFman);

    void pdf2png(int dense, bool defineNumbPages);

private:
    FileManager *fman;
};

#endif // MAGICCONVERTER_H
