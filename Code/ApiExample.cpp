#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <Magick++.h>

using namespace Magick;
using namespace std;

int main(int /*argc*/, char ** argv)
{
    InitializeMagick(* argv);

    string target="/home/andi/Dokumente/PDF2TeX/Quellcode/Summentest.tif";
    string document="/home/andi/Dokumente/PDF2TeX/Quellcode/Summentest.pdf";

    Image img;
    img.density(Magick::Geometry(300,300));
    img.read("/home/andi/Dokumente/PDF2TeX/Quellcode/Summentest.pdf");
    img.write("/home/andi/Dokumente/PDF2TeX/Quellcode/Summentest.tif");

    char *outText;

    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }

    // Open input image with leptonica library
    Pix *image = pixRead("/home/andi/Dokumente/PDF2TeX/Quellcode/Summentest.tif");
    api->SetImage(image);
    // Get OCR result
    outText = api->GetUTF8Text();
    printf("OCR output:\n%s", outText);

    // Destroy used object and release memory
    api->End();
    delete [] outText;
    pixDestroy(&image);

    return 0;
}
