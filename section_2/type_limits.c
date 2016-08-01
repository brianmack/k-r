#include <stdio.h>
#include <limits.h>
#include <float.h>

main()
{
    printf("char max = %d\n", CHAR_MAX);
    printf("char min = %d\n", CHAR_MIN);
    
    printf("char max = %d\n", SHRT_MAX);

    printf("int max = %d\n", INT_MAX);
    printf("int min = %d\n", INT_MIN);

    printf("float dig = %d\n", FLT_DIG);
    const i = 2147483650.f;
    printf("i = %d\n, i - int = %d\n", i, i - SHRT_MAX);
    return 0;
}
