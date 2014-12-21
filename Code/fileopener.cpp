#include <QtGui>
#include <QFileDialog>
#include <QDesktopWidget>
#include "fileopener.h"

using namespace std;

FileOpener::FileOpener(TessReader *pTessi)
{
setupUi(this);

tessi=pTessi;

// Position des Fensters zentriert
QDesktopWidget *desktop = QApplication::desktop();

int screenWidth, width;
int screenHeight, height;
int x, y;
QSize windowSize;

screenWidth = desktop->width();
screenHeight = desktop->height();

windowSize = size();
width = windowSize.width();
height = windowSize.height();

// Größe anpassen
x = (screenWidth - width) / 2;
y = (screenHeight - height) / 2;
y -= 50;

move ( x, y );

// Flags werden gesetzt
Qt::WindowFlags flags;
// TODO: Flags richtig setzen
//flags = Qt::Window | Qt::WindowMinimizeButtonHint;
setWindowFlags( flags );

// Knöpfe drückbar
connect( pushButton_browse, SIGNAL( clicked() ), this, SLOT( getPath() ) );
connect( pushButton_convert, SIGNAL( clicked() ), this, SLOT( checkInput() ) );
connect( pushButton_quit, SIGNAL( clicked() ), this, SLOT( quit() ) );

// Startpfad wird angezeigt
setText(tessi->getTarget());

}

void FileOpener::getPath()
{
    QString path;

    path = QFileDialog::getOpenFileName(
        this,
        "Choose a file to open",
        QString::null,
        QString::null);

    setText(path);

    // Datei soll im Fenster angezeit werden
    QImage img(path);
    //view_document->fitInView(img);
}

void FileOpener::checkInput(){
    close();
}

void FileOpener::quit(){
    tessi->setTarget("");
    close();
}

// Überladene Methode um Textfeld zu füllen
void FileOpener::setText(string pIn){
    QString in(pIn.c_str());
    QString out=in;
    out.replace(".pdf",".tex");
    text_input->setText(in);
    text_output->setText(out);
}

// Überladene Methode um Textfeld zu füllen
void FileOpener::setText(QString in){
    QString out=in;
    out.replace(".pdf",".tex");
    text_input->setText(in);
    text_output->setText(out);
}
