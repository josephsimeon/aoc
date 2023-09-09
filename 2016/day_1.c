#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef enum {
    No_Direction,
    Left,
    Right,
} Direction_e;

const char practice_input_1[] = "R2, R2, R2";
const char practice_input_2[] = "R5, L5, R5, R3";

int DetermineBlocksAwayFromHQ(char *input, int size_of_input);
int SearchForNextDirection(char *input, int size_of_input, int current_position);
Direction_e GetDirection(char direction);
int GetNumberOfSteps(char *input, int size_of_input, int direction_position);
bool IsNumber(char number);

int main (void)
{
    printf("Easter bunny HQ is %i blocks away. /n", DetermineBlocksAwayFromHQ((char *)practice_input_1, sizeof(practice_input_1)));
}

int DetermineBlocksAwayFromHQ(char *input, int size_of_input)
{
    int blocks_away = 0;
    
    for (int i = 0; i < size_of_input; ) {
        i = SearchForNextDirection(input, size_of_input, i);

        Direction_e direction = GetDirection(input[i]);

        if (direction != No_Direction) {
            int number_of_steps = GetNumberOfSteps(input, size_of_input, i);
        }

        // increase i by 1, move a position higher than the currently found direction
        i++;
    }

    return blocks_away;
}

int SearchForNextDirection(char *input, int size_of_input, int current_position)
{
    for (int i = current_position; i < size_of_input; i++) {
        if (input[i] == 'R' || input[i] == 'L') {
            return i;
        }
    }

    return size_of_input;
}

Direction_e GetDirection(char direction)
{
    if (direction == 'L') {
        return Left;
    } else if (direction == 'R') {
        return Right;
    } else {
        return No_Direction;
    }
}

int GetNumberOfSteps(char *input, int size_of_input, int direction_position)
{
    int number_of_steps = 0;
    
    for (int i = direction_position + 1; i < size_of_input; i++) {
        if (IsNumber(input[i]) {
            // increase number of steps by 10 for the next number to be added
            number_of_steps *= 10;
            // add in the number, offset to its int value by subtracting '0' ascii
            number_of_steps += (input[i] - '0');
        } else {
            return number_of_steps;
        }
    }
}

bool IsNumber(char number)
{
    return (number >= '0' && number =< '9');
}
