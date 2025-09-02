#include <stdio.h>
#include <string.h>

int main()
{
    printf("DFA Accepting Binary Strings that Never End with 1\n");

    int state = 0; // Q0 = accept, Q1 = reject
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
            if (ch == '0')
                state = 0; // stays in Q0
            else
                state = 1; // goes to Q1
        }
        else if (state == 1)
        {
            if (ch == '0')
                state = 0; // goes to Q0
            else
                state = 1; // stays in Q1
        }

        printf("Q%d,", state);
    }

    if (state == 0)
    {
        printf(" Accepted (Does not end with 1)\n");
    }
    else
    {
        printf(" Rejected (Ends with 1)\n");
    }

    return 0;
}
