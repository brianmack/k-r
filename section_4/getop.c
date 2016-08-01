#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int getch(void);
void ungetch(int);

/* getop:  get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ; 
    s[1] = '\0';
    
    i = 0; 
    if (isalpha(c)) { /* get any word operations */
        while (isalpha(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        return FUNC;
    }
    
    if (!isdigit(c) && c != '.' && c != '-')
        return c; /* not a number */


    if (isdigit(c) || c == '-') /* collect integer digits */
        while (isdigit(s[++i] = c = getch()))
            ;
    
    if (c == '.') /* collect fraction digits if any */
        while (isdigit(s[++i] = c = getch()))
            ;
    
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
