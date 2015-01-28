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
    vector<int> pages_vec=fman->getPageVec();
    magic.pdf2png(300,pages_vec);

    // OCR-interpretierung
    stringstream input;
    string tessTarget;
    for(int i=0; i<pages_vec.size(); i++){
        tessTarget="../temp/pg" + utility::convertInt(pages_vec[i]-1) + ".png";
        input << tessi.startReading(tessTarget);
    }
    tessi.endReading();

    // .tex erzeugen
    TexParser parser;
    parser.parseText(input.str());

    return 0;
}
