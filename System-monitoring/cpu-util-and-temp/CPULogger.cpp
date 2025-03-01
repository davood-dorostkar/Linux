#include "CPULogger.h"

CPULogger::CPULogger()
{
    QString filename = "TempTestLog.txt";
    file.setFileName(filename);
    if (file.open(QIODevice::Append))
    {
      stream.setDevice(&file);
    }
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(CPULoggerSlot()));
    timer->start(10000);
}

void CPULogger::CPULoggerSlot()
{
    QString time = QTime::currentTime().toString();
    stream << time << "," << CPUMonitor::GetCPUTemp()<< "," <<  CPUMonitor::GetCPUFreq()<< endl;
    stream.flush();
 }
