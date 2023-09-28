#ifndef FUNCTIONQWIDGET_H
#define FUNCTIONQWIDGET_H
#include <QWidget>

class FunctionQWidget : public QWidget
{

public:
    explicit FunctionQWidget(QWidget *parent = nullptr );

    int min = 0;
    int max = 10;
    double lambda_p = 1;
    double lambda_e = 1;
    double mean = 0;
    double stddev = 1;
    int distribution = 4;   // 0: uniform, 1: poisson, 2: exponential, 3: gaussian, 4: random

    double horizontal_slider_value = 35;
    double vertical_slider_value = 25;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    double transform(double x);
};
#endif //FUNCTIONQWIDGET_H
