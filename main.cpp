#include "mainwindow.h"
#include <QApplication>
#include <QFileInfo>
#include <QMessageBox>
#include <QtDebug>

#include <stdio.h>

#include "generator.h"
#include "Database/database.h"
#include "Database/dbConnection.h"

//#define CLEAR_DB

#if __APPLE__
#include <unistd.h>
#elif defined(WIN32)
#endif

void setSeed()
{
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);
}

bool fileExists(QString file)
{
    QDir databaseDir = getlogDir();
    QString database = databaseDir.filePath(file);
    QFileInfo check_file(database);
    return check_file.exists() && check_file.isFile();
}

void displayError()
{
    QMessageBox errorMsg;
    errorMsg.setText("A fatal error has occured. Please report this bug at:\nEasyNPC@protonmail.com");
    errorMsg.exec();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    createLogDir();
    setSeed();
    if(!createConnection())
    {
        //error
        qDebug() << "Error has occured in main";
        displayError();
        return 0;
    }

    ClassSaver classSaver = ClassSaver();
    RaceSaver raceSaver = RaceSaver();
    NpcSaver genSaver = NpcSaver();

#ifdef CLEAR_DB
    classSaver.removeAllAttributes();
    raceSaver.removeAllAttributes();
    genSaver.removeAllAttributes();
#endif

    classSaver.readAttributes();
    raceSaver.readAttributes();
    if(availableRaces.empty())
    {
        generateBaseRaces();
        qDebug() << "Generating base races";
    }
    if(availableClasses.empty())
    {
        generateBaseClasses();
        qDebug() << "Generating base classes";
    }
    genSaver.readAttributes();

    createMap();

    QTextStream debug(stdout);

    MainWindow mainWindow;
    mainWindow.show();

    // On exit, have everything saved
    QObject::connect(&a, SIGNAL(aboutToQuit()), &mainWindow, SLOT(onQuit()));
    return a.exec();
}
