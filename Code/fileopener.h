#ifndef FILEOPENER_H
#define FILEOPENER_H

#include "ui_fileopener.h"
#include "tessreader.h"
#include "magicconverter.h"
#include "filemanager.h"


using namespace std;

class FileOpener : public QWidget, private Ui::FileOpenerDLG
{
    Q_OBJECT
public:
    FileOpener(TessReader *pTessi, MagicConverter *pMagic, FileManager *pFman);
    void target2Picture(const char *img, vector<int> pages_vec);
    void resizeEvent(QResizeEvent *);
    bool parsePages();

private:
    TessReader *tessi;
    MagicConverter *magic;
    FileManager *fman;
    QGraphicsScene *sc;

public slots:
    void getPath();
    void checkInput();

private slots:
    void quit();
    void setText(string pIn);
    void setText(QString in);
    void changeDisplayedPage_next();
    void changeDisplayedPage_previous();
};

#endif // FILEOPENER_H
