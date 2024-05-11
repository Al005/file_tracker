#ifndef FILETRACKER_H
#define FILETRACKER_H

#include "file.h"

#include <QTimer>
#include <QVector>
#include "InfoPrinter.h"
#include <QObject>

class FileTracker : public QObject
{
    Q_OBJECT
    QVector <File*> files;
    InfoPrinter fileInfoPrinter;
    FileTracker(QStringList file_paths);
    ~FileTracker() { qDeleteAll(files); }
    FileTracker& operator=(FileTracker const&);

public:
    static FileTracker &getInstance(QStringList file_paths) {
        static FileTracker instance(file_paths);
        return instance;
    }

public slots:
    void checkFiles();
signals:
    void FileUpdated(File* fileData);
};

#endif // FILETRACKER_H
