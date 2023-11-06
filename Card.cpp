#include "Card.hpp"

//default constructor
Card::Card(){
    instruction_ = "";
    bitmap_ = nullptr;
    drawn_ = false;
}

// Destructor
Card::~Card() {
    delete[] bitmap_;
}

// Copy Constructor
Card::Card(const Card& rhs) : cardType_(rhs.cardType_), instruction_(rhs.instruction_), drawn_(rhs.drawn_) {
    // Copy image data
    if (rhs.bitmap_ != nullptr) {
        int size = sizeof(rhs.bitmap_) / sizeof(rhs.bitmap_[0]);
        bitmap_ = new int[size];
        for (int i = 0; i < size; ++i) {
            bitmap_[i] = rhs.bitmap_[i];
        }
    } else {
        bitmap_ = nullptr;
    }
}

// Copy Assignment Operator
Card& Card::operator=(const Card& rhs) {
    if (this != &rhs) {
        // Release existing resources
        delete[] bitmap_;

        // Copy member variables
        cardType_ = rhs.cardType_;
        instruction_ = rhs.instruction_;
        drawn_ = rhs.drawn_;

        // Copy image data
        if (rhs.bitmap_ != nullptr) {
            int size = sizeof(rhs.bitmap_) / sizeof(rhs.bitmap_[0]);
            bitmap_ = new int[size];
            for (int i = 0; i < size; ++i) {
                bitmap_[i] = rhs.bitmap_[i];
            }
        } else {
            bitmap_ = nullptr;
        }
    }
    return *this;
}

// Move Constructor
Card::Card(Card&& rhs) : cardType_(rhs.cardType_), instruction_(std::move(rhs.instruction_)), bitmap_(rhs.bitmap_), drawn_(rhs.drawn_) {
    rhs.bitmap_ = nullptr; // Take ownership of the moved data
}

// Move Assignment Operator
Card& Card::operator=(Card&& rhs) {
    if (this != &rhs) {
        // Release existing resources
        delete[] bitmap_;

        // Move member variables
        cardType_ = rhs.cardType_;
        instruction_ = std::move(rhs.instruction_);
        drawn_ = rhs.drawn_;

        // Take ownership of the moved data
        bitmap_ = rhs.bitmap_;
        rhs.bitmap_ = nullptr;
    }
    return *this;
}

// Default Constructor
Card::Card() : cardType_(POINT_CARD), instruction_(""), bitmap_(nullptr), drawn_(false) {
    // Default image data
    bitmap_ = new int[3]{1, 2, 3};
}

std::string Card::getType() const {
    return (cardType_ == POINT_CARD) ? "POINT_CARD" : "ACTION_CARD";
}

void Card::setType(const CardType& type) {
    cardType_ = type;
}

const std::string& Card::getInstruction() const {
    return instruction_;
}

void Card::setInstruction(const std::string& instruction) {
    instruction_ = instruction;
}

const int* Card::getImageData() const {
    return bitmap_;
}

void Card::setImageData(int* data) {
    // Assuming data is an array of 3 integers for simplicity
    delete[] bitmap_;
    bitmap_ = new int[3];
    for (int i = 0; i < 3; ++i) {
        bitmap_[i] = data[i];
    }
}

bool Card::getDrawn() const {
    return drawn_;
}

void Card::setDrawn(const bool& drawn) {
    drawn_ = drawn;
}



