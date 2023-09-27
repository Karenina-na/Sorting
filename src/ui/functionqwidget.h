#ifndef FUNCTIONQWIDGET_H
#define FUNCTIONQWIDGET_H
#include <QWidget>

class FunctionQWidget : public QWidget
{

public:
    explicit FunctionQWidget(QWidget *parent = nullptr );

protected:
    void paintEvent(QPaintEvent *event) override;

private:
};
#endif //FUNCTIONQWIDGET_H
