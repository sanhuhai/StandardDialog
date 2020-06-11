#include "StandardDialog.h"

StandardDialog::StandardDialog(QWidget *parent)
    : QDialog(parent)
{
    //ui.setupUi(this);
    mainLayout = new QGridLayout(this);
    display();
}

void StandardDialog::showFile() {
    
    QString str = QFileDialog::getOpenFileName(this, "open file dialog", "/", "C++ files(*.cpp);;C files(*.c);;Head files(*.h)");
    fileLineEdit->setText(str);
}

void StandardDialog::showColor() {
	QColor c = QColorDialog::getColor(Qt::blue);
	if (c.isValid())
	{
		colorFrame->setPalette(QPalette(c));
	}
}

void StandardDialog::showFont() {
    bool ok;
    QFont f = QFontDialog::getFont(&ok);
    if (ok) {
        fileLineEdit->setFont(f);
    }
}

void StandardDialog::showWidget() {
	fileBtn = new QPushButton("文件标准对话框实例");
	fileLineEdit = new QLineEdit;
	mainLayout = new QGridLayout(this);
	mainLayout->addWidget(fileBtn, 0, 0);
	mainLayout->addWidget(fileLineEdit, 0, 1);
	colorBtn = new QPushButton("颜色标准对话框实例");
	colorFrame = new QFrame;
	colorFrame->setFrameShape(QFrame::Box);
	colorFrame->setAutoFillBackground(true);
	mainLayout->addWidget(colorBtn, 1, 0);
	mainLayout->addWidget(colorFrame, 1, 1);
	fontBtn = new QPushButton("字体标准对话框实例");
	fontLineEdit = new QLineEdit;
	fontLineEdit->setText("Hello world");
	mainLayout->addWidget(fontBtn, 2, 0);
	mainLayout->addWidget(fontLineEdit, 2, 1);
	bool ok;
	QFont f = QFontDialog::getFont(&ok);
	if (ok) {
		fileLineEdit->setFont(f);
	}
}

void StandardDialog::display() {
    showWidget();
    connect(fileBtn, SIGNAL(clicked()), this, SLOT(showFont()));
	connect(fileBtn, SIGNAL(clicked()), this, SLOT(showFile()));
	connect(colorBtn, SIGNAL(clicked()), this, SLOT(showColor()));
}

