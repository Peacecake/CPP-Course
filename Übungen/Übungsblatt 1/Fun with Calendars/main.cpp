#include <iostream>

#include "CalendarDate.h"

int main()
{
    try
    {
        CalendarDate date(9, 5, 2018, CalendarDate::GREGORIAN);
        CalendarDate date2(9, 5, 2017, CalendarDate::GREGORIAN);
        std::cout << "Difference in days: " << date.GetDifferenceInDays(date2) << std::endl;
        std::cout << "Difference in years: " << date.GetDifferenceInYears(date2) << std::endl;
        std::cout << "Easter in the year " << date.GetYear() << " is on the " << date.GetEasterDate().ToString() << std::endl;
        std::cout << "Easter in the year " << date2.GetYear() << " is on the " << date2.GetEasterDate().ToString() << std::endl;
    }
    catch (const char* msg )
    {
        std::cerr << msg << std::endl;
    }
    return 0;
}