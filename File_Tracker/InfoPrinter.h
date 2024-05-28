#ifndef INFOPRINTER_H
#define INFOPRINTER_H

#include <QObject>
#include "FileTracker.h"

class InfoPrinter : public QObject {
    Q_OBJECT
public:
    InfoPrinter(FileTracker &tracker) {
        setlocale(LC_ALL, "Russian");
        connect(&tracker, &FileTracker::FileInfo, this, &InfoPrinter::printFileInfo);
        connect(&tracker, &FileTracker::FileUpdated, this, &InfoPrinter::printFileChanged);

        connect(&tracker, &FileTracker::FileAdded, this, &InfoPrinter::printFileAdded);
        connect(&tracker, &FileTracker::FileRemoved, this, &InfoPrinter::printFileRemoved);

        connect(&tracker, &FileTracker::FileNotAdded, this, &InfoPrinter::printFileNotAdded);
        connect(&tracker, &FileTracker::FileNotRemoved, this, &InfoPrinter::printFileNotRemoved);

    }
public slots:
    void printFileInfo(File& fileData);
    void printFileChanged(File& fileData);

    void printFileAdded(File& fileData);
    void printFileRemoved(File& fileData);

    void printFileNotAdded(File& fileData);
    void printFileNotRemoved(File& fileData);
};
#endif // INFOPRINTER_H

