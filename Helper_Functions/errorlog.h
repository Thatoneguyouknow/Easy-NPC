#ifndef ERRORLOG_H
#define ERRORLOG_H

#include <QFile>
#include <QString>
#include <QSysInfo>
#include <QDateTime>
#include <QTextStream>
#include <QDir>
#include <QFileInfoList>
#include <QStandardPaths>

#include <unistd.h>

#define MSHELLSCRIPT "\
#/bin/bash \n\
cp data.db ~/Library/Application\\ Support/EasyNPC"

const QString logfileName = "errors.log";
const QString dbFileName = "data.db";

void logError(int Code, QString toLog);
bool checkLogDir();
void createLogDir();
void copydataFile();
QDir getlogDir();

static const int paintErr = 1102;


#endif // ERRORLOG_H
