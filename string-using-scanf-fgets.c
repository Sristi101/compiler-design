#include <stdio.h>

int main()
{
    char str[100];
    char sub_str[100];

    printf("Enter a string: ");

    fgets(str, sizeof(str), stdin);
    sscanf(str, "%99s", sub_str);

    printf("Using scanf: %s\n", sub_str);
    printf("Using fgets: %s", str);

    // we can also take first character
    printf("First character of our input: %c", sub_str[0]);

    return 0;
}

