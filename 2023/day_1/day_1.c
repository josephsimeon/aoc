//! @file       day_1.c
//! @brief      first part of the challenge is to find the first and last digit of each string and then sum them all together
//!
//! @author     Joseph Simeon
//! @date       Created: 11/12/2023 19:48
//! @url        https://github.com/josephsimeon/aoc/2023
//!
//! @date       Last updated: 12/12/2023 21:12

#include "day_1.h"

/// @brief  processes the puzzle to return the digits found in the string
/// @param  pointer_to_puzzle_output pointer that holds the address of the puzzle output
/// @see    look at define PROCESS_PUZZLE_OUTPUT_FOR_PART_2, if you need part 1's answer you will need to set it to false
/// @return struct that holds the digits that were found after processing
/// @note   if the string is empty it will keep
#define PROCESS_PUZZLE_OUTPUT_FOR_PART_2 (true)
puzzle_output_string_digits_t ProcessPuzzleStringToFindDigits(puzzle_output_t* pointer_to_puzzle_output)
{
    puzzle_output_string_digits_t digits;

    // give the digits null
    digits.first_digit = NULLED_ASCII_CHARACTER;
    digits.second_digit = NULLED_ASCII_CHARACTER;

    // move through the string
    for(int i = 0; i < pointer_to_puzzle_output->puzzle_string_len; i++) {
        // process through the string
        if (IsCharFromPuzzleFileADigit(pointer_to_puzzle_output->puzzle_string[i])) {
            SaveFoundCharacterDigit(digits, pointer_to_puzzle_output->puzzle_string[i]);
        } else if (IsCharFromPuzzleFileAnAlpha(pointer_to_puzzle_output->puzzle_string[i])) {
            // check that the define to process for part 2 is active
            if (PROCESS_PUZZLE_OUTPUT_FOR_PART_2) {
                // TODO
                // check that the letter associates with a particular word
                // wait for buffer to be filled based on that word
                // check against the saved buffer
                // if the buffer and word is confirmed, save found digit as character
            }
        } else {
            // the character is not an alpha or number, do nothing
        }
    }

    return digits;
}

/// @brief  find the digits based on the instructions for part one of the puzzle
/// @param  pointer_to_string_digits pointer that holds the address of the puzzle output string digit struct
/// @param  found_digit_character character that is a digit
void SaveFoundCharacterDigit(puzzle_output_string_digits_t* pointer_to_string_digits, char found_digit_character)
{
    // check that the first digit has been processed
    if (pointer_to_string_digits->first_digit == NULLED_ASCII_CHARACTER) {
        pointer_to_string_digits->first_digit = found_digit_character;
    } else {
        // the next digit found until the end of the string will always be given
        // to the next digit
        pointer_to_string_digits->second_digit = found_digit_character;
    }
}

/// @brief  processes the character digits from the puzzle output string struct into
///         an integer and then returned
/// @param  digits stored digits from the puzzle file string
/// @return an integer that is made up of two ascii numbers
/// @note   if a
int ProcessCharacterDigitsToInteger(puzzle_output_string_digits_t digits)
{
    int converted_integer = 0;

    // check if the second digit is blank
    if (digits.second_digit == NULLED_ASCII_CHARACTER) {
        // if the second digit is blank, it means that there was only one digit within the
        // previous string and that digit will need to be doubled via the first digit
        digits.second_digit = digits.first_digit;
    }

    // only convert the digits if the first digit is not nulled, the second digit
    // doesn't need to be checked, if the first digit is nulled than the second digit
    // will be nulled as well
    if (digits.first_digit != NULLED_ASCII_CHARACTER) {
        // convert the ascii digits to integer
        converted_integer += ((digits.first_digit - STARTING_ZERO_ASCII_VALUE) * 10);
        converted_integer += (digits.second_digit - STARTING_ZERO_ASCII_VALUE);
    }
    
    return converted_integer;
}
