bool exhaustive_solve(Puzzle& puzzle, std::string letters_to_assign) {
    if (letters_to_assign.empty()) {  
        return puzzle_solved(puzzle); 
    }
    for (int digit = 0; digit < 10; ++digit) {  // try all digits
        if (assign_letter_to_digit(letters_to_assign[0], digit)) {
            if (exhaustive_solve(puzzle, letters_to_assign.substr(1))) {
                return true;
            }
            unassign_letter_from_digit(letters_to_assign[0], digit);
        }
    }
    return false;
}
