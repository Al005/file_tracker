#include "InfoPrinter.h"
#include <QDebug>

void InfoPrinter::printFileInfo(File* fileData) {
    qDebug() << "Файл: " << fileData->getFilePath();
                                if (fileData->getFileExists()) {
        qDebug() << "Файл существует.";
        qDebug() << "Размер файла: " << fileData->getFileSize() << " байт";
    }
    else {
        qDebug() << "Файл не существует.";
    }
}
