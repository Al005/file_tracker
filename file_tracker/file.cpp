#include "file.h"

File::File()
{
    this->file_path = QString("");
    this->file_size = 0;
    this->file_exists = false;
}

File::File(const QString &file_path)
{
    QFileInfo file_info(file_path);
    this->file_path = file_info.filePath();
    this->file_size = file_info.size();
    this->file_exists = file_info.exists();
}

QString File::getFilePath() {return file_path;}
qint64 File::getFileSize() {return file_size;}
bool File::getFileExists() {return file_exists;}

