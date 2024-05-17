#include "InfoPrinter.h"
#include <QDebug>

void InfoPrinter::printFileInfo(File& fileData) {
    setlocale(LC_ALL, "Russian");
    qDebug() << "Файл: " << fileData.getFilePath();
    if (fileData.getFileExists()) {
        qDebug() << "Файл существует.";
        qDebug() << "Размер файла: " << fileData.getFileSize() << " байт" << Qt::endl;
    }
    else {
        qDebug() << "Файл не существует." << Qt::endl;
    }
}

void InfoPrinter::printFileChanged(File& fileData) {
    qDebug() << "Файл изменился! ";
    printFileInfo(fileData);
}

void InfoPrinter::printFileAdded(File& fileData) {
    qDebug() << "Файл добавлен для отслеживания! ";
    printFileInfo(fileData);
}

void InfoPrinter::printFileRemoved(File& fileData) {
    qDebug() << "Файл: " << fileData.getFilePath() << " удален из отслеживания!" << Qt::endl;
}

void InfoPrinter::printFileNotAdded(File& fileData) {
    qDebug() << "Файл: " << fileData.getFilePath() << " уже отслеживается!" << Qt::endl;
}

void InfoPrinter::printFileNotRemoved(File& fileData) {
    qDebug() << "Файла: " << fileData.getFilePath() << " нет в отслеживании!" << Qt::endl;
}



