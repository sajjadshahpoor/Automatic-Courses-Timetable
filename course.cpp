#include "course.h"

course::course()
{

}

course::~course()
{

}

course::course(QString courseCode, QString courseName, QString semesterYear, QString credit, QString compulsoryOrElective, QString departmentOrService, QString professorName)
{
    this->course_Code = courseCode;
    this->course_Name = courseName;
    this->semester_Year = semesterYear;
    this->credit = credit;
    this->compulsory_Or_Elective = compulsoryOrElective;
    this->department_Or_Service = departmentOrService;
    this->professor_Name = professorName;
}

QString course::get_Course_Code() const
{
    return course_Code;
}

void course::set_Course_Code(const QString &value)
{
    course_Code = value;
}

QString course::get_Course_Name() const
{
    return course_Name;
}

void course::set_Course_Name(const QString &value)
{
    course_Name = value;
}

QString course::get_Year_Of_Semester() const
{
    return semester_Year;
}

void course::set_Semester_Year(const QString &value)
{
    semester_Year = value;
}

QString course::get_Credit() const
{
    return credit;
}

void course::set_Credit(const QString &value)
{
    credit = value;
}

QString course::get_Compulsory_Or_Elective() const
{
    return compulsory_Or_Elective;
}

void course::set_Compulsory_Or_Elective(const QString &value)
{
    compulsory_Or_Elective = value;
}

QString course::get_Department_Or_Service() const
{
    return department_Or_Service;
}

void course::set_Department_Or_Service(const QString &value)
{
    department_Or_Service = value;
}

QString course::get_Professor_Name() const
{
    return professor_Name;
}

void course::set_Professor_Name(const QString &value)
{
    professor_Name = value;
}
