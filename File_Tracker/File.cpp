#include "File.h"

File::File()
{
    this->file_path = QString("");
    this->file_size = 0;
    this->file_exists = false;
}

File::File(const QString &file_path) : file_path(file_path) {
    updateFileInfo();
}

QString File::getFilePath() {return file_path;}
qint64 File::getFileSize() {return file_size;}
bool File::getFileExists() {return file_exists;}
void File::updateFileInfo()
{
    QFileInfo fileInfo(file_path);
    file_exists = fileInfo.exists();
    file_size = file_exists ? fileInfo.size() : 0;
}
