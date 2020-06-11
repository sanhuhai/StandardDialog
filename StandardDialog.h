#pragma once

#include <QtWidgets/QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QFileDialog>
#include <QFrame>
#include <QFont>
#include <QFontDialog>
#include <QColorDialog>
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif // WIN32

//#include "ui_StandardDialog.h"

class StandardDialog : public QDialog
{
    Q_OBJECT

public:
    StandardDialog(QWidget *parent = Q_NULLPTR);
    void display();
    void showWidget();
private slots:
    void showFile();
    void showColor();
    void showFont();
private:
    //Ui::StandardDialogClass ui;
    QPushButton* fileBtn, * colorBtn, *fontBtn;
    QLineEdit* fileLineEdit;
    QGridLayout* mainLayout;
    QFrame* colorFrame;
    QLineEdit* fontLineEdit;
};
