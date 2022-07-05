#ifndef CPULOGGER_H
#define CPULOGGER_H
#include <QTimer>
#include <QTime>
#include <QFile>
#include <QProcess>
#include <QTextStream>
#include "CPUMonitor.h"

class CPULogger: public QObject
{
    Q_OBJECT
    QFile file;
    QTextStream stream;
public:
    CPULogger();
    QTimer *timer;
public slots:
    void CPULoggerSlot();
};

#endif // CPULOGGER_H
