#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <QObject>
#include <QTimer>
#include <task.h>

class Scheduler : public QObject {
    Q_OBJECT
    QVector<Task*> tasks;
    QTimer* timer;
    Task* currentTask;
    int currentTaskIndex;

public:
    Scheduler(QVector<Task*> tasks);
    void start();
    void addTask(Task* task);
    int tasksCount();
    int getExecTime(int index);
    ~Scheduler();

private slots:
    void schedule();

private:
    bool shouldPreempt();
    void selectNextTask();
    int findTopPriorityTaskIndex();
    bool isTaskWithSamePriority(int priority);
    bool isValidTasksVec();


signals:
    void taskUpdated(int taskIndex, int progress);
};

#endif // SCHEDULER_H
