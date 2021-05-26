// Copyright (c) Year Layla Michel All rights reserved.
//
// Created by: Layla Michel
// Date: May 26, 2021
// This program generates a random number between 0 and 9,
// asks the user to guess it, and displays whether they
// guessed correctly or not, while using a loop

#include <iostream>
#include <random>
#include <string>


int main() {
    // declare variables
    int guessAsInt, correctGuess;
    std::string guessAsString;

    // generate random number
    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(0, 9);
    correctGuess = idist(rgen);

    while (true) {
        // get the user guess
        std::cout << "Guess what number I am thinking of between 0 and 9: ";
        std::cin >> guessAsString;

        try {
            // convert from string to integer
            guessAsInt = std::stoi(guessAsString);

            if (guessAsInt < 0 || guessAsInt > 9) {
                // check if number is within range
                std::cout << guessAsInt << " is not within range, try again.\n";
            } else {
                if (guessAsInt == correctGuess) {
                    // if the user guesses correctly
                    std::cout << "You guessed correctly!\n";
                    std::cout << "Thanks for playing.\n";
                    break;
                } else {
                    // if the user guesses incorrectly
                    std::cout << guessAsInt << " is not the "
                    "correct guess, try again.\n";
                }
            }
        } catch (std::invalid_argument) {
            // error message
            std::cout << guessAsString << " is not a "
            "valid number, try again.\n";
        }
    }
}
