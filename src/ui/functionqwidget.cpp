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
    return x * 2;
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

    int point_num = 5000;

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
    painter.drawText(max_x_num * one_px_x - 15, 12, QString::fromStdString("X"));
    painter.drawText(-12, - max_y_num * one_px_y + 15, QString::fromStdString("Y"));

    // 输出点数量信息与赛贝尔曲线名称
    pan.setColor(Qt::black);
    pan.setStyle(Qt::SolidLine);
    pan.setWidth(1);
    painter.setPen(pan);
    painter.drawText(-width / 2 + 10, -height / 2 + 20, QString::fromStdString("Point Num: " + QString::number(point_num).toStdString()));
    painter.drawText(-35, height / 2 - 10, QString::fromStdString("Bezier Curve"));

    // 绘制函数
    pan.setColor(Qt::red);
    pan.setStyle(Qt::SolidLine);
    pan.setWidth(2);
    painter.setPen(pan);
    QList<QPointF> points;
    switch(distribution){
        case 0: // uniform
            for (double i = 0; i <= point_num; i++) {
                double x = min + (max - min) * i / point_num;
                double y = - 1.0 / (max - min);
                points.append(QPointF(x * one_px_x, y * one_px_y));
            }
            break;
        case 1: // poisson
            for (double i = 0; i <= point_num; i++) {
                double x = min + (max - min) * i / point_num;
                double y = - qExp(-lambda_p) * qPow(lambda_p, x) / tgamma(x + 1);
                points.append(QPointF(x * one_px_x, y * one_px_y));
            }
            break;
        case 2: // exponential
            for (double i = 0; i <= point_num; i++) {
                double x = min + (max - min) * i / point_num;
                double y = - lambda_e * qExp(-lambda_e * x);
                points.append(QPointF(x * one_px_x, y * one_px_y));
            }
            break;
        case 3: // gaussian
            for (double i = 0; i <= point_num; i++) {
                double x = min + (max - min) * i / point_num;
                double y = - 1.0 / (stddev * qSqrt(2 * M_PI)) * qExp(-qPow(x - mean, 2) / (2 * qPow(stddev, 2)));
                points.append(QPointF(x * one_px_x, y * one_px_y));
            }
            break;
    }

    // min max 两条竖直线
    pan.setColor(Qt::red);
    pan.setStyle(Qt::SolidLine);
    pan.setWidth(1);
    painter.setPen(pan);
    painter.drawLine(min * one_px_x, -height / 2, min * one_px_x, height / 2);
    painter.drawLine(max * one_px_x, -height / 2, max * one_px_x, height / 2);
    painter.drawText(min * one_px_x - 10, height / 2 - 20, QString::fromStdString("min"));
    painter.drawText(max * one_px_x - 10, height / 2 - 20, QString::fromStdString("max"));

    // 赛贝尔曲线
    pan.setColor(Qt::blue);
    pan.setStyle(Qt::SolidLine);
    pan.setWidth(1);
    painter.setPen(pan);
    QPainterPath path;
    path.moveTo(points[0]);
    for (int i = 0; i < points.size() - 1; i++) {
        QPointF p1 = points[i];
        QPointF p2 = points[i + 1];
        QPointF c1 = QPointF(p1.x() + (p2.x() - p1.x()) / 2, p1.y());
        QPointF c2 = QPointF(p1.x() + (p2.x() - p1.x()) / 2, p2.y());
        path.cubicTo(c1, c2, p2);
    }
    painter.drawPath(path);
}
