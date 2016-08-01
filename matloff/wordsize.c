#include <stdio.h>
#include <inttypes.h>

main()
{

    printf("size of int = %lu bytes\n", sizeof(int));
    printf("size of long int = %lu bytes\n", sizeof(long));
    printf("size of long long int = %lu bytes\n", sizeof(long long));
    printf("size of uintmax_t = %lu bytes\n", sizeof(uintmax_t));

}
