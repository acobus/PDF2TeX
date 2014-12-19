#ifndef FILEOPENER_H
#define FILEOPENER_H

#include "ui_fileopener.h"

class FileOpener : public QWidget, private Ui::FileOpenerDLG
{
    Q_OBJECT
public:
    FileOpener(QWidget *parent=0);

};

#endif // FILEOPENER_H
