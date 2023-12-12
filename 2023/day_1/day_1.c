//! @file       day_1.c
//! @brief      first part of the challenge is to find the first and last digit of each
//!             string and then sum them all together
//!
//! @author     Joseph Simeon
//! @date       Created: 11/12/2023 19:48
//! @url        https://github.com/josephsimeon/aoc/2023
//!
//! @date       Last updated: 12/12/2023 21:12

#include "day_1.h"

/// @brief  processes the puzzle to return the digits found in the string
/// @param  pointer_to_puzzle_output pointer that holds the address of the puzzle output
/// @return struct that holds the digits that were found after processing
/// @note   if the string is empty it will keep
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
            // check that the first digit has been processed
            if (digits.first_digit == NULLED_ASCII_CHARACTER) {
                digits.first_digit = pointer_to_puzzle_output->puzzle_string[i];
            } else {
                // the next digit found until the end of the string will always be given
                // to the next digit
                digits.second_digit = pointer_to_puzzle_output->puzzle_string[i];
            }
        }
    }

    return digits;
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
