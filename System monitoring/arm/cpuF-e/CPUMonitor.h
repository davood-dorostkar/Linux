#ifndef CPUMONITOR_H
#define CPUMONITOR_H

#include <QObject>
#include <QProcess>

class CPUMonitor : public QObject
{
    Q_OBJECT

public:
    explicit CPUMonitor(QObject *parent = nullptr);
    static  QString GetCPUTemp();
    static QString GetCPUFreq();

};

#endif // CPUMONITOR_H
