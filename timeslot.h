#ifndef TIMESLOT_H
#define TIMESLOT_H
#include <course.h>

class timeSlot
{
public:
    timeSlot();
    course bigClassroom1_Course;
    course bigClassroom2_Course;
    course smallClassroom1_Course;
    course smallClassroom2_Course;
    bool bigClassroom1=false;
    bool bigClassroom2=false;
    bool smallClassroom1=false;
    bool smallClassroom2=false;
};

#endif // TIMESLOT_H
