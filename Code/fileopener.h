#ifndef FILEOPENER_H
#define FILEOPENER_H

#include <QApplication>
#include <QTextEdit>

class FileOpener
{
public:
    FileOpener(int &argc, char *argv[]);
    int openDialog();

private:
    QApplication *app;

    QTextEdit *text;
};

#endif // FILEOPENER_H
