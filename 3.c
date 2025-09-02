#include <stdio.h>
#include <string.h>

// Recursive function to generate leftmost derivation
void derive(char *str, int left, int right, char *current)
{
    if (left > right)
    {
        // epsilon, do nothing
        return;
    }

    if (left == right)
    {
        // Base case: single character (0 or 1)
        for (int i = 0; i < left; i++)
            printf("%c", str[i]); // prefix
        printf("%c", str[left]);  // middle
        for (int j = right + 1; j < strlen(str); j++)
            printf("%c", str[j]); // suffix
        printf("\n");
        return;
    }

    if (str[left] == '0' && str[right] == '0')
    {
        // Expand S -> 0S0
        for (int i = 0; i < left; i++)
            printf("%c", str[i]);
        printf("0S0");
        for (int j = right + 1; j < strlen(str); j++)
            printf("%c", str[j]);
        printf("\n");
        derive(str, left + 1, right - 1, current);
    }
    else if (str[left] == '1' && str[right] == '1')
    {
        // Expand S -> 1S1
        for (int i = 0; i < left; i++)
            printf("%c", str[i]);
        printf("1S1");
        for (int j = right + 1; j < strlen(str); j++)
            printf("%c", str[j]);
        printf("\n");
        derive(str, left + 1, right - 1, current);
    }
}

int main()
{
    char input[100];
    printf("Enter a binary string: ");
    scanf("%s", input);

    int n = strlen(input);
    int flag = 1;

    // Check if palindrome
    for (int i = 0; i < n / 2; i++)
    {
        if (input[i] != input[n - i - 1])
        {
            flag = 0;
            break;
        }
    }

    if (!flag)
    {
        printf("The string is not a palindrome. Derivation not possible.\n");
        return 0;
    }

    printf("Leftmost derivation for %s:\n", input);
    printf("S\n");

    if (n == 1)
    {
        printf("=> %c\n", input[0]); // single char case
    }
    else
    {
        derive(input, 0, n - 1, input);
        printf("=> %s\n", input); // final derived string
    }

    return 0;
}
