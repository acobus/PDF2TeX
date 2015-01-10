#include "magicconverter.h"
#include "utility.h"
#include <string>
#include <fstream>
#include <Magick++.h>

#include <iostream>

using namespace Magick;

using namespace std;
using namespace utility;

MagicConverter::MagicConverter(FileManager *pFman)
{
    fman=pFman;
}

void MagicConverter::pdf2png(int dense,bool defineNumbPages){
    string target = fman->getTarget();
    // PDF einlesen und in Zieldatei speichern
    InitializeMagick(*fman->getArgv());
    Image img;
    img.density(Magick::Geometry(dense,dense));
    int page;
    string page_s;
    for (page=0;true;page++){
        if(!defineNumbPages && page>=fman->getNumb()){
            return;
        }
        page_s="../temp/pg" + utility::convertInt(page) + ".png";
        try{
            img.read(target + "[" + utility::convertInt(page) + "]");
            // Nur die erste konvertieren
            if((page==0 && defineNumbPages)||!defineNumbPages){
                img.write(page_s);
            }
        // Letzte Seite gelesen
        }catch(Magick::ErrorDelegate error){
            fman->setNumb(page);
            return;
        }
    }
}
