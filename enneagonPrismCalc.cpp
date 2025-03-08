// Copyright (c) 2025. Joseph Wondimagnehu. All rights reserved.
//
// Created by: Joseph Wondimagnehu
// Date: Mar. 7, 2025
/* This program allows the user to calculate the volume,
surface area, lateral surface area, and base area of
an enneagonal prism by asking them for the base length
(edge) and height. */

// Include iostream, string, and cstdio libraries.
#include <iostream>
#include <string>
#include <algorithm>

// Declare constants for some input error detections.
const std::string ACCEPTED_CHOICES[4] = {"volume", "surface area", 
"lateral surface area", "base area"}, 
ACCEPTED_UNITS[4] = {"mm", "cm", "in", "ft"};
    
// Get and check the user's choice for calculation.
std::string initChoiceInput() {
    // Construct an infinite loop.
    while (true) {
        // Try to get a correct input from the user.
        try {
            // Declare the string variable.
            std::string targetCalculation;
            std::string findChoice;
            bool validChoice;

            // Get what the user wants to calculate for the enneagonal prism.
            std::cout << "\n\033[1;35mWhat do you want to calculate? Again, choices are:" 
" volume, surface area, lateral surface area, or base area."
" Enter only one of these, in all lowercase.\033[0m\n";
            std::cin >> targetCalculation;

            for (int i = 0; i < 4; i++) {
               if (targetCalculation == ACCEPTED_CHOICES[i]) {
                   findChoice = ACCEPTED_CHOICES[i];
                   validChoice = true;
               }
            };

            // Checks if the user did not input a valid choice.
            if (validChoice == true) {
                throw(targetCalculation);
            };
        } 
        
        catch (std::string d) {
            std::cout << "No.\n";
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

    initChoiceInput();
}
