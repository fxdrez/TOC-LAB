#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if character is non-terminal (Uppercase letter)
int isNonTerminal(char c)
{
    return (c >= 'A' && c <= 'Z');
}

// Function to check if character is terminal (Lowercase letter)
int isTerminal(char c)
{
    return (c >= 'a' && c <= 'z');
}

int main()
{
    char production[20];
    int len;

    printf("Enter a production (Format _->__): ");
    scanf("%s", production);

    len = strlen(production);

    // Check for valid input format (A->...)
    if (!(isNonTerminal(production[0]) && production[1] == '-' && production[2] == '>'))
    {
        printf("Invalid production format.\n");
        return 0;
    }

    // RHS (right-hand side of production)
    char *rhs = production + 3;
    int rhsLen = strlen(rhs);

    // Case 1: A → BC  (two non-terminals)
    if (rhsLen == 2 && isNonTerminal(rhs[0]) && isNonTerminal(rhs[1]))
    {
        printf("The production is in CNF.\n");
    }
    // Case 2: A → a  (single terminal)
    else if (rhsLen == 1 && isTerminal(rhs[0]))
    {
        printf("The production is in CNF.\n");
    }
    // Case 3: S → ε  (nullable start symbol)
    else if (strcmp(rhs, "ep") == 0 && production[0] == 'S')
    {
        printf("The production is in CNF (epsilon allowed only for Start Symbol).\n");
    }
    else
    {
        printf("The production is NOT in CNF.\n");
    }

    return 0;
}
