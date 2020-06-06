#include "readmyfile.h"
#include <QFile>
#include <QTextStream>
#include<QDebug>
read_Myfile::read_Myfile()
{

}

QVector<QVector<QString> > read_Myfile::split_To_String(QString fileName)
{
    QFile mfile(fileName);
    if(!mfile.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << mfile.errorString();
    }
    QTextStream in(&mfile);
    QVector<QVector<QString>> vline;
    QVector<QString> tokens;

    while(!in.atEnd()){
        QString line = in.readLine();
        for(int i=0; i<line.split(';').length(); i++){
        tokens.push_back(line.split(';').at(i));
        }
          vline.push_back(tokens);
          tokens.clear();
}

    mfile.close();
    return vline;
}
