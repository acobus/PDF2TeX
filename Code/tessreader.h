#ifndef TESSREADER_H
#define TESSREADER_H

#include "filemanager.h"

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <string>

using namespace std;

class TessReader
{
public:
    TessReader(FileManager *pFman);
    void startReading();
    void setTarget(string pTarget);
    string getTarget();

private:
    char *outText;
    FileManager *fman;
    tesseract::TessBaseAPI *api;
};

#endif // TESSREADER_H
