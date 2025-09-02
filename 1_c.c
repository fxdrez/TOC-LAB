#include <stdio.h>
#include <string.h>

int main()
{
    printf("DFA Accepting Binary Strings where each 0 is always followed by 1\n");

    int state = 0; // Q0 = start/accept, Q1 = saw 0, Qdead = 2
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

        if (state == 0) // Q0
        {
            if (ch == '0')
                state = 1; // expect 1 next
            else
                state = 0; // stay
        }
        else if (state == 1) // Q1
        {
            if (ch == '1')
                state = 0; // valid pair 01 → back to Q0
            else
                state = 2; // Qdead
        }
        else if (state == 2) // Qdead
        {
            state = 2; // remain trapped
        }

        printf("Q%d,", state);
    }

    if (state == 0)
    {
        printf(" Accepted (Every 0 is followed by 1)\n");
    }
    else
    {
        printf(" Rejected (Some 0 not followed by 1)\n");
    }

    return 0;
}
