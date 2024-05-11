#include "FileTracker.h"
#include <QDebug>


FileTracker::FileTracker(QStringList file_paths)
{
    for (const QString &filePath : file_paths) {
        File *fileData = new File(filePath);
        files.append(fileData);
        fileInfoPrinter.printFileInfo(fileData);
    }
    QObject::connect(this, &FileTracker::FileUpdated, &fileInfoPrinter, &InfoPrinter::printFileChanged);
}

void FileTracker::checkFiles() {

    for (int i = 0; i < files.size(); ++i) {
        File *fileData = files[i];
        qint64 oldSize = fileData->getFileSize();
        bool oldExists = fileData->getFileExists();
        fileData->updateFileInfo();
        if (fileData->getFileSize() != oldSize || fileData->getFileExists() != oldExists) {
            emit FileUpdated(fileData);
        }
    }
}

