#ifndef TASK_H
#define TASK_H

#include <QString>


enum TaskState { Idle, Running, Paused, Finished };

class Task {
private:
    QString name;
    int priority;
    int remainingTime;
    TaskState state{ Idle };
public:
    Task(QString name, int priority, int execTime);
    void start();
    void pause();
    void finish();
    void runOneQuantum();
    int getPriority();
    int getRemainingTime();
    TaskState getState();
};
#endif // TASK_H
