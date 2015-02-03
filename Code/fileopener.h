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

    const static int next_button=1;
    const static int previous_button=-1;
    const static int akt_button=0;

public slots:
    void getPath();
    void checkInput();

private slots:
    void quit();
    void setText(string pIn);
    void setText(QString in);
    void changeDisplayedPage();
};

#endif // FILEOPENER_H
