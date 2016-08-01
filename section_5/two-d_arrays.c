#include <stdio.h>


static char arr[2][10] = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
    {10, 11, 12, 13, 14, 15, 16, 17, 18, 19}
};


int main()
{
    
    printf("arr[0][5] = %d\n", arr[0][5]);
    printf("arr[1][5] = %d\n", arr[1][5]);

    /* garbage value */
    printf("arr[15] = %d\n", arr[15]); 

    //char *arrp = &arr[0][0];
    char *arrp = *arr;

    /* but this works */
    printf("arrp + 15 = %d\n", *arrp + 15);

    int i;
    for (i = 0; i < 20; i++) { 
        printf("%d\n", *arrp++);
    }



}
