#ifndef INFOPRINTER_H
#define INFOPRINTER_H

#include <QObject>
#include "file.h"

class InfoPrinter : public QObject {
    Q_OBJECT

public slots:
    void printFileInfo(File* fileData);
    void printFileChanged(File* fileData);
};
#endif // INFOPRINTER_H

