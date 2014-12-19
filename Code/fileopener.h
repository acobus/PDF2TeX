#ifndef FILEOPENER_H
#define FILEOPENER_H

#include "ui_fileopener.h"

class FileOpener : public QWidget, private Ui::FileOpenerDLG
{
    Q_OBJECT
public:
    FileOpener(QWidget *parent=0);

public slots:
    void getPath();
    void checkInput();

private slots:
    void quit();
};

#endif // FILEOPENER_H
