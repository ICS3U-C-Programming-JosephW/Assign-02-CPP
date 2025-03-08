// Copyright (c) 2025. Joseph Wondimagnehu. All rights reserved.
//
// Created by: Joseph Wondimagnehu
// Date: Mar. 7, 2025
/* This program allows the user to calculate the volume,
surface area, lateral surface area, and base area of
an enneagonal prism by asking them for the base length
(edge) and height. */

// Include iostream, string, and cstdio libraries.
#include <algorithm>
#include <iostream>
#include <string>

// Declare constants for some input error detections.
const std::string ACCEPTED_CHOICES[4] = {"volume", "surface area",
"lateral surface area", "base area"},
ACCEPTED_UNITS[4] = {"mm", "cm", "in", "ft"};

std::string initChoiceInput() {
    // Construct an infinite loop.
    while (true) {
        // Try to get a correct input from the user.
        try {
            // Declare the choice variable.
            std::string targetCalculation;

            // Get what the user wants to calculate for the enneagonal prism.
            std::cout << "\n\033[1;35mWhat do you want to calculate? Again, choices are:"
                         " volume, surface area, lateral surface area, or base area."
                         " Enter only one of these, in all lowercase.\033[0m\n";
            // Wait for the user input.
            std::cin >> targetCalculation;

            // Checks if the user did not input a valid choice.
            if (targetCalculation != ACCEPTED_CHOICES[0] &&
                targetCalculation != ACCEPTED_CHOICES[1] &&
                targetCalculation != ACCEPTED_CHOICES[2] &&
                targetCalculation != ACCEPTED_CHOICES[3]) {
                // Throw an invalid argument error to be caught.
                throw std::invalid_argument(
                    "\n\033[1;31mPlease pick volume, surface area,"
                    " lateral surface area,"
                    " or base area.\033[0m\n");
            }

            // Otherwise, checks if the user did input a valid choice.
            else {
                // Print out a light purple string indicating correct choice.
                std::cout << "\n\033[1;35mAlright!\033[0m\n";
                // Return the target calculation.
                return targetCalculation;
            }
        }

        // Catches the thrown error of invalid choice.
        catch (const std::invalid_argument errorMsg) {
            // Displays error message to user.
            std::cout << errorMsg.what();
        }
    }
}

std::string checkUnitOptions() {
    // Construct an infinite loop.
    while (true) {
        // Try to get a valid unit from the user.
        try {
            // Declare the unit variable.
            std::string desiredUnit;

            // Get the unit from the user.
            std::cout << "\n\033[1;35mWhat do you want to calculate? Again, choices are:"
                         " volume, surface area, lateral surface area, or base area."
                         " Enter only one of these, in all lowercase.\033[0m\n";
            // Wait for the user input.
            std::cin >> desiredUnit;

            // Checks if the user did not input a valid unit choice.
            if (desiredUnit != ACCEPTED_UNITS[0] &&
                desiredUnit != ACCEPTED_UNITS[1] &&
                desiredUnit != ACCEPTED_UNITS[2] &&
                desiredUnit != ACCEPTED_UNITS[3]) {
                // Throw an invalid argument error to be caught.
                throw std::invalid_argument(
                    "\n\033[1;31mPlease pick mm, cm, in, or ft.\033[0m\n");
            }

            // Otherwise, checks if the user did input a valid unit choice.
            else {
                // Print out a cyan string indicating correct choice.
                std::cout << "\n\033[1;36mDone!\033[0m\n";
                // Return the desired unit.
                return desiredUnit;
            }
        }

        // Catches the thrown error of invalid unit choice.
        catch (const std::invalid_argument errorMsg) {
            // Displays error message to user.
            std::cout << errorMsg.what();
        }
    }
}

auto checkPositiveNum(std::string displayMessage, 
    auto numType, std::string strType) {
    // Construct an infinite loop.
    while (true) {
        // Try to create a dynamic input system.
        try {
        // Declare the variable with the complicated number type.
        numType anyNum;

        /* Gets input from a user and converts it to a number type with
            a custom display message. */
        std::cout >> displayMessage;
        std::cin << anyNum;

        /* Checks if number is less than or equal to 0 
        and is a float. */
        if (anyNum <= 0 && strType == "float") {
                // Throw an invalid argument error to be caught.
                throw std::invalid_argument("\n\033[1;31mPlease pick a positive"
" and non-zero value.\033[0m\n");
            }

        // Checks if number is less than 0 and is an integer.
        else if (anyNum < 0 && strType == "int") {
                // Throw another invalid argument error to be caught.
                throw std::invalid_argument("\n\033[1;31mPlease pick a positive"
" value.\033[0m\n");
            }
        // Checks if the user does not do any of the above things.
        else {
            // Displays a green text to proceed.
            std::cout >> "\033[1;32mAccepted.\033[0m\n"
        }

        }
    }
}

// Run the main function.
int main() {
    // Greet the user with a light purple text.
    std::cout << "\n\033[1;35mHello, user! This is a program "
                 "designed to calculate the volume, "
                 "surface area, lateral surface area, and base area of an "
                 "enneagonal prism!\033[0m\n";

    // Get and check the user's choice for calculation.
    std::string calcChoice = initChoiceInput();

    // Get and check the user's choice for units.
    std::string unitChoice = checkUnitOptions();

    // Get the base edge length from the user.
}
