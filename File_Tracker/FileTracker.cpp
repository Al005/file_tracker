#include "FileTracker.h"
#include <QDebug>


FileTracker::FileTracker(QStringList file_paths)
{
    for (const QString &filePath : file_paths) {
        File *fileData = new File(filePath);
        files.append(fileData);
        //emit FileInfo(*fileData);
    }
    //emitFileInfo();
    //QMetaObject::invokeMethod(this, "PrintFileInfo", Qt::QueuedConnection);
}

void FileTracker::PrintFilesInfo() {
    for (int i = 0; i < files.size(); ++i) {
        emit FileInfo(*files[i]);
    }
}

void FileTracker::addFile(const QString& file_path) {
    for (int i = 0; i < files.size(); ++i) {
        if (files[i]->getFilePath() == file_path) {
            emit FileNotAdded(*files[i]);  // Передаем такой же нашедший файл
            return;
        }
    }
    File *fileData = new File(file_path);
    files.append(fileData);
    emit FileAdded(*fileData);

}

void FileTracker::removeFile(const QString& file_path) {
    for (int i = 0; i < files.size(); ++i) {
        if (files[i]->getFilePath() == file_path) {
            emit FileRemoved(*files[i]);
            delete files[i];  // Удаляем объект File
            files.remove(i);  // Удаляем указатель из QVector
            return;
        }
    }
    File fileData = file_path;
    emit FileNotRemoved(fileData);
}

void FileTracker::checkFiles() {
    for (int i = 0; i < files.size(); ++i) {
        File *fileData = files[i];
        qint64 oldSize = fileData->getFileSize();
        bool oldExists = fileData->getFileExists();
        fileData->updateFileInfo();
        if (fileData->getFileSize() != oldSize || fileData->getFileExists() != oldExists) {
            emit FileUpdated(*fileData);
        }
    }
}

