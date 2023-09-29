#ifndef REPORTWINDOW_H
#define REPORTWINDOW_H
#include <QDialog>
#include "ReportStruct.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ReportWindow; }
QT_END_NAMESPACE

class ReportWindow : public QDialog
{
Q_OBJECT
public:
    explicit ReportWindow(QWidget *parent, structure::Report<int>* report, int task_num);
    ~ReportWindow() override;

private:
    Ui::ReportWindow *ui;

    void on_buttonBox_click_accept();
    void on_buttonBox_click_reject();

    structure::Report<int>* report;
};


#endif //REPORTWINDOW_H
