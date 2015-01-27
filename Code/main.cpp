#include "texparser.h"
#include "magicconverter.h"
#include "tessreader.h"
#include "fileopener.h"
#include "utility.h"
#include "filemanager.h"

#include <QApplication>

#include <string>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{

    // temp-Verzeichnis leeren
    utility::emptyTemp();

    FileManager *fman=new FileManager;

    // LogoAnzeige
    char logo[]="../Documents/Logo.png";
    fman->setLogo(logo);

    // Target Standardbelegung
    fman->setTarget(fman->getLogo());

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

    // Datei ausgewählt?
    if(!fman->getTarget().compare(fman->getLogo())){
        cout<<"\n ****Abbruch**** \n";
        return 0;
    }

    // Konvertierung in passendes Format
    magic.pdf2png(300,false);

    // OCR-interpretierung
    stringstream input;
    string tessTarget;
    //fman->setNumb(1);
    for(int page=0;page<fman->getNumb();page++){
        tessTarget="../temp/pg" + utility::convertInt(page) + ".png";
        input << tessi.startReading(tessTarget);
    }
    tessi.endReading();

    // .tex erzeugen
    TexParser parser;
    parser.parseText(input.str());

    return 0;
}
