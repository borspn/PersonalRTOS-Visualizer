#include "scheduler.h"
#include <QDebug>


Scheduler::Scheduler(QVector<Task*> tasks) : tasks(tasks), currentTask(nullptr), currentTaskIndex(0) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Scheduler::schedule);
}

bool Scheduler::isValidTasksVec(){
    QSet<int> validationSet;
    for (int i = 0; i < tasks.size(); ++i) {
        if (validationSet.find(tasks[i]->getPriority()) != validationSet.end()){
            return false;
        }
        validationSet.insert(tasks[i]->getPriority());
    }
    return true;
}

void Scheduler::start() {
    if(isValidTasksVec()){
        timer->start(100);
    }
    else{
        qWarning() << "Error: There are tasks with the same priorities";
    }

}

void Scheduler::schedule() {
    if (currentTask && currentTask->getState() == Running) {
        currentTask->runOneQuantum();

        emit taskUpdated(currentTaskIndex, currentTask->getRemainingTime());

        if (currentTask->getState() == Finished) {
            delete tasks[currentTaskIndex];
            //tasks.erase(tasks.cbegin() + currentTaskIndex);
            selectNextTask();
        } else if (shouldPreempt()) {
            currentTask->pause();
            selectNextTask();
        }
    } else {
        selectNextTask();
    }
}

bool Scheduler::shouldPreempt() {
    if (currentTask)
        return (tasks[findTopPriorityTaskIndex()]->getPriority() > currentTask->getPriority());
    else
        return true;
}

void Scheduler::selectNextTask() {
    if (tasks.size()){
    currentTaskIndex = findTopPriorityTaskIndex();
    currentTask = tasks[currentTaskIndex];
    currentTask->start();
    }
}

int Scheduler::findTopPriorityTaskIndex() {
    int indexOfTopPriorTask = 0;
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i]->getPriority() > tasks[indexOfTopPriorTask]->getPriority()) {
            indexOfTopPriorTask = i;
        }
    }
    return indexOfTopPriorTask;
}


void Scheduler::addTask(Task* task) {
    if (!isTaskWithSamePriority(task->getPriority()))
    {
        tasks.push_back(task);
    }
    else{
    qWarning() << "Task with priority" << task->getPriority() << "already exists.";
    }
    }

bool Scheduler::isTaskWithSamePriority(int priority) {
    for (auto i : tasks)
    {
        if (i->getPriority() == priority)
        {
            return true;
        }
    }

    return false;
}

int Scheduler::tasksCount(){
    return tasks.size();
}

int Scheduler::getExecTime(int index){
    if (index < tasks.size()){
        return tasks[index]->getRemainingTime();
    }
    else{
        return 0;
    }
}

Scheduler::~Scheduler() {
    for (Task* task : tasks) {
        delete task;
    }
}
