#include <stdio.h>


#define MAXLEN 1000000

void getinput(char *);


main()
{
    
    char buf[MAXLEN];
    char *bufp = buf;
    
    getinput(bufp);
    printf("%x, %x\n", &buf[0], bufp);
    printf("%d, %d\n", buf[0], *bufp);
    printf("%s\n", bufp);

}

void getinput(char *p)
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == ' ')
            continue;
        *p++ = c;
    }
    *p = '\0';
}
