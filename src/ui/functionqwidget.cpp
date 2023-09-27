#include "functionqwidget.h"
#include <QPainter>
#include <QtMath>
#include <QTimer>
#include <QMouseEvent>

FunctionQWidget::FunctionQWidget(QWidget *parent)
: QWidget(parent)
{
    // set background
    QPalette palette;
    palette.setColor(backgroundRole(), Qt::white);
    setPalette(palette);
}

void FunctionQWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    int width = this->width();
    int height = this->height();
    int side = qMin(width, height);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);//设置抗锯齿
    painter.translate(width / 2, height / 2); //设置坐标中心为控件中心
    painter.scale(side / 200.0, side / 200.0); //设置比例缩放

    //绘制坐标轴，
    painter.setPen(QPen(Qt::black, 2));
    painter.drawLine(QPointF(-100, 0), QPointF(100, 0));
    painter.drawLine(QPointF(0, -100), QPointF(0, 100));
}
