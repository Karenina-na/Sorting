#include "functionqwidget.h"
#include <QPainter>
#include <QtMath>
#include <QTimer>
#include <QMouseEvent>
#include <QPainterPath>

FunctionQWidget::FunctionQWidget(QWidget *parent)
: QWidget(parent)
{
    // set background
    QPalette palette;
    palette.setColor(backgroundRole(), Qt::white);
    setPalette(palette);
}

double FunctionQWidget::transform(double x){
    // 需要一个当 x = 50 时 y = 50
    // y = [0, +00)
    // x = [0, 100]
    return x;
}

void FunctionQWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    int width = this->width();
    int height = this->height();

    QPainter painter(this);
    QPen pan;
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);//设置抗锯齿
    painter.translate(width / 2, height / 2); //设置坐标中心为控件中心

    int point_num = 50000;

    // 缩放系数
    // x = x * (horizontal_slider_value / 50) y = y * (vertical_slider_value / 50)
    double max_y_num = 0.5 * (50 / this->transform(vertical_slider_value));    //  y 轴初始最大值 0.5
    double max_x_num = 20 * (50 / this->transform(horizontal_slider_value));    //  x 轴初始最大值 20
    double one_px_y = height / (2 * max_y_num); // y 轴每1刻度所占像素
    double one_px_x = width / (2 * max_x_num);  // x 轴每1刻度所占像素
    painter.setPen(pan);

    // 填充背景为白色
    painter.setBrush(Qt::white);
    painter.drawRect(-width / 2, -height / 2, width, height);

    //绘制坐标轴
    pan.setColor(Qt::black);
    pan.setStyle(Qt::SolidLine);
    pan.setWidth(1);
    painter.setPen(pan);
    painter.drawLine(-width / 2, 0, width / 2, 0);
    painter.drawLine(0, -height / 2, 0, height / 2);

    // 绘制刻度
    pan.setColor(Qt::black);
    pan.setStyle(Qt::SolidLine);
    pan.setWidth(1);
    painter.setPen(pan);
    // x
    for (int i = 0; i < max_x_num; i += 10) {
        painter.drawLine(i * one_px_x, 0, i * one_px_x, -5);
        painter.drawLine(-i * one_px_x, 0, -i * one_px_x, -5);
    }
    // y
    for (double i = 0; i < max_y_num; i += 0.1) {
        painter.drawLine(0, i * one_px_y, 5, i * one_px_y);
        painter.drawLine(0, -i * one_px_y, 5, -i * one_px_y);
    }

    // 绘制坐标轴名称
    pan.setColor(Qt::black);
    pan.setStyle(Qt::SolidLine);
    pan.setWidth(1);
    painter.setPen(pan);
    painter.drawText(max_x_num * one_px_x - 10, -5, QString::fromStdString("X"));
    painter.drawText(5, max_y_num * one_px_y - 10, QString::fromStdString("Y"));

    // 绘制函数
    pan.setColor(Qt::red);
    pan.setStyle(Qt::SolidLine);
    pan.setWidth(2);
    painter.setPen(pan);
    QList<QPointF> points;
    switch(distribution){
        case 0: // uniform
            for (int i = 0; i <= point_num; i++) {
                double x = min + (max - min) * i / point_num;
                double y = - 1.0 / (max - min);
                points.append(QPointF(x * one_px_x, y * one_px_y));
            }
            break;
        case 1: // poisson
            for (int i = 0; i <= point_num; i++) {
                double x = min + (max - min) * i / point_num;
                double y = - qExp(-lambda_p) * qPow(lambda_p, x) / tgamma(x + 1);
                points.append(QPointF(x * one_px_x, y * one_px_y));
            }
            break;
        case 2: // exponential
            for (int i = 0; i <= point_num; i++) {
                double x = min + (max - min) * i / point_num;
                double y = - lambda_e * qExp(-lambda_e * x);
                points.append(QPointF(x * one_px_x, y * one_px_y));
            }
            break;
        case 3: // gaussian
            for (int i = 0; i <= point_num; i++) {
                double x = min + (max - min) * i / point_num;
                double y = - 1.0 / (stddev * qSqrt(2 * M_PI)) * qExp(-qPow(x - mean, 2) / (2 * qPow(stddev, 2)));
                points.append(QPointF(x * one_px_x, y * one_px_y));
            }
            break;
    }

    // 赛贝尔曲线
    QPainterPath P;
    for(int i = 0; i < points.size() - 1; ++i)
    {
        QPointF c1 = points.at(i) + (points.at(i + 1) - points.at(i)) * 0.25;
        QPointF c2 = points.at(i) + (points.at(i + 1) - points.at(i)) * 0.75;
        QPointF ep = points.at(i + 1);
        if(i == 0)
            P.moveTo(points.at(i));
        P.cubicTo(c1,c2,ep);
    }
    painter.drawPath(P);
}
