#include "tessreader.h"
#include "utility.h"
#include "filemanager.h"
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

#include <iostream>

using namespace std;

/*
 * Initialisierung der OCR-Einheit.
 * Hier wird insbesondere das Sprachpaket festgelegt.
 */
TessReader::TessReader(FileManager *pFman)
{
    fman=pFman;

    api = new tesseract::TessBaseAPI();
    // Sprachoptionen variieren?
    if (api->Init("../Code/", "eng")) {
        fprintf(stderr, "Tesseract konnte nicht initialisiert werden.\n");
        exit(1);
    }
}

/*
 * Diese funktion leitet ein gegebenes Bild (tessTarget)
 * zum Auslesen an tesseract weiter.
 * Ausgabe ist der gelesene Text.
 */
const char* TessReader::startReading(string tessTarget){
    // .png verarbeiten
    Pix *image = pixRead(tessTarget.c_str());
    api->SetImage(image);
    outText = api->GetUTF8Text();
    //printf("Eingelesener Text:\n%s", outText);

    pixDestroy(&image);

    return outText;
}

/*
 * Hier wird nach fertiger OCR-Interpretierung
 * der Speicher durch löschen der Objekte frei
 * gegeben.
 */
void TessReader::endReading(){
    delete [] outText;
    api->End();
}


