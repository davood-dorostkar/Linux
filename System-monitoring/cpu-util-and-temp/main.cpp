#include <QCoreApplication>
#include <QProcess>
#include <QDebug>
#include <QFile>
#include <QTime>
#include <QTimer>
#include "CPULogger.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CPULogger Logger;
//    MyTimer timer;
//    QTimer *timer1 = new QTimer();
//        timer1->setTimerType(Qt::PreciseTimer); // [ms] accuracy
//        timer1->setInterval(30000);
//        connect(timer1, SIGNAL(timeout(void)), this, SLOT(SaveData(&file,&p)));
//        timer1->start(30000);



//    qDebug()<<GetCPUTemp(&p);
//    qDebug()<<GetCPUFreq(&p);
//    file.close();
    return a.exec();
}

