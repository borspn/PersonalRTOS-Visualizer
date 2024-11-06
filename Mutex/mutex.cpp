#include "mutex.h"
#include <QDebug>

Mutex::Mutex(QObject *parent)
    : QObject{parent}
{}

bool Mutex::lock(Task* possessor){
    if(!isLocked){
        possessor = possessor;
        isLocked = true;
        return true;
    }
    return false;
}

void Mutex::unlock(Task* possessor){
    if(isLocked){
        if (possessor == possessor){
            possessor = nullptr;
            isLocked = false;
        }else{
            qWarning() << "Attempt to unlock from a task in which I do not possess the mutex";
        }
    }
}
