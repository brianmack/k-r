#include <stdio.h>
#define MAXLINE 1000 /* max input line size */

int getline(char line[], int maxline);
void reverse(char to_reverse[], char reversed[], int len);

/* print all input lines longer than 80 characters */
main()
{
    int len;
    
    char line[MAXLINE];
    
    while (len = getline(line, MAXLINE)) {
        char newline[len];
        reverse(line, newline, len);
        printf("%s\n", newline);
    }

    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* fill in reverse array 'r' */
void reverse(char s[], char r[], int len)
{
    int i;

    i = 0;
    while (len > -1 && (r[i++] = s[--len]))
        ;
    r[i] = '\0';
}
