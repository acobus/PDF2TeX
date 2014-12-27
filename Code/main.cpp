#include "magicconverter.h"
#include "tessreader.h"
#include "fileopener.h"
#include "utility.h"
#include "filemanager.h"

#include <string>
#include <QApplication>

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    FileManager *fman=new FileManager;

    // Automatisch bearbeitete Datei
    fman->setTarget("../Documents/Summentest.pdf");

    fman->setArgc(argc);
    fman->setArgv(argv);

    MagicConverter magic(fman);

    TessReader tessi(fman);

    QApplication app(argc,argv);
    FileOpener *dialogue = new FileOpener(&tessi,&magic,fman);
    dialogue->show();
    app.exec();

    if(fman->getTarget().empty()){
        return 0;
    }

    magic.pdf2png();

    tessi.startReading();

    return 0;
}
