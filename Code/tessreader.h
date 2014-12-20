#ifndef TESSREADER_H
#define TESSREADER_H

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <string>

using namespace std;

class TessReader
{
public:
    TessReader(string target);
    void startReading();
    void setTarget(string pTarget);
    string getTarget();

    char *outText;
    const char *target;
    tesseract::TessBaseAPI *api;
};

#endif // TESSREADER_H
