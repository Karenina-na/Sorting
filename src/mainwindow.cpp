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

void MainWindow::on_data_input_uniform_button_clicked() {
    auto* distributionWindow = new DistributionWindow(this);
    distributionWindow->show();
}

void MainWindow::on_data_input_poisson_button_clicked() {
    auto* distributionWindow = new DistributionWindow(this);
    distributionWindow->show();
}

void MainWindow::on_data_input_exponential_button_clicked() {
    auto* distributionWindow = new DistributionWindow(this);
    distributionWindow->show();
}

void MainWindow::on_data_input_gaussian_button_clicked() {
    auto* distributionWindow = new DistributionWindow(this);
    distributionWindow->show();
}

