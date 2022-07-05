#include "CPUMonitor.h"

CPUMonitor::CPUMonitor(QObject *parent) : QObject(parent)
{

}

QString CPUMonitor::GetCPUTemp()
{
    QProcess p;
    QString command = "vcgencmd measure_temp";
    p.start(command);
    p.waitForFinished();
    QString result = p.readAll();
    QString Temp = "0";

//    for(int i =0;i<4;i++){
//        QString temp = result.split("Core "+QString::number(i)+":")[1].trimmed().split("+")[1].split(".")[0];
//        if (temp.toUInt() > maxTemp.toUInt()) {maxTemp= temp;}
//    }
    Temp = result.split("=")[1].split("'C")[0].trimmed();
    return Temp;
}

QString CPUMonitor::GetCPUFreq()
{    QProcess p;
    QString command = "cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq";
    p.start(command);
    p.waitForFinished();
    QString freq = p.readAll();
    int freqNum = freq.toInt() / 1000;
    freq = QString::number(freqNum);
    return  freq;
}
