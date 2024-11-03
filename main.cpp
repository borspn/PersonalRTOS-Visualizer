#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QVector<Task*> tasks = {
        new Task("Task 1", 3, 130),
        new Task("Task 2", 1, 50),
        new Task("Task 3", 2, 10)
    };

    MainWindow w(nullptr, tasks);
    w.show();

    return a.exec();
}
