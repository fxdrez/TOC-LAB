#include <stdio.h>
#include <string.h>

#define STATES 4
#define SYMBOLS 2 // input symbols: 0 and 1

// Transition table: transition[current_state][input_symbol]
int transition[STATES][SYMBOLS] = {
    {1, 2}, // q1: on '0' -> q2, on '1' -> q3 (dead)
    {1, 3}, // q2: on '0' -> q2, on '1' -> q4
    {2, 2}, // q3 (dead): loops to itself
    {1, 3}  // q4: on '0' -> q2, on '1' -> q4
};

int start_state = 0;      // q1
int final_states[] = {3}; // q4 is final
int final_count = 1;

int is_final(int state)
{
    for (int i = 0; i < final_count; i++)
    {
        if (final_states[i] == state)
            return 1;
    }
    return 0;
}

void print_state(int state)
{
    printf("q%d", state + 1);
}

void simulate_dfa(char *input)
{
    int current = start_state;
    printf("Processing string: %s\n", input);
    printf("Start at ");
    print_state(current);
    printf("\n");

    for (int i = 0; i < strlen(input); i++)
    {
        char symbol = input[i];
        int col = (symbol == '0') ? 0 : 1;
        printf("Read '%c' : ", symbol);
        print_state(current);
        current = transition[current][col];
        printf(" -> ");
        print_state(current);
        printf("\n");
    }

    if (is_final(current))
    {
        printf("Result: Accepted (ended in ");
        print_state(current);
        printf(")\n\n");
    }
    else
    {
        printf("Result: Rejected (ended in ");
        print_state(current);
        printf(")\n\n");
    }
}

int main()
{
    simulate_dfa("0000001101");
    simulate_dfa("100000010");
    return 0;
}
