#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int htoi2(char hex_string[]);

int htoi2(char hex_string[])
{
    int len;
    int i = 0;
    int n = 0;
    int hex_digit;
    
    len = strlen(hex_string)-1;
    while ((hex_digit = hex_string[i++]) != '\0') {
        if (isdigit(hex_digit)) {
            n += ((hex_digit - '0') * pow(16, len--));
        } else {
            n += ((hex_digit - 'a') + pow(16, len--));
        }
    }
    
    return n;
}



main()
{
    char hex[] = "145";
    int as_number;
    as_number = htoi2(hex);
    printf("%s -> %d\n", hex, as_number); 
    return 0;
}





