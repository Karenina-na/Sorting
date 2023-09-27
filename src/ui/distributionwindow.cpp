#include "distributionwindow.h"
#include "ui_distributionwindow.h"

DistributionWindow::DistributionWindow(QWidget *parent)
        : QDialog(parent)
        , ui(new Ui::DistributionWindow)
{
    ui->setupUi(this);

}

DistributionWindow::~DistributionWindow()
{
    delete ui;
}