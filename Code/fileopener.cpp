#include <QtGui>
#include <QFileDialog>
#include <QDesktopWidget>

#include "fileopener.h"
#include "utility.h"
#include "filemanager.h"

#include <iostream>
#include <sstream>
#include <stack>

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
connect( next_page, SIGNAL (clicked() ) ,this, SLOT (changeDisplayedPage()));
connect( previous_page, SIGNAL( clicked() ), this, SLOT ( changeDisplayedPage() ) );

// Starttext
string starttext="";
setText(starttext);

// Startbild wird angezeigt
vector<int> fake_vec;
target2Picture(fman->getLogo(),fake_vec);

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
    }
    string s_path(c_path);

    // Überprüfe ob sich Target geändert hat
    if(strcmp(s_path.c_str(),fman->getTarget().c_str())==0) return;

    // Wenn geändert setze alles neu:
    fman->setTarget(s_path);

    // Erstellte Konvertierungen löschen
    utility::emptyTemp();

    // Bildanzeige in GUI
    int v[5] = { 1,2,3,4,5 };
    vector<int> pages_vec(&v[0], &v[0]+5);
    target2Picture(c_path,pages_vec);

    // Pfad und Seitenzahlen in GUI anzeigen
    setText(path);
}

/*
 * Hier soll geprüft werden, ob eingegebener Path-String
 * auf eine Konsistente Datei zeigt. Wenn ja soll
 * Dialog geschlossen und Konvertierung gestartet
 * werden.
 */
void FileOpener::checkInput(){
    parsePages();
    utility::emptyTemp();
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
 * Setzt Bild in GUI-Anzeige
 * Diese Methode bekommt dazu die Datei gegeben sowie einen Vektor mit
 * Seitenzahlen. Dabei wird das erste Bild des Vektors in der GUI angezeigt.
 * Falls die Datei nicht im richtigen Format ist, findet eine entsprechende
 * Konvertierung statt.
 * Falls der String leer ist, wird das LOGO als Bild gesetzt.
 */
void FileOpener::target2Picture(const char *imag, vector<int> pages_vec){
    const char * n_img;
    char format[]=".pdf";
    // StandardBild, wenn nichts ausgewählt
    if(imag==0 || strcmp(imag,"../Documents/Logo.png")==0){
        n_img="../Documents/Logo.png";
    }else if (utility::checkFormat(imag,format)){
        //Zieldatei als bild convertieren
        magic->pdf2png(100,pages_vec);
        // Es soll erstes Bild aus Vektor angezeigt werden
        int firstPage=pages_vec[0];
        fman->setAktPage(firstPage);
        string page_numb=utility::convertInt(firstPage);
        QString pageOutput(page_numb.c_str());
        page_interact->setText(pageOutput);
        string tmp="../temp/pg" + page_numb + ".png";
        n_img=tmp.c_str();
    }else{
        // TODO : was passiert wenn keine pdf gegeben wird
        return;
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


/*
 * Diese Methode liest die parsed die Seitenzahl-Eingabe
 * Die Rückgabe entspricht Erfolg oder Misserfolg des Lesen.
 */
bool FileOpener::parsePages(){
    string s_pages = utility::QString2Char_p(pages->text());
    s_pages+="Z";
    vector<int> i_pages;
    char lastMember=0;
    stack<char> aktInt;
    bool identifyNumber=false;

    for(string::iterator it=s_pages.begin();it!=s_pages.end();it++){
        char temp=*it;

        // Zahl erkennen
        if(48<=temp && temp<=57){
            aktInt.push(temp);
            identifyNumber=true;
            continue;
        }
        // Zahlerkennung zuende
        if(identifyNumber){
            identifyNumber=false;
            int temp_i=0;
            int size=aktInt.size();
            for(int j=0; j<size; j++){
                // char in int konvertieren
                temp_i+=(aktInt.top()-'0')*pow(10,j);
                aktInt.pop();
            }
            // Wenn kein "-" dann einfach schreiben
            if(lastMember!=45) i_pages.push_back(temp_i);
            else{
                for(int j=i_pages[i_pages.size()-1]+1; j<=temp_i; j++){
                    i_pages.push_back(j);
                }
            }
        }

        // Seiten von/bis : "-"
        if(temp==45){
            lastMember=temp;
            continue;
        }
    }
    // Gelesene Seiten an FileManager übergeben
    for(int i=0; i<i_pages.size(); i++){
        fman->addPage(i_pages[i]);
    }

    // Vorläufige Ausgabe der gelesenen Seiten zum Überprüfen
    int size=i_pages.size();
    cout<<"\n Parsed pages:";
    for(int k=0; k<size; k++){
        cout<<endl<<i_pages[k];
    }
    cout<<endl;
    return true;
}

void FileOpener::changeDisplayedPage(){

}
