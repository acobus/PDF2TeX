/********************************************************************************
** Form generated from reading UI file 'fileopener.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEOPENER_H
#define UI_FILEOPENER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileOpenerDLG
{
public:
    QTextEdit *text_input;
    QTextEdit *text_output;
    QPushButton *pushButton_browse;
    QPushButton *pushButton_convert;
    QPushButton *pushButton_quit;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *FileOpenerDLG)
    {
        if (FileOpenerDLG->objectName().isEmpty())
            FileOpenerDLG->setObjectName(QStringLiteral("FileOpenerDLG"));
        FileOpenerDLG->resize(607, 523);
        text_input = new QTextEdit(FileOpenerDLG);
        text_input->setObjectName(QStringLiteral("text_input"));
        text_input->setGeometry(QRect(30, 100, 201, 31));
        text_output = new QTextEdit(FileOpenerDLG);
        text_output->setObjectName(QStringLiteral("text_output"));
        text_output->setGeometry(QRect(30, 210, 201, 31));
        pushButton_browse = new QPushButton(FileOpenerDLG);
        pushButton_browse->setObjectName(QStringLiteral("pushButton_browse"));
        pushButton_browse->setGeometry(QRect(130, 150, 98, 27));
        pushButton_convert = new QPushButton(FileOpenerDLG);
        pushButton_convert->setObjectName(QStringLiteral("pushButton_convert"));
        pushButton_convert->setGeometry(QRect(250, 430, 98, 27));
        pushButton_quit = new QPushButton(FileOpenerDLG);
        pushButton_quit->setObjectName(QStringLiteral("pushButton_quit"));
        pushButton_quit->setGeometry(QRect(30, 430, 99, 27));
        graphicsView = new QGraphicsView(FileOpenerDLG);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(260, 31, 331, 371));

        retranslateUi(FileOpenerDLG);

        QMetaObject::connectSlotsByName(FileOpenerDLG);
    } // setupUi

    void retranslateUi(QWidget *FileOpenerDLG)
    {
        FileOpenerDLG->setWindowTitle(QApplication::translate("FileOpenerDLG", "PDF2TeX", 0));
        text_input->setHtml(QApplication::translate("FileOpenerDLG", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Browse a PDF...</p></body></html>", 0));
        text_output->setHtml(QApplication::translate("FileOpenerDLG", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Insert a target...</p></body></html>", 0));
        pushButton_browse->setText(QApplication::translate("FileOpenerDLG", "Browse", 0));
        pushButton_convert->setText(QApplication::translate("FileOpenerDLG", "Convert", 0));
        pushButton_quit->setText(QApplication::translate("FileOpenerDLG", "Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class FileOpenerDLG: public Ui_FileOpenerDLG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEOPENER_H
