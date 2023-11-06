/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name
Date
PointCard.cpp Defines the PointCard class.
*/

#include "PointCard.hpp"
#include <iostream>

// Default Constructor
PointCard::PointCard() {
    
}

// isPlayable function implementation
bool PointCard::isPlayable() {
    // Check if the card is drawn
    if (!getDrawn()) {
        return false;
    }

    // Check if the instruction is a valid number
    try {
        std::stoi(getInstruction());
    } catch (const std::invalid_argument& e) {
        return false;
    }

    // The card is playable if it is drawn and the instruction is a valid number
    return true;
}

// Print function implementation
void PointCard::Print() const {
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Points: " << getInstruction() << std::endl;

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