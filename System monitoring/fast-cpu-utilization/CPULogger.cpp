#include "CPULogger.h"

CPULogger::CPULogger()
{
    QString filename = "cpu.txt";
    file.setFileName(filename);
    if (file.open(QIODevice::Append))
    {
      stream.setDevice(&file);
    }
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(CPULoggerSlot()));
    timer->start(10);
}

void CPULogger::CPULoggerSlot()
{
    QString time = QTime::currentTime().toString();
    stream << CPULogger::GetCPUFreq()<< endl;
    stream.flush();
 }

QString CPULogger::GetCPUFreq()
{   QProcess p;
//    QString command = "lscpu";
    QString command = "cat /proc/cpuinfo";
    p.start(command);
    p.waitForFinished();
    QString freq = p.readAll();
    QString result;
    for(int i=0;i<8;i++)
    {
      result.append(freq.split("cpu MHz\t\t: ")[i+1].split(".")[0]+",");
    }
//    qDebug()<<result;
    return  result;
}
