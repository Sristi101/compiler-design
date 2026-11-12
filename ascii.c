#include <stdio.h>

int main()
{
    char input[100];

    printf("Enter a single character: ");
    fgets(input, sizeof(input), stdin);

    // Check whether exactly one character was entered
    if (input[0] == '\n' || input[1] != '\n')
    {
        printf("Error: Please enter exactly one character.\n");
        return 1;
    }

    printf("Character: %c\n", input[0]);
    printf("ASCII Value: %d\n", (unsigned char)input[0]);

    if (input[0] >= '0' && input[0] <= '9')
    {
        printf("It is a Digit.\n");
    }
    else if ((input[0] >= 'A' && input[0] <= 'Z') ||
             (input[0] >= 'a' && input[0] <= 'z'))
    {
        printf("It is an Alphabet.\n");
    }
    else
    {
        printf("It is a Special Character.\n");
    }

    return 0;
}


