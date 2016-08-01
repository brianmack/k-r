

#include <stdio.h>

#define MAXLEN 1000

void expand(char[], char[]);

int main()
{
    char s2[MAXLEN];
    char s1[] = "-a-h, 3-b, s-z- some other chars 0-8 -2-4";
    
    expand(s1, s2);
    printf("%s\n", s2);

    return 0;
}


void expand(char s1[], char s2[])
{
    int i,j,c,sign,new;

    for (i=0,j=0; ((c = s1[i]) != '\0'); i++) {
        // printf("%s -- %s\n", s1, s2);
        if (c == '-') {
            if (i==0 || s1[i+2]=='-') 
                continue;
            else if (isalpha(s1[i-1]) && !isalpha(s1[i+1]))
                continue;
            else if (isdigit(s1[i-1]) && !isdigit(s1[i+1]))
                continue;
            c = s1[i-1] + 1;
            while (c != s1[i+1])
                s2[j++] = c++;
        } else {
            s2[j++] = c;
        }
    }
    s2[j] = '\0';
}
