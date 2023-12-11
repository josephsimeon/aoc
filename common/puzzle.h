//! @file       puzzle.h
//! @brief      This file holds common functions regarding retrieval and processing of
//!             puzzle information in the more generic manor.
//!
//! @author     Joseph Simeon
//! @date       11/12/2023 19:48
//! @url        https://github.com/josephsimeon/aoc/common

#include <stdio.h>

/// @brief  get the puzzle file pointer
/// @param  name_of_puzzle_text_file puzzle text filename
/// @return file pointer to the puzzle text
/// @note   this file does not deal with error handling if the file does not exist
FILE* GetPuzzleFile(char* name_of_puzzle_text_file);