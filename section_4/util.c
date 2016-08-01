#include <stdio.h>

int streq(char s1[], char s2[]);

int streq(char s1[], char s2[])
{
    int c1, c2;
    int i = 0;
    while (1) {
        c1 = s1[i];
        c2 = s2[i];
        i++;
        if (c1 != c2)
            return 0;
        if (c1 == '\0' && c2 != '\0')
            return 0;
        if (c1 != '\0' && c2 == '\0')
            return 0;
        if (c1 == '\0' && c2 == '\0')
            return 1;
    }
}
