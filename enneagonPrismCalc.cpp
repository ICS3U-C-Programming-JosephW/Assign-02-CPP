// Copyright (c) 2025. Joseph Wondimagnehu. All rights reserved.
//
// Created by: Joseph Wondimagnehu
// Date: Mar. 7, 2025
/* This program allows the user to calculate the volume,
surface area, lateral surface area, and base area of
an enneagonal prism by asking them for the base length
(edge) and height. */ 

// Include the iostream and other libraries.
#include <iostream>
#include <algorithm>
#include <cctype>
#include <set>
#include <variant>

// Constant strings for text colours.
const std::string LIGHT_GREEN = "\033[1;32m",
LIGHT_CYAN = "\033[1;36m",
LIGHT_PURPLE = "\033[1;35m",
LIGHT_RED = "\033[1;31m",
DARK_GRAY = "\033[1;30m",
LIGHT_BLUE = "\033[1;34m",
LIGHT_YELLOW = "\033[1;33m",
WHITE = "\033[0m";

/* ??? */
const std::string ACCEPTED_UNITS[4] = {"mm", "cm", "in", "ft"};

/* Define a function validating the user's 
choice of calculation. */
std::string initChoiceInput() {
    
    // Constant string set for input error detections.
    std::set<std::string> ACCEPTED_CHOICES = {"volume", "surface area", 
    "lateral surface area", "base area"};

    // Declare string variables.
    std::string targetCalculation, transformedString;

    // Construct an infinite loop.
    while (true) {

        /* Display a message asking the user
        to choose their calculation. */
        std::cout << "\n" << LIGHT_YELLOW << "What do you want to calculate?" 
        << " Again, choices are: volume, surface area," << 
        " lateral surface area, \nor base area." << " Enter only one of these."
        << WHITE << "\n";
        
        // Wait for user to input.
        std::getline(std::cin, targetCalculation);

        /* Prepare the size of the transformed string 
        to match the size of the user's choice. */
        transformedString.resize(targetCalculation.size());

        // Transforms the user's choice in lowercase.
        std::transform(targetCalculation.begin(), targetCalculation.end(), 
        transformedString.begin(), [](char scannedChar) { return std::tolower(scannedChar); });

        // Checks if the transformed string is not in the iterated set.
        if (ACCEPTED_CHOICES.find(transformedString) == ACCEPTED_CHOICES.end()) {
            // Throws an invalid argument error to be caught.
            std::cout << "\n" << LIGHT_RED << "Please pick volume," 
            << " surface area, lateral surface area, or base area." 
            << WHITE << "\n";
        }

        // Otherwise, checks if the transformed string is in the iterated set.
        else {
            /* Display a word to the user 
            indicating they chose correctly. */
            std::cout << "\n" << LIGHT_PURPLE << "Alright!" << WHITE << "\n";

            // Return the transformed string for future usage.
            return transformedString;
        }
    }
}

/* Define a dynamic function to check if a number is valid
for the specific type or case. */
double checkCaseValidNum(std::string displayMessage, 
    std::string actualType) {
    /* Declare variable as double, which 
    can hold integers. For simplicity, strings 
    are used to deduce the actual type. */
    double anyNum;

    while (true) {
        // Displays custom message to user.
        std::cout << displayMessage;

        // Waits for user input.
        std::cin >> anyNum;
    
        if (anyNum <= 0 && actualType == "double") {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
            '\n'); 
            std::cout << "\n" << LIGHT_RED << "Please pick a" 
            << " positive and non-zero value." 
            << WHITE << "\n";
        }
        else if (anyNum < 0 && actualType == "int") {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
            '\n');
            std::cout << "\n" << LIGHT_RED << "Please pick a" 
            << " positive value or zero." 
            << WHITE << "\n";
        }
        else {
            // Displays a green text to proceed.
            std::cout << "\n"
            << LIGHT_PURPLE << "Accepted."
            << WHITE << "\n";

            // Returns the number.
            return anyNum;
        }
    }
}

// Runs the main function.
int main() {
    // Greet the user with a light blue text.
    std::cout << "\n" << LIGHT_BLUE << "Hello, user! This is a program" <<
    " designed to calculate the volume, surface area," << 
    "\nlateral surface area, and base area of an enneagonal prism!" 
    << WHITE << "\n";

    // Get and check the user's choice for calculation.
    std::string calcChoice = initChoiceInput();

    // Get the base edge length from the user.
    double base_len = checkCaseValidNum("\n" + LIGHT_BLUE +
        "Enter the base edge length." + WHITE + "\n", 
        "double");

    if (calcChoice == "volume" || "surface area" 
        || "lateral surface area") {

        double height = checkCaseValidNum("\n" + LIGHT_BLUE +
        "Enter the height." + WHITE + "\n", 
        "double");
    }
}
