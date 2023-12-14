//! @file       day_1.h
//! @brief      holds specific functions, defines, structs and enums for the day_1 challenge
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
/// @param  pointer_to_puzzle_output pointer that holds the address of the puzzle output
/// @return struct that holds the digits that were found after processing
puzzle_output_string_digits_t ProcessPuzzleStringToFindDigits(puzzle_output_t* pointer_to_puzzle_output);

/// @brief  find the digits based on the instructions for part one of the puzzle
/// @param  pointer_to_string_digits pointer that holds the address of the puzzle output string digit struct
/// @param  found_digit_character character that is a digit
void SaveFoundCharacterDigit(puzzle_output_string_digits_t* pointer_to_string_digits, char found_digit_character);

/// @brief  processes the character digits from the puzzle output string struct into
///         an integer and then returned
/// @param  digits stored digits from the puzzle file string
/// @return an integer that is made up of two ascii numbers
int ProcessCharacterDigitsToInteger(puzzle_output_string_digits_t digits);

/// @brief  get a reference digit string first character from a variable that holds the string
/// @param  string_number number corresponds to a digit string within the list of digit strings stored in a variable
/// @return retrun the starting first character of the string
char GetReferenceDigitStringFirstCharacter(int string_number);

/// @brief  get a reference digit string from a variable that holds the string
/// @param  string_number number corresponds to a digit string within the list of digit strings stored in a variable
/// @return retruns the address of the digit string
char* GetReferenceDigitString(int string_number);

/// @brief  get a reference size of a digit string from a variable that holds the string
/// @param  string_number number corresponds to a digit string within the list of digit strings stored in a variable
/// @return returns the size of the digit string wanted
int GetReferenceDigitStringSize(int string_number);

/// @brief  check if the character is the starting character of a specific string
/// @param  character_to_check character to check if it is the starting character of specific string
/// @return true or false
bool IsCharacterDigitTheStartOfASpecificString(char character_to_check);

/// @brief  find the character digit that is spelled out in the string
/// @param  pointer_to_puzzle_output pointer that holds the address of the puzzle output struct
/// @param  string_position gives the position of the starting character of the possible
/// @return digit character with an ascii value of '0' to '9' or nulled
char FindCharacterDigitWithinString(puzzle_output_t* pointer_to_puzzle_output, int string_position);

/// @brief  if a digit was found spelled out in the string, move the position forward by the size of that string to save processing time
/// @param  character_digit the character digit that was found
/// @param  current_processing_position current position in the processing
int MoveProcessingPositionBasedOnFoundDigitString(char character_digit, int current_processing_position);
bool IsCharacterDigitTheStartOfASpecificString(char character_to_check);

#endif // __DAY_1_H__
