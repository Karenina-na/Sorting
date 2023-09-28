#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "distributionwindow.h"
#include "functionqwidget.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // generator
    connect(ui->data_input_uniform_button, &QPushButton::clicked, this, &MainWindow::on_data_input_uniform_button_clicked);
    connect(ui->data_input_poisson_button, &QPushButton::clicked, this, &MainWindow::on_data_input_poisson_button_clicked);
    connect(ui->data_input_exponential_button, &QPushButton::clicked, this, &MainWindow::on_data_input_exponential_button_clicked);
    connect(ui->data_input_gaussian_button, &QPushButton::clicked, this, &MainWindow::on_data_input_gaussian_button_clicked);

    // QSideBar
    connect(ui->data_input_distribution_horizontal_slider, &QSlider::valueChanged, this, &MainWindow::on_data_input_distribution_horizontal_slider_valueChanged);
    connect(ui->data_input_distribution_vertical_slider, &QSlider::valueChanged, this, &MainWindow::on_data_input_distribution_vertical_slider_valueChanged);

    // load data
    connect(ui->data_loader_button, &QPushButton::clicked, this, &MainWindow::on_data_loader_button_clicked);
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
}