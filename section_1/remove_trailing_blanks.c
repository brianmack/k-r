#include <stdio.h>
#define MAXLINE 1000 /* max input line size */

int getline(char line[], int maxline);
void cleanline(char to[], char from[]);
void reverse(char to_reverse[]);

/* print all input lines longer than 80 characters */
main()
{
    int len;
    
    char line[MAXLINE];
    
    while ((len = getline(line, MAXLINE)) > 80)
        printf("%s\n", line);

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

/* copy from into to; assume to is big enough */
void cleanline(char to[], char from[], int lineline)
{
    int i;

    i = 0;
    while (from[i] != '\0') {
        
        ++i;
}

void reverse(char s[])
{

    int ct = -1;
    while (s[++ct] != '\0')
        ;
    char r[ct];
    
    int i = 0;
    while (r[ct--] = s[i++] != '\0')
        ;
    return r
}

