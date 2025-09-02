#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char c)
{
    if (top < MAX - 1)
    {
        stack[++top] = c;
    }
}

// Pop function
char pop()
{
    if (top >= 0)
    {
        return stack[top--];
    }
    return '\0';
}

int main()
{
    char input[50];
    int i, len;
    int valid = 1;

    printf("Enter a string (consisting of a's followed by b's): ");
    scanf("%s", input);

    len = strlen(input);

    // Step 1: Push all 'a's into stack
    i = 0;
    while (i < len && input[i] == 'a')
    {
        push('A');
        i++;
    }

    // Must have at least one 'a'
    if (i == 0)
    {
        printf("Rejected: No 'a' found.\n");
        return 0;
    }

    // Step 2: For each 'b', pop one 'A'
    while (i < len && input[i] == 'b')
    {
        if (pop() != 'A')
        {
            valid = 0;
            break;
        }
        i++;
    }

    // Step 3: Accept if fully consumed and stack is empty
    if (i == len && top == -1 && valid)
    {
        printf("Accepted: String belongs to {a^n b^n | n >= 1}\n");
    }
    else
    {
        printf("Rejected: String does not belong to {a^n b^n | n >= 1}\n");
    }

    return 0;
}
