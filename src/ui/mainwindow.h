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

    // load data
    void on_data_loader_button_clicked();

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

    // file path
    QString file_path;

    // algorithm
    // -1: not selected
    // 0: insertion sort, 1: bubble sort, 2: selection sort, 3: shell sort,
    // 4: quick sort, 5: heap sort, 6: radix sort, 7: merge sort, 8: my
    int algorithm = -1;
    bool generate_flag = false;

    void recreate_functionqwidget();
    int distribution = 3;   // 0: uniform, 1: poisson, 2: exponential, 3: gaussian
};
#endif // MAINWINDOW_H
