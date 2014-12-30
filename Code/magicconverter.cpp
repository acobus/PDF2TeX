#include "magicconverter.h"
#include "utility.h"
#include <Magick++.h>

using namespace Magick;

using namespace std;
using namespace utility;

MagicConverter::MagicConverter(FileManager *pFman)
{
    fman=pFman;
}

void MagicConverter::pdf2png(int dense){
    string target = fman->getTarget();
    // PDF einlesen und in Zieldatei speichern
    InitializeMagick(*fman->getArgv());
    Image img;
    img.density(Magick::Geometry(dense,dense));
    img.read(target);
    string pic=utility::replace(target,".pdf",".png");
    img.write(pic);
}
