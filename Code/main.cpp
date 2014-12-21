#include "magicconverter.h"
#include "tessreader.h"
#include "fileopener.h"
#include <string>
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    // Standarddateien
    string target="../Documents/Summentest.pdf";

    MagicConverter magic(*argv,target);

    TessReader tessi(target);

    QApplication app(argc,argv);
    FileOpener *dialogue = new FileOpener(&tessi,&magic);
    dialogue->show();
    app.exec();

    if(tessi.getTarget().empty()){
        return 0;
    }

    tessi.startReading();

    return 0;
}
