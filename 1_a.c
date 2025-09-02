#include <stdio.h>
#include <conio.h>
#include <string.h>
int main()
{
    printf("DFA Accepting Binary Strings Start with 0 and End with 1");
    int state = 0, state1;
    char input[10];
    printf("\nEnter the binary string :");
    gets(input);
    int i;
    printf("Q%d,", state);
    for (i = 0; i < strlen(input); i++)
    {
        char ch = input[i];
        if (state == 0)
        {
            if (ch == '0')
            {
                state = 1;
            }
            else
            {
                state = 3;
            }
        }
        else if (state == 1)
        {
            if (ch == '0')
            {
                state = 1;
            }
            else
            {
                state = 2;
            }
        }
        else if (state == 2)
        {
            if (ch == '0')
            {
                state = 1;
            }
            else
            {
                state = 2;
            }
        }
        else if (state1 == 3)
        {
            state = 3;
        }
        printf("Q%d,", state);
    }
    if (state == 2)
    {
        printf("Accepted");
    }
    else
    {
        printf("Rejected");
    }
    return 0;
}
