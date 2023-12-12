//! @file       puzzle.h
//! @brief      This file holds common functions regarding retrieval and processing of
//!             puzzle information in the more generic manor.
//!
//! @author     Joseph Simeon
//! @date       Created: 11/12/2023 19:48
//! @url        https://github.com/josephsimeon/aoc/common
//!
//! @date       Last updated: 12/12/2023 21:12

#include <stdlib.h>
#include <string.h>
#include "puzzle.h"

puzzle_output_t puzzle_output; ///< global variable that stores the string of a puzzle as well as the length of that string

/// @brief  error checking for the puzzle file pointer
/// @param  pointer_to_puzzle_file the file pointer that holds the address to the puzzle
///         file
/// @note   checks whether or not the puzzle file is real, if the puzzle file is not real
///         an error will be displayed and the program will be exited
void CheckValidityOfPuzzleFile(FILE* pointer_to_puzzle_file)
{
    if (pointer_to_puzzle_file == NULL) {
        // NULL'd pointer to the puzzle file would mean that the file does not exist
        printf("Error: Puzzle file may not exist or name is wrong.\n");
        exit(0);
    }
}

/// @brief  check if file pointer is still valid
/// @return true or false
bool IsPuzzleFileStillValid(void)
{
    return (!puzzle_output.b_end_of_file);
}

/// @brief  getting string from the puzzle file
/// @param  pointer_to_puzzle_file the file pointer that holds the address to the puzzle
///         file
/// @return puzzle output struct that holds the string from a line of the puzzel file and
///         length
/// @note   string length needs to be checked, it needs to be less than string length
puzzle_output_t *GetStringFromPuzzleFile(FILE* pointer_to_puzzle_file)
{
    // clear the memory of the puzzle string
    memset(puzzle_output.puzzle_string, '0', PUZZLE_STRING_MAX_VALUE);
    // set the bool for end of file by grabbing the next string and the result is nulled
    puzzle_output.b_end_of_file = (fgets(puzzle_output.puzzle_string, PUZZLE_STRING_MAX_VALUE, pointer_to_puzzle_file) == NULL);
    // grab the string length, if the memset is still 0, the string length will be 0
    puzzle_output.puzzle_string_len = strlen(puzzle_output.puzzle_string);

    CheckValidityOfPuzzleFileStringLength(pointer_to_puzzle_file);

    return &puzzle_output;
}

/// @brief  error checking for the valid string length
/// @param  pointer_to_puzzle_file the file pointer that holds the address to the puzzle
///         file
/// @note   exit if the string length reaches near max
void CheckValidityOfPuzzleFileStringLength(FILE* pointer_to_puzzle_file)
{
    if (puzzle_output.puzzle_string_len == (PUZZLE_STRING_MAX_VALUE - 1)) {
        // string length is larger than expected, the string needs to be bigger
        printf("Error: Increase the size of the puzzle_output string.\n");
        fclose(pointer_to_puzzle_file);
        exit(0);
    }
}

/// @brief  check if the character is an ascii value of a digit
/// @param  ascii_character a value between 0-255 that corresponds to an ascii character
/// @return true or false
bool IsCharFromPuzzleFileADigit(char ascii_character)
{
    // ascii value of '0' is 0x30 and the ascii value of '9' is 0x39 so that an
    // ascii character that is a digit is between the values of 0x30 & 0x39 including
    return ((ascii_character >= '0') && (ascii_character <= '9'));
}
