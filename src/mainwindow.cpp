#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ui/distributionwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->data_input_uniform_button, &QPushButton::clicked, this, &MainWindow::on_data_input_uniform_button_clicked);
    connect(ui->data_input_poisson_button, &QPushButton::clicked, this, &MainWindow::on_data_input_poisson_button_clicked);
    connect(ui->data_input_exponential_button, &QPushButton::clicked, this, &MainWindow::on_data_input_exponential_button_clicked);
    connect(ui->data_input_gaussian_button, &QPushButton::clicked, this, &MainWindow::on_data_input_gaussian_button_clicked);
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

