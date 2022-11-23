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
    timer->start(30000);
}

void CPULogger::CPULoggerSlot()
{
    QString time = QTime::currentTime().toString();
    stream << CPULogger::GetCPUFreq()<< endl;
    stream.flush();
 }

QString CPULogger::GetCPUFreq()
{   QProcess p;
    QString command = "sensors";
    p.start(command);
    p.waitForFinished();
    QString temp = p.readAll();
    QString result;
    for(int i=5;i<16;i+=3)
    {
      result.append(temp.split("+")[i].split(".")[0]+",");
    }
    return  result;
}
