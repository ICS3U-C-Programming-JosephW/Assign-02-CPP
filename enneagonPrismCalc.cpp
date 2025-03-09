// Copyright (c) 2025. Joseph Wondimagnehu. All rights reserved.
//
// Created by: Joseph Wondimagnehu
// Date: Mar. 7, 2025
/* This program allows the user to calculate the volume,
surface area, lateral surface area, and base area of
an enneagonal prism by asking them for the base length
(edge) and height. */

// Include the iostream and other libraries.
#include <algorithm>
#include <cctype>
#include <iostream>
#include <set>
#include <variant>
#include <map>

// Constant strings for text colours.
const std::string LIGHT_GREEN = "\033[1;32m",
                  LIGHT_CYAN = "\033[1;36m",
                  LIGHT_PURPLE = "\033[1;35m",
                  LIGHT_RED = "\033[1;31m",
                  DARK_GRAY = "\033[1;30m",
                  LIGHT_BLUE = "\033[1;34m",
                  LIGHT_YELLOW = "\033[1;33m",
                  LIGHT_WHITE = "\033[37;1m",
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
        std::cout << "\n"
                  << LIGHT_YELLOW << "What do you want to calculate?"
                  << " Again, choices are: volume, surface area," << " lateral surface area, \nor base area." << " Enter only one of these."
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
            std::cout << "\n"
                      << LIGHT_RED << "Please pick volume,"
                      << " surface area, lateral surface area, or base area."
                      << WHITE << "\n";
        }

        // Otherwise, checks if the transformed string is in the iterated set.
        else {
            /* Display a word to the user
            indicating they chose correctly. */
            std::cout << "\n"
                      << LIGHT_PURPLE << "Alright!" << WHITE << "\n";

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
        std::cout << "\n"
                  << LIGHT_YELLOW << "Enter what units you want"
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
            std::cout << "\n"
                      << LIGHT_RED << "Please pick mm, cm,"
                      << " in, or ft." << WHITE << "\n";
        }

        // Otherwise, checks if the transformed unit is in the iterated set.
        else {
            /* Display a word to the user
            indicating they chose a valid unit. */
            std::cout << "\n"
                      << LIGHT_CYAN << "Done!" << WHITE << "\n";

            // Return the transformed string for future usage.
            return transformedUnit;
        }
    }
}

/* Define a dynamic function to check if the user
inputted the correct number type for the case.
Return type is double as it contains integers. */
double checkValidNumCase(std::string displayMessage,
    std::string desiredErrorMsg, std::string desiredType, 
    std::string unit, std::string lengthCase) {

    // Declare entered number as a string to use getline.
    std::string strToBeConverted;

    /* Declare the variable types that the
    string will possibly be converted into. */
    int possibleInt;
    double possibleDouble;

    // Construct an infinite loop.
    while (true) {
        /* Displays custom message to user.
        Also, indicates spaces are ignored. */
        std::cout << displayMessage
        << "\n(WARNING: characters and spaces" 
        << " following your number will be ignored)." 
        << WHITE << "\n";

        // Waits for user input.
        std::getline(std::cin, strToBeConverted);

        // Tries the conversion.
        try {

            if (desiredType == "int") {
                /* Convert the string to int.
                stoi will throw an error if not possible. */
                possibleInt = stoi(strToBeConverted);
            }

            else {
                /* Convert the string to double.
                stod will throw an error if not possible. */
                possibleDouble = stod(strToBeConverted);
            }

            /* If it passes, check if the int is less than 0
            or if the double is less than or equal to 0. */
            if ((desiredType == "int" && possibleInt < 0)
            || (desiredType == "double" && possibleDouble <= 0)) {
                
                /* Prompt the user to pick the valid value
                for the case. */
                std::cout << "\n" << LIGHT_RED << desiredErrorMsg
                << WHITE << "\n";
            }
            // Otherwise, the user has choosen a valid value.
            else {

                if (desiredType == "int") {
                    /* Display a proceeding message to the user for 
                    inputting a valid integer. */
                    std::cout << "\n" << LIGHT_GREEN << "Accepted." 
                    << " You chose " << possibleInt << " " << unit 
                    << " for " << lengthCase << "." << WHITE << "\n";

                    // Return the valid integer.
                    return possibleInt;
                }
                else {
                    /* Display a proceeding message to the user for
                    inputting a valid double. */
                    std::cout << "\n" << LIGHT_GREEN << "Accepted." 
                    << " You chose " << possibleDouble << " " << unit 
                    << " for " << lengthCase << "." << WHITE << "\n";

                    // Return the valid double.
                    return possibleDouble;
                }
            }
        }  

        // Catches any exception thrown by either stoi or stod.
        catch (const std::exception& exception) {

            // Prompts the user not to enter other characters.
            std::cout << "\n" << LIGHT_RED <<
            "Please do not enter non-numerical values."
            << WHITE << "\n";
        }
    }
}

long double calculateEnneaprism(std::string calcChoice, 
    double baseLen, double height, std::string unit,
    int placesToRound) {

    std::map<std::string, int> choiceToInt {
        {"volume", 1},
        {"surface area", 2},
        {"lateral surface area", 3},
        {"base area", 4}
    };

    int correspondingInt = choiceToInt[calcChoice];

    // Match the user's choice with the following cases using a switch statement.
    switch (correspondingInt) {
        }
    }



// Runs the main function.
int main() {
    // Greet the user with a light blue text.
    std::cout << "\n"
              << LIGHT_BLUE << "Hello, user! This is a program" << " designed to calculate the volume, surface area," << "\nlateral surface area, and base area of an enneagonal prism!"
              << WHITE << "\n";

    // Get and check the user's choice for calculation.
    std::string calcChoice = initChoiceInput();

    // Get and check the user's choice for units.
    std::string desiredUnit = getValidUnitInput();

    // Get and check the user's choice for base edge length.
    double baseLen = checkValidNumCase("\n" + LIGHT_YELLOW + 
    "Enter the base edge length", 
    "Please pick a positive and non-zero value.", 
    "double", desiredUnit, "base edge length");

    // Create a boolean to determine whether the height is needed.
    bool heightNeeded = calcChoice == "volume" || 
    calcChoice == "surface area" || calcChoice == "lateral surface area";

    // Checks if the height is needed.
    if (heightNeeded) {
        // Get and check the user's choice for height.
        double height = checkValidNumCase("\n" + LIGHT_PURPLE + 
        "Enter the height", 
        "Please pick a positive and non-zero value.",
        "double", desiredUnit, "height");
    }

    // Otherwise, checks if the height is not needed.
    else {
        /* Set height to a placeholder value like
        zero since it is not needed for base area.*/
        double height = 0;
    }

    /* Get and check the amount of decimal
    places the user wants to round the result to. */
    int placesToRound = checkValidNumCase("\n" + LIGHT_WHITE + 
    "How many decimal places would you like to round the result to?", 
    "Please pick a positive value or zero.",
    "int", "decimal places", "rounding the result");
}