//! @file       day_1.h
//! @brief      
//!
//! @author     Joseph Simeon
//! @date       Created: 11/12/2023 19:48
//! @url        https://github.com/josephsimeon/aoc/2023
//!
//! @date       Last updated: 12/12/2023 21:12

#ifndef __DAY_1_H__
#define __DAY_1_H__

#include "../../common/puzzle.h"

#define NULLED_ASCII_CHARACTER      (0)
#define STARTING_ZERO_ASCII_VALUE   (0x30)

typedef struct {
    char first_digit;
    char second_digit;
} puzzle_output_string_digits_t;

/// @brief  processes the puzzle to return the digits found in the string
/// @param  pointer_to_puzzle_output pointer that holds the address of the puzzle output
/// @return struct that holds the digits that were found after processing
puzzle_output_string_digits_t ProcessPuzzleStringToFindDigits(puzzle_output_t* pointer_to_puzzle_output);

/// @brief  processes the character digits from the puzzle output string struct into
///         an integer and then returned
/// @param  digits stored digits from the puzzle file string
/// @return an integer that is made up of two ascii numbers
int ProcessCharacterDigitsToInteger(puzzle_output_string_digits_t digits);

#endif // __DAY_1_H__
