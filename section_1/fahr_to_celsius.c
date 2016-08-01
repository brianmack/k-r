#include <stdio.h>

float convert_temp(int fahr);

/* print Fahrenheit-Celcius table
    for fahr = 0, 20 .... , 300; floating-point version */
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0; /* lower limit of temp table */
    upper = 300; /* upper limit */
    step = 20; /* step size */

    printf("%s %s\n", "fahr", "celsius");
    fahr = lower;
    while (fahr <= upper) {
        celsius = convert_temp(fahr);
        printf("%4.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

float convert_temp(int fahr)
{
    return (5.0/9.0) * (fahr-32.0);
}
