#ifndef DISTRIBUTIONWINDOW_H
#define DISTRIBUTIONWINDOW_H
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class DistributionWindow; }
QT_END_NAMESPACE

class DistributionWindow : public QDialog
{
Q_OBJECT

public:
    explicit DistributionWindow(QWidget *parent = nullptr);
    ~DistributionWindow() override;

private:
    Ui::DistributionWindow *ui;
};
#endif //DISTRIBUTIONWINDOW_H
