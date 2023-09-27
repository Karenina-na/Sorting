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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void on_data_input_uniform_button_clicked();
    void on_data_input_poisson_button_clicked();
    void on_data_input_gaussian_button_clicked();
    void on_data_input_exponential_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
