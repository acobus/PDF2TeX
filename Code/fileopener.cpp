#include <QtGui>
#include <fileopener.h>

FileOpener::FileOpener(int &argc, char *argv[])
{
app=new QApplication(argc, argv);
text=new QTextEdit();

}

int FileOpener::openDialog(){
    text->show();
    return app->exec();
}
