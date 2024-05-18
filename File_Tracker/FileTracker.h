#ifndef FILETRACKER_H
#define FILETRACKER_H

#include "file.h"

#include <QTimer>
#include <QVector>
//#include "InfoPrinter.h"
#include <QObject>

class FileTracker : public QObject
{
    Q_OBJECT
    QVector <File*> files;
    FileTracker(QStringList file_paths);
    ~FileTracker() { qDeleteAll(files); }
    FileTracker (const FileTracker&);
    FileTracker& operator=(FileTracker const&);

public:
    static FileTracker &getInstance(QStringList file_paths) {
        static FileTracker instance(file_paths);
        return instance;
    }
    void addFile(const QString& file_path);
    void removeFile(const QString& filePath);
public slots:
    void checkFiles();
signals:
    void FileInfo(File& fileData);
    void FileUpdated(File& fileData);

    void FileAdded(File& fileData);
    void FileRemoved(File& fileData);

    void FileNotAdded(File& fileData);
    void FileNotRemoved(File& fileData);
};

#endif // FILETRACKER_H
