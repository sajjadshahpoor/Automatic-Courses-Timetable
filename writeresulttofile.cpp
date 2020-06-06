#include "writeresulttofile.h"
#include <QDebug>
#include <QFile>

write_Resul_To_File::write_Resul_To_File()
{


}


void write_Resul_To_File::write_File(const QVector<day>& schedule_day)
{
    QFile result_file("C:/Users/DELL/Desktop/PL 2nd checkpoint/table/result.txt");

    if(!result_file.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << result_file.errorString();
    }

        QTextStream out(&result_file);

        out << "Time Table for full Weeek!!" << endl;

        for (int i=0; i<schedule_day.size(); i++) {

            if ( schedule_day[i].morning.bigClassroom1 == true )
                qDebug() << schedule_day[i].day_Name << " Morning Big Class Room #1 " << schedule_day[i].morning.bigClassroom1_Course.get_Course_Code();
                out << schedule_day[i].day_Name << " Morning Big Class Room #1 " << schedule_day[i].morning.bigClassroom1_Course.get_Course_Code()<<endl;
            if ( schedule_day[i].morning.bigClassroom2 == true )
                qDebug() << schedule_day[i].day_Name << " Morning Big Class Room #2 " << schedule_day[i].morning.bigClassroom2_Course.get_Course_Code();
                out<<schedule_day[i].day_Name << " Morning Big Class Room #2 " << schedule_day[i].morning.bigClassroom2_Course.get_Course_Code()<<endl;
            if ( schedule_day[i].morning.smallClassroom1 == true )
                qDebug() << schedule_day[i].day_Name << " Morning Small Class Room #1 " << schedule_day[i].morning.smallClassroom1_Course.get_Course_Code();
                out<<schedule_day[i].day_Name << " Morning Small Class Room #1 " << schedule_day[i].morning.smallClassroom1_Course.get_Course_Code()<<endl;
            if ( schedule_day[i].morning.smallClassroom2 == true )
                qDebug() << schedule_day[i].day_Name << " Morning Small Class Room #2 " << schedule_day[i].morning.smallClassroom2_Course.get_Course_Code();
                out<<schedule_day[i].day_Name << " Morning Small Class Room #2 " << schedule_day[i].morning.smallClassroom2_Course.get_Course_Code()<<endl;
            if ( schedule_day[i].afternoon.bigClassroom1 == true )
                qDebug() << schedule_day[i].day_Name << " Afternoon Big Class Room #1 " << schedule_day[i].afternoon.bigClassroom1_Course.get_Course_Code();
                out<<schedule_day[i].day_Name << " Afternoon Big Class Room #1 " << schedule_day[i].afternoon.bigClassroom1_Course.get_Course_Code() <<endl;
            if ( schedule_day[i].afternoon.bigClassroom2 == true )
                qDebug() << schedule_day[i].day_Name << " Afternoon Big Class Room #2 " << schedule_day[i].afternoon.bigClassroom2_Course.get_Course_Code();
                out<<schedule_day[i].day_Name << " Afternoon Big Class Room #2 " << schedule_day[i].afternoon.bigClassroom2_Course.get_Course_Code()<<endl;
            if ( schedule_day[i].afternoon.smallClassroom1 == true )
                qDebug() << schedule_day[i].day_Name << " Afternoon Small Class Room #1 " << schedule_day[i].afternoon.smallClassroom1_Course.get_Course_Code();
                out<<schedule_day[i].day_Name << " Afternoon Small Class Room #1 " << schedule_day[i].afternoon.smallClassroom1_Course.get_Course_Code()<<endl;
            if ( schedule_day[i].afternoon.smallClassroom2 == true )
                qDebug() << schedule_day[i].day_Name << " Afternoon Small Class Room #2 " << schedule_day[i].afternoon.smallClassroom2_Course.get_Course_Code();
                out<<schedule_day[i].day_Name << " Afternoon Small Class Room #2 " << schedule_day[i].afternoon.smallClassroom2_Course.get_Course_Code()<<endl;
        }

        qDebug() << "\n\nCourses has been scheduled, Check Result.txt file!!";
       result_file.flush();
       result_file.close();
}

