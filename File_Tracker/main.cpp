#include <QCoreApplication>
#include "FileTracker.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QStringList filePaths;
    filePaths << "/testFiles/file1";// << "/testFiles/file2" << "/testFiles/file3";
    FileTracker fileWatcher(filePaths);

    return a.exec();
}
