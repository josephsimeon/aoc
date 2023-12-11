//! @file       puzzle.h
//! @brief      This file holds common functions regarding retrieval and processing of
//!             puzzle information in the more generic manor.
//!
//! @author     Joseph Simeon
//! @date       11/12/2023 19:48
//! @url        https://github.com/josephsimeon/aoc/common

#include <stdio.h>

#define PUZZLE_STRING_MAX_VALUE (256)
typedef struct {
    char puzzle_string[PUZZLE_STRING_MAX_VALUE];
    int puzzle_string_len;
} puzzle_output_t;

/// @brief  get the puzzle file pointer
/// @return file pointer to the puzzle text
/// @note   this file does not deal with error handling if the file does not exist
FILE* GetPuzzleFile(void);

/// @brief  get the test puzzle file pointer
/// @return file pointer to the puzzle text
/// @note   this file does not deal with error handling if the file does not exist
FILE* GetTestPuzzleFile(void);

/// @brief  error checking for the puzzle file pointer
/// @param  pointer_to_puzzle_file the file pointer that holds the address to the puzzle
///         file
/// @note   checks whether or not the puzzle file is real, if the puzzle file is not real
///         an error will be displayed and the program will be exited
void CheckValidityOfPuzzleFile(FILE* pointer_to_puzzle_file);