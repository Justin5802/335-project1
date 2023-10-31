/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name
Date
ActionCard.cpp Defines the ActionCard class.
*/

#include "ActionCard.hpp"
#include <iostream>

// Default Constructor
ActionCard::ActionCard() {}

// isPlayable function implementation
bool ActionCard::isPlayable() {
    // Check if the card is drawn
    if (!getDrawn()) {
        return false;
    }

    // Check if the instruction is valid
    std::regex validInstructions("DRAW \\d+ CARD\\(S\\)|PLAY \\d+ CARD\\(S\\)|REVERSE HAND|SWAP HAND WITH OPPONENT");
    if (!std::regex_match(getInstruction(), validInstructions)) {
        return false;
    }

    // The card is playable if it is drawn and the instruction is valid
    return true;
}

// Print function implementation
void ActionCard::Print() const {
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Instruction: " << getInstruction() << std::endl;

    // Print image data or indicate if there is no image data
    const int* imageData = getImageData();
    if (imageData) {
        std::cout << "Card:" << std::endl;
        // Assuming imageData is an array of integers representing image data
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                std::cout << imageData[i * 5 + j] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "No image data" << std::endl;
    }
}
