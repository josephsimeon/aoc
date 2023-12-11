//! @file       day_1.c
//! @brief      first part of the challenge is to find the first and last digit of each
//!             string and then sum them all together
//!
//! @author     Joseph Simeon
//! @date       11/12/2023 19:48
//! @url        https://github.com/josephsimeon/aoc/2023

#include "../../common/puzzle.h"

typedef struct {
    char first_digit;
    char second_digit;
} puzzle_output_string_digits_t;

int main (void)
{
    FILE* pointer_to_puzzle_file = fopen("puzzle.txt", "r");
    CheckValidityOfPuzzleFile(pointer_to_puzzle_file);

    puzzle_output_t* pointer_to_puzzle_output;

    do {

        pointer_to_puzzle_output = GetStringFromPuzzleFile(pointer_to_puzzle_file);

        // todo process the information finding 

    } while (IsPuzzleFileStillValid());

    return 0;
}
