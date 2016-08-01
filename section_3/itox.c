#include <string.h>
#include <stdio.h>

#define MAXLINE 1000

void itoa(int i, char s[], int padding_len);
void itob(int i, char s[], int b);
void reverse(char s[]);
int power(int base, int n);
void apt_to_str(char input[], char output[], int b);


main()
{
    int i = 76;
    char s[] = "000000000";
    itoa(i, s, 6);
    printf("itoa: %s\n", s);
    
    itob(i, s, 12);
    printf("itob, b=12: %s\n", s);
        
    itob(i, s, 2);
    printf("itob, b=2: %s\n", s);

    itob(76, s, 16);
    printf("itob, b=16: %s\n", s);

    itob(566, s, 21);
    printf("itob, b=21: %s\n", s);

    char s1[] = "4c";
    char s2[] = "000000000";
    apt_to_str(s1, s2, -1);
    printf("apt str: %s\n", s2);

}

/* exercise 3-6:  convert n to characters in s */
void itoa(int n, char s[], int padding_len)
{
    int i, sign;

    if ((sign = n) < 0) /* record sign */
        n = -n; /* make n positive */
    i = 0;
    do { /* generate digits in reverse order */
        s[i++] = n % 10 + '0';  /* get next digit */
    } while ((n /= 10) > 0); /* delete it */
    if (sign < 0) 
        s[i++] = '-';
    while (i < padding_len)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

void itob(int n, char s[], int b) 
{
    
    int i, k, sign, tmp;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        tmp = n % b;
        if (tmp > 9)
            tmp = tmp - 10 + 'a';
        else
            tmp = tmp + '0';
        s[i++] = tmp; /* get number string */
    } while ((n /= b) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void apt_to_str(char input[], char output[], int b)
{
    int n, i, tmp;
    n = 0;
    reverse(input); /* we're going to go backwards and build our number*/
    if (b < 0) {
        if (isalpha(input[0])) {
            /* set base from trailing alpha char in input */
            b = input[0] - 'a' + 11; /* because we're zero indexed */
            tmp = b - 1;
            printf("%d\n", b);
        }
        else {
            b = 2; /* gee thanks */
            tmp = input[0] - '0' + 10;
        }
    }
    i = 0;
    while (input[i] != '\0') {
        printf("%d, %d, %d\n", input[i], tmp, power(b, i));
        n += tmp * power(b, i);
        tmp = input[++i] - '0';
    }
    itoa(n, output, 0);
}

int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}

void reverse(char s[]) 
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
