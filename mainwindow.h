//
// Created by hoho on 2019/3/27.
//

#ifndef CLIONQT_MAINWINDOW_H
#define CLIONQT_MAINWINDOW_H


#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
public slots:
    void changeColor();
    void setUnderline(bool checked);
    void setItalic(bool checked);

    void setBold(bool checked);

private:
    Ui::MainWindow *ui;
};


#endif //CLIONQT_MAINWINDOW_H
