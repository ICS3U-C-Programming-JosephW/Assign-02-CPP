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
        throw std::invalid_argument("\n" + LIGHT_RED + "Please pick volume," 
        + " surface area, lateral surface area, or base area." 
        + WHITE + "\n");
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

// Runs the main function.
int main() {
    // Greet the user with a light blue text.
    std::cout << "\n" << LIGHT_BLUE << "Hello, user! This is a program" <<
    " designed to calculate the volume, surface area," << 
    "\nlateral surface area, and base area of an enneagonal prism!" 
    << WHITE << "\n";

    // Try to run the following.
    try {
        // Get and check the user's choice for calculation.
        std::string calcChoice = initChoiceInput();
    }
    // Catch any exception thrown dynamically.
    catch(const std::invalid_argument exception) {
        // Displays what the error was to the user.
        std::cout << exception.what() << std::endl;
    }
}