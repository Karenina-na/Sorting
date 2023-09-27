#include "distributionwindow.h"
#include "ui_distributionwindow.h"
#include <QlineEdit>
#include <random>
#include <Qpainter>

DistributionWindow::DistributionWindow(QWidget *parent, bool first_change,
                                       int max, int min, int size, unsigned int seed,
                                       double lambda_p, double lambda_e, double mean, double stddev, int distribution)
        : QDialog(parent)
        , ui(new Ui::DistributionWindow)
{
    ui->setupUi(this);
    this->distribution = distribution;

    if (first_change){
        // set default param
        set_default_param();
    }else{
        // set param
        set_param(max, min, size, seed, lambda_p, lambda_e, mean, stddev);
    }

    // connect signal and slot
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &DistributionWindow::on_buttonBox_click_accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &DistributionWindow::on_buttonBox_click_reject);

    connect(ui->max_input, &QLineEdit::editingFinished, this, &DistributionWindow::on_distribution_change);
    connect(ui->min_input, &QLineEdit::editingFinished, this, &DistributionWindow::on_distribution_change);
    connect(ui->size_input, &QLineEdit::editingFinished, this, &DistributionWindow::on_distribution_change);
    connect(ui->param1_input, &QLineEdit::editingFinished, this, &DistributionWindow::on_distribution_change);
    connect(ui->param2_input, &QLineEdit::editingFinished, this, &DistributionWindow::on_distribution_change);
}
DistributionWindow::~DistributionWindow()
{
    delete ui;
}

// pdf
double DistributionWindow::pdf_u(double x, int min, int max) {
    return 1.0 / (max - min + 1);
}

double DistributionWindow::pdf_g(double x, int min, int max, double mean, double stddev) {
    // 1 / (sita * sqrt(2 * pi)) * exp(-1 * (x - u)^2 / (2 * sita^2)
    return 1.0 / (stddev * sqrt(2 * M_PI)) * exp(-1.0 * (x - mean) * (x - mean) / (2 * stddev * stddev));
}

double DistributionWindow::pdf_p(double x, int min, int max, double lambda) {
    // (lambda^x / x!) * exp(-1 * lambda)
    double result = 1;
    for (int i = 1; i <= x; i++){
        result *= lambda / i;
    }
    result *= exp(-1 * lambda);
    return result;
}

double DistributionWindow::pdf_e(double x, int min, int max, double lambda) {
    // lambda * exp(-1 * lambda * x)
    return lambda * exp(-1 * lambda * x);
}

// set param
void DistributionWindow::set_default_param(){
    // set param text
    ui->max_input->setText("100");
    ui->min_input->setText("0");
    ui->size_input->setText("100");
    std::default_random_engine generator;
    std::uniform_int_distribution<int32_t> d(0, INT32_MAX);
    int32_t rand_int32 = d(generator);
    ui->seed_input->setText(QString::number(rand_int32));
    switch(distribution){
        case 0: // uniform
            ui->param1->setText("--");
            ui->param2->setText("--");
            ui->param1_input->setReadOnly(true);
            ui->param2_input->setReadOnly(true);
            break;
        case 1: // poisson
            ui->param1->setText("lambda");
            ui->param2->setText("--");
            ui->param1_input->setReadOnly(false);
            ui->param1_input->setText("1");
            ui->param2_input->setReadOnly(true);
            break;
        case 2: // exponential
            ui->param1->setText("lambda");
            ui->param2->setText("--");
            ui->param1_input->setReadOnly(false);
            ui->param1_input->setText("1");
            ui->param2_input->setReadOnly(true);
            break;
        case 3: // gaussian
            ui->param1->setText("mean");
            ui->param2->setText("stddev");
            ui->param1_input->setReadOnly(false);
            ui->param1_input->setText("0");
            ui->param2_input->setReadOnly(false);
            ui->param2_input->setText("1");
            break;
    }
}

void DistributionWindow::set_param(int max, int min, int size, unsigned int seed,
                                            double lambda_p, double lambda_e, double mean, double stddev){
    if (max != 0){
        this->max = max;
    }else{
        this->max = 100;
    }
    if (min != 0){
        this->min = min;
    }else{
        this->min = 0;
    }
    if (size != 0){
        this->size = size;
    }else{
        this->size = 100;
    }
    if (seed != 0){
        this->seed = seed;
    }else{
        std::default_random_engine generator;
        std::uniform_int_distribution<int32_t> d(0, INT32_MAX);
        int32_t rand_int32 = d(generator);
        this->seed = rand_int32;
    }
    if (lambda_p != 0){
        this->lambda_p = lambda_p;
    }else{
        this->lambda_p = 1;
    }
    if (lambda_e != 0){
        this->lambda_e = lambda_e;
    }else{
        this->lambda_e = 1;
    }
    if (mean != 0){
        this->mean = mean;
    }else{
        this->mean = 0;
    }
    if (stddev != 0){
        this->stddev = stddev;
    }else{
        this->stddev = 1;
    }
    // set param text
    ui->max_input->setText(QString::number(this->max));
    ui->min_input->setText(QString::number(this->min));
    ui->size_input->setText(QString::number(this->size));
    ui->seed_input->setText(QString::number(this->seed));
    switch(distribution){
        case 0: // uniform
            ui->param1->setText("--");
            ui->param2->setText("--");
            ui->param1_input->setReadOnly(true);
            ui->param2_input->setReadOnly(true);
            break;
        case 1: // poisson
            ui->param1->setText("lambda");
            ui->param2->setText("--");
            ui->param1_input->setReadOnly(false);
            ui->param1_input->setText(QString::number(this->lambda_p));
            ui->param2_input->setReadOnly(true);
            break;
        case 2: // exponential
            ui->param1->setText("lambda");
            ui->param2->setText("--");
            ui->param1_input->setReadOnly(false);
            ui->param1_input->setText(QString::number(this->lambda_e));
            ui->param2_input->setReadOnly(true);
            break;
        case 3: // gaussian
            ui->param1->setText("mean");
            ui->param2->setText("stddev");
            ui->param1_input->setReadOnly(false);
            ui->param1_input->setText(QString::number(this->mean));
            ui->param2_input->setReadOnly(false);
            ui->param2_input->setText(QString::number(this->stddev));
            break;
    }
}

// button signal
void DistributionWindow::on_buttonBox_click_accept() {
    this->change = true;
    // get parameters
    switch (distribution){
        case 0: // uniform
            seed = ui->seed_input->text().toUInt();
            size = ui->size_input->text().toInt();
            min = ui->min_input->text().toInt();
            max = ui->max_input->text().toInt();
            break;
        case 1: // poisson
            seed = ui->seed_input->text().toUInt();
            size = ui->size_input->text().toInt();
            min = ui->min_input->text().toInt();
            max = ui->max_input->text().toInt();
            lambda_p = ui->param1_input->text().toDouble();
            break;
        case 2: // exponential
            seed = ui->seed_input->text().toUInt();
            size = ui->size_input->text().toInt();
            min = ui->min_input->text().toInt();
            max = ui->max_input->text().toInt();
            lambda_e = ui->param1_input->text().toDouble();
            break;
        case 3: // gaussian
            seed = ui->seed_input->text().toUInt();
            size = ui->size_input->text().toInt();
            min = ui->min_input->text().toInt();
            max = ui->max_input->text().toInt();
            mean = ui->param1_input->text().toDouble();
            stddev = ui->param2_input->text().toDouble();
            break;
    }
    this->close();
}

void DistributionWindow::on_buttonBox_click_reject() {
    this->change = false;
    // close window
    this->close();
}

// param update
void DistributionWindow::on_distribution_change() {

}


