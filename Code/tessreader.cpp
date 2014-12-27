#include "tessreader.h"
#include "utility.h"
#include "filemanager.h"
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

#include <iostream>

using namespace std;

TessReader::TessReader(FileManager *pFman)
{
    fman=pFman;

    api = new tesseract::TessBaseAPI();
    // Sprachoptionen variieren?
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Tesseract konnte nicht initialisiert werden.\n");
        exit(1);
    }

}

void TessReader::startReading(){
    // .png verarbeiten
    string tessTarget=fman->getTarget();
    tessTarget=utility::replace(tessTarget,".pdf",".png");
    Pix *image = pixRead(tessTarget.c_str());
    api->SetImage(image);
    outText = api->GetUTF8Text();
    printf("Eingelesener Text:\n%s", outText);

    // Speicher freigeben
    api->End();
    delete [] outText;
    pixDestroy(&image);
}


