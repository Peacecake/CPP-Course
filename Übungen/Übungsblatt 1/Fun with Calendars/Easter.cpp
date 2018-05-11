//
// Created by sebastian on 5/9/18.
//

#include "Easter.h"

CalendarDate Easter::GetEasterDate(int year, int calendarType)
{
    int m, n, a, b, c, d, e, dayOfMonth, month;

    if (year < 1700 || year > 2199)
    {
        throw "Invalid year. Choose year between 1700 and 2199";
    }


    if (calendarType == CalendarDate::GREGORIAN)
    {
        GetNAndM(year, m, n);
    } else
        {
        m = 15;
        n = 5;
    }

    a = year % 19;
    b = year % 4;
    c = year % 7;
    d = ((19 * a) + m) % 30;
    e = ((2 * b) + (4 * c) + (6 * d) + n) % 7;

    dayOfMonth = 22 + d + e;
    month = 3;
    if (dayOfMonth > 31 || dayOfMonth < 0)
    {
        month = 4;
        dayOfMonth = d + e - 9;
        if (dayOfMonth == 26)
        {
            dayOfMonth = 19;
        }
        if (dayOfMonth == 25 && (d == 28 && e == 6 && (((11 * m) + 11) % 30 < 19)))
        {
            dayOfMonth = 18;
        }
    }

    return CalendarDate(dayOfMonth, month, year, calendarType);
}

void Easter::GetNAndM(int year, int &m, int &n)
{
    switch (year / 100)
    {
        case 17:
            m = 23;
            n = 3;
            break;
        case 18:
            m = 23;
            n = 4;
            break;
        case 19:
            m = 24;
            n = 5;
            break;
        case 20:
            m = 24;
            n = 5;
            break;
        case 21:
            m = 24;
            n = 6;
            break;
        case 22:
            m = 25;
            n = 0;
            break;
        case 23:
            m = 26;
            n = 1;
            break;
        case 24:
            m = 25;
            n = 1;
            break;
    }
}
