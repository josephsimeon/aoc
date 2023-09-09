#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef enum {
    No_Direction,
    Left,
    Right,
} Direction_e;

typedef enum {
    North,
    East,
    South,
    West,
} Compass_e;

const char puzzle_input[] = "R3, L5, R2, L2, R1, L3, R1, R3, L4, R3, L1, L1, R1, L3, R2, L3, L2, R1, R1, L1, R4, L1, L4, R3, L2, L2, R1, L1, R5, R4, R2, L5, L2, R5, R5, L2, R3, R1, R1, L3, R1, L4, L4, L190, L5, L2, R4, L5, R4, R5, L4, R1, R2, L5, R50, L2, R1, R73, R1, L2, R191, R2, L4, R1, L5, L5, R5, L3, L5, L4, R4, R5, L4, R4, R4, R5, L2, L5, R3, L4, L4, L5, R2, R2, R2, R4, L3, R4, R5, L3, R5, L2, R3, L1, R2, R2, L3, L1, R5, L3, L5, R2, R4, R1, L1, L5, R3, R2, L3, L4, L5, L1, R3, L5, L2, R2, L3, L4, L1, R1, R4, R2, R2, R4, R2, R2, L3, L3, L4, R4, L4, L4, R1, L4, L4, R1, L2, R5, R2, R3, R3, L2, L5, R3, L3, R5, L2, R3, R2, L4, L3, L1, R2, L2, L3, L5, R3, L1, L3, L4, L3"

int DetermineBlocksAwayFromHQ(char *input, int size_of_input);
int SearchForNextDirection(char *input, int size_of_input, int current_position);
Direction_e GetDirection(char direction);
int GetNumberOfSteps(char *input, int size_of_input, int direction_position);
bool IsNumber(char number);
int GetBlocksAwayFromPosition(Direction_e direction, int number_of_steps);
int CalculateBlocksAwayFromPosition(int x, int y);

int main (void)
{
    printf("Easter bunny HQ is %i blocks away.\n", DetermineBlocksAwayFromHQ((char *)practice_input_1, sizeof(practice_input_1)));
}

int DetermineBlocksAwayFromHQ(char *input, int size_of_input)
{
    int blocks_away = 0;
    
    for (int i = 0; i < size_of_input; ) {
        i = SearchForNextDirection(input, size_of_input, i);

        Direction_e direction = GetDirection(input[i]);

        if (direction != No_Direction) {
            int number_of_steps = GetNumberOfSteps(input, size_of_input, i);

            blocks_away = GetBlocksAwayFromPosition(direction, number_of_steps);
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
        if (IsNumber(input[i])) {
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
    return (number >= '0' && number <= '9');
}

int GetBlocksAwayFromPosition(Direction_e direction, int number_of_steps)
{
    static Compass_e compass = North;
    static int x = 0, y = 0;

    if (compass == North && direction == Right) {
        compass = East;
        x += number_of_steps;
    } else if (compass == North && direction == Left) {
        compass = West;
        x -= number_of_steps;
    } else if (compass == East && direction == Right) {
        compass = South;
        y -= number_of_steps;
    } else if (compass == East && direction == Left) {
        compass = North;
        y += number_of_steps;
    } else if (compass == South && direction == Right) {
        compass = West;
        x -= number_of_steps;
    } else if (compass == South && direction == Left) {
        compass = East;
        x += number_of_steps;
    } else if (compass == West && direction == Right) {
        compass = North;
        y += number_of_steps;
    } else if (compass == West && direction == Left) {
        compass = South;
        y -= number_of_steps;
    }

    return CalculateBlocksAwayFromPosition(x, y);
}

int CalculateBlocksAwayFromPosition(int x, int y)
{
    if (x < 0) {
        x *= -1;
    }

    if (y < 0) {
        y *= -1;
    }

    return (x + y);
}
