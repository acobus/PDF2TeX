#ifndef TEXPARSER_H
#define TEXPARSER_H

#include <fstream>

using namespace std;

class TexParser
{
public:
    TexParser();
    void parseText(const char* input);

private:
    void makeBeginning();
    void makeEnding();

    ofstream texdat;
};

#endif // TEXPARSER_H
