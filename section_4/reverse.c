#include <stdio.h>

void printd(int);
void swap(int [], int, int);
void reverse(char [], int, int);
int itoa(int, char [], int);

int main()
{
    char s[] = "brian";
    printf("%s\n", s);
    reverse(s, 0, 4);
    printf("%s\n", s);
    
    printf("%d\n", 104 / 10);
    printf("%d\n", 104 % 10);
    printd(104);
    printf("\n");
    itoa(34, s, 0);
    printf("%s\n", s);
    return 0;
}


/* convert an integer into a string by recursive calls */
int itoa(int n, char s[], int i)
{
    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }

    if (n / 10)
        i = itoa(n / 10, s, i);

    s[i++] = (n % 10) + '0';
    s[i] = '\0';

    return i;
}

/* print n in decimal */
void printd(int n)
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}


/* reverse a string in place using recursive function call */
void reverse(char s[], int start, int end)
{
    int tmp;
    
    if (end - start < 2)
        return;
    
    tmp = s[start];
    s[start] = s[end];
    s[end] = tmp;
    reverse(s, start+1, end-1);
}
