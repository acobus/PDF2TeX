#include "magicconverter.h"
#include "tessreader.h"
#include "fileopener.h"
#include "utility.h"
#include "filemanager.h"

#include <QApplication>

#include <string>
#include <stdio.h>
#include <iostream>
#include <sys/stat.h>

using namespace std;

int main(int argc, char *argv[])
{
    // Funktioniert nur unter Linux
    // Allgemeinere Variante?!
    system("rm -r ../temp");
    mkdir("../temp",0777);

    FileManager *fman=new FileManager;

    // Automatisch bearbeitete Datei
    fman->setTarget("");

    // LogoAnzeige
    char logo[]="../Documents/Logo.png";
    fman->setLogo(logo);

    // Anzahl Seiten initial auf 0 setzen
    fman->setNumb(0);

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

    magic.pdf2png(300,false);

    tessi.startReading();

    return 0;
}
