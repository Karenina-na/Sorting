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

    // parameters
    void on_data_input_uniform_button_clicked();
    void on_data_input_poisson_button_clicked();
    void on_data_input_gaussian_button_clicked();
    void on_data_input_exponential_button_clicked();

    // QSideBar
    void on_data_input_distribution_horizontal_slider_valueChanged(int value);
    void on_data_input_distribution_vertical_slider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    bool first_flag = true;

    // store parameters
    unsigned int seed{};
    int size{};
    int min{};
    int max{};
    double lambda_p{};
    double lambda_e{};
    double mean{};
    double stddev{};

    void recreate_functionqwidget();
    int distribution = 3;   // 0: uniform, 1: poisson, 2: exponential, 3: gaussian
};
#endif // MAINWINDOW_H
