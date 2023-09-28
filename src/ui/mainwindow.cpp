#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "distributionwindow.h"
#include "functionqwidget.h"
#include <QFileDialog>
#include <thread>
#include <QScrollBar>
#include <mutex>
#include <shared_mutex>
#include "Algorithm.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->algorithm_message_show->setText(
            "welcome to use this program"
    );

    // show param
    QString param = "seed: " + QString::number(this->seed) + "\n"
                    + "size: " + QString::number(this->size) + "\n"
                    + "min: " + QString::number(this->min) + "\n"
                    + "max: " + QString::number(this->max) + "\n"
                    + "lambda for p: " + QString::number(this->lambda_p) + "\n"
                    + "lambda for e: " + QString::number(this->lambda_e) + "\n"
                    + "mean: " + QString::number(this->mean) + "\n"
                    + "stddev: " + QString::number(this->stddev) + "\n";
    ui->data_input_parameter_show->setText(param);

    // generator
    connect(ui->data_input_uniform_button, &QPushButton::clicked, this, &MainWindow::on_data_input_uniform_button_clicked);
    connect(ui->data_input_poisson_button, &QPushButton::clicked, this, &MainWindow::on_data_input_poisson_button_clicked);
    connect(ui->data_input_exponential_button, &QPushButton::clicked, this, &MainWindow::on_data_input_exponential_button_clicked);
    connect(ui->data_input_gaussian_button, &QPushButton::clicked, this, &MainWindow::on_data_input_gaussian_button_clicked);

    // QSideBar
    connect(ui->data_input_distribution_horizontal_slider, &QSlider::valueChanged, this, &MainWindow::on_data_input_distribution_horizontal_slider_valueChanged);
    connect(ui->data_input_distribution_vertical_slider, &QSlider::valueChanged, this, &MainWindow::on_data_input_distribution_vertical_slider_valueChanged);
    connect(ui->algorithm_message_show, &QTextEdit::textChanged, this, &MainWindow::on_algorithm_message_show_value_change);

    // load data
    connect(ui->data_loader_button, &QPushButton::clicked, this, &MainWindow::on_data_loader_button_clicked);
    connect(ui->data_loader_sort_checkbox, &QCheckBox::stateChanged, this, &MainWindow::on_data_loader_sort_checkbox_stateChanged);
    connect(ui->data_generator_sort_checkbox, &QCheckBox::stateChanged, this, &MainWindow::on_data_generator_sort_checkbox_stateChanged);

    // greater or less
    connect(ui->greater_checkbox, &QCheckBox::stateChanged, this, &MainWindow::on_greater_checkbox_stateChanged);
    connect(ui->less_checkbox, &QCheckBox::stateChanged, this, &MainWindow::on_less_checkbox_stateChanged);

    // algorithm selection
    connect(ui->insert_sort_button, &QPushButton::clicked, this, &MainWindow::on_insert_sort_button_clicked);
    connect(ui->bubble_sort_button, &QPushButton::clicked, this, &MainWindow::on_bubble_sort_button_clicked);
    connect(ui->select_sort_button, &QPushButton::clicked, this, &MainWindow::on_select_sort_button_clicked);
    connect(ui->shell_sort_button, &QPushButton::clicked, this, &MainWindow::on_shell_sort_button_clicked);
    connect(ui->quick_sort_button, &QPushButton::clicked, this, &MainWindow::on_quick_sort_button_clicked);
    connect(ui->heap_sort_button, &QPushButton::clicked, this, &MainWindow::on_heap_sort_button_clicked);
    connect(ui->radix_sort_button, &QPushButton::clicked, this, &MainWindow::on_radix_sort_button_clicked);
    connect(ui->merge_sort_button, &QPushButton::clicked, this, &MainWindow::on_merge_sort_button_clicked);
    connect(ui->algorithm_button, &QPushButton::clicked, this, &MainWindow::on_my_sort_button_clicked);

    // generate data
    connect(ui->sort_generate_data_button, &QPushButton::clicked, this, &MainWindow::on_sort_generate_data_button_clicked);

    // launch
    connect(ui->sort_launch_button, &QPushButton::clicked, this, &MainWindow::on_launch_button_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// uniform button
void MainWindow::on_data_input_uniform_button_clicked() {
    auto* distributionWindow = new DistributionWindow(this, first_flag,
                                                        max, min, size, seed,
                                                        lambda_p, lambda_e, mean, stddev, 0);
    distributionWindow->show();
    distributionWindow->exec();

    first_flag = false;

    // store parameters
    if (distributionWindow->change){
        seed = distributionWindow->seed;
        size = distributionWindow->size;
        min = distributionWindow->min;
        max = distributionWindow->max;
        lambda_p = distributionWindow->lambda_p;
        lambda_e = distributionWindow->lambda_e;
        mean = distributionWindow->mean;
        stddev = distributionWindow->stddev;
        distribution = distributionWindow->distribution;

        // recreate functionqwidget
        ui->data_input_distribution_preview->min = min;
        ui->data_input_distribution_preview->max = max;
        ui->data_input_distribution_preview->lambda_p = lambda_p;
        ui->data_input_distribution_preview->lambda_e = lambda_e;
        ui->data_input_distribution_preview->mean = mean;
        ui->data_input_distribution_preview->stddev = stddev;
        ui->data_input_distribution_preview->distribution = distribution;
        recreate_functionqwidget();

        ui->algorithm_message_show->setText(
                ui->algorithm_message_show->toPlainText() + "\n" +
                "save parameters uniform"
        );
    }

    // show param
    QString param = "seed: " + QString::number(this->seed) + "\n"
                    + "size: " + QString::number(this->size) + "\n"
                    + "min: " + QString::number(this->min) + "\n"
                    + "max: " + QString::number(this->max) + "\n";
    ui->data_input_parameter_show->setText(param);
}

// poisson button
void MainWindow::on_data_input_poisson_button_clicked() {
    auto* distributionWindow = new DistributionWindow(this, first_flag,
                                                        max, min, size, seed,
                                                        lambda_p, lambda_e, mean, stddev, 1);
    distributionWindow->show();
    distributionWindow->exec();

    first_flag = false;

    // store parameters
    if (distributionWindow->change){
        seed = distributionWindow->seed;
        size = distributionWindow->size;
        min = distributionWindow->min;
        max = distributionWindow->max;
        lambda_p = distributionWindow->lambda_p;
        lambda_e = distributionWindow->lambda_e;
        mean = distributionWindow->mean;
        stddev = distributionWindow->stddev;
        distribution = distributionWindow->distribution;

        // recreate functionqwidget
        ui->data_input_distribution_preview->min = min;
        ui->data_input_distribution_preview->max = max;
        ui->data_input_distribution_preview->lambda_p = lambda_p;
        ui->data_input_distribution_preview->lambda_e = lambda_e;
        ui->data_input_distribution_preview->mean = mean;
        ui->data_input_distribution_preview->stddev = stddev;
        ui->data_input_distribution_preview->distribution = distribution;
        recreate_functionqwidget();

        ui->algorithm_message_show->setText(
                ui->algorithm_message_show->toPlainText() + "\n" +
                "save parameters poisson"
        );
    }

    // show param
    QString param = "seed: " + QString::number(this->seed) + "\n"
                    + "size: " + QString::number(this->size) + "\n"
                    + "min: " + QString::number(this->min) + "\n"
                    + "max: " + QString::number(this->max) + "\n"
                    + "lambda: " + QString::number(this->lambda_p) + "\n";
    ui->data_input_parameter_show->setText(param);

}

// exponential button
void MainWindow::on_data_input_exponential_button_clicked() {
    auto* distributionWindow = new DistributionWindow(this, first_flag,
                                                        max, min, size, seed,
                                                        lambda_p, lambda_e, mean, stddev, 2);
    distributionWindow->show();
    distributionWindow->exec();

    first_flag = false;

    // store parameters
    if (distributionWindow->change){
        seed = distributionWindow->seed;
        size = distributionWindow->size;
        min = distributionWindow->min;
        max = distributionWindow->max;
        lambda_p = distributionWindow->lambda_p;
        lambda_e = distributionWindow->lambda_e;
        mean = distributionWindow->mean;
        stddev = distributionWindow->stddev;
        distribution = distributionWindow->distribution;

        // recreate functionqwidget
        ui->data_input_distribution_preview->min = min;
        ui->data_input_distribution_preview->max = max;
        ui->data_input_distribution_preview->lambda_p = lambda_p;
        ui->data_input_distribution_preview->lambda_e = lambda_e;
        ui->data_input_distribution_preview->mean = mean;
        ui->data_input_distribution_preview->stddev = stddev;
        ui->data_input_distribution_preview->distribution = distribution;
        recreate_functionqwidget();

        ui->algorithm_message_show->setText(
                ui->algorithm_message_show->toPlainText() + "\n" +
                "save parameters exponential"
        );
    }

    // show param
    QString param = "seed: " + QString::number(this->seed) + "\n"
                    + "size: " + QString::number(this->size) + "\n"
                    + "min: " + QString::number(this->min) + "\n"
                    + "max: " + QString::number(this->max) + "\n"
                    + "lambda: " + QString::number(this->lambda_e) + "\n";
    ui->data_input_parameter_show->setText(param);

}

// gaussian button
void MainWindow::on_data_input_gaussian_button_clicked() {
    auto* distributionWindow = new DistributionWindow(this, first_flag,
                                                        max, min, size, seed,
                                                        lambda_p, lambda_e, mean, stddev, 3);
    distributionWindow->show();
    distributionWindow->exec();

    first_flag = false;

    // store parameters
    if (distributionWindow->change){
        seed = distributionWindow->seed;
        size = distributionWindow->size;
        min = distributionWindow->min;
        max = distributionWindow->max;
        lambda_p = distributionWindow->lambda_p;
        lambda_e = distributionWindow->lambda_e;
        mean = distributionWindow->mean;
        stddev = distributionWindow->stddev;
        distribution = distributionWindow->distribution;

        // recreate functionqwidget
        ui->data_input_distribution_preview->min = min;
        ui->data_input_distribution_preview->max = max;
        ui->data_input_distribution_preview->lambda_p = lambda_p;
        ui->data_input_distribution_preview->lambda_e = lambda_e;
        ui->data_input_distribution_preview->mean = mean;
        ui->data_input_distribution_preview->stddev = stddev;
        ui->data_input_distribution_preview->distribution = distribution;
        recreate_functionqwidget();

        ui->algorithm_message_show->setText(
                ui->algorithm_message_show->toPlainText() + "\n" +
                "save parameters gaussian"
        );
    }

    // show param
    QString param = "seed: " + QString::number(this->seed) + "\n"
                    + "size: " + QString::number(this->size) + "\n"
                    + "min: " + QString::number(this->min) + "\n"
                    + "max: " + QString::number(this->max) + "\n"
                    + "mean: " + QString::number(this->mean) + "\n"
                    + "stddev: " + QString::number(this->stddev) + "\n";
    ui->data_input_parameter_show->setText(param);
}

// QSideBar
void MainWindow::on_data_input_distribution_horizontal_slider_valueChanged(int value) {
    ui->data_input_distribution_preview->horizontal_slider_value = value;
    recreate_functionqwidget();
}

void MainWindow::on_data_input_distribution_vertical_slider_valueChanged(int value) {
    ui->data_input_distribution_preview->vertical_slider_value = value;
    recreate_functionqwidget();
}

void MainWindow::on_algorithm_message_show_value_change() {
    this->ui->algorithm_message_show->moveCursor(QTextCursor::End);
}

// recreate functionqwidget
void MainWindow::recreate_functionqwidget() {
    ui->data_input_distribution_preview->update();
}

// load data
void MainWindow::on_data_loader_button_clicked(){
    QString sPath = QFileDialog::getOpenFileName(this,"选择数据文件",".","txt files(*.txt);");

    // read data
    QFile file(sPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        ui->algorithm_message_show->setText(
                ui->algorithm_message_show->toPlainText() + "\n" +
                "error: file open failed - " + sPath
        );
        return;
    }
    QTextStream in(&file);
    QString line = in.readLine();
    QStringList list = line.split(",");
    std::vector<int> data;
    for (QString i : list){
        data.push_back(i.toInt());
    }
    file.close();

    // show data
    QString param = "size: " + QString::number(data.size()) + " " + "preview (100): " + "\n";
    for (int i = 0; i < 100; i++){
        param += QString::number(data[i]) + ", ";
    }

    ui->data_loader_preview->setText(param);
    file_path = sPath;
    ui->data_loader_show->setText(file_path);

    ui->algorithm_message_show->setText(
            ui->algorithm_message_show->toPlainText() + "\n" +
            "load data success - " + file_path.split("/").last()
    );
}

void MainWindow::on_data_loader_sort_checkbox_stateChanged() {
    if (ui->data_loader_sort_checkbox->isChecked()){
        ui->data_generator_sort_checkbox->setChecked(false);
    } else {
        ui->data_generator_sort_checkbox->setChecked(true);
    }
}

void MainWindow::on_data_generator_sort_checkbox_stateChanged() {
    if (ui->data_generator_sort_checkbox->isChecked()){
        ui->data_loader_sort_checkbox->setChecked(false);
    } else {
        ui->data_loader_sort_checkbox->setChecked(true);
    }
}

void MainWindow::on_greater_checkbox_stateChanged() {
    if (ui->greater_checkbox->isChecked()){
        ui->less_checkbox->setChecked(false);
    } else {
        ui->less_checkbox->setChecked(true);
    }
}

void MainWindow::on_less_checkbox_stateChanged() {
    if (ui->less_checkbox->isChecked()){
        ui->greater_checkbox->setChecked(false);
    } else {
        ui->greater_checkbox->setChecked(true);
    }
}

// algorithm selection
void MainWindow::on_insert_sort_button_clicked() {
    ui->algorithm_message_show->setText(
            ui->algorithm_message_show->toPlainText() + "\n" +
            "choose algorithm - insert sort"
    );
    algorithm = 0;
}

void MainWindow::on_bubble_sort_button_clicked() {
    ui->algorithm_message_show->setText(
            ui->algorithm_message_show->toPlainText() + "\n" +
            "choose algorithm - bubble sort"
    );
    algorithm = 1;
}

void MainWindow::on_select_sort_button_clicked() {
    ui->algorithm_message_show->setText(
            ui->algorithm_message_show->toPlainText() + "\n" +
            "choose algorithm - select sort"
    );
    algorithm = 2;
}

void MainWindow::on_shell_sort_button_clicked() {
    ui->algorithm_message_show->setText(
            ui->algorithm_message_show->toPlainText() + "\n" +
            "choose algorithm - shell sort"
    );
    algorithm = 3;
}

void MainWindow::on_quick_sort_button_clicked() {
    ui->algorithm_message_show->setText(
            ui->algorithm_message_show->toPlainText() + "\n" +
            "choose algorithm - quick sort"
    );
    algorithm = 4;
}

void MainWindow::on_heap_sort_button_clicked() {
    ui->algorithm_message_show->setText(
            ui->algorithm_message_show->toPlainText() + "\n" +
            "choose algorithm - heap sort"
    );
    algorithm = 5;
}

void MainWindow::on_radix_sort_button_clicked() {
    ui->algorithm_message_show->setText(
            ui->algorithm_message_show->toPlainText() + "\n" +
            "choose algorithm - radix sort"
    );
    algorithm = 6;
}

void MainWindow::on_merge_sort_button_clicked() {
    ui->algorithm_message_show->setText(
            ui->algorithm_message_show->toPlainText() + "\n" +
            "choose algorithm - merge sort"
    );
    algorithm = 7;
}

void MainWindow::on_my_sort_button_clicked() {
    ui->algorithm_message_show->setText(
            ui->algorithm_message_show->toPlainText() + "\n" +
            "choose algorithm - algorithm sort"
    );
    algorithm = 8;
}

// generate data
void MainWindow::on_sort_generate_data_button_clicked() {
    // generate data
    if (ui->data_generator_sort_checkbox->isChecked()){
        std::vector<int>* data;
        distribution::Uniform<int>* u;
        distribution::Poisson<int>* p;
        distribution::Exponential<int>* e;
        distribution::Gaussian<int>* g;
        // sort
        switch (distribution){
            case 0: // uniform
                u = new distribution::Uniform<int>(size, min, max, seed);
                data = u->generate();
                ui->algorithm_message_show->setText(
                        ui->algorithm_message_show->toPlainText() + "\n" +
                        "generate data - uniform - "
                        "(" + "min: " + QString::number(min) + ", " + "max: " + QString::number(max) + ", " +
                        "size: " + QString::number(size) + ", " + "seed: " + QString::number(seed) + ")"
                );
                break;
            case 1: // poisson
                p = new distribution::Poisson<int>(size, min, max, lambda_p, seed);
                data = p->generate();
                ui->algorithm_message_show->setText(
                        ui->algorithm_message_show->toPlainText() + "\n" +
                        "generate data - poisson - "
                        "(" + "min: " + QString::number(min) + ", " + "max: " + QString::number(max) + ", " +
                        "size: " + QString::number(size) + ", " + "seed: " + QString::number(seed) + ", " +
                        "lambda: " + QString::number(lambda_p) + ")"
                );
                break;
            case 2: // exponential
                e = new distribution::Exponential<int>(size, min, max, lambda_e, seed);
                data = e->generate();
                ui->algorithm_message_show->setText(
                        ui->algorithm_message_show->toPlainText() + "\n" +
                        "generate data - exponential - "
                        "(" + "min: " + QString::number(min) + ", " + "max: " + QString::number(max) + ", " +
                        "size: " + QString::number(size) + ", " + "seed: " + QString::number(seed) + ", " +
                        "lambda: " + QString::number(lambda_e) + ")"
                );
                break;
            case 3: // gaussian
                g = new distribution::Gaussian<int>(size, min, max, mean, stddev, seed);
                data = g->generate();
                ui->algorithm_message_show->setText(
                        ui->algorithm_message_show->toPlainText() + "\n" +
                        "generate data - gaussian - "
                        "(" + "min: " + QString::number(min) + ", " + "max: " + QString::number(max) + ", " +
                        "size: " + QString::number(size) + ", " + "seed: " + QString::number(seed) + ", " +
                        "mean: " + QString::number(mean) + ", " + "stddev: " + QString::number(stddev) + ")"
                );
                break;
        }

        // create linklist
        list = new structure::BidirectionalLinkList<int>();
        for (int d : *data){
            list->insertAtTail(d);
        }

        // delete
        delete data;
    }

    // load data
    if (ui->data_loader_sort_checkbox->isChecked()){
        QFile file(file_path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            ui->algorithm_message_show->setText(
                    ui->algorithm_message_show->toPlainText() + "\n" +
                    "error: file open failed - " + file_path
            );
            return;
        }

        list = new structure::BidirectionalLinkList<int>();

        // read data
        QTextStream in(&file);
        QString line = in.readLine();
        QStringList l = line.split(",");
        for (QString d : l){
            this->list->insertAtTail(d.toInt());
        }

        size = list->size();

        ui->algorithm_message_show->setText(
                ui->algorithm_message_show->toPlainText() + "\n" +
                "load data - " + "(" + "size: " + QString::number(size) +
                " file: " + file_path.split("/").last() +
                " file path: " + file_path + ")"
        );

        // close file
        file.close();
    }

    generate_flag = true;
}

// launch
void MainWindow::on_launch_button_clicked() {
    // generate data
    if (!generate_flag){
        ui->algorithm_message_show->setText(
                ui->algorithm_message_show->toPlainText() + "\n" +
                "error: no generate data"
        );
        return;
    }
    // algorithm
    if (algorithm == -1){
        ui->algorithm_message_show->setText(
                ui->algorithm_message_show->toPlainText() + "\n" +
                "error: no choose algorithm"
        );
        return;
    }
    // make report
    auto* report = new structure::Report<int>();

    // distribution
    if (ui->data_generator_sort_checkbox->isChecked()){
        report->flag = true;
        switch (distribution){
            case 0: // uniform
                report->set_distribution(
                        "uniform", 0,
                        {"min", "max", "seed"},
                        {(double)min, (double)max, (double)seed}
                        );
                break;
            case 1: // poisson
                report->set_distribution(
                        "poisson", 1,
                        {"min", "max", "seed", "lambda"},
                        {(double)min, (double)max, (double)seed, lambda_p}
                        );
                break;
            case 2: // exponential
                report->set_distribution(
                        "exponential", 2,
                        {"min", "max", "seed", "lambda"},
                        {(double)min, (double)max, (double)seed, lambda_e}
                        );
                break;
            case 3: // gaussian
                report->set_distribution(
                        "gaussian", 3,
                        {"min", "max", "seed", "mean", "stddev"},
                        {(double)min, (double)max, (double)seed, mean, stddev}
                        );
                break;
        }
    }

    // load
    if (ui->data_loader_sort_checkbox->isChecked()){
        report->flag = false;
    }

    // algorithm
    // 获取文件名
    std::string filename;
    if (file_path.endsWith(".txt")){
        const QStringList &l = file_path.split("/").last().split(".");
        for (int i = 0; i < l.size() - 1; i++){
            filename += l[i].toStdString();
            filename += ".";
        }
        filename += l[l.size() - 1].toStdString();
    }
    switch (algorithm){
        case 0: // insertion sort
            report->set_message("insert sort", size,
                                filename,
                                file_path.toStdString());
            break;
        case 1: // bubble sort
            report->set_message("bubble sort", size,
                                filename,
                                file_path.toStdString());
            break;
        case 2: // selection sort
            report->set_message("select sort", size,
                                filename,
                                file_path.toStdString());
            break;
        case 3: // shell sort
            report->set_message("shell sort", size,
                                filename,
                                file_path.toStdString());
            break;
        case 4: // quick sort
            report->set_message("quick sort", size,
                                filename,
                                file_path.toStdString());
            break;
        case 5: // heap sort
            report->set_message("heap sort", size,
                                filename,
                                file_path.toStdString());
            break;
        case 6: // radix sort
            report->set_message("radix sort", size,
                                filename,
                                file_path.toStdString());
            break;
        case 7: // merge sort
            report->set_message("merge sort", size,
                                filename,
                                file_path.toStdString());
            break;
        case 8: // my sort
            report->set_message("algorithm sort", size,
                                filename,
                                file_path.toStdString());
            break;
    }

    // run
    new std::thread(&MainWindow::run_launch, this, report, list,
                    ui->timer_checkbox->isChecked(),
                    ui->comparer_mover_checkbox->isChecked(),
                    ui->data_build_checkbox->isChecked(),
                    ui->mutil_thread_checkbox->isChecked());
    std::unique_lock<std::shared_mutex> lock(report_mutex);
    reports.push_back(report);
    lock.unlock();

    ui->algorithm_message_show->setText(
            ui->algorithm_message_show->toPlainText() + "\n" +
            "launch sort thread ..."
    );

    // init
    this->algorithm = -1;
    generate_flag = false;
}

void MainWindow::run_launch(structure::Report<int>* report, structure::BidirectionalLinkList<int> *list,
                            bool timer, bool compare_and_move, bool build, bool multi_thread) {
    algorithm::Algorithm<structure::BidirectionalLinkList<int>, int> algorithm{};
    algorithm::Evaluate evaluate;

    evaluate.flag = compare_and_move;
    if (build){
        list->build();
    }
    algorithm.use_thread = multi_thread;
    algorithm.max_deep = 8;

    // run
    switch (report->algorithm_name_id){
        case 0: // insertion sort
            break;
        case 1: // bubble sort
            break;
        case 2: // selection sort
            break;
        case 3: // shell sort
            break;
        case 4: // quick sort
            break;
        case 5: // heap sort
            break;
        case 6: // radix sort
            break;
        case 7: // merge sort
            break;
        case 8: // my sort
            break;
    }
}



