#include <stdio.h>


int endian();

main()
{
    endian();
}

/* Returns 1 if the machine is little-endian, else 0 */
endian()
{
    int x;
    char *PC;

    x = 1;
    PC = (char *) &x;
    printf("%s\n", *PC ? "this machine is little endian" : "big endian");
    return *PC;
}

