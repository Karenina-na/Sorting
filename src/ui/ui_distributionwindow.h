/********************************************************************************
** Form generated from reading UI file 'distributionwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISTRIBUTIONWINDOW_H
#define UI_DISTRIBUTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "functionqwidget.h"

QT_BEGIN_NAMESPACE

class Ui_DistributionWindow
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QGridLayout *function_show_layout;
    FunctionQWidget *function_show;
    QSlider *verticalSlider;
    QSlider *horizontalSlider;
    QGridLayout *input_data_layout;
    QLabel *max;
    QLineEdit *max_input;
    QLabel *param1;
    QLineEdit *param1_input;
    QLabel *min;
    QLineEdit *min_input;
    QLabel *param2;
    QLineEdit *param2_input;
    QLabel *size;
    QLineEdit *size_input;
    QLabel *seed;
    QLineEdit *seed_input;
    QVBoxLayout *button_layout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DistributionWindow)
    {
        if (DistributionWindow->objectName().isEmpty())
            DistributionWindow->setObjectName("DistributionWindow");
        DistributionWindow->resize(470, 400);
        DistributionWindow->setMinimumSize(QSize(470, 400));
        DistributionWindow->setMaximumSize(QSize(470, 400));
        layoutWidget = new QWidget(DistributionWindow);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 20, 431, 361));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(14);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        function_show_layout = new QGridLayout();
        function_show_layout->setSpacing(10);
        function_show_layout->setObjectName("function_show_layout");
        function_show = new FunctionQWidget(layoutWidget);
        function_show->setObjectName("function_show");

        function_show_layout->addWidget(function_show, 0, 0, 1, 1);

        verticalSlider = new QSlider(layoutWidget);
        verticalSlider->setObjectName("verticalSlider");
        verticalSlider->setMinimum(15);
        verticalSlider->setValue(25);
        verticalSlider->setOrientation(Qt::Vertical);

        function_show_layout->addWidget(verticalSlider, 0, 1, 2, 1);

        horizontalSlider = new QSlider(layoutWidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setMinimum(2);
        horizontalSlider->setMaximum(50);
        horizontalSlider->setValue(35);
        horizontalSlider->setOrientation(Qt::Horizontal);

        function_show_layout->addWidget(horizontalSlider, 1, 0, 1, 1);


        gridLayout->addLayout(function_show_layout, 0, 0, 1, 2);

        input_data_layout = new QGridLayout();
        input_data_layout->setObjectName("input_data_layout");
        input_data_layout->setHorizontalSpacing(10);
        max = new QLabel(layoutWidget);
        max->setObjectName("max");
        QFont font;
        font.setPointSize(12);
        max->setFont(font);
        max->setAlignment(Qt::AlignCenter);

        input_data_layout->addWidget(max, 0, 0, 1, 1);

        max_input = new QLineEdit(layoutWidget);
        max_input->setObjectName("max_input");
        max_input->setAlignment(Qt::AlignCenter);

        input_data_layout->addWidget(max_input, 0, 1, 1, 1);

        param1 = new QLabel(layoutWidget);
        param1->setObjectName("param1");
        param1->setFont(font);
        param1->setAlignment(Qt::AlignCenter);

        input_data_layout->addWidget(param1, 0, 2, 1, 1);

        param1_input = new QLineEdit(layoutWidget);
        param1_input->setObjectName("param1_input");
        param1_input->setAlignment(Qt::AlignCenter);

        input_data_layout->addWidget(param1_input, 0, 3, 1, 1);

        min = new QLabel(layoutWidget);
        min->setObjectName("min");
        min->setFont(font);
        min->setAlignment(Qt::AlignCenter);

        input_data_layout->addWidget(min, 1, 0, 1, 1);

        min_input = new QLineEdit(layoutWidget);
        min_input->setObjectName("min_input");
        min_input->setAlignment(Qt::AlignCenter);

        input_data_layout->addWidget(min_input, 1, 1, 1, 1);

        param2 = new QLabel(layoutWidget);
        param2->setObjectName("param2");
        param2->setFont(font);
        param2->setAlignment(Qt::AlignCenter);

        input_data_layout->addWidget(param2, 1, 2, 1, 1);

        param2_input = new QLineEdit(layoutWidget);
        param2_input->setObjectName("param2_input");
        param2_input->setAlignment(Qt::AlignCenter);

        input_data_layout->addWidget(param2_input, 1, 3, 1, 1);

        size = new QLabel(layoutWidget);
        size->setObjectName("size");
        size->setFont(font);
        size->setAlignment(Qt::AlignCenter);

        input_data_layout->addWidget(size, 2, 0, 1, 1);

        size_input = new QLineEdit(layoutWidget);
        size_input->setObjectName("size_input");
        size_input->setAlignment(Qt::AlignCenter);

        input_data_layout->addWidget(size_input, 2, 1, 1, 1);

        seed = new QLabel(layoutWidget);
        seed->setObjectName("seed");
        seed->setFont(font);
        seed->setAlignment(Qt::AlignCenter);

        input_data_layout->addWidget(seed, 2, 2, 1, 1);

        seed_input = new QLineEdit(layoutWidget);
        seed_input->setObjectName("seed_input");
        seed_input->setAlignment(Qt::AlignCenter);

        input_data_layout->addWidget(seed_input, 2, 3, 1, 1);

        input_data_layout->setRowStretch(0, 1);
        input_data_layout->setRowStretch(1, 1);
        input_data_layout->setRowStretch(2, 1);
        input_data_layout->setColumnStretch(0, 1);
        input_data_layout->setColumnStretch(1, 4);
        input_data_layout->setColumnStretch(2, 1);
        input_data_layout->setColumnStretch(3, 4);
        input_data_layout->setColumnMinimumWidth(0, 1);
        input_data_layout->setColumnMinimumWidth(1, 4);
        input_data_layout->setColumnMinimumWidth(2, 1);
        input_data_layout->setColumnMinimumWidth(3, 4);

        gridLayout->addLayout(input_data_layout, 1, 0, 1, 1);

        button_layout = new QVBoxLayout();
        button_layout->setObjectName("button_layout");
        horizontalSpacer_2 = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        button_layout->addItem(horizontalSpacer_2);

        horizontalSpacer = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        button_layout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        button_layout->addWidget(buttonBox);


        gridLayout->addLayout(button_layout, 1, 1, 1, 1);

        gridLayout->setRowStretch(0, 10);
        gridLayout->setRowStretch(1, 4);

        retranslateUi(DistributionWindow);

        QMetaObject::connectSlotsByName(DistributionWindow);
    } // setupUi

    void retranslateUi(QDialog *DistributionWindow)
    {
        DistributionWindow->setWindowTitle(QCoreApplication::translate("DistributionWindow", "Dialog", nullptr));
        max->setText(QCoreApplication::translate("DistributionWindow", "max:", nullptr));
        max_input->setText(QString());
        param1->setText(QCoreApplication::translate("DistributionWindow", "p1:", nullptr));
        param1_input->setText(QString());
        min->setText(QCoreApplication::translate("DistributionWindow", "min:", nullptr));
        min_input->setText(QString());
        param2->setText(QCoreApplication::translate("DistributionWindow", "p2:", nullptr));
        param2_input->setText(QString());
        size->setText(QCoreApplication::translate("DistributionWindow", "size:", nullptr));
        size_input->setText(QString());
        seed->setText(QCoreApplication::translate("DistributionWindow", "seed", nullptr));
        seed_input->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DistributionWindow: public Ui_DistributionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISTRIBUTIONWINDOW_H
