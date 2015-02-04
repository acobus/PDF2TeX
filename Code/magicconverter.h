#ifndef MAGICCONVERTER_H
#define MAGICCONVERTER_H

#include "filemanager.h"

#include <vector>

#include <string>

using namespace std;

class MagicConverter
{
public:
    MagicConverter(FileManager *pFman);

    bool pdf2png(int dense, vector<int> page_vec);

private:
    FileManager *fman;
};

#endif // MAGICCONVERTER_H
