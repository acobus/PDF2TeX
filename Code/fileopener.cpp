#include <QtGui>
#include <QFileDialog>
#include <QDesktopWidget>
#include "fileopener.h"
#include "utility.h"

using namespace std;

FileOpener::FileOpener(TessReader *pTessi,MagicConverter *pMagic)
{
setupUi(this);

// Pfad des Startbildes
char *cimg="../Documents/Summentest.png";

tessi=pTessi;
magic=pMagic;

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

// Startbild wird angezeigt
target2Picture(cimg);

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

// Setzt Bild - Wird noch zu klein angezeit...
void FileOpener::target2Picture(char *img){
    if (utility::checkFormat(img,".png")){
    sc =new QGraphicsScene();
    QPixmap qimg(img);
    sc->addPixmap(qimg);
    graphicsView->setScene(sc);
    QShowEvent *event();
    graphicsView->fitInView(sc->sceneRect(),Qt::KeepAspectRatio);
    }
}

void FileOpener::resizeEvent(QResizeEvent *) {
    QRectF bounds = sc->itemsBoundingRect();
    bounds.setWidth(bounds.width()*0.9);
    bounds.setHeight(bounds.height()*0.9);
    graphicsView->fitInView(bounds, Qt::KeepAspectRatio);
    graphicsView->centerOn(0, 0);
}
