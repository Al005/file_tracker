#include "InfoPrinter.h"
#include <QDebug>

void InfoPrinter::printFileInfo(File* fileData) {
    setlocale(LC_ALL, "Russian");
    qDebug() << "Файл: " << fileData->getFilePath();
    if (fileData->getFileExists()) {
        qDebug() << "Файл существует.";
        qDebug() << "Размер файла: " << fileData->getFileSize() << " байт" << Qt::endl;
    }
    else {
        qDebug() << "Файл не существует." << Qt::endl;
    }
}

void InfoPrinter::printFileChanged(File* fileData){
    qDebug() << "Файл: " << fileData->getFilePath() << " изменился";
    if (fileData->getFileExists()) {
        qDebug() << "Файл существует.";
        qDebug() << "Размер файла: " << fileData->getFileSize() << " байт" << Qt::endl;
    }
    else {
        qDebug() << "Файл не существует." << Qt::endl;
    }
}
