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

#define DIGIT_STRING_MAX_LENGTH     (5)

typedef struct {
    char first_digit;
    char second_digit;
} puzzle_output_string_digits_t;

/// @brief  processes the puzzle to return the digits found in the string
/// @param  solution_part informs the function which solution part to find
/// @param  pointer_to_puzzle_output pointer that holds the address of the puzzle output
/// @return struct that holds the digits that were found after processing
puzzle_output_string_digits_t ProcessPuzzleStringToFindDigits(Find_Solution_For_Puzzle_e solution_part, puzzle_output_t* pointer_to_puzzle_output);

/// @brief  find the digits based on the instructions for part one of the puzzle
/// @param  pointer_to_string_digits pointer that holds the address of the puzzle output string digit struct
/// @param  found_digit_character character that is a digit
void SaveFoundCharacterDigit(puzzle_output_string_digits_t* pointer_to_string_digits, char found_digit_character);

/// @brief  processes the character digits from the puzzle output string struct into
///         an integer and then returned
/// @param  digits stored digits from the puzzle file string
/// @return an integer that is made up of two ascii numbers
int ProcessCharacterDigitsToInteger(puzzle_output_string_digits_t digits);

/// @brief  find
char FindCharacterDigitBasedOnDigitStrinf(puzzle_output_t* pointer_to_puzzle_output, int string_position);

int MoveProcessingPositionBasedOnFoundDigitString(char character_digit, int string_position);

#endif // __DAY_1_H__
