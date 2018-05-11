//
// Created by sebastian on 5/9/18.
//

#ifndef FUN_WITH_CALENDARS_EASTER_H
#define FUN_WITH_CALENDARS_EASTER_H


#include "CalendarDate.h"

class Easter {
public: static CalendarDate GetEasterDate(int year, int calendarType);
private: static void GetNAndM(int year, int &m, int &n);
};


#endif //FUN_WITH_CALENDARS_EASTER_H
