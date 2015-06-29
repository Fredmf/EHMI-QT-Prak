#ifndef gpioListener_h
#define gpioListener_h

#include <QThread>
#include <wiringPi.h>
class gpioListener : public QThread {
    Q_OBJECT
protected:
 void run();
public:
 void buttonLoop();
signals:
void b0sig();
void b1sig();
void b2sig();
void b3sig();
};
#endif