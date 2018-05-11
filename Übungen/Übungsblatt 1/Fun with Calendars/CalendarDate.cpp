//
// Created by sebastian on 5/9/18.
//

#include "CalendarDate.h"
#include "Easter.h"
#include <sstream>
#include <iostream>

CalendarDate GREGORIAN_APPOINTED_DATE(1,1,1600, CalendarDate::GREGORIAN);
CalendarDate JULIAN_APPOINTED_DATE(17,11,1858, CalendarDate::JULIAN);
const double DAYS_OF_YEAR = 365.242199;
const double DAYS_OF_MONTH = 29.53059;


CalendarDate::CalendarDate(int day, int month, int year, int type)
{
    _day = day;
    _month = month;
    _year = year;
    _type = type;

    if (! IsValid(*this))
    {
        throw "Invalid date";
    }

    _dayNumber = ToDayNumber(_day, _month, _year);
}

long int CalendarDate::GetDifferenceInDays(CalendarDate date)
{
    return _dayNumber - date.GetDayNumber();
}

double CalendarDate::GetDifferenceInYears(CalendarDate date)
{
    return (_dayNumber - date.GetDayNumber()) / DAYS_OF_YEAR;
}

long int CalendarDate::GetDayNumber()
{
    return _dayNumber;
}
int CalendarDate::GetDay()
{
    return _day;
}

int CalendarDate::GetMonth()
{
    return _month;
}

int CalendarDate::GetYear()
{
    return _year;
}

int CalendarDate::GetType()
{
    return _type;
}

std::string CalendarDate::ToString()
{
    std::stringstream ss;
    ss << _day << "." << _month << "." << _year;
    return ss.str();
}

bool CalendarDate::IsValid(CalendarDate date)
{
    if (date.GetDay() < 0 || date.GetDay() > 31)
    {
        return false;
    }
    if (date.GetMonth() < 0 || date.GetMonth() > 12)
    {
        return false;
    }
    if (date.GetType() == CalendarDate::GREGORIAN)
    {
        if (date.GetYear() < GREGORIAN_APPOINTED_DATE.GetYear())
        {
            return false;
        }
    }
    else
    {
        if (date.GetYear() < JULIAN_APPOINTED_DATE.GetYear())
        {
            return false;
        }
        if (date.GetYear() == JULIAN_APPOINTED_DATE.GetYear())
        {
            if (date.GetMonth() < JULIAN_APPOINTED_DATE.GetMonth() || date.GetDay() < JULIAN_APPOINTED_DATE.GetDay())
            {
                return false;
            }
        }
    }
    return true;
}

long int CalendarDate::ToDayNumber(int day, int month, int year)
{
    CalendarDate appointedDate = (_type == CalendarDate::GREGORIAN) ? GREGORIAN_APPOINTED_DATE : JULIAN_APPOINTED_DATE;
    long int yearDifference = year - appointedDate.GetYear();
    long int monthDifference = month - appointedDate.GetMonth();
    long int dayDifference = day - appointedDate.GetDay();
    return static_cast<long>((yearDifference * DAYS_OF_YEAR) + (monthDifference * DAYS_OF_MONTH) + dayDifference);
}

CalendarDate CalendarDate::GetEasterDate()
{
    return Easter::GetEasterDate(_year, _type);
}
