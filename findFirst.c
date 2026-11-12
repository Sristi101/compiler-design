
#include <stdio.h>
#include <string.h>

#define MAX 20

char lhs[MAX][10];
char rhs[MAX][50];

int productionCount;

// Read grammar productions
void readGrammar() {
    char line[100];

    printf("Enter number of productions: ");
    scanf("%d", &productionCount);

    getchar(); // Remove leftover newline

    for (int i = 0; i < productionCount; i++) {
        printf("Production %d: ", i + 1);

        fgets(line, sizeof(line), stdin);

        // Remove newline
        line[strcspn(line, "\n")] = '\0';

        // Separate left and right sides
        sscanf(line, " %[^=] = %[^\n]", lhs[i], rhs[i]);

        // Remove spaces from left side
        lhs[i][strcspn(lhs[i], " ")] = '\0';
    }
}

// Find FIRST of a non-terminal
void findFirst(char symbol) {
    char firstSet[MAX];
    int count = 0;

    for (int i = 0; i < productionCount; i++) {

        if (lhs[i][0] == symbol) {

            char first = rhs[i][0];

            // Check for duplicate
            int found = 0;

            for (int j = 0; j < count; j++) {
                if (firstSet[j] == first) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                firstSet[count++] = first;
            }
        }
    }

    printf("\nFIRST(%c) = { ", symbol);

    for (int i = 0; i < count; i++) {
        printf("%c", firstSet[i]);

        if (i < count - 1) {
            printf(", ");
        }
    }

    printf(" }\n");
}

int main() {
    char symbol;

    readGrammar();

    printf("\nEnter non-terminal: ");
    scanf(" %c", &symbol);

    findFirst(symbol);

    return 0;
}
