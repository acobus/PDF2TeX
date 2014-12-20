#ifndef FILEOPENER_H
#define FILEOPENER_H

#include "ui_fileopener.h"
#include "tessreader.h"

using namespace std;

class FileOpener : public QWidget, private Ui::FileOpenerDLG
{
    Q_OBJECT
public:
    FileOpener(TessReader *tessi);
    TessReader *tessi;

public slots:
    void getPath();
    void checkInput();

private slots:
    void quit();
    void setText(string pIn);
    void setText(QString in);
};

#endif // FILEOPENER_H
