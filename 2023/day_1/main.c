//! @file       main.c
//! @brief      main file that access functions to complete the first day of 2023 aoc
//!
//! @author     Joseph Simeon
//! @date       11/12/2023 19:48
//! @url        https://github.com/josephsimeon/aoc/2023
//!
//! @date       Last updated: 12/12/2023 21:12

#include "day_1.h"

int main (void)
{
    FILE* pointer_to_puzzle_file = fopen("puzzle.txt", "r");
    CheckValidityOfPuzzleFile(pointer_to_puzzle_file);

    puzzle_output_t* pointer_to_puzzle_output;
    int sum = 0;

    // get the first line starting the process before entering into the loop
    pointer_to_puzzle_output = GetStringFromPuzzleFile(pointer_to_puzzle_file);
    while (IsPuzzleFileStillValid()) {
        puzzle_output_string_digits_t digits = ProcessPuzzleStringToFindDigits(pointer_to_puzzle_output);
        sum += ProcessCharacterDigitsToInteger(digits);
    
        pointer_to_puzzle_output = GetStringFromPuzzleFile(pointer_to_puzzle_file);
    }

    printf("Sum of the digits from the puzzle is %i.\n", sum);

    return 0;
}
