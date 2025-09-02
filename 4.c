#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[50], lhs, rhs[40][20];
    int n, i, j, k = 0, betaCount = 0, alphaCount = 0;
    char alpha[20][20], beta[20][20];

    printf("Enter Left Recursive Production :\n");
    scanf("%s", input);

    lhs = input[0]; // LHS non-terminal

    // Extract RHS (everything after ->)
    char *rhsStr = strchr(input, '>') + 1;

    // Split RHS by "|"
    char *token = strtok(rhsStr, "|");
    while (token != NULL)
    {
        strcpy(rhs[k++], token);
        token = strtok(NULL, "|");
    }
    n = k;

    // Separate into alpha and beta
    for (i = 0; i < n; i++)
    {
        if (rhs[i][0] == lhs)
        {
            // Aα → store α
            for (j = 1; rhs[i][j] != '\0'; j++)
            {
                alpha[alphaCount][j - 1] = rhs[i][j];
            }
            alpha[alphaCount][j - 1] = '\0';
            alphaCount++;
        }
        else
        {
            // β → store β
            strcpy(beta[betaCount++], rhs[i]);
        }
    }

    // If no left recursion
    if (alphaCount == 0)
    {
        printf("The grammar has no left recursion.\n");
        return 0;
    }

    // Print transformed grammar
    printf("\nGrammar after removing Left Recursion:\n");

    // Rule for A
    printf("%c -> ", lhs);
    for (i = 0; i < betaCount; i++)
    {
        printf("%s%c'", beta[i], lhs);
        if (i != betaCount - 1)
            printf(" | ");
    }

    // Rule for A'
    printf("\n%c' -> ", lhs);
    for (i = 0; i < alphaCount; i++)
    {
        printf("%s%c' | ", alpha[i], lhs);
    }
    printf("ep\n"); // epsilon written as ep

    return 0;
}
