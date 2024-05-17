#ifndef INFOPRINTER_H
#define INFOPRINTER_H

#include <QObject>
#include "FileTracker.h"

class InfoPrinter : public QObject {
    Q_OBJECT
public:
    InfoPrinter(FileTracker &track);
public slots:
    void printFileInfo(File& fileData);
    void printFileChanged(File& fileData);

    void printFileAdded(File& fileData);
    void printFileRemoved(File& fileData);

    void printFileNotAdded(File& fileData);
    void printFileNotRemoved(File& fileData);
};
#endif // INFOPRINTER_H

