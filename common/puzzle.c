//! @file       puzzle.h
//! @brief      This file holds common functions regarding retrieval and processing of
//!             puzzle information in the more generic manor.
//!
//! @author     Joseph Simeon
//! @date       11/12/2023 19:48
//! @url        https://github.com/josephsimeon/aoc/common

#include <stdlib.h>
#include "puzzle.h"

/// @brief  get the puzzle file pointer
/// @param  name_of_puzzle_text_file puzzle text filename
/// @return file pointer to the puzzle text
/// @note   this file does not deal with error handling if the file does not exist
FILE* GetPuzzleFile(char* name_of_puzzle_text_file)
{
    return fopen(name_of_puzzle_text_file, "r");
}

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