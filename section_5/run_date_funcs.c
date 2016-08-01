#include "date_funcs.h"

int main()
{
    int year, month, day, yearday;
    
    year = 1984;
    month = 3;
    day = 16;

    yearday = day_of_year(year, month, day);
    printf("yearday for %d-%d-%d:  %d\n", year, month, day, yearday);

    yearday = 164;
    month_day(year, yearday, &month, &day);
    printf("date from yearday %d:  %d-%d-%d\n", yearday, year, month, day);

}
