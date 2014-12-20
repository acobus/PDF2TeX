#include "tessreader.h"
#include "utility.h"
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

#include <iostream>

using namespace std;

TessReader::TessReader(string pTarget)
{
    setTarget(pTarget);

    api = new tesseract::TessBaseAPI();
    // Sprachoptionen variieren?
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Tesseract konnte nicht initialisiert werden.\n");
        exit(1);
    }

}

void TessReader::startReading(){
    // .tif verarbeiten
    string tessTarget(target);
    tessTarget=utility::replace(tessTarget,".pdf",".tif");
    Pix *image = pixRead(tessTarget.c_str());
    api->SetImage(image);
    outText = api->GetUTF8Text();
    printf("Eingelesener Text:\n%s", outText);

    // Speicher freigeben
    api->End();
    delete [] outText;
    pixDestroy(&image);
}

// Setter für Zieldatei
void TessReader::setTarget(string pTarget){
    target=pTarget.c_str();
}

// Getter für Zieldatei
string TessReader::getTarget(){
    return target;
}
