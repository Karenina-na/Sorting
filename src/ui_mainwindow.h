/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ui/functionqwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *Data_Input_Layout;
    QWidget *layoutWidget;
    QHBoxLayout *Data_layout;
    QHBoxLayout *Data_Generator_layout;
    QVBoxLayout *data_generator_left_layout;
    QLabel *data_input_generator_title;
    QTextBrowser *data_input_parameter_show;
    QGridLayout *distribution_choose_layout;
    QPushButton *data_input_uniform_button;
    QPushButton *data_input_gaussian_button;
    QPushButton *data_input_poisson_button;
    QPushButton *data_input_exponential_button;
    QSpacerItem *Data_Generator_space;
    QGridLayout *distribution_show_layout;
    FunctionQWidget *data_input_distribution_preview;
    QSlider *data_input_distribution_vertical_slider;
    QSlider *data_input_distribution_horizontal_slider;
    QSpacerItem *Data_Loader_space;
    QVBoxLayout *Data_Loader_layout;
    QLabel *Data_Loader_title;
    QTextBrowser *Data_Loader_preview;
    QHBoxLayout *Data_Loader_button_layout;
    QTextBrowser *Data_Loader_show;
    QPushButton *Data_Loader_Button;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        MainWindow->setMouseTracking(false);
        MainWindow->setContextMenuPolicy(Qt::DefaultContextMenu);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("accessories-calculator");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        MainWindow->setWindowIcon(icon);
        Data_Input_Layout = new QWidget(MainWindow);
        Data_Input_Layout->setObjectName("Data_Input_Layout");
        layoutWidget = new QWidget(Data_Input_Layout);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 781, 221));
        Data_layout = new QHBoxLayout(layoutWidget);
        Data_layout->setSpacing(0);
        Data_layout->setObjectName("Data_layout");
        Data_layout->setContentsMargins(0, 0, 0, 0);
        Data_Generator_layout = new QHBoxLayout();
        Data_Generator_layout->setSpacing(6);
        Data_Generator_layout->setObjectName("Data_Generator_layout");
        data_generator_left_layout = new QVBoxLayout();
        data_generator_left_layout->setObjectName("data_generator_left_layout");
        data_input_generator_title = new QLabel(layoutWidget);
        data_input_generator_title->setObjectName("data_input_generator_title");
        QFont font;
        font.setPointSize(12);
        data_input_generator_title->setFont(font);
        data_input_generator_title->setAutoFillBackground(false);
        data_input_generator_title->setAlignment(Qt::AlignCenter);

        data_generator_left_layout->addWidget(data_input_generator_title);

        data_input_parameter_show = new QTextBrowser(layoutWidget);
        data_input_parameter_show->setObjectName("data_input_parameter_show");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(12);
        font1.setKerning(true);
        font1.setHintingPreference(QFont::PreferDefaultHinting);
        data_input_parameter_show->setFont(font1);
        data_input_parameter_show->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        data_input_parameter_show->setStyleSheet(QString::fromUtf8(""));
        data_input_parameter_show->setLineWidth(1);
        data_input_parameter_show->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        data_input_parameter_show->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        data_generator_left_layout->addWidget(data_input_parameter_show);

        distribution_choose_layout = new QGridLayout();
        distribution_choose_layout->setObjectName("distribution_choose_layout");
        data_input_uniform_button = new QPushButton(layoutWidget);
        data_input_uniform_button->setObjectName("data_input_uniform_button");

        distribution_choose_layout->addWidget(data_input_uniform_button, 0, 0, 1, 1);

        data_input_gaussian_button = new QPushButton(layoutWidget);
        data_input_gaussian_button->setObjectName("data_input_gaussian_button");

        distribution_choose_layout->addWidget(data_input_gaussian_button, 0, 1, 1, 1);

        data_input_poisson_button = new QPushButton(layoutWidget);
        data_input_poisson_button->setObjectName("data_input_poisson_button");

        distribution_choose_layout->addWidget(data_input_poisson_button, 1, 0, 1, 1);

        data_input_exponential_button = new QPushButton(layoutWidget);
        data_input_exponential_button->setObjectName("data_input_exponential_button");

        distribution_choose_layout->addWidget(data_input_exponential_button, 1, 1, 1, 1);


        data_generator_left_layout->addLayout(distribution_choose_layout);


        Data_Generator_layout->addLayout(data_generator_left_layout);

        Data_Generator_space = new QSpacerItem(5, 198, QSizePolicy::Minimum, QSizePolicy::Expanding);

        Data_Generator_layout->addItem(Data_Generator_space);

        distribution_show_layout = new QGridLayout();
        distribution_show_layout->setObjectName("distribution_show_layout");
        data_input_distribution_preview = new FunctionQWidget(layoutWidget);
        data_input_distribution_preview->setObjectName("data_input_distribution_preview");

        distribution_show_layout->addWidget(data_input_distribution_preview, 0, 0, 1, 1);

        data_input_distribution_vertical_slider = new QSlider(layoutWidget);
        data_input_distribution_vertical_slider->setObjectName("data_input_distribution_vertical_slider");
        data_input_distribution_vertical_slider->setMinimum(15);
        data_input_distribution_vertical_slider->setMaximum(99);
        data_input_distribution_vertical_slider->setValue(25);
        data_input_distribution_vertical_slider->setSliderPosition(25);
        data_input_distribution_vertical_slider->setOrientation(Qt::Vertical);

        distribution_show_layout->addWidget(data_input_distribution_vertical_slider, 0, 1, 2, 1);

        data_input_distribution_horizontal_slider = new QSlider(layoutWidget);
        data_input_distribution_horizontal_slider->setObjectName("data_input_distribution_horizontal_slider");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(data_input_distribution_horizontal_slider->sizePolicy().hasHeightForWidth());
        data_input_distribution_horizontal_slider->setSizePolicy(sizePolicy1);
        data_input_distribution_horizontal_slider->setMinimum(2);
        data_input_distribution_horizontal_slider->setMaximum(50);
        data_input_distribution_horizontal_slider->setPageStep(10);
        data_input_distribution_horizontal_slider->setValue(35);
        data_input_distribution_horizontal_slider->setOrientation(Qt::Horizontal);

        distribution_show_layout->addWidget(data_input_distribution_horizontal_slider, 1, 0, 1, 1);

        distribution_show_layout->setRowStretch(0, 20);
        distribution_show_layout->setColumnStretch(0, 20);

        Data_Generator_layout->addLayout(distribution_show_layout);

        Data_Generator_layout->setStretch(0, 32);
        Data_Generator_layout->setStretch(1, 1);
        Data_Generator_layout->setStretch(2, 48);

        Data_layout->addLayout(Data_Generator_layout);

        Data_Loader_space = new QSpacerItem(5, 188, QSizePolicy::Minimum, QSizePolicy::Expanding);

        Data_layout->addItem(Data_Loader_space);

        Data_Loader_layout = new QVBoxLayout();
        Data_Loader_layout->setObjectName("Data_Loader_layout");
        Data_Loader_layout->setSizeConstraint(QLayout::SetDefaultConstraint);
        Data_Loader_layout->setContentsMargins(-1, -1, -1, 0);
        Data_Loader_title = new QLabel(layoutWidget);
        Data_Loader_title->setObjectName("Data_Loader_title");
        Data_Loader_title->setFont(font);
        Data_Loader_title->setAutoFillBackground(false);
        Data_Loader_title->setAlignment(Qt::AlignCenter);

        Data_Loader_layout->addWidget(Data_Loader_title);

        Data_Loader_preview = new QTextBrowser(layoutWidget);
        Data_Loader_preview->setObjectName("Data_Loader_preview");
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Data_Loader_preview->sizePolicy().hasHeightForWidth());
        Data_Loader_preview->setSizePolicy(sizePolicy2);

        Data_Loader_layout->addWidget(Data_Loader_preview);

        Data_Loader_button_layout = new QHBoxLayout();
        Data_Loader_button_layout->setSpacing(8);
        Data_Loader_button_layout->setObjectName("Data_Loader_button_layout");
        Data_Loader_button_layout->setContentsMargins(-1, 4, -1, 4);
        Data_Loader_show = new QTextBrowser(layoutWidget);
        Data_Loader_show->setObjectName("Data_Loader_show");
        QSizePolicy sizePolicy3(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Data_Loader_show->sizePolicy().hasHeightForWidth());
        Data_Loader_show->setSizePolicy(sizePolicy3);
        Data_Loader_show->setFocusPolicy(Qt::NoFocus);
        Data_Loader_show->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Data_Loader_show->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        Data_Loader_button_layout->addWidget(Data_Loader_show);

        Data_Loader_Button = new QPushButton(layoutWidget);
        Data_Loader_Button->setObjectName("Data_Loader_Button");
        QSizePolicy sizePolicy4(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(Data_Loader_Button->sizePolicy().hasHeightForWidth());
        Data_Loader_Button->setSizePolicy(sizePolicy4);

        Data_Loader_button_layout->addWidget(Data_Loader_Button);

        Data_Loader_button_layout->setStretch(0, 12);
        Data_Loader_button_layout->setStretch(1, 4);

        Data_Loader_layout->addLayout(Data_Loader_button_layout);

        Data_Loader_layout->setStretch(0, 2);
        Data_Loader_layout->setStretch(1, 14);
        Data_Loader_layout->setStretch(2, 2);

        Data_layout->addLayout(Data_Loader_layout);

        Data_layout->setStretch(0, 24);
        Data_layout->setStretch(1, 1);
        Data_layout->setStretch(2, 12);
        MainWindow->setCentralWidget(Data_Input_Layout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        data_input_generator_title->setText(QCoreApplication::translate("MainWindow", "Data Generator", nullptr));
        data_input_parameter_show->setMarkdown(QString());
        data_input_parameter_show->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Times New Roman'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        data_input_uniform_button->setText(QCoreApplication::translate("MainWindow", "Uniform", nullptr));
        data_input_gaussian_button->setText(QCoreApplication::translate("MainWindow", "Gaussian", nullptr));
        data_input_poisson_button->setText(QCoreApplication::translate("MainWindow", "Poisson", nullptr));
        data_input_exponential_button->setText(QCoreApplication::translate("MainWindow", "Exponential", nullptr));
        Data_Loader_title->setText(QCoreApplication::translate("MainWindow", "Data Loader", nullptr));
        Data_Loader_preview->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        Data_Loader_show->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        Data_Loader_Button->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
