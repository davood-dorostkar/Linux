#include "CPUMonitor.h"

CPUMonitor::CPUMonitor(QObject *parent) : QObject(parent)
{

}

QString CPUMonitor::GetCPUTemp()
{
    QProcess p;
    QString command = "sensors";
    p.start(command);
    p.waitForFinished();
    QString result = p.readAll();
    QString maxTemp = "0";

    for(int i =0;i<4;i++){
        QString temp = result.split("Core "+QString::number(i)+":")[1].trimmed().split("+")[1].split(".")[0];
        if (temp.toUInt() > maxTemp.toUInt()) {maxTemp= temp;}
    }

    return maxTemp;
}

QString CPUMonitor::GetCPUFreq()
{    QProcess p;
    QString command = "lscpu";
    p.start(command);
    p.waitForFinished();
    QString freq = p.readAll();
    freq = freq.split("CPU MHz:")[1].trimmed().split(".")[0];
    return  freq;
}
