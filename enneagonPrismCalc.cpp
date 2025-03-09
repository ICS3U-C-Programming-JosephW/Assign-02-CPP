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

/* Define a function validating the user's 
choice of calculation. */
std::string initChoiceInput() {
    
    /* String set for detecting 
    invalid choices from user input. */
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
            // Prompts user to pick a valid choice.
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

/* Define a function validating the user's
unit choice. */
std::string getValidUnitInput() {

    /* Another string set 
    for false unit input detections. */
    std::set<std::string> ACCEPTED_UNITS = {"mm", "cm", "in", "ft"};

    // Declare string variables.
    std::string targetUnit, transformedUnit;

    // Construct an infinite loop.
    while (true) { 
        /* Display a message asking the user
        to choose their unit. */
        std::cout << "\n" << LIGHT_YELLOW << "Enter what units you want" 
        << " the answer to be in. Choices are: mm, cm, in, or ft." 
        << WHITE << "\n";

        // Wait for user to input their unit.
        std::getline(std::cin, targetUnit);

        /* Prepare the size of the transformed unit
        to match the size of the user's unit of choice. */
        transformedUnit.resize(targetUnit.size());

        // Transforms the user's choice in lowercase.
        std::transform(targetUnit.begin(), targetUnit.end(), 
        transformedUnit.begin(), [](char scannedChar) { return std::tolower(scannedChar); });
            
        // Checks if the transformed unit is not in the iterated set.
        if (ACCEPTED_UNITS.find(transformedUnit) == ACCEPTED_UNITS.end()) {
            // Prompts user to pick a valid unit.
            std::cout << "\n" << LIGHT_RED << "Please pick mm, cm," 
            << " in, or ft." << WHITE << "\n";
        }

        // Otherwise, checks if the transformed unit is in the iterated set.
        else {
            /* Display a word to the user 
            indicating they chose a valid unit. */
            std::cout << "\n" << LIGHT_CYAN << "Done!" << WHITE << "\n";

            // Return the transformed string for future usage.
            return transformedUnit;
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

    // Construct an infinite loop.
    while (true) {
        // Displays custom message to user.
        std::cout << displayMessage;

        // Waits for user input.
        std::cin >> anyNum;

        /* Ignores spaces and other characters that skip the other
        input statements. */
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
        '\n');

        /* Checks if the actual type is a double 
        and if the number is less than or equal to 0. */
        if (anyNum <= 0 && actualType == "double") {
            // Clears flags the infinite loop triggers.
            std::cin.clear();

            // Discards false input from the user.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
            '\n'); 

            // Prompts the user to pick a positive and non-zero value.
            std::cout << "\n" << LIGHT_RED << "Please pick a" 
            << " positive and non-zero value." 
            << WHITE << "\n";
        }

        /* Checks if the actual type is an int
        and if the number is less than 0. */
        else if (anyNum < 0 && actualType == "int") {
            // Clears flags the infinite loop triggers.
            std::cin.clear();

            // Discards false input from the user.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
            '\n');

            // Prompts the user to pick a positive and non-zero value.
            std::cout << "\n" << LIGHT_RED << "Please pick a" 
            << " positive value or zero." 
            << WHITE << "\n";

        } else {
            /* Displays a text to the user, 
            allowing them to proceed. Reminds them what number
            they chose. */
            std::cout << "\n"
            << LIGHT_PURPLE << "Accepted. You chose: " << anyNum
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

    // Get and check the user's choice for units.
    std::string unit = getValidUnitInput();

    // Get and check the user's choice for base edge length.
    double baseLen = checkCaseValidNum("\n" + LIGHT_BLUE +
        "Enter the base edge length." + WHITE + "\n", 
        "double");

    // Create a boolean to determine whether the height is needed.
    bool heightNeeded = calcChoice == "volume" || calcChoice == "surface area"
    || calcChoice == "lateral surface area";

    // Checks if the height is needed.
    if (heightNeeded) {
        // Get and check the user's choice for height.
        double height = checkCaseValidNum("\n" + LIGHT_BLUE +
        "Enter the height." + WHITE + "\n", 
        "double");
    }
}