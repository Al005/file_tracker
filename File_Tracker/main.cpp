#include <QCoreApplication>
#include "FileTracker.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QStringList filePaths;
    filePaths << "D:/Projects/TRPO_labs/lab2/file_tracker/File_Tracker/testFiles/file1.txt" \
              << "D:/Projects/TRPO_labs/lab2/file_tracker/File_Tracker/testFiles/file2.docx" \
              << "D:/Projects/TRPO_labs/lab2/file_tracker/File_Tracker/testFiles/file3.png";
    FileTracker &fileWatcher = FileTracker::getInstance(filePaths);
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &fileWatcher, &FileTracker::checkFiles);
    timer.start(1000);

    return a.exec();
}
