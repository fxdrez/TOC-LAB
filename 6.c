#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a symbol is non-terminal (Uppercase)
int isNonTerminal(char c)
{
    return (c >= 'A' && c <= 'Z');
}

// Function to check if a symbol is terminal (Lowercase)
int isTerminal(char c)
{
    return (c >= 'a' && c <= 'z');
}

int main()
{
    char production[50];
    char lhs, *rhs;
    int isLeft = 0, isRight = 0;

    printf("Enter a production : ");
    scanf("%s", production);

    // Validate LHS
    if (!(isNonTerminal(production[0]) && production[1] == '-' && production[2] == '>'))
    {
        printf("Invalid production format.\n");
        return 0;
    }

    lhs = production[0];
    rhs = production + 3; // RHS

    int len = strlen(rhs);

    // Case: A -> single terminal (valid for both)
    if (len == 1 && isTerminal(rhs[0]))
    {
        printf("The production is both Left Linear and Right Linear (trivial case).\n");
        return 0;
    }

    // Check Left Linear: starts with Non-terminal, then terminals
    if (isNonTerminal(rhs[0]))
    {
        int ok = 1;
        for (int i = 1; i < len; i++)
        {
            if (!isTerminal(rhs[i]))
            {
                ok = 0;
                break;
            }
        }
        if (ok)
            isLeft = 1;
    }

    // Check Right Linear: terminals first, then maybe one Non-terminal at end
    if (isNonTerminal(rhs[len - 1]))
    {
        int ok = 1;
        for (int i = 0; i < len - 1; i++)
        {
            if (!isTerminal(rhs[i]))
            {
                ok = 0;
                break;
            }
        }
        if (ok)
            isRight = 1;
    }

    // Output result
    if (isLeft && !isRight)
    {
        printf("The production is Left Linear.\n");
    }
    else if (isRight && !isLeft)
    {
        printf("The production is Right Linear.\n");
    }
    else if (isLeft && isRight)
    {
        printf("The production is both Left Linear and Right Linear (rare case).\n");
    }
    else
    {
        printf("The production is NOT Linear.\n");
    }

    return 0;
}
