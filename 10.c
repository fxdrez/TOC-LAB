#include <stdio.h>
#include <string.h>

int main()
{
    char tape[100];
    int i, j, len;
    int accept = 1;

    printf("Enter a string (only a's followed by b's): ");
    scanf("%s", tape);

    len = strlen(tape);

    // Step 1: Check format (all a's then all b's)
    i = 0;
    while (i < len && tape[i] == 'a')
        i++;
    while (i < len && tape[i] == 'b')
        i++;
    if (i != len)
    {
        printf("Rejected: String not in form a^n b^m.\n");
        return 0;
    }

    // Step 2: TM simulation
    while (1)
    {
        // find first 'a'
        for (i = 0; i < len; i++)
        {
            if (tape[i] == 'a')
            {
                tape[i] = 'X'; // mark
                break;
            }
        }

        if (i == len)
        {
            // No 'a' left, check if any 'b' remains
            for (j = 0; j < len; j++)
            {
                if (tape[j] == 'b')
                {
                    accept = 0;
                    break;
                }
            }
            break;
        }

        // find last 'b'
        for (j = len - 1; j >= 0; j--)
        {
            if (tape[j] == 'b')
            {
                tape[j] = 'Y'; // mark
                break;
            }
        }

        if (j < 0 || j < i)
        {
            accept = 0;
            break;
        }
    }

    if (accept)
        printf("Accepted: String belongs to {a^n b^n | n >= 1}\n");
    else
        printf("Rejected: String does not belong to {a^n b^n | n >= 1}\n");
    printf("Nirmal Gajurel");
    return 0;
}
