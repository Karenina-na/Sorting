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
    explicit DistributionWindow(QWidget *parent, bool first_change,
                                int max, int min, int size, unsigned int seed,
                                double lambda_p, double lambda_e, double mean, double stddev, int distribution);
    ~DistributionWindow() override;

    int distribution{};   // 0: uniform, 1: poisson, 2: exponential, 3: gaussian
    bool change = false;

    // parameters
    unsigned int seed{};
    int size{};
    int min{};
    int max{};

    // uniform parameters

    // gaussian parameters
    double mean{};
    double stddev{};

    // poisson parameters
    double lambda_p{};

    // exponential parameters
    double lambda_e{};

    // button signal
    void on_buttonBox_click_accept();
    void on_buttonBox_click_reject();

    // param update
    void on_distribution_change();

    // QSideBar
    void on_horizontal_slider_valueChanged(int value);
    void on_vertical_slider_valueChanged(int value);

private:
    Ui::DistributionWindow *ui;

    // set param
    void set_default_param();
    void set_param(int max, int min, int size, unsigned int seed,
                    double lambda_p, double lambda_e, double mean, double stddev);

    void recreate_functionqwidget();
};
#endif //DISTRIBUTIONWINDOW_H
