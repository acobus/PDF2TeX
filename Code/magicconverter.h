#ifndef MAGICCONVERTER_H
#define MAGICCONVERTER_H

#include "filemanager.h"

#include <string>

using namespace std;

class MagicConverter
{
public:
    MagicConverter(FileManager *pFman);

    void pdf2png();

private:
    FileManager *fman;
};

#endif // MAGICCONVERTER_H
