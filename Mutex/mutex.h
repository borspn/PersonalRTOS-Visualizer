#ifndef MUTEX_H
#define MUTEX_H

#include <QObject>
#include "task/task.h"

class Mutex : public QObject
{
    bool isLocked{false};
    Task* possessor;

    Q_OBJECT
public:
    explicit Mutex(QObject *parent = nullptr);
    bool lock(Task* possessor);
    void unlock(Task* possessor);

signals:
};

#endif // MUTEX_H
