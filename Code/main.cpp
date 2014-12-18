#include <magicconverter.h>
#include <tessreader.h>
#include <fileopener.h>
#include <string>

using namespace std;

int main(int /*argc*/, char ** argv)
{

    // Zieldateien, vorläufig hier angegeben
    string target="../Documents/Summentest.tif";
    string document="../Documents/Summentest.pdf";

    FileOpener wind();

    MagicConverter magic(*argv,document,target);

    TessReader tessi(target);

    return 0;
}
