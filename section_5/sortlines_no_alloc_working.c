#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define LINELEN 100

int getline(char *line, int lim);
int readlines(char *lineptr[], char *p, int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);
void qsort(char *v[], int i, int j);
/*void strcpy(char *, char *);
int strcmp(char *, char *);
int strlen(char *); */
void afree(char *p); /* free storage pointed to by p */
char *alloc(int);

static char *lineptr[MAXLINES];

static char line_arr[MAXLINES * LINELEN];
static char *line_arr_p = line_arr; /* &line_arr[0] */

/* sort input lines */
main()
{
    int nlines;

    if ((nlines = readlines(lineptr, line_arr_p, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1); 
        writelines(lineptr, nlines); 
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
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


#define MAXLEN 1000 /* max length of any input line */

/* readlines: read input lines 
    lineptr: array of pointers to beginning of lines
    p: pointer to space in array owned by calling function
    maxlines: max number of lines to read */
int readlines(char *linep[], char *p, int maxlines)
{
    int len, nlines;

    nlines = 0;
    while ((len = getline(p, MAXLEN)) > 0) {
        
        if (nlines >= maxlines) {
            return -1;
        } else {
            *(p-1) = '\0'; /* delete newline */
            linep[nlines++] = p;
            /* printf("%x, %s", p, linep[nlines-1]); */
            p += len;
        }
    }
    return nlines;
}


/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */


char *alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    } else 
        return 0;
}

void afree(char *p) /* free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}



void qsort(char *v[], int left, int right)
{
    int i, last;

    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
