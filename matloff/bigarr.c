#include <stdio.h>
#include <stdlib.h>

main()
{
    unsigned long *ptr;
    // ptr = (unsigned long*)malloc(4294967294 * sizeof(unsigned long));
    ptr = (unsigned long*)malloc(1294967000 * sizeof(unsigned long));
    printf("allocated.\n");
    
    unsigned long i = 0;
    while (i < 1294967000) {// 4294967294)
        *ptr = i;
        ptr++;
        i++;
    }
    printf("all done.\n");
    free(ptr - i);
}
