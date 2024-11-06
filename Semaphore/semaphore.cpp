#include "semaphore.h"

Semaphore::Semaphore(QObject *parent, int maxEquires)
    : QObject{parent}, maxEquires{maxEquires}{}

bool Semaphore::equire(){
    if (equireCnt < maxEquires){
        equireCnt++;
        return true;
    }else{
        return false;
    }
}

void Semaphore::release(){
    if (equireCnt){
        equireCnt--;
    }
}
