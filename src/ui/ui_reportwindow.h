/********************************************************************************
** Form generated from reading UI file 'reportwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTWINDOW_H
#define UI_REPORTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportWindow
{
public:
    QWidget *widget;
    QHBoxLayout *report_layout;
    QGridLayout *report_left_layout;
    QLabel *date_title;
    QLineEdit *date_input;
    QLabel *algorithm_name_title;
    QLineEdit *algorithm_name_input;
    QLabel *data_size_title;
    QLineEdit *date_size_input;
    QSpacerItem *horizontalSpacer;
    QLabel *timer_title;
    QLineEdit *timer_input;
    QLabel *compare_title;
    QLineEdit *compare_input;
    QLabel *mover_title;
    QLineEdit *mover_input;
    QSpacerItem *horizontalSpacer_2;
    QLabel *dIstribution_name;
    QLineEdit *distribution_input;
    QLabel *param1_title;
    QLineEdit *param1_input;
    QLabel *param2_title;
    QLineEdit *param2_input;
    QSpacerItem *horizontalSpacer_3;
    QLabel *file_name_title;
    QLineEdit *file_name_input;
    QLabel *file_path_title;
    QLineEdit *file_path_input;
    QVBoxLayout *report_right_layout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ReportWindow)
    {
        if (ReportWindow->objectName().isEmpty())
            ReportWindow->setObjectName("ReportWindow");
        ReportWindow->resize(400, 398);
        widget = new QWidget(ReportWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 20, 351, 362));
        report_layout = new QHBoxLayout(widget);
        report_layout->setObjectName("report_layout");
        report_layout->setContentsMargins(0, 0, 0, 0);
        report_left_layout = new QGridLayout();
        report_left_layout->setObjectName("report_left_layout");
        date_title = new QLabel(widget);
        date_title->setObjectName("date_title");
        QFont font;
        font.setPointSize(10);
        date_title->setFont(font);
        date_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        report_left_layout->addWidget(date_title, 0, 0, 1, 1);

        date_input = new QLineEdit(widget);
        date_input->setObjectName("date_input");
        date_input->setReadOnly(true);

        report_left_layout->addWidget(date_input, 0, 1, 1, 1);

        algorithm_name_title = new QLabel(widget);
        algorithm_name_title->setObjectName("algorithm_name_title");
        algorithm_name_title->setFont(font);
        algorithm_name_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        report_left_layout->addWidget(algorithm_name_title, 1, 0, 1, 1);

        algorithm_name_input = new QLineEdit(widget);
        algorithm_name_input->setObjectName("algorithm_name_input");
        algorithm_name_input->setReadOnly(true);

        report_left_layout->addWidget(algorithm_name_input, 1, 1, 1, 1);

        data_size_title = new QLabel(widget);
        data_size_title->setObjectName("data_size_title");
        data_size_title->setFont(font);
        data_size_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        report_left_layout->addWidget(data_size_title, 2, 0, 1, 1);

        date_size_input = new QLineEdit(widget);
        date_size_input->setObjectName("date_size_input");
        date_size_input->setReadOnly(true);

        report_left_layout->addWidget(date_size_input, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        report_left_layout->addItem(horizontalSpacer, 3, 0, 1, 2);

        timer_title = new QLabel(widget);
        timer_title->setObjectName("timer_title");
        timer_title->setFont(font);
        timer_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        report_left_layout->addWidget(timer_title, 4, 0, 1, 1);

        timer_input = new QLineEdit(widget);
        timer_input->setObjectName("timer_input");
        timer_input->setReadOnly(true);

        report_left_layout->addWidget(timer_input, 4, 1, 1, 1);

        compare_title = new QLabel(widget);
        compare_title->setObjectName("compare_title");
        compare_title->setFont(font);
        compare_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        report_left_layout->addWidget(compare_title, 5, 0, 1, 1);

        compare_input = new QLineEdit(widget);
        compare_input->setObjectName("compare_input");
        compare_input->setReadOnly(true);

        report_left_layout->addWidget(compare_input, 5, 1, 1, 1);

        mover_title = new QLabel(widget);
        mover_title->setObjectName("mover_title");
        mover_title->setFont(font);
        mover_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        report_left_layout->addWidget(mover_title, 6, 0, 1, 1);

        mover_input = new QLineEdit(widget);
        mover_input->setObjectName("mover_input");
        mover_input->setReadOnly(true);

        report_left_layout->addWidget(mover_input, 6, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        report_left_layout->addItem(horizontalSpacer_2, 7, 0, 1, 2);

        dIstribution_name = new QLabel(widget);
        dIstribution_name->setObjectName("dIstribution_name");
        dIstribution_name->setFont(font);
        dIstribution_name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        report_left_layout->addWidget(dIstribution_name, 8, 0, 1, 1);

        distribution_input = new QLineEdit(widget);
        distribution_input->setObjectName("distribution_input");
        distribution_input->setReadOnly(true);

        report_left_layout->addWidget(distribution_input, 8, 1, 1, 1);

        param1_title = new QLabel(widget);
        param1_title->setObjectName("param1_title");
        param1_title->setFont(font);
        param1_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        report_left_layout->addWidget(param1_title, 9, 0, 1, 1);

        param1_input = new QLineEdit(widget);
        param1_input->setObjectName("param1_input");
        param1_input->setReadOnly(true);

        report_left_layout->addWidget(param1_input, 9, 1, 1, 1);

        param2_title = new QLabel(widget);
        param2_title->setObjectName("param2_title");
        param2_title->setFont(font);
        param2_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        report_left_layout->addWidget(param2_title, 10, 0, 1, 1);

        param2_input = new QLineEdit(widget);
        param2_input->setObjectName("param2_input");
        param2_input->setReadOnly(true);

        report_left_layout->addWidget(param2_input, 10, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        report_left_layout->addItem(horizontalSpacer_3, 11, 0, 1, 2);

        file_name_title = new QLabel(widget);
        file_name_title->setObjectName("file_name_title");
        file_name_title->setFont(font);
        file_name_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        report_left_layout->addWidget(file_name_title, 12, 0, 1, 1);

        file_name_input = new QLineEdit(widget);
        file_name_input->setObjectName("file_name_input");
        file_name_input->setReadOnly(true);

        report_left_layout->addWidget(file_name_input, 12, 1, 1, 1);

        file_path_title = new QLabel(widget);
        file_path_title->setObjectName("file_path_title");
        file_path_title->setFont(font);
        file_path_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        report_left_layout->addWidget(file_path_title, 13, 0, 1, 1);

        file_path_input = new QLineEdit(widget);
        file_path_input->setObjectName("file_path_input");
        file_path_input->setReadOnly(true);

        report_left_layout->addWidget(file_path_input, 13, 1, 1, 1);


        report_layout->addLayout(report_left_layout);

        report_right_layout = new QVBoxLayout();
        report_right_layout->setObjectName("report_right_layout");
        report_right_layout->setContentsMargins(6, -1, 6, 10);
        label = new QLabel(widget);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        report_right_layout->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 248, QSizePolicy::Expanding, QSizePolicy::Minimum);

        report_right_layout->addItem(horizontalSpacer_4);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName("buttonBox");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        report_right_layout->addWidget(buttonBox);

        report_right_layout->setStretch(0, 5);
        report_right_layout->setStretch(1, 10);

        report_layout->addLayout(report_right_layout);


        retranslateUi(ReportWindow);

        QMetaObject::connectSlotsByName(ReportWindow);
    } // setupUi

    void retranslateUi(QDialog *ReportWindow)
    {
        ReportWindow->setWindowTitle(QCoreApplication::translate("ReportWindow", "Dialog", nullptr));
        date_title->setText(QCoreApplication::translate("ReportWindow", "Date", nullptr));
        algorithm_name_title->setText(QCoreApplication::translate("ReportWindow", "Algorithm Name", nullptr));
        data_size_title->setText(QCoreApplication::translate("ReportWindow", "Data Size", nullptr));
        timer_title->setText(QCoreApplication::translate("ReportWindow", "Timer", nullptr));
        compare_title->setText(QCoreApplication::translate("ReportWindow", "Compare", nullptr));
        mover_title->setText(QCoreApplication::translate("ReportWindow", "Mover", nullptr));
        dIstribution_name->setText(QCoreApplication::translate("ReportWindow", "Distribution", nullptr));
        param1_title->setText(QCoreApplication::translate("ReportWindow", "param 1", nullptr));
        param2_title->setText(QCoreApplication::translate("ReportWindow", "param 2", nullptr));
        file_name_title->setText(QCoreApplication::translate("ReportWindow", "File Name", nullptr));
        file_path_title->setText(QCoreApplication::translate("ReportWindow", "File Path", nullptr));
        label->setText(QCoreApplication::translate("ReportWindow", "Task 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReportWindow: public Ui_ReportWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTWINDOW_H
