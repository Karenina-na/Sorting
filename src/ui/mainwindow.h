#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <shared_mutex>
#include "ReportStruct.h"
#include "Algorithm.h"
#include "Distribution.h"
#include "BidirectionalLinkList.h"

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
    void on_algorithm_message_show_value_change();

    // load data
    void on_data_loader_button_clicked();
    void on_data_loader_sort_checkbox_stateChanged();
    void on_data_generator_sort_checkbox_stateChanged();

    // greater or less
    void on_greater_checkbox_stateChanged();
    void on_less_checkbox_stateChanged();

    // algorithm selection
    void on_insert_sort_button_clicked();
    void on_bubble_sort_button_clicked();
    void on_select_sort_button_clicked();
    void on_shell_sort_button_clicked();
    void on_quick_sort_button_clicked();
    void on_heap_sort_button_clicked();
    void on_radix_sort_button_clicked();
    void on_merge_sort_button_clicked();
    void on_my_sort_button_clicked();

    // generate data
    void on_sort_generate_data_button_clicked();

    // launch
    void on_launch_button_clicked();
    void run_launch(structure::Report<int>* report, structure::BidirectionalLinkList<int> *list,
                    bool timer, bool compare_and_move, bool build, bool multi_thread);

private:
    Ui::MainWindow *ui;
    bool first_flag = true;

    // store parameters
    unsigned int seed = rand();
    int size = 100;
    int min = 0;
    int max = 10;
    double lambda_p = 1;
    double lambda_e = 1;
    double mean = 0;
    double stddev = 1;

    // file path
    QString file_path;

    // data
    structure::BidirectionalLinkList<int> *list = nullptr;

    // algorithm
    // -1: not selected
    // 0: insertion sort, 1: bubble sort, 2: selection sort, 3: shell sort,
    // 4: quick sort, 5: heap sort, 6: radix sort, 7: merge sort, 8: my
    int algorithm = -1;
    bool generate_flag = false;

    // report
    std::shared_mutex report_mutex;
    std::vector<structure::Report<int>*> reports;

    void recreate_functionqwidget();
    int distribution = 3;   // 0: uniform, 1: poisson, 2: exponential, 3: gaussian
};
#endif // MAINWINDOW_H
