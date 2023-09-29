#include "ui/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Sorting");
    w.setWindowIcon(QIcon(":/res/logo.png"));
    w.show();
    return QApplication::exec();
}
