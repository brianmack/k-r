#include <stdio.h>

void strcat(char*, char*);
int strend(char*, char*);
// void strncopy(char *, char *, int);
void strcopy(char*, char*);
void reverse(char*);

main()
{
    char s[100] = "my program";
    char t[100] = "program";
    
    /* copy t onto s */
    strcat(s, t);
    printf("s w t cat = %s\n", s);
    printf("t orig = %s\n", t);

    int found;
    found = strend(s, t);
    printf("substr found - %d\n", found);
    
    printf("before reversed: %s\n", s);
    reverse(s);
    printf("reversed: %s\n", s);


}

void strcopy(char* s, char* t)
{
    while (*s++ = *t++)
        ;
}

void strcat(char* s, char* t)
{
    while (*s++)
        ;
    *s--;
    while (*s++ = *t++)
        ;
}


int strend(char* s, char* t)
{
    char *t_orig;
    t_orig = t;
    printf("t @ %d, t_orig @ %d\n", t, t_orig);
    while (*s)
        s++;
    while (*t)
        t++;
    printf("before loop: t @ %d, t_orig @ %d\n", t, t_orig);
    while (*t == *s && t > t_orig) {
        t--;
        s--;
        printf("\tt @ %d, t_orig @ %d\n", t, t_orig);
        printf("\t %d, %d\n", *t, *s);
        //;
    }
    printf("after loop: t @ %d, t_orig @ %d\n", t, t_orig);
    if (t_orig == t)
        return 1;
    return 0;
}

void reverse(char* s)
{
    char* end = s;
    printf("got string %d\n", *s);
    printf("before inc %d, %d\n", s, end);
    while (*++end)
        ;
    end--; 
    
    printf("after inc %d, %d\n", s, end);
    printf("start, end - %d, %d\n", *s, *end);
    printf("end-start= %d\n", end - s);
    

    char* tmp;
    while (end - s > 2) {
        printf("start, end - %d, %d\n", s, end);
        *tmp = *s;
        *s++ = *end;
        *end-- = *tmp;
    }
    printf("%d, %d\n", s, end);
    printf("%d\n", *s);
}

/*
void strncpy(char *s, char *t, int n)
{
    while ((*s++ = *t++) < n)


}

*/
