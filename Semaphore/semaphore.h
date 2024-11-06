#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <QObject>

class Semaphore : public QObject
{
    Q_OBJECT
private:
    int equireCnt{0};
    int maxEquires{1};

public:
    explicit Semaphore(QObject *parent = nullptr, int maxEquires = 1);
    bool equire();
    void release();

signals:
};

#endif // SEMAPHORE_H
