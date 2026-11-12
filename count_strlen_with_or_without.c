#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int length = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Without using strlen()
    while (str[length] != '\0')
    {
        length++;
    }

    // Removing newline character
    if (str[length - 1] == '\n')
    {
        length--;
    }

    printf("Length without strlen(): %d\n", length);

    // Using strlen()
    printf("Length using strlen(): %lu\n", strlen(str) - 1);

    return 0;
}



