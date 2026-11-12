#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];

    printf("Enter a string: ");

    fgets(str, sizeof(str), stdin);

    printf("String entered: %s", str);

    printf("Length including newline: %lu\n", strlen(str));

    return 0;
}