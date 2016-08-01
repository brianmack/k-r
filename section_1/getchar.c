#include <stdio.h>

main()
{
    int c;
    int test;

    /* while ((c = getchar()) != EOF)
        commented out to print the EOF charachter */
    while (c = getchar()) {
        putchar(c);
        test = c == EOF;
        printf(" - test:\t%d\n", test);
        if (test) 
            break;
    }
        
}
