#include <stdio.h>

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 200;
    step = 20;

    printf("%6s %8s\n", "fahr", "celsius");
    celsius = lower;
    while (celsius <= upper) {
        fahr = (celsius * (9.0 / 5.0)) + 32;
        printf("%6.1f %8.1f\n", celsius, fahr);
        celsius += step;
    }
}
