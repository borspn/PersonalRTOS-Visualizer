#pragma once

#include <QMainWindow>
#include <QProgressBar>
#include <QVBoxLayout>
#include "scheduler.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, QVector<Task*> tasks = {});
    ~MainWindow();

private slots:
    void setupTasks();
    void updateTaskProgress(int taskIndex, int progress);

private:
    Scheduler *scheduler;
    QVBoxLayout *layout;
};
