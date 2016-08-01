#include <stdio.h>
#include <string.h>

#define MAXLEN 1000 /* max length of any input line */


int getline(char *, int);
void writelines(char *lineptr[], int nlines);


/* tail:  takes parameter -n for number of lines to print */
int main(int argc, char *argv[])
{
    
    /* read args to get number of lines */
    if (argc == 0)
        printf("Usage: tail -n <num lines>\n");

    writelines(argv, argc);

    int c;
    int nlines = 10;
    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        nlines = atoi(argv[2]);
    if (nlines < 1) {
        printf("number of lines must be > 0\n");
        return 1;
    }


    /* allocate storage for lines */
    char *lines[nlines];
    char linebuf[nlines * MAXLEN];
    char *p = &linebuf[0];

    /* read file, cycling lines through storage */
    int line_ct;
    while ((getline(p, MAXLEN)) > 0) {
    
        *(p-1) = '\0'; /* delete newline */
        /* linebuf[line_ct % nlines] = p; */
        *(*lines + line_ct % nlines) = p;
        
        p += MAXLEN;
        if (p > &linebuf[0] + nlines * MAXLEN)
            *p = &linebuf[0];
            
    }
    

    /* print lines in storage */
    writelines(lines, nlines);
}


/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* getline: specialized version */
int getline(char *line, int lim)
{
    int c, len;
    char *start = line;
    
    for (len = 0; len < lim-1
        && (c=getchar()) != EOF && c != '\n'; ++len)
        *line++ = c;
    if (c == '\n') {
        *line++ = '\n';
        ++len;
    }
    *line = '\0';
    return len;
}

