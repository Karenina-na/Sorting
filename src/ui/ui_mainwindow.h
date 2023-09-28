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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
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
#include "functionqwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *MainWindow_Widget;
    QWidget *widget;
    QGridLayout *window_layout;
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
    QLabel *data_loader_title;
    QTextBrowser *data_loader_preview;
    QHBoxLayout *Data_Loader_button_layout;
    QTextBrowser *data_loader_show;
    QPushButton *data_loader_button;
    QGridLayout *sort_button_layout;
    QHBoxLayout *sort_checkbox_layout;
    QCheckBox *data_generator_sort_checkbox;
    QCheckBox *data_loader_sort_checkbox;
    QPushButton *heap_sort_button;
    QPushButton *insert_sort_button;
    QPushButton *quick_sort_button;
    QPushButton *select_sort_button;
    QPushButton *bubble_sort_button;
    QPushButton *radix_sort_button;
    QSpacerItem *verticalSpacer_2;
    QPushButton *merge_sort_button;
    QPushButton *shell_sort_button;
    QGridLayout *result_show_layout;
    QCheckBox *timer_checkbox;
    QLabel *label;
    QCheckBox *comparer_mover_checkbox;
    QComboBox *result_sort_select;
    QTextBrowser *result_show;
    QPushButton *result_sort_select_open_button;
    QFrame *line_2;
    QGridLayout *sort_button_show_layout;
    QPushButton *algorithm_button;
    QCheckBox *mutil_thread_checkbox;
    QPushButton *sort_generate_data_button;
    QPushButton *sort_launch_button;
    QTextBrowser *algorithm_message_show;
    QCheckBox *less_checkbox;
    QCheckBox *data_build_checkbox;
    QCheckBox *greater_checkbox;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(820, 520);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(820, 520));
        MainWindow->setMaximumSize(QSize(820, 520));
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
        MainWindow_Widget = new QWidget(MainWindow);
        MainWindow_Widget->setObjectName("MainWindow_Widget");
        MainWindow_Widget->setEnabled(true);
        sizePolicy.setHeightForWidth(MainWindow_Widget->sizePolicy().hasHeightForWidth());
        MainWindow_Widget->setSizePolicy(sizePolicy);
        MainWindow_Widget->setMinimumSize(QSize(820, 520));
        MainWindow_Widget->setMaximumSize(QSize(820, 520));
        widget = new QWidget(MainWindow_Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 10, 781, 491));
        window_layout = new QGridLayout(widget);
        window_layout->setObjectName("window_layout");
        window_layout->setVerticalSpacing(12);
        window_layout->setContentsMargins(0, 0, 0, 0);
        Data_layout = new QHBoxLayout();
        Data_layout->setSpacing(0);
        Data_layout->setObjectName("Data_layout");
        Data_Generator_layout = new QHBoxLayout();
        Data_Generator_layout->setSpacing(6);
        Data_Generator_layout->setObjectName("Data_Generator_layout");
        data_generator_left_layout = new QVBoxLayout();
        data_generator_left_layout->setObjectName("data_generator_left_layout");
        data_input_generator_title = new QLabel(widget);
        data_input_generator_title->setObjectName("data_input_generator_title");
        QFont font;
        font.setPointSize(12);
        data_input_generator_title->setFont(font);
        data_input_generator_title->setAutoFillBackground(false);
        data_input_generator_title->setAlignment(Qt::AlignCenter);

        data_generator_left_layout->addWidget(data_input_generator_title);

        data_input_parameter_show = new QTextBrowser(widget);
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
        data_input_uniform_button = new QPushButton(widget);
        data_input_uniform_button->setObjectName("data_input_uniform_button");

        distribution_choose_layout->addWidget(data_input_uniform_button, 0, 0, 1, 1);

        data_input_gaussian_button = new QPushButton(widget);
        data_input_gaussian_button->setObjectName("data_input_gaussian_button");

        distribution_choose_layout->addWidget(data_input_gaussian_button, 0, 1, 1, 1);

        data_input_poisson_button = new QPushButton(widget);
        data_input_poisson_button->setObjectName("data_input_poisson_button");

        distribution_choose_layout->addWidget(data_input_poisson_button, 1, 0, 1, 1);

        data_input_exponential_button = new QPushButton(widget);
        data_input_exponential_button->setObjectName("data_input_exponential_button");

        distribution_choose_layout->addWidget(data_input_exponential_button, 1, 1, 1, 1);


        data_generator_left_layout->addLayout(distribution_choose_layout);


        Data_Generator_layout->addLayout(data_generator_left_layout);

        Data_Generator_space = new QSpacerItem(5, 198, QSizePolicy::Minimum, QSizePolicy::Expanding);

        Data_Generator_layout->addItem(Data_Generator_space);

        distribution_show_layout = new QGridLayout();
        distribution_show_layout->setObjectName("distribution_show_layout");
        data_input_distribution_preview = new FunctionQWidget(widget);
        data_input_distribution_preview->setObjectName("data_input_distribution_preview");

        distribution_show_layout->addWidget(data_input_distribution_preview, 0, 0, 1, 1);

        data_input_distribution_vertical_slider = new QSlider(widget);
        data_input_distribution_vertical_slider->setObjectName("data_input_distribution_vertical_slider");
        data_input_distribution_vertical_slider->setMinimum(15);
        data_input_distribution_vertical_slider->setMaximum(99);
        data_input_distribution_vertical_slider->setValue(25);
        data_input_distribution_vertical_slider->setSliderPosition(25);
        data_input_distribution_vertical_slider->setOrientation(Qt::Vertical);

        distribution_show_layout->addWidget(data_input_distribution_vertical_slider, 0, 1, 2, 1);

        data_input_distribution_horizontal_slider = new QSlider(widget);
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
        data_loader_title = new QLabel(widget);
        data_loader_title->setObjectName("data_loader_title");
        data_loader_title->setFont(font);
        data_loader_title->setAutoFillBackground(false);
        data_loader_title->setAlignment(Qt::AlignCenter);

        Data_Loader_layout->addWidget(data_loader_title);

        data_loader_preview = new QTextBrowser(widget);
        data_loader_preview->setObjectName("data_loader_preview");
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(data_loader_preview->sizePolicy().hasHeightForWidth());
        data_loader_preview->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font2.setPointSize(10);
        data_loader_preview->setFont(font2);

        Data_Loader_layout->addWidget(data_loader_preview);

        Data_Loader_button_layout = new QHBoxLayout();
        Data_Loader_button_layout->setSpacing(8);
        Data_Loader_button_layout->setObjectName("Data_Loader_button_layout");
        Data_Loader_button_layout->setContentsMargins(-1, 4, -1, 4);
        data_loader_show = new QTextBrowser(widget);
        data_loader_show->setObjectName("data_loader_show");
        QSizePolicy sizePolicy3(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(data_loader_show->sizePolicy().hasHeightForWidth());
        data_loader_show->setSizePolicy(sizePolicy3);
        data_loader_show->setFocusPolicy(Qt::NoFocus);
        data_loader_show->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        data_loader_show->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        data_loader_show->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        data_loader_show->setLineWrapMode(QTextEdit::NoWrap);

        Data_Loader_button_layout->addWidget(data_loader_show);

        data_loader_button = new QPushButton(widget);
        data_loader_button->setObjectName("data_loader_button");
        QSizePolicy sizePolicy4(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(data_loader_button->sizePolicy().hasHeightForWidth());
        data_loader_button->setSizePolicy(sizePolicy4);

        Data_Loader_button_layout->addWidget(data_loader_button);

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

        window_layout->addLayout(Data_layout, 0, 0, 1, 4);

        sort_button_layout = new QGridLayout();
        sort_button_layout->setObjectName("sort_button_layout");
        sort_button_layout->setHorizontalSpacing(12);
        sort_button_layout->setVerticalSpacing(8);
        sort_checkbox_layout = new QHBoxLayout();
        sort_checkbox_layout->setObjectName("sort_checkbox_layout");
        sort_checkbox_layout->setContentsMargins(0, -1, -1, -1);
        data_generator_sort_checkbox = new QCheckBox(widget);
        data_generator_sort_checkbox->setObjectName("data_generator_sort_checkbox");
        QFont font3;
        font3.setPointSize(10);
        data_generator_sort_checkbox->setFont(font3);
        data_generator_sort_checkbox->setCursor(QCursor(Qt::PointingHandCursor));
        data_generator_sort_checkbox->setChecked(true);

        sort_checkbox_layout->addWidget(data_generator_sort_checkbox);

        data_loader_sort_checkbox = new QCheckBox(widget);
        data_loader_sort_checkbox->setObjectName("data_loader_sort_checkbox");
        data_loader_sort_checkbox->setFont(font3);
        data_loader_sort_checkbox->setCursor(QCursor(Qt::PointingHandCursor));
        data_loader_sort_checkbox->setLayoutDirection(Qt::LeftToRight);

        sort_checkbox_layout->addWidget(data_loader_sort_checkbox);


        sort_button_layout->addLayout(sort_checkbox_layout, 0, 0, 1, 3);

        heap_sort_button = new QPushButton(widget);
        heap_sort_button->setObjectName("heap_sort_button");
        sizePolicy.setHeightForWidth(heap_sort_button->sizePolicy().hasHeightForWidth());
        heap_sort_button->setSizePolicy(sizePolicy);
        heap_sort_button->setFont(font3);

        sort_button_layout->addWidget(heap_sort_button, 2, 1, 1, 1);

        insert_sort_button = new QPushButton(widget);
        insert_sort_button->setObjectName("insert_sort_button");
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(insert_sort_button->sizePolicy().hasHeightForWidth());
        insert_sort_button->setSizePolicy(sizePolicy5);
        insert_sort_button->setFont(font3);

        sort_button_layout->addWidget(insert_sort_button, 1, 0, 1, 1);

        quick_sort_button = new QPushButton(widget);
        quick_sort_button->setObjectName("quick_sort_button");
        sizePolicy.setHeightForWidth(quick_sort_button->sizePolicy().hasHeightForWidth());
        quick_sort_button->setSizePolicy(sizePolicy);
        quick_sort_button->setFont(font3);

        sort_button_layout->addWidget(quick_sort_button, 1, 1, 1, 1);

        select_sort_button = new QPushButton(widget);
        select_sort_button->setObjectName("select_sort_button");
        sizePolicy.setHeightForWidth(select_sort_button->sizePolicy().hasHeightForWidth());
        select_sort_button->setSizePolicy(sizePolicy);
        select_sort_button->setFont(font3);

        sort_button_layout->addWidget(select_sort_button, 3, 0, 1, 1);

        bubble_sort_button = new QPushButton(widget);
        bubble_sort_button->setObjectName("bubble_sort_button");
        sizePolicy.setHeightForWidth(bubble_sort_button->sizePolicy().hasHeightForWidth());
        bubble_sort_button->setSizePolicy(sizePolicy);
        bubble_sort_button->setFont(font3);

        sort_button_layout->addWidget(bubble_sort_button, 2, 0, 1, 1);

        radix_sort_button = new QPushButton(widget);
        radix_sort_button->setObjectName("radix_sort_button");
        sizePolicy.setHeightForWidth(radix_sort_button->sizePolicy().hasHeightForWidth());
        radix_sort_button->setSizePolicy(sizePolicy);
        radix_sort_button->setFont(font3);

        sort_button_layout->addWidget(radix_sort_button, 3, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 158, QSizePolicy::Minimum, QSizePolicy::Expanding);

        sort_button_layout->addItem(verticalSpacer_2, 1, 2, 4, 1);

        merge_sort_button = new QPushButton(widget);
        merge_sort_button->setObjectName("merge_sort_button");
        sizePolicy.setHeightForWidth(merge_sort_button->sizePolicy().hasHeightForWidth());
        merge_sort_button->setSizePolicy(sizePolicy);
        merge_sort_button->setFont(font3);

        sort_button_layout->addWidget(merge_sort_button, 4, 1, 1, 1);

        shell_sort_button = new QPushButton(widget);
        shell_sort_button->setObjectName("shell_sort_button");
        sizePolicy.setHeightForWidth(shell_sort_button->sizePolicy().hasHeightForWidth());
        shell_sort_button->setSizePolicy(sizePolicy);
        shell_sort_button->setFont(font3);

        sort_button_layout->addWidget(shell_sort_button, 4, 0, 1, 1);

        sort_button_layout->setRowStretch(0, 1);
        sort_button_layout->setRowStretch(1, 2);
        sort_button_layout->setRowStretch(2, 2);
        sort_button_layout->setRowStretch(3, 2);
        sort_button_layout->setRowStretch(4, 2);
        sort_button_layout->setColumnStretch(0, 10);
        sort_button_layout->setColumnStretch(1, 10);
        sort_button_layout->setColumnStretch(2, 1);

        window_layout->addLayout(sort_button_layout, 1, 1, 1, 1);

        result_show_layout = new QGridLayout();
        result_show_layout->setObjectName("result_show_layout");
        result_show_layout->setContentsMargins(6, 6, -1, -1);
        timer_checkbox = new QCheckBox(widget);
        timer_checkbox->setObjectName("timer_checkbox");
        sizePolicy.setHeightForWidth(timer_checkbox->sizePolicy().hasHeightForWidth());
        timer_checkbox->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setPointSize(11);
        timer_checkbox->setFont(font4);
        timer_checkbox->setCursor(QCursor(Qt::PointingHandCursor));

        result_show_layout->addWidget(timer_checkbox, 0, 1, 1, 1);

        label = new QLabel(widget);
        label->setObjectName("label");
        label->setFont(font3);
        label->setAlignment(Qt::AlignCenter);

        result_show_layout->addWidget(label, 2, 0, 1, 2);

        comparer_mover_checkbox = new QCheckBox(widget);
        comparer_mover_checkbox->setObjectName("comparer_mover_checkbox");
        sizePolicy.setHeightForWidth(comparer_mover_checkbox->sizePolicy().hasHeightForWidth());
        comparer_mover_checkbox->setSizePolicy(sizePolicy);
        comparer_mover_checkbox->setFont(font4);
        comparer_mover_checkbox->setCursor(QCursor(Qt::PointingHandCursor));

        result_show_layout->addWidget(comparer_mover_checkbox, 0, 0, 1, 1);

        result_sort_select = new QComboBox(widget);
        result_sort_select->setObjectName("result_sort_select");

        result_show_layout->addWidget(result_sort_select, 3, 0, 1, 1);

        result_show = new QTextBrowser(widget);
        result_show->setObjectName("result_show");
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(result_show->sizePolicy().hasHeightForWidth());
        result_show->setSizePolicy(sizePolicy6);
        result_show->setLineWrapMode(QTextEdit::NoWrap);

        result_show_layout->addWidget(result_show, 4, 0, 1, 2);

        result_sort_select_open_button = new QPushButton(widget);
        result_sort_select_open_button->setObjectName("result_sort_select_open_button");

        result_show_layout->addWidget(result_sort_select_open_button, 3, 1, 1, 1);

        line_2 = new QFrame(widget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        result_show_layout->addWidget(line_2, 1, 0, 1, 2);

        result_show_layout->setRowStretch(0, 2);
        result_show_layout->setRowStretch(1, 1);
        result_show_layout->setRowStretch(2, 2);
        result_show_layout->setRowStretch(3, 2);
        result_show_layout->setRowStretch(4, 10);

        window_layout->addLayout(result_show_layout, 1, 3, 1, 1);

        sort_button_show_layout = new QGridLayout();
        sort_button_show_layout->setSpacing(8);
        sort_button_show_layout->setObjectName("sort_button_show_layout");
        algorithm_button = new QPushButton(widget);
        algorithm_button->setObjectName("algorithm_button");
        sizePolicy.setHeightForWidth(algorithm_button->sizePolicy().hasHeightForWidth());
        algorithm_button->setSizePolicy(sizePolicy);
        algorithm_button->setFont(font3);

        sort_button_show_layout->addWidget(algorithm_button, 0, 0, 1, 1);

        mutil_thread_checkbox = new QCheckBox(widget);
        mutil_thread_checkbox->setObjectName("mutil_thread_checkbox");
        sizePolicy.setHeightForWidth(mutil_thread_checkbox->sizePolicy().hasHeightForWidth());
        mutil_thread_checkbox->setSizePolicy(sizePolicy);
        mutil_thread_checkbox->setFont(font4);
        mutil_thread_checkbox->setCursor(QCursor(Qt::PointingHandCursor));

        sort_button_show_layout->addWidget(mutil_thread_checkbox, 0, 1, 1, 2);

        sort_generate_data_button = new QPushButton(widget);
        sort_generate_data_button->setObjectName("sort_generate_data_button");
        sizePolicy.setHeightForWidth(sort_generate_data_button->sizePolicy().hasHeightForWidth());
        sort_generate_data_button->setSizePolicy(sizePolicy);
        sort_generate_data_button->setFont(font);

        sort_button_show_layout->addWidget(sort_generate_data_button, 1, 0, 1, 2);

        sort_launch_button = new QPushButton(widget);
        sort_launch_button->setObjectName("sort_launch_button");
        sizePolicy.setHeightForWidth(sort_launch_button->sizePolicy().hasHeightForWidth());
        sort_launch_button->setSizePolicy(sizePolicy);
        sort_launch_button->setFont(font4);

        sort_button_show_layout->addWidget(sort_launch_button, 2, 0, 1, 1);

        algorithm_message_show = new QTextBrowser(widget);
        algorithm_message_show->setObjectName("algorithm_message_show");
        algorithm_message_show->setTabChangesFocus(false);
        algorithm_message_show->setUndoRedoEnabled(false);
        algorithm_message_show->setLineWrapMode(QTextEdit::NoWrap);
        algorithm_message_show->setLineWrapColumnOrWidth(0);

        sort_button_show_layout->addWidget(algorithm_message_show, 3, 0, 1, 3);

        less_checkbox = new QCheckBox(widget);
        less_checkbox->setObjectName("less_checkbox");
        sizePolicy.setHeightForWidth(less_checkbox->sizePolicy().hasHeightForWidth());
        less_checkbox->setSizePolicy(sizePolicy);
        less_checkbox->setFont(font4);
        less_checkbox->setCursor(QCursor(Qt::PointingHandCursor));

        sort_button_show_layout->addWidget(less_checkbox, 2, 2, 1, 1);

        data_build_checkbox = new QCheckBox(widget);
        data_build_checkbox->setObjectName("data_build_checkbox");
        sizePolicy.setHeightForWidth(data_build_checkbox->sizePolicy().hasHeightForWidth());
        data_build_checkbox->setSizePolicy(sizePolicy);
        data_build_checkbox->setFont(font4);
        data_build_checkbox->setCursor(QCursor(Qt::PointingHandCursor));
        data_build_checkbox->setChecked(true);

        sort_button_show_layout->addWidget(data_build_checkbox, 1, 2, 1, 1);

        greater_checkbox = new QCheckBox(widget);
        greater_checkbox->setObjectName("greater_checkbox");
        sizePolicy.setHeightForWidth(greater_checkbox->sizePolicy().hasHeightForWidth());
        greater_checkbox->setSizePolicy(sizePolicy);
        greater_checkbox->setFont(font4);
        greater_checkbox->setCursor(QCursor(Qt::PointingHandCursor));
        greater_checkbox->setChecked(true);

        sort_button_show_layout->addWidget(greater_checkbox, 2, 1, 1, 1);

        sort_button_show_layout->setRowStretch(0, 3);
        sort_button_show_layout->setRowStretch(1, 3);
        sort_button_show_layout->setRowStretch(2, 3);
        sort_button_show_layout->setRowStretch(3, 5);
        sort_button_show_layout->setColumnStretch(0, 3);
        sort_button_show_layout->setColumnStretch(1, 2);
        sort_button_show_layout->setColumnStretch(2, 1);

        window_layout->addLayout(sort_button_show_layout, 1, 2, 1, 1);

        window_layout->setRowStretch(0, 1);
        window_layout->setRowStretch(1, 1);
        MainWindow->setCentralWidget(MainWindow_Widget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        data_input_generator_title->setText(QCoreApplication::translate("MainWindow", "Distribution", nullptr));
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
        data_loader_title->setText(QCoreApplication::translate("MainWindow", "Data Loader", nullptr));
        data_loader_preview->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        data_loader_show->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        data_loader_button->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        data_generator_sort_checkbox->setText(QCoreApplication::translate("MainWindow", "For Generator", nullptr));
        data_loader_sort_checkbox->setText(QCoreApplication::translate("MainWindow", "For Loader", nullptr));
        heap_sort_button->setText(QCoreApplication::translate("MainWindow", "Heap Sort", nullptr));
        insert_sort_button->setText(QCoreApplication::translate("MainWindow", "Insert Sort", nullptr));
        quick_sort_button->setText(QCoreApplication::translate("MainWindow", "Quick Sort", nullptr));
        select_sort_button->setText(QCoreApplication::translate("MainWindow", "Select Sort", nullptr));
        bubble_sort_button->setText(QCoreApplication::translate("MainWindow", "Bubble Sort", nullptr));
        radix_sort_button->setText(QCoreApplication::translate("MainWindow", "Radix Sort", nullptr));
        merge_sort_button->setText(QCoreApplication::translate("MainWindow", "Merge Sort", nullptr));
        shell_sort_button->setText(QCoreApplication::translate("MainWindow", "Shell Sort", nullptr));
        timer_checkbox->setText(QCoreApplication::translate("MainWindow", "Timer", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "OPEN RESULT REPORT", nullptr));
        comparer_mover_checkbox->setText(QCoreApplication::translate("MainWindow", "Comparer and Mover", nullptr));
        result_sort_select_open_button->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        algorithm_button->setText(QCoreApplication::translate("MainWindow", "Algorithm", nullptr));
        mutil_thread_checkbox->setText(QCoreApplication::translate("MainWindow", "Multithreading", nullptr));
        sort_generate_data_button->setText(QCoreApplication::translate("MainWindow", "Generate Data", nullptr));
        sort_launch_button->setText(QCoreApplication::translate("MainWindow", "Launch", nullptr));
        algorithm_message_show->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        less_checkbox->setText(QCoreApplication::translate("MainWindow", "Less", nullptr));
        data_build_checkbox->setText(QCoreApplication::translate("MainWindow", "Build", nullptr));
        greater_checkbox->setText(QCoreApplication::translate("MainWindow", "Greater", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
