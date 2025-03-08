// Copyright (c) 2025. Joseph Wondimagnehu. All rights reserved.
//
// Created by: Joseph Wondimagnehu
// Date: Mar. 7, 2025
/* This program allows the user to calculate the volume,
surface area, lateral surface area, and base area of
an enneagonal prism by asking them for the base length
(edge) and height. */ 

// Include the iostream, and ... libraries.
#include <iostream>

// Constant strings for text colours.
const std::string LIGHT_GREEN = "\033[1;32m",
LIGHT_CYAN = "\033[1;36m",
LIGHT_PURPLE = "\033[1;35m",
LIGHT_RED = "\033[1;31m",
DARK_GRAY = "\033[1;30m",
LIGHT_BLUE = "\033[1;34m",
LIGHT_YELLOW = "\033[1;33m",
WHITE = "\033[0m";

/* Constant string arrays for 
input error detections. */
const std::string ACCEPTED_CHOICES[4] = 
{"volume", "surface area", "lateral surface area", "base area"},
ACCEPTED_UNITS[4] = {"mm", "cm", "in", "ft"};

