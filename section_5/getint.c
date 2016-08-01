#include <stdio.h>
#include <ctype.h>
#define SIZE 97

int getch(void);
void ungetch(int);
int getint(int *);

int main()
{
    int n, array[SIZE];

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;
    printf("%d\n", *array);
}


/* getint: get next integer from input to *pn */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c))
            ungetch(c);
    }
    for (*pn = 0; isdigit(c); c = getch()) {
        printf("%d, %d\n", c, *pn);
        *pn = 10 * *pn + (c - '0');
        printf("-- %d\n", *pn);
    }
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
 
