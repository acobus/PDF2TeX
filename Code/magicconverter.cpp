#include "magicconverter.h"
#include "utility.h"
#include <Magick++.h>

using namespace Magick;

using namespace std;
using namespace utility;

MagicConverter::MagicConverter(char *&argv, string &target)
{
    // PDF einlesen und in Zieldatei speichern
    InitializeMagick(argv);
    Image img;
    img.density(Magick::Geometry(300,300));
    img.read(target);
    string pic=utility::replace(target,".pdf",".png");
    img.write(pic);
}
