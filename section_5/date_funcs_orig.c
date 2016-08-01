/* convert day of the month to day of the year and vice versa. */

#include "date_funcs.h" 

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

/* day of year:  set day of year from month & day */
int day_of_year(int year, int month, int day) 
{
    int i, leap, error;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    
    /* check inputs */
    error = 0;
    if (month < 1 || month > 12) {
        printf("error: month input must be in range 1-12\n");
        error = 1;
    }
    else if (day < 1 || day > daytab[leap][month]) {
        printf("error: day input must be in range 1-%d\n",
            daytab[leap][month]);
        error = 1;
    }
    if (!error) {

        for (i = 1; i < month; i++)
            day += daytab[leap][i];
        return day;
    }
}


/* month day:  set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap, error;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    
    /* check inputs */
    error = 0;
    if (*pmonth < 1 || *pmonth > 12) {
        printf("error: month input must be in range 1-12\n");
        error = 1;
    }
    else if (*pday < 1 || *pday > daytab[leap][*pmonth]) {
        printf("error: day input must be in range 1-%d\n",
            daytab[leap][*pmonth]);
        error = 1;
    }
    if (!error) {
     
        for (i = 1; yearday > daytab[leap][i]; i++)
            yearday -= daytab[leap][i];
        *pmonth = i;
        *pday = yearday;
    }
}
