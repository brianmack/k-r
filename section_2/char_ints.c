#include <stdio.h>

/* print the numeric representation of digits. */

main()
{
    int c, i;
    i = 0;
    
    /* internal representation of strings has \0 at end. */
    while ((c="0123456789ABCDEFGabcdefg"[i++]) != '\0')
        printf("%d\n", c);
    
    i = "d" - "b";
    printf("\v%d\n", i);
    printf("\vhex a = %d\n", 0xa);
    printf("hex A = %d\n", 0xA);
    printf("hex b = %d\n", 0xb);
    printf("a = %d\n", 'a');
    printf("f = %d\n", 'f');
    printf("hex b - a = %d\n", 'b' - 'a');
    printf("hex b converted == hex b %d\n", ('b' - 'a' + 0xa)==0xb);
    printf("hex 0 = %d\n", 0x0);
    printf("hex 3 = %d\n", 0x3);
    printf("hex 122f = %d\n", 0x122f);
    
    return 0;
}
