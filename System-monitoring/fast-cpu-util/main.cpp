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
    return a.exec();
    return  0;
}

