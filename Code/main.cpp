#include "texparser.h"
#include "magicconverter.h"
#include "tessreader.h"
#include "fileopener.h"
#include "utility.h"
#include "filemanager.h"

#include <QApplication>

#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    // temp-Verzeichnis leeren
    utility::emptyTemp();

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

    // Datei ausgewählt?
    if(fman->getTarget().empty()){
        return 0;
    }

    // Konvertierung in passendes Format
    magic.pdf2png(300,false);

    // OCR-interpretierung
    const char *pdfText=tessi.startReading();

    // .tex erzeugen
    TexParser parser;
    parser.parseText(pdfText);

    return 0;
}
