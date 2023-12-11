//! @file       day_1.c
//! @brief
//!
//! @author     Joseph Simeon
//! @date       11/12/2023 19:48
//! @url        https://github.com/josephsimeon/aoc/2023

#include "../../common/puzzle.h"

int main (void)
{
    FILE* pointer_to_puzzle_file = GetPuzzleFile("puzz.txt");
    CheckValidityOfPuzzleFile(pointer_to_puzzle_file);

    return 0;
}