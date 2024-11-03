#include "task.h"

Task::Task(QString name, int priority, int remainingTime) :
    name(name), priority(priority),  remainingTime(remainingTime) {
}


void Task::start() {
    state = Running;
}

void Task::pause() {
    state = Paused;
}

void Task::finish() {
    state = Finished;
}

int Task::getPriority() {
    return priority;
}

TaskState Task::getState() {
    return state;
}

int Task::getRemainingTime(){
    return remainingTime;
}

void Task::runOneQuantum() {
    if (state == Running && remainingTime > 0) {
        remainingTime--;
        if (remainingTime == 0) finish();
    }
}

