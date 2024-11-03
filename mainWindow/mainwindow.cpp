#include "mainwindow.h"
#include <QTimer>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent, QVector<Task*> tasks)
    : QMainWindow(parent), scheduler(new Scheduler(tasks)) {

    QWidget *centralWidget = new QWidget(this);
    layout = new QVBoxLayout(centralWidget);

    setupTasks();

    setCentralWidget(centralWidget);

    connect(scheduler, &Scheduler::taskUpdated, this, &MainWindow::updateTaskProgress);

    scheduler->start();
}

void MainWindow::setupTasks() {
    for (int i = 0; i < scheduler->tasksCount(); ++i) {

        QHBoxLayout *taskLayout = new QHBoxLayout();

        QLabel *taskLabel = new QLabel(QString("Task %1:").arg(i + 1), this);
        taskLayout->addWidget(taskLabel);

        QProgressBar *progressBar = new QProgressBar(this);
        progressBar->setRange(0, scheduler->getExecTime(i)); // Встановіть діапазон
        taskLayout->addWidget(progressBar);

        layout->addLayout(taskLayout);
    }
}

void MainWindow::updateTaskProgress(int taskIndex, int progress) {
    if (taskIndex < 0 || taskIndex >= layout->count()) {
        qWarning() << "Неприпустимий індекс задачі:" << taskIndex;
        return;
    }

    QHBoxLayout *taskLayout = qobject_cast<QHBoxLayout*>(layout->itemAt(taskIndex)->layout());
    if (taskLayout) {
        QProgressBar *progressBar = qobject_cast<QProgressBar*>(taskLayout->itemAt(1)->widget());
        if (progressBar) {
            progressBar->setValue(progress);
        }
    }
}

MainWindow::~MainWindow() {
    delete scheduler;
}
