//
// Created by hoho on 2019/3/27.
//

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->chkBoxBold, &QCheckBox::clicked, this, &MainWindow::setBold);
    connect(ui->chkBoxItalic, &QCheckBox::clicked, this, &MainWindow::setItalic);
    connect(ui->chkBoxUnder, &QCheckBox::clicked, this, &MainWindow::setUnderline);


    connect(ui->rBtnBlue, &QRadioButton::clicked, this, &MainWindow::changeColor);
    connect(ui->rBtnBlack, &QRadioButton::clicked, this, &MainWindow::changeColor);
    connect(ui->rBtnRed, &QRadioButton::clicked, this, &MainWindow::changeColor);

    ui->centralWidget->setStyleSheet("background-color: white;"
                                     "border-bottom: none;");

    ui->textEdit->setStyleSheet("border: 5px solid green;"
                                // "border-image: url(./res/login/loginIcon.png);"
                                );
    ui->fontBox->setStyleSheet("background-color: gray;"
                               "border-radius: 5px;");

    ui->colorBox->setStyleSheet("background-color: grey;"
                                "border-radius: 5px;");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setBold(bool checked) {
    QFont qFont = ui->textEdit->font();
    qFont.setBold(checked);
    ui->textEdit->setFont(qFont);
}

void MainWindow::setItalic(bool checked) {
    QFont qFont = ui->textEdit->font();
    qFont.setItalic(checked);
    ui->textEdit->setFont(qFont);

}

void MainWindow::setUnderline(bool checked) {
    QFont qFont = ui->textEdit->font();
    qFont.setUnderline(checked);
    ui->textEdit->setFont(qFont);

}

void MainWindow::changeColor() {
    QPalette qPalette = ui->textEdit->palette();
    if (ui->rBtnRed->isChecked()) {
        qPalette.setColor(QPalette::Text, Qt::red);
    } else if (ui->rBtnBlue->isChecked()) {
        qPalette.setColor(QPalette::Text, Qt::blue);
    } else {
        qPalette.setColor(QPalette::Text, Qt::black);
    }

    ui->textEdit->setPalette(qPalette);
}