//
// Created by sebastian on 5/9/18.
//

#ifndef FUN_WITH_CALENDARS_CALENDARDATE_H
#define FUN_WITH_CALENDARS_CALENDARDATE_H

#include <string>

class CalendarDate
{
public: static const int GREGORIAN = 0;
public: static const int JULIAN = 1;

private: int _type;
private: int _day;
private: int _month;
private: int _year;
private: long int _dayNumber = 0;

public: CalendarDate(int day, int month, int year, int type);
public: int GetDay();
public: int GetMonth();
public: int GetYear();
public: int GetType();
public: long int GetDayNumber();
public: std::string ToString();
public: static bool IsValid(CalendarDate date);
public: long int GetDifferenceInDays(CalendarDate date);
public: double GetDifferenceInYears(CalendarDate date);
public: CalendarDate GetEasterDate();

private: long int ToDayNumber(int day, int month, int year);

};


#endif //FUN_WITH_CALENDARS_CALENDARDATE_H
