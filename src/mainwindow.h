#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // 事件与状态声明
    void on_pushButton_clicked();
    int num = 0;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
