#ifndef FILEOPENER_H
#define FILEOPENER_H

#include "ui_fileopener.h"
#include "tessreader.h"
#include "magicconverter.h"

using namespace std;

class FileOpener : public QWidget, private Ui::FileOpenerDLG
{
    Q_OBJECT
public:
    FileOpener(TessReader *pTessi, MagicConverter *pMagic);
    void target2Picture(char *img);
    TessReader *tessi;
    MagicConverter *magic;

public slots:
    void getPath();
    void checkInput();

private slots:
    void quit();
    void setText(string pIn);
    void setText(QString in);
};

#endif // FILEOPENER_H
