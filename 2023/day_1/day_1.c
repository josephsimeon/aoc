//! @file       day_1.c
//! @brief      holds specific functions for the day_1 challenge
//! @note       the challenge is to find the first and last digit of each string and then sum them all together
//!             first part of the puzzle is to distinguish the character digits hidden in the string from alphabet
//!             second part of the puzzle is to include strings that spell out digit names
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

/// @brief  check if the character is the starting character of a specific string
/// @param  character_to_check character to check if it is the starting character of specific string
/// @return true or false
/// @note   all characters within this puzzle are lowercase
bool IsCharacterDigitTheStartOfASpecificString(char character_to_check)
{
    // specific strings: zero, one, two, three, four, five, six, seven, eight, nine
    // checking against the starting character to these specific strings
    return ((character_to_check == 'z') ||
            (character_to_check == 'o') ||
            (character_to_check == 't') ||
            (character_to_check == 'f') ||
            (character_to_check == 's') ||
            (character_to_check == 'e') ||
            (character_to_check == 'n'));
}

/// @brief  find the character digit that is spelled out in the string
/// @param  pointer_to_puzzle_output pointer that holds the address of the puzzle output struct
/// @param  string_position gives the position of the starting character of the possible
/// @return digit character with an ascii value of '0' to '9' or nulled
char FindCharacterDigitWithinString(puzzle_output_t* pointer_to_puzzle_output, int string_position)
{
    // todo
    return NULLED_ASCII_CHARACTER;
}

/// @brief  if a digit was found spelled out in the string, move the position forward by the size of that string to save processing time
/// @param  character_digit the character digit that was found
/// @param  current_processing_position current position in the processing
int MoveProcessingPositionBasedOnFoundDigitString(char character_digit, int current_processing_position)
{
    int new_position_offset;

    switch (character_digit) {
        case '0':
            new_position_offset = strlen("zero");
            break;

        case '1':
            new_position_offset = strlen("one");
            break;

        case '2':
            new_position_offset = strlen("two");
            break;

        case '3':
            new_position_offset = strlen("three");
            break;

        case '4':
            new_position_offset = strlen("four");
            break;

        case '5':
            new_position_offset = strlen("five");
            break;

        case '6':
            new_position_offset = strlen("six");
            break;

        case '7':
            new_position_offset = strlen("seven");
            break;

        case '8':
            new_position_offset = strlen("eight");
            break;

        case '9':
            new_position_offset = strlen("nine");
            break;

        default:
            new_position_offset = NULLED_ASCII_CHARACTER;
            break;
    }

    return (current_processing_position + new_position_offset);
}
