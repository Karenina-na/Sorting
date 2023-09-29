//
// Created by Karenina-na on 2023/9/28.
//
#include <QFileDialog>
#include "reportwindow.h"
#include "ui_reportwindow.h"

ReportWindow::ReportWindow(QWidget *parent, structure::Report<int>* report, int task_num)
        : QDialog(parent)
        , ui(new Ui::ReportWindow){
    ui->setupUi(this);
    this->setWindowTitle("Report");
    this->report = report;
    ui->label->setText("Task " + QString::number(task_num));

    // set value
    time_t t = report->date;
    struct tm *p;
    p = gmtime(&t);
    char s[100];
    strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", p);
    ui->date_input->setText(QString::fromStdString(s));
    ui->algorithm_name_input->setText(QString::fromStdString(report->algorithm_name));
    ui->date_size_input->setText(QString::number(report->data_size));

    ui->timer_input->setText(QString::number(report->time));
    ui->compare_input->setText(QString::number(report->comp_count));
    ui->mover_input->setText(QString::number(report->move_count));

    ui->distribution_input->setText(QString::fromStdString(report->data_distribution));
    if (report->data_distribution_param_name.size() > 3){
        ui->param1_title->setText(QString::fromStdString(report->data_distribution_param_name[3]));
        ui->param1_input->setText(QString::number(report->data_distribution_param[3]));
        if (report->data_distribution_param_name.size() > 4){
            ui->param2_title->setText(QString::fromStdString(report->data_distribution_param_name[4]));
            ui->param2_input->setText(QString::number(report->data_distribution_param[4]));
        }
    }

    ui->file_name_input->setText(QString::fromStdString(report->file_name));
    ui->file_path_input->setText(QString::fromStdString(report->file_path));

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &ReportWindow::on_buttonBox_click_accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &ReportWindow::on_buttonBox_click_reject);
}

ReportWindow::~ReportWindow()
{
    delete ui;
}

void ReportWindow::on_buttonBox_click_accept() {
    // get file path
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setOption(QFileDialog::ShowDirsOnly);
    dialog.setDirectory(QDir::currentPath());
    dialog.exec();
    QString path = dialog.selectedFiles()[0];

    // save
    report->save(path.toStdString());

    this->close();
}

void ReportWindow::on_buttonBox_click_reject() {
    this->close();
}
