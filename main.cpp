#include <QCoreApplication>
#include <iostream>
#include <QVector>
#include <day.h>
#include <readmyfile.h>
#include <writeresulttofile.h>
#include <course.h>
#include <QDebug>


using namespace std;


/*used inline for function to Get Number of Day*/
inline int get_Number_Of_Day(QString dayValue){
    if(dayValue=="Monday") return 0;
    if(dayValue=="Tuesday") return 1;
    if(dayValue=="Wednesday") return 2;
    if(dayValue=="Thursday") return 3;
    if(dayValue=="Friday") return 4;
        else return -1;
}


/*Checkig if monring timeslot is busy or not*/
/* bool value_To_Be_Returned = false used as default paramaters*/
bool is_CourseMorning_Busy(course& value_of_Course, int index_Of_Day, QVector<QVector<QString>>& time_Slot_Busy, bool value_To_Be_Returned = false)
{
    //bool value_To_Be_Returned = false;
       int j = 0;
       while(j < time_Slot_Busy.size()){
           int index_Busy_TimeSlot = get_Number_Of_Day(time_Slot_Busy[j][1]);
           if ( index_Of_Day == index_Busy_TimeSlot && value_of_Course.get_Course_Code() == time_Slot_Busy[j][0] &&
                  time_Slot_Busy[j][2] == "Morning" )
           {
               value_To_Be_Returned = true;
               break;
           }
           j++;
       }
       return value_To_Be_Returned;
}

/*Checkig if afternoon timeslot is busy or not*/
bool is_CourseAfternoon_Busy(course& value_of_Course, int index_Of_Day, QVector<QVector<QString>>& time_Slot_Busy)
{
    bool value_To_Be_Returned = false;

    int j = 0;
    while(j < time_Slot_Busy.size()){
        int busyTimeSlotDayIndex = get_Number_Of_Day(time_Slot_Busy[j][1]);
        if ( index_Of_Day == busyTimeSlotDayIndex && value_of_Course.get_Course_Code() == time_Slot_Busy[j][0] &&
               time_Slot_Busy[j][2] == "Afternoon" )
        {
            value_To_Be_Returned = true;
            break;
        }
        j++;
    }
    return value_To_Be_Returned;
}

void Vector_Filling_Of_Schedule_With_Service( QVector<day>& schedule, QVector<course>& my_Course){
    read_Myfile read_service_csv;
    QString fileName="C:/Users/DELL/Desktop/PL 2nd checkpoint/table/service.csv";
    QVector<QVector<QString>> serviceCourse = read_service_csv.split_To_String(fileName);

    for (int i=0; i<serviceCourse.size(); i++) {
         int courseIndex=-1;
        for (int j = 0; j < my_Course.size(); ++j) {
            if (my_Course[j].get_Course_Code()== serviceCourse[i][0]) {
            courseIndex=j;
            break;
            }
        }

        int dayIndex = get_Number_Of_Day(serviceCourse[i][1]);
        bool isElective = my_Course[courseIndex].get_Compulsory_Or_Elective() == "E" ? true : false;

        if( serviceCourse[i][2] == "Afternoon" )
        {
            if ( isElective )
            {
                if(schedule[dayIndex].afternoon.smallClassroom1 == false){
                schedule[dayIndex].afternoon.smallClassroom1 = true;
                my_Course[courseIndex].isAssigned = true;
                schedule[dayIndex].afternoon.smallClassroom1_Course = my_Course[courseIndex];

                }
                else if(schedule[dayIndex].afternoon.smallClassroom2 == false){
                schedule[dayIndex].afternoon.smallClassroom2= true;
                my_Course[courseIndex].isAssigned = true;
                schedule[dayIndex].afternoon.smallClassroom2_Course = my_Course[courseIndex];
                }
                else if(schedule[dayIndex].afternoon.bigClassroom1 == false){
                schedule[dayIndex].afternoon.bigClassroom1 = true;
                my_Course[courseIndex].isAssigned = true;
                schedule[dayIndex].afternoon.bigClassroom1_Course = my_Course[courseIndex];
                }
                else if(schedule[dayIndex].afternoon.bigClassroom2 == false){
                schedule[dayIndex].afternoon.bigClassroom2 = true;
                my_Course[courseIndex].isAssigned = true;
                schedule[dayIndex].afternoon.bigClassroom2_Course = my_Course[courseIndex];
                }

            }
            else { //check compulsory
                if(schedule[dayIndex].afternoon.bigClassroom1 == false){
                schedule[dayIndex].afternoon.bigClassroom1 = true;
                my_Course[courseIndex].isAssigned = true;
                schedule[dayIndex].afternoon.bigClassroom1_Course = my_Course[courseIndex];
                }
                else if(schedule[dayIndex].afternoon.bigClassroom2 == false){
                schedule[dayIndex].afternoon.bigClassroom2 = true;
                my_Course[courseIndex].isAssigned = true;
                schedule[dayIndex].afternoon.bigClassroom2_Course = my_Course[courseIndex];
                }
            }
        }
        else if(serviceCourse[i][2] == "Morning")
        {
            if ( isElective )
            {
                if(schedule[dayIndex].morning.smallClassroom1 == false){
                schedule[dayIndex].morning.smallClassroom1 = true;
                my_Course[courseIndex].isAssigned = true;
                schedule[dayIndex].morning.smallClassroom1_Course = my_Course[courseIndex];
                }
                else if(schedule[dayIndex].morning.smallClassroom2 == false){
                schedule[dayIndex].morning.smallClassroom2= true;
                my_Course[courseIndex].isAssigned = true;
                schedule[dayIndex].morning.smallClassroom2_Course = my_Course[courseIndex];
                }
                else if(schedule[dayIndex].morning.bigClassroom1 == false){
                schedule[dayIndex].morning.bigClassroom1 = true;
                my_Course[courseIndex].isAssigned = true;
                schedule[dayIndex].morning.bigClassroom1_Course = my_Course[courseIndex];
                }
                else if(schedule[dayIndex].morning.bigClassroom2 == false){
                schedule[dayIndex].morning.bigClassroom2 = true;
                my_Course[courseIndex].isAssigned = true;
                schedule[dayIndex].morning.bigClassroom2_Course = my_Course[courseIndex];
                }

            }
            else { //check Compulsory
                if(schedule[dayIndex].morning.bigClassroom1 == false){
                schedule[dayIndex].morning.bigClassroom1 = true;
                my_Course[courseIndex].isAssigned = true;
                schedule[dayIndex].morning.bigClassroom1_Course = my_Course[courseIndex];
                }
                else if(schedule[dayIndex].morning.bigClassroom2 == false){
                schedule[dayIndex].morning.bigClassroom2 = true;
                my_Course[courseIndex].isAssigned = true;
                schedule[dayIndex].morning.bigClassroom2_Course = my_Course[courseIndex];
                }
            }

        }
    }
}


/*reading courses.csv file to vector*/
void Store_Course_Info_To_Vector(QVector<course>& new_Course, int columns = 0,int rows = 0 ){
    read_Myfile read_courses_csv_file;
     QString file_Name="C:/Users/DELL/Desktop/PL 2nd checkpoint/table/courses.csv";
     read_courses_csv_file.split_To_String(file_Name);
     try {
         while(rows < read_courses_csv_file.split_To_String(file_Name).size()){
             course newCourse(read_courses_csv_file.split_To_String(file_Name)[rows][columns], read_courses_csv_file.split_To_String(file_Name)[rows][columns+1],
             read_courses_csv_file.split_To_String(file_Name)[rows][columns+2], read_courses_csv_file.split_To_String(file_Name)[rows][columns+3],
                     read_courses_csv_file.split_To_String(file_Name)[rows][columns+4], read_courses_csv_file.split_To_String(file_Name)[rows][columns+5],
                     read_courses_csv_file.split_To_String(file_Name)[rows][columns+6]);
                     new_Course.push_back(newCourse);
             rows++;
         }if(rows > read_courses_csv_file.split_To_String(file_Name).size()){
             throw "read_courses_csv_file out of boundary";
                }
        } catch (char *ex) {
        cout<< ex;
       }
}


bool isSameTime_Morning_Class(day& value_ofDay, course& value_ofCourse)
{
    bool value_To_Be_Returned = false;

    if ( value_ofDay.morning.bigClassroom1 == true &&
         value_ofDay.morning.bigClassroom1_Course.get_Year_Of_Semester() == value_ofCourse.get_Year_Of_Semester() )
        value_To_Be_Returned = true;

    if ( value_ofDay.morning.bigClassroom2 == true &&
         value_ofDay.morning.bigClassroom2_Course.get_Year_Of_Semester() == value_ofCourse.get_Year_Of_Semester() )
        value_To_Be_Returned = true;

    if ( value_ofDay.morning.smallClassroom1 == true &&
         value_ofDay.morning.smallClassroom1_Course.get_Year_Of_Semester() == value_ofCourse.get_Year_Of_Semester() )
        value_To_Be_Returned = true;

    if ( value_ofDay.morning.smallClassroom2 == true &&
         value_ofDay.morning.smallClassroom2_Course.get_Year_Of_Semester() == value_ofCourse.get_Year_Of_Semester() )
        value_To_Be_Returned = true;

    return value_To_Be_Returned;

}
bool isSameTime_Afternoon_Class(day& value_ofDay, course& value_ofCourse)
{
    bool value_To_Be_Returned = false;

    if ( value_ofDay.afternoon.bigClassroom1 == true &&
         value_ofDay.afternoon.bigClassroom1_Course.get_Year_Of_Semester() == value_ofCourse.get_Year_Of_Semester() )
        value_To_Be_Returned = true;

    if ( value_ofDay.afternoon.bigClassroom2 == true &&
         value_ofDay.afternoon.bigClassroom2_Course.get_Year_Of_Semester() == value_ofCourse.get_Year_Of_Semester() )
        value_To_Be_Returned = true;

    if ( value_ofDay.afternoon.smallClassroom1 == true &&
         value_ofDay.afternoon.smallClassroom1_Course.get_Year_Of_Semester() == value_ofCourse.get_Year_Of_Semester() )
        value_To_Be_Returned = true;

    if ( value_ofDay.afternoon.smallClassroom2 == true &&
         value_ofDay.afternoon.smallClassroom2_Course.get_Year_Of_Semester() == value_ofCourse.get_Year_Of_Semester() )
        value_To_Be_Returned = true;

    return value_To_Be_Returned;
}


void store_Vector_Of_Schedule_With_Department( QVector<day>& my_schedule_day, QVector<course>& my_Course, QVector<QVector<QString>>& busyTimeSlot){
    int j;
    int dayIndex;

    for (j = 0; j < my_Course.size(); j++) {
        if(my_Course[j].isAssigned==true){
            continue;
        }

        bool is_Elective_subject = my_Course[j].get_Compulsory_Or_Elective() == "E" ? true : false;
        for (dayIndex = 0; dayIndex<5; dayIndex++) {

            bool isSameClassMorning_temp = isSameTime_Morning_Class(my_schedule_day[dayIndex], my_Course[j]);
            bool isSameClassAfternoon_temp = isSameTime_Afternoon_Class(my_schedule_day[dayIndex], my_Course[j]);

            bool isBusy_Morning_temp = is_CourseMorning_Busy(my_Course[j], dayIndex, busyTimeSlot);
            bool isBusy_Afternoon_temp = is_CourseAfternoon_Busy(my_Course[j], dayIndex, busyTimeSlot);

            if ( isSameClassMorning_temp == true && isSameClassAfternoon_temp == true )
                continue;

            if ( isBusy_Morning_temp == true && isBusy_Afternoon_temp == true )
                continue;

            if ( isSameClassMorning_temp == false && isBusy_Morning_temp == false )
            {
                if ( is_Elective_subject )
                {
                    if(my_schedule_day[dayIndex].morning.smallClassroom1 == false){
                    my_schedule_day[dayIndex].morning.smallClassroom1 = true;
                    my_Course[j].isAssigned = true;
                    my_schedule_day[dayIndex].morning.smallClassroom1_Course = my_Course[j];
                    }
                    else if(my_schedule_day[dayIndex].morning.smallClassroom2 == false){
                    my_schedule_day[dayIndex].morning.smallClassroom2= true;
                    my_Course[j].isAssigned = true;
                    my_schedule_day[dayIndex].morning.smallClassroom2_Course = my_Course[j];
                    }
                    else if(my_schedule_day[dayIndex].morning.bigClassroom1 == false){
                    my_schedule_day[dayIndex].morning.bigClassroom1 = true;
                    my_Course[j].isAssigned = true;
                    my_schedule_day[dayIndex].morning.bigClassroom1_Course = my_Course[j];
                    }
                    else if(my_schedule_day[dayIndex].morning.bigClassroom2 == false){
                    my_schedule_day[dayIndex].morning.bigClassroom2 = true;
                    my_Course[j].isAssigned = true;
                    my_schedule_day[dayIndex].morning.bigClassroom2_Course = my_Course[j];
                    }

                }
                else { //check Compulsory
                    if(my_schedule_day[dayIndex].morning.bigClassroom1 == false){
                    my_schedule_day[dayIndex].morning.bigClassroom1 = true;
                    my_Course[j].isAssigned = true;
                    my_schedule_day[dayIndex].morning.bigClassroom1_Course = my_Course[j];
                    }
                    else if(my_schedule_day[dayIndex].morning.bigClassroom2 == false){
                    my_schedule_day[dayIndex].morning.bigClassroom2 = true;
                    my_Course[j].isAssigned = true;
                    my_schedule_day[dayIndex].morning.bigClassroom2_Course = my_Course[j];
                    }
                }
            }
            else if ( isSameClassAfternoon_temp == false && isBusy_Afternoon_temp == false  )
            {
                if ( is_Elective_subject )
                {
                    if(my_schedule_day[dayIndex].afternoon.smallClassroom1 == false){
                    my_schedule_day[dayIndex].afternoon.smallClassroom1 = true;
                    my_Course[j].isAssigned = true;
                    my_schedule_day[dayIndex].afternoon.smallClassroom1_Course = my_Course[j];

                    }
                    else if(my_schedule_day[dayIndex].afternoon.smallClassroom2 == false){
                    my_schedule_day[dayIndex].afternoon.smallClassroom2= true;
                    my_Course[j].isAssigned = true;
                    my_schedule_day[dayIndex].afternoon.smallClassroom2_Course = my_Course[j];
                    }
                    else if(my_schedule_day[dayIndex].afternoon.bigClassroom1 == false){
                    my_schedule_day[dayIndex].afternoon.bigClassroom1 = true;
                    my_Course[j].isAssigned = true;
                    my_schedule_day[dayIndex].afternoon.bigClassroom1_Course = my_Course[j];
                    }
                    else if(my_schedule_day[dayIndex].afternoon.bigClassroom2 == false){
                    my_schedule_day[dayIndex].afternoon.bigClassroom2 = true;
                    my_Course[j].isAssigned = true;
                    my_schedule_day[dayIndex].afternoon.bigClassroom2_Course = my_Course[j];
                    }

                }
                else { //check compulsory
                    if(my_schedule_day[dayIndex].afternoon.bigClassroom1 == false){
                    my_schedule_day[dayIndex].afternoon.bigClassroom1 = true;
                    my_Course[j].isAssigned = true;
                    my_schedule_day[dayIndex].afternoon.bigClassroom1_Course = my_Course[j];
                    }
                    else if(my_schedule_day[dayIndex].afternoon.bigClassroom2 == false){
                    my_schedule_day[dayIndex].afternoon.bigClassroom2 = true;
                    my_Course[j].isAssigned = true;
                    my_schedule_day[dayIndex].afternoon.bigClassroom2_Course = my_Course[j];
                    }
                }
            }

        }

    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<course> myCourse;
    Store_Course_Info_To_Vector(myCourse);
    QVector<day> schedule_day(5);
    qDebug() << "Time Table for full Weeek!!";
    schedule_day[0].day_Name = "Monday";
    schedule_day[1].day_Name = "Tuesday";
    schedule_day[2].day_Name = "Wednesday";
    schedule_day[3].day_Name = "Thursday";
    schedule_day[4].day_Name = "Friday";

    QVector<QVector<QString>> busyTimeSlot = read_Myfile().split_To_String("C:/Users/DELL/Desktop/PL 2nd checkpoint/table/busy.csv");
   // qDebug() << "busy.csv fill has benn readed";
    Vector_Filling_Of_Schedule_With_Service(schedule_day,myCourse);
    store_Vector_Of_Schedule_With_Department(schedule_day, myCourse, busyTimeSlot);
    write_Resul_To_File().write_File(schedule_day);
    return a.exec();
}





