#ifndef COURSE_H
#define COURSE_H
#include<QString>

class course
{
public:
    //default constructor
    course();
    //~course(); destructor
    ~course();
    //constructor has been overloaded
    course(QString, QString, QString, QString,QString, QString, QString);
    //part of accessor functions
    QString get_Course_Code() const;
    QString get_Course_Name() const;
    QString get_Year_Of_Semester() const;
    QString get_Credit() const;
    QString get_Compulsory_Or_Elective() const;
    QString get_Department_Or_Service() const;
    QString get_Professor_Name() const;
    //part of mutator functions
    void set_Course_Code(const QString &value);
    void set_Course_Name(const QString &value);
    void set_Semester_Year(const QString &value);
    void set_Credit(const QString &value);
    void set_Compulsory_Or_Elective(const QString &value);
    void set_Department_Or_Service(const QString &value);
    void set_Professor_Name(const QString &value);




private:
    //part of memmber variables
    QString course_Code;
    QString course_Name;
    QString semester_Year; //firstClass, SecondClass,..
    QString credit;
    QString compulsory_Or_Elective;
    QString department_Or_Service;
    QString professor_Name;
public:
    bool isAssigned=false;


};

#endif // COURSE_H
