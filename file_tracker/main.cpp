#include "proj.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    proj w;
    w.show();
    return a.exec();
}