
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Check whether a word is a keyword
int isKeyword(char word[]) {
    char keywords[][10] = {
        "int", "float", "char", "double",
        "void", "return", "if", "else",
        "while", "for"
    };

    for (int i = 0; i < 10; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

// Check operators
int isOperator(char ch) {
    return ch == '+' || ch == '-' ||
           ch == '*' || ch == '/' ||
           ch == '%' || ch == '=';
}

// Check special symbols
int isSpecialSymbol(char ch) {
    return ch == '(' || ch == ')' ||
           ch == '{' || ch == '}' ||
           ch == ';' || ch == ',';
}

// Recognize all tokens
void recognizeTokens(char input[]) {
    char word[100];
    int i = 0, j;

    while (input[i] != '\0') {

        // Ignore whitespace
        if (isspace((unsigned char)input[i])) {
            i++;
            continue;
        }

        // Recognize string literals
        if (input[i] == '"') {
            j = 0;
            word[j++] = input[i++];

            while (input[i] != '"' && input[i] != '\0') {
                word[j++] = input[i++];
            }

            if (input[i] == '"') {
                word[j++] = input[i++];
            }

            word[j] = '\0';

            printf("%s -> String Literal\n", word);
        }

        // Recognize keywords and identifiers
        else if (isalpha((unsigned char)input[i]) ||
                 input[i] == '_') {

            j = 0;

            while (isalnum((unsigned char)input[i]) ||
                   input[i] == '_') {
                word[j++] = input[i++];
            }

            word[j] = '\0';

            if (isKeyword(word)) {
                printf("%s -> Keyword\n", word);
            } else {
                printf("%s -> Identifier\n", word);
            }
        }

        // Recognize numbers
        else if (isdigit((unsigned char)input[i])) {
            j = 0;

            while (isdigit((unsigned char)input[i])) {
                word[j++] = input[i++];
            }

            word[j] = '\0';

            printf("%s -> Number\n", word);
        }

        // Recognize operators
        else if (isOperator(input[i])) {
            printf("%c -> Operator\n", input[i]);
            i++;
        }

        // Recognize special symbols
        else if (isSpecialSymbol(input[i])) {
            printf("%c -> Special Symbol\n", input[i]);
            i++;
        }

        // Unknown character
        else {
            printf("%c -> Unknown Token\n", input[i]);
            i++;
        }
    }
}

int main() {
    char input[1000];
    char line[200];

    printf("Enter your C program (type END to finish):\n");

    input[0] = '\0';

    while (fgets(line, sizeof(line), stdin)) {

        if (strcmp(line, "END\n") == 0 ||
            strcmp(line, "END") == 0) {
            break;
        }

        strcat(input, line);
    }

    printf("\n----- Recognized Tokens -----\n");

    recognizeTokens(input);

    return 0;
}
