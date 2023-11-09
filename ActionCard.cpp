
/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Justin Chu
Date: 11/8/23
ActionCard.hpp implements the ActionCard class and inherits from the Card Class.
*/

#include <iostream>
#include <string>
#include "ActionCard.hpp"


/**
  * @post: Construct a new Action Card object
*/
ActionCard::ActionCard() {
    setType(ACTION_CARD);
}


/**
  * @return true if the card is playable, false otherwise
  * For a card to be playable, it has to be drawn and the
    instruction has to be valid
  * Valid instructions:
  * DRAW x CARD(S) : assume x is a positive integer
  * PLAY x CARD(S) : assume x is a positive integer
  * REVERSE HAND : reverse the order of the cards in the hand
  * SWAP HAND WITH OPPONENT : swap the hand with the opponent
*/
bool ActionCard::isPlayable() {
  if(!getDrawn() || getInstruction().empty()) {
    return false;
  }
  const std::regex validInstructionRegex(R"(^(DRAW|PLAY)\s+(\d+)\s+CARD\(S\)$|^(REVERSE HAND)$|^(SWAP HAND WITH OPPONENT)$)");
    
  return std::regex_match(getInstruction(), validInstructionRegex);
}


/**
  * @post: Print the ActionCard in the following format:
  * Type: [CardType]
  * Instruction: [Instruction]
  * Card:
  * [ImageData]
  *
  * Note: For [ImageData]: If there is no image data, print "No image data" instead
*/
void ActionCard::Print() const {
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Instruction: " << getInstruction() << std::endl;
    std::cout << "Card: " << std::endl;

    if(const int* imageData = getImageData()) {
        for(int i = 0; i < 80; i++) {
            std::cout << imageData[i] << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "No image data" << std::endl;
    }
}
