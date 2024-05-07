#ifndef FILE_H
#define FILE_H

#include <QFile>
#include <QFileInfo>

class File{
    QString file_path;
    qint64 file_size;
    bool file_exists;
public:
    File();
    File(const QString &file_path);
    QString getFilePath();
    qint64 getFileSize();
    bool getFileExists();
    void updateFileInfo();
};

#endif // FILE_H
