#include <iostream>
#include <string>
#include "PointCard.hpp"

/**
  * @post: Construct a new Point Card object
*/
PointCard::PointCard() {
    setType(POINT_CARD);
}


/**
  * @return true if the card is playable, false otherwise
  * For a card to be playable, it has to be drawn and the instruction has
    to be a valid number
*/
bool PointCard::isPlayable() {
    if(!getDrawn() || getInstruction().empty()) {
        return false;
    }
    for(char c : getInstruction()){
        if(!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}


/**
  * @post: Print the Point Card in the following format:
  * Type: [CardType]
  * Points: [Instruction]
  * Card:
  * [ImageData]
  *
  * Note: For [ImageData]: If there is no image data, print "No image data" instead
*/
void PointCard::Print() const {
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Points: " << getInstruction() << std::endl;
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