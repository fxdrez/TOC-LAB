#include <stdio.h>
#include <string.h>

int main()
{
    printf("DFA Accepting Binary Strings of Even Length\n");

    int state = 0; // Q0 = even, Q1 = odd
    char input[100];

    printf("Enter the binary string: ");
    scanf("%s", input);

    int i;
    printf("Q%d,", state);

    for (i = 0; i < strlen(input); i++)
    {
        char ch = input[i];
        if (ch != '0' && ch != '1')
        {
            printf("\nInvalid character detected. Only 0 and 1 are allowed.\n");
            return 0;
        }

        if (state == 0)
        {
            state = 1; // move to odd
        }
        else
        {
            state = 0; // move to even
        }

        printf("Q%d,", state);
    }

    if (state == 0)
    {
        printf(" Accepted (Even length)\n");
    }
    else
    {
        printf(" Rejected (Odd length)\n");
    }

    return 0;
}
