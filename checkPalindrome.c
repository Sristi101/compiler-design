#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, length, flag = 1;

    printf("Enter a word: ");
    scanf("%99s", str);

    length = strlen(str);

    for (i = 0; i < length; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    }

    for (i = 0; i < length / 2; i++)
    {
        if (str[i] != str[length - i - 1])
        {
            flag = 0;
            break;
        }
    }

    if (flag)
    {
        printf("%s is a Palindrome.\n", str);
    }
    else
    {
        printf("%s is not a Palindrome.\n", str);
    }

    return 0;
}

