#include <QtGui>
#include <QFileDialog>
#include <QDesktopWidget>
#include "fileopener.h"
#include "utility.h"
#include "filemanager.h"

#include <iostream>

using namespace std;

/*
 * Hauptdialog über den die Datei ausgewählt und Optionen eingestellt
 * werden sollen.
 */
FileOpener::FileOpener(TessReader *pTessi, MagicConverter *pMagic, FileManager *pFman)
{
setupUi(this);

tessi=pTessi;
magic=pMagic;
fman=pFman;

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

// Starttext
string starttext="";
setText(starttext);

// Startbild wird angezeigt
target2Picture(fman->getLogo());

}

/*
 * Diese Funktion wird genutzt um einen Datei-Öffnen
 * Dialog zu starten. Die Daten werden dann entsprechend
 * an Methoden weitergeleitet um diese auf der GUI
 * anzuzeigen.
 */
void FileOpener::getPath()
{
    QString path;

    path = QFileDialog::getOpenFileName(
        this,
        "Choose a file to open",
        QString::null,
        QString::null);

    // Datei soll im Fenster angezeit werden
    // Dazu umwandlung der des QString in char*
    char *c_path=utility::QString2Char_p(path);
    if(*c_path==0){
        c_path=fman->getLogo();
        fman->setNumb(0);
    }
    string s_path(c_path);
    fman->setTarget(s_path);
    target2Picture(c_path);

    // Pfad und Seitenzahlen in GUI anzeigen
    setText(path);
    setPageNumbers();
}

/*
 * Hier soll geprüft werden, ob eingegebener Path-String
 * auf eine Konsistente Datei zeigt. Wenn ja soll
 * Dialog geschlossen und Konvertierung gestartet
 * werden.
 */
void FileOpener::checkInput(){
    close();
}

/*
 * Dialog wird geschlossen und das Ziel-PDF
 * auf standard gesetzt.
 */
void FileOpener::quit(){
    fman->setTarget(fman->getLogo());
    close();
}

/*
 * Überladene Methode um Textfeld für Dateianzeige
 * zu füllen
 */
void FileOpener::setText(string pIn){
    QString in(pIn.c_str());
    setText(in);
}

/*
 * Überladene Methode um Textfeld für Dateianzeige
 * zu füllen
 */
void FileOpener::setText(QString in){
    // Anzeige falls keine Zieldatei
    if(in.isEmpty()){
        text_input->setText("browse pdf...");
        text_output->setText("browse tex...");
        return;
    }
    // Später hier weiter machen!! kürzere anzeige des path
    // in_shor=utility::partStringFromBehind(utility::QString2Char_p(in);
    QString out=in;
    out.replace(".pdf",".tex");
    text_input->setText(in);
    text_output->setText(out);
}


/*
 * Seitenzahlen werden in GUI angezeigt
 */
void FileOpener::setPageNumbers(){
    QString start;
    QString end;
    if(fman->getNumb()==0){
        start="Page start";
        end="Page end";
    }else{
        start=utility::convertInt(1).c_str();
        end=utility::convertInt(fman->getNumb()).c_str();
    }
    start_page->setText(start);
    end_page->setText(end);
}

/*
 * Setzt Bild in GUI-Anzeige
 */
void FileOpener::target2Picture(const char *imag){
    const char * n_img;
    // StandardBild, wenn nichts ausgewählt
    if(imag==0){
        n_img="../Documents/Logo.png";
    }
    char format[]=".pdf";
    if (utility::checkFormat(imag,format)){
        //Zieldatei als bild convertieren
        magic->pdf2png(100,true);
        n_img="../temp/pg0.png";
    }else{
        n_img=imag;
    }
    QPixmap qimg(n_img);
    sc =new QGraphicsScene();
    sc->addPixmap(qimg);
    graphicsView->setScene(sc);
    QShowEvent *event();
    graphicsView->fitInView(sc->sceneRect(),Qt::KeepAspectRatio);
}

/*
 * Hilfsfunktion um Bild auf richtige Größe zu bekommen
 */
void FileOpener::resizeEvent(QResizeEvent *) {
    QRectF bounds = sc->itemsBoundingRect();
    bounds.setWidth(bounds.width()*0.9);
    bounds.setHeight(bounds.height()*0.9);
    graphicsView->fitInView(bounds, Qt::KeepAspectRatio);
    graphicsView->centerOn(0, 0);
}
