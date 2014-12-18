#include <magicconverter.h>
#include <tessreader.h>
#include <fileopener.h>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    // Zieldateien, vorläufig hier angegeben
    string target="../Documents/Summentest.tif";
    string document="../Documents/Summentest.pdf";

    FileOpener *wind = new FileOpener(argc,argv);
    wind->openDialog();

    MagicConverter magic(*argv,document,target);

    TessReader tessi(target);

    return 0;
}
