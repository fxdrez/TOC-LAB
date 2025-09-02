#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char c)
{
    if (top < MAX - 1)
    {
        stack[++top] = c;
    }
}

// Pop
char pop()
{
    if (top >= 0)
    {
        return stack[top--];
    }
    return '\0'; // empty stack
}

int main()
{
    char input[50];
    int len, i, mid;
    int valid = 1;

    printf("Enter a binary string: ");
    scanf("%s", input);

    len = strlen(input);

    // Check odd length
    if (len % 2 == 0)
    {
        printf("Rejected: String length is even, not allowed.\n");
        return 0;
    }

    mid = len / 2;

    // Step 1: Push first half into stack
    for (i = 0; i < len; i++)
    {
        if (input[i] != '0' && input[i] != '1')
        {
            printf("Rejected: Not a binary string.\n");
            return 0;
        }
        push(input[i]);
    }

    // Step 2: Skip middle symbol (any 0 or 1 allowed)
    i = mid + 1;

    // Step 3: Match second half with stack
    while (i < len)
    {
        char c = pop();
        if (c != input[i])
        {
            valid = 0;
            break;
        }
        i++;
    }

    // Accept if all matched and stack is empty
    if (valid && top == -1)
    {
        printf("Accepted: Palindrome of odd length.\n");
    }
    else
    {
        printf("Rejected: Not a palindrome of odd length.\n");
    }

    return 0;
}
