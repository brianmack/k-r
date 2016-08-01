#include <stdio.h>

void squeeze2(char s1[], char s2[]);

main()
{
    char s1[] = "mary had a little lamb";
    char s2[] = "fleece as white as snow";
    printf("s1 = %s, s2 = %s\n", s1, s2);
    squeeze2(s1, s2);
    printf("new s1 = %s\n", s1);
    return 0;
}

void squeeze2(char s1[], char s2[])
{    
    int i, j, k, c, found;
    i = k = 0;
    while ((c = s1[i]) != '\0') {
        j = found = 0;
        for (j=0; s2[j] != '\0'; j++) {
            if (s2[j] == c)
                found = 1;
        }
        if (!found)
            s1[k++] = s1[i];
        i++;
    } 
    s1[k] = '\0';
}
