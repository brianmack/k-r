#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned setbits(unsigned, int, int, int);
unsigned getbits(unsigned, int, int);
char * int2bin(int);
int bitcount(unsigned);

/* these bit operations are new to me so I'm printing out 
    everything covered in the text */
main()
{

    /* test mask */
    unsigned n = 271;
    printf("%s\n", int2bin(n));
    printf("%s in octal ->\n%s in bits\n", "0177", int2bin(0177));
    printf("mask all but low-order 7 bits:\n%s\n", int2bin(n & 0177));
    printf("makes number:\n%d -> %d\n", n, n & 0177);

    /* set bits on */
    printf("set on low-order 7 bits:\n%s\n", int2bin(n | 0177));
    printf("makes number:\n%d -> %d\n", n, n | 0177);
    
    /* compliment */
    printf("compliment on low-order 6 bits:\n%s\n", int2bin(n & ~077));
    printf("makes number:\n%d -> %d\n", n, n & ~077);
    
    printf("\v");
    
    /* shift right by 4 */
    printf("%s\n", int2bin(n >> 4));
    printf("%s\n", int2bin(4));
    printf("%s\n", int2bin(4 << 1));
    printf("%s\n", int2bin(4 << 2));
    printf("%d\n", n);
    /* shift is masked to 5 bits by intel processor 
        http://stackoverflow.com/questions/3871650/gcc-left-shift-overflow */
    printf("%s\n", int2bin(4 << n));
    /* shift right by 2 */
    printf("%s\n", int2bin(n >> 2));
    
    /* shift left by 4 */
    printf("%s\n", int2bin(n << 4));
    /* shift left by 2 */
    printf("%s\n", int2bin(n << 2));
    
    /* now piece apart what the getbits function is doing. */
    printf("\vwhat is getbits doing...\n");
    printf("getbits for n, 5, 4 (0111): %u\n", getbits(n,5,4));
    printf("shift n right by 2 -\n%s\n", int2bin(n >> (5+1-4)));
    printf("shift 1's left by 4 -\n%s\n", int2bin(~0 << 4));
    printf("invert that to make mask -\n%s\n", int2bin(~(~0 << 4)));
    printf("combine it -\n%s\n", int2bin((n >> 2) & ~(~0 << 4)));

    int p = 4;
    int nb = 2;
    int source = 2;
    printf("\v");
    printf("setbits n=%d, p=%d, nb=%d, source=%d ->\n",
        n, p, nb, source);
    printf("original-\n%s\n", int2bin(n));
    printf("mask 1-\n%s\n", int2bin(~0 << (p+nb)));
    printf("mask 2-\n%s\n", int2bin(~0 << p));
    printf("mask 1^2 -\n%s\n", 
        int2bin(~(~0 << (p+nb) ^ ~0 << p)));
    printf("n & 1^2 -\n%s\n", 
        int2bin(n & ~(~0 << (p+nb) ^ ~0 << p)));
    
    printf("source %s\n", int2bin(source));
    printf("source %d shifted << %d-\n%s\n", source, p,
        int2bin(getbits(source, nb-1, nb) << p+1-nb));
    printf("set on-\n%s\n", int2bin(
        (n & ~(~0 << (p+nb) ^ ~0 << p)) | 
        (getbits(source, nb-1, nb) << p+1-nb)  
    ));
    printf("with func-\n%s\n", int2bin(setbits(n, p, nb, source)));
    printf("with func-\n%s\n", int2bin(setbits(-n, p, nb, source)));
    printf("original-\n%s\n", int2bin(-n));
    printf("original-\n%s\n", int2bin(n));

    bitcount(298);
}


/* returns x with the n bits that begin at position p set to the 
    rightmost n bits of y, leaving the other bits unchanged. */
unsigned setbits(unsigned x, int p, int n, int y)
{
    return x & ~(~0 << p+n ^ ~0 << p) | getbits(y, n-1, n) << p+1-n;
}


/* from the text: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    return x >> (p+1-n) & ~(~0 << n);
}


/* from: 
    http://stackoverflow.com/questions/1024389/
    print-an-int-in-binary-representation-using-c */
char * int2bin(int i)
{
    size_t bits = sizeof(int) * CHAR_BIT;

    char * str = malloc(bits + 1);
    if(!str) return NULL;
    str[bits] = 0;

    /* type punning because signed shift is implementation-defined */
    unsigned u = *(unsigned *)&i;
    for(; bits--; u >>= 1)
        str[bits] = u & 1 ? '1' : '0';

    return str;
}

int bitcount(unsigned x)
{
    int b = 0;

    printf("%s, %d, %d, \n", int2bin(x), 0, x);
    while (x!=0) {
        printf("x       = %s\n", int2bin(x));
        printf("x-1     = %s\n", int2bin(x-1));
        printf("x & x-1 = %s\n", int2bin(x & x-1));
        printf("\v");
        x = x & (x-1);
        ++b;
        printf("%s, %d, %d\n\v", int2bin(x), b, x);
    }
    return b;
}
