#include "magicconverter.h"
#include <Magick++.h>

using namespace Magick;

using namespace std;

MagicConverter::MagicConverter(char *&argv, string &document, string &target)
{
    // PDF einlesen und in Zieldatei speichern
    InitializeMagick(argv);
    Image img;
    img.density(Magick::Geometry(300,300));
    img.read(document);
    img.write(target);
}
