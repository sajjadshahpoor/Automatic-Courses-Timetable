#ifndef READMYFILE_H
#define READMYFILE_H
#include <QVector>
#include <QString>



class read_Myfile
{
public:
    read_Myfile();
    QVector<QVector<QString>> split_To_String(QString);
};


#endif // READMYFILE_H
