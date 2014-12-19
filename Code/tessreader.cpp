#include "tessreader.h"
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

using namespace std;
TessReader::TessReader(string pTarget)
{
    char *outText;
    const char *target=pTarget.c_str();

    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Sprachoptionen variieren?
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Tesseract konnte nicht initialisiert werden.\n");
        exit(1);
    }

    // Leptonica
    Pix *image = pixRead(target);
    api->SetImage(image);
    outText = api->GetUTF8Text();
    printf("Eingelesener Text:\n%s", outText);

    // Speicher freigeben
    api->End();
    delete [] outText;
    pixDestroy(&image);
}
