#include <stdio.h>
#include <string.h>

int main()
{
    char tape[100];
    int left, right;
    int len;
    int accept = 1;

    printf("Enter a binary string: ");
    scanf("%s", tape);

    len = strlen(tape);

    // Validate binary characters
    for (int i = 0; i < len; i++)
    {
        if (tape[i] != '0' && tape[i] != '1')
        {
            printf("Rejected: Not a binary string.\n");
            return 0;
        }
    }
    
    // Check even length
    if (len % 2 != 0)
    {
        printf("Rejected: Length is odd.\n");
        return 0;
    }

    left = 0;
    right = len - 1;

    while (left < right)
    {
        // Compare left and right
        if (tape[left] != tape[right])
        {
            accept = 0;
            break;
        }
        left++;
        right--;
    }

    if (accept)
    {
        printf("Accepted: Palindrome of even length.\n");
    }
    else
    {
        printf("Rejected: Not a palindrome of even length.\n");
    }

    return 0;
}
