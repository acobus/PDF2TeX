#include <QtGui>
#include <fileopener.h>

FileOpener::FileOpener(int argc, char *argv[])
{
QApplication *app=new QApplication(argc, argv);
QTextEdit *text=new QTextEdit();

openDialog(app,text);
}

int FileOpener::openDialog(QApplication *app,QTextEdit *text){
    text->show();
    return app->exec();
}
