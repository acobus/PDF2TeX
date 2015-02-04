#include "magicconverter.h"
#include "utility.h"
#include <string>
#include <fstream>
#include <Magick++.h>

#include <iostream>
#include <vector>

using namespace Magick;

using namespace std;
using namespace utility;

MagicConverter::MagicConverter(FileManager *pFman)
{
    fman=pFman;
}

/*
 * Startet Konvertierung in .png Format.
 * Es wird das Bild bearbeitet, welches in FileManager als
 * target hinterlegt ist.
 * Input:
 *  dense               Kompaktheit des Bildes
 *  page_vec            Vektor mit zu parsenden Seiten
 *
 */
bool MagicConverter::pdf2png(int dense, vector<int> page_vec){
    string target = fman->getTarget();
    // PDF einlesen und in Zieldatei speichern
    InitializeMagick(*fman->getArgv());
    Image img;
    img.density(Magick::Geometry(dense,dense));
    string page_s;
    for (int i=0; i<page_vec.size();i++){
        page_s="../temp/pg" + utility::convertInt(page_vec[i]) + ".png";
        // Überprüfe zunächst, ob Seite bereits vorliegt
        if (utility::pageConverted(page_s)) continue;
        try{
            img.read(target + "[" + utility::convertInt(page_vec[i]-1) + "]");
            img.write(page_s);
        // Letzte Seite gelesen
        }catch(Magick::ErrorDelegate error){
            return false;
        }
    }
    return true;
}
