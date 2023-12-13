//! @file       puzzle.h
//! @brief      This file holds common functions regarding retrieval and processing of
//!             puzzle information in the more generic manor.
//!
//! @author     Joseph Simeon
//! @date       Created: 11/12/2023 19:48
//! @url        https://github.com/josephsimeon/aoc/common
//!
//! @date       Last updated: 12/12/2023 21:12

#ifndef __PUZZLE_H__
#define __PUZZLE_H__

#include <stdio.h>
#include <stdbool.h>

#define PUZZLE_STRING_MAX_VALUE (256)
typedef struct {
    char puzzle_string[PUZZLE_STRING_MAX_VALUE];
    int puzzle_string_len;
    bool b_end_of_file;
} puzzle_output_t;

/// @brief  error checking for the puzzle file pointer
/// @param  pointer_to_puzzle_file the file pointer that holds the address to the puzzle
///         file
/// @note   checks whether or not the puzzle file is real, if the puzzle file is not real
///         an error will be displayed and the program will be exited
void CheckValidityOfPuzzleFile(FILE* pointer_to_puzzle_file);

/// @brief  check if file pointer is still valid
/// @return true or false
bool IsPuzzleFileStillValid(void);

/// @brief  getting string from the puzzle file
/// @param  pointer_to_puzzle_file the file pointer that holds the address to the puzzle
///         file
/// @return puzzle output struct that holds the string from a line of the puzzel file and
///         length
puzzle_output_t *GetStringFromPuzzleFile(FILE* pointer_to_puzzle_file);

/// @brief  error checking for the valid string length
/// @note   exit if the string length reaches near max
void CheckValidityOfPuzzleFileStringLength(FILE* pointer_to_puzzle_file);

/// @brief  check if the character is an ascii value of a digit
/// @param  ascii_character a value between 0-255 that corresponds to an ascii character
/// @return true or false
bool IsCharFromPuzzleFileADigit(char ascii_character);

/// @brief  check if the character is an ascii value of an alphabet character
/// @param  ascii_character a value between 0-255 that corresponds to an ascii character
/// @return true or false
bool IsCharFromPuzzleFileAnAlpha(char ascii_character);

#endif // __PUZZLE_H__
