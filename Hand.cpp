/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name
Date
Hand.cpp Defines the Hand class.
*/

#include "Hand.hpp"
#include <stdexcept>

// Constructor
Hand::Hand() {}

// Destructor
Hand::~Hand() {}

// Copy Constructor
Hand::Hand(const Hand& other) : cards_(other.cards_) {}

// Copy Assignment Operator
Hand& Hand::operator=(const Hand& other) {
    if (this != &other) {
        cards_ = other.cards_;
    }
    return *this;
}

// Move Constructor
Hand::Hand(Hand&& other) noexcept : cards_(std::move(other.cards_)) {}

// Move Assignment Operator
Hand& Hand::operator=(Hand&& other) noexcept {
    if (this != &other) {
        cards_ = std::move(other.cards_);
    }
    return *this;
}

const std::deque<PointCard>& Hand::getCards() const {
    return cards_;
}

void Hand::addCard(PointCard&& card) {
    cards_.emplace_back(std::move(card));
}

bool Hand::isEmpty() const {
    return cards_.empty();
}

void Hand::Reverse() {
    std::reverse(cards_.begin(), cards_.end());
}

int Hand::PlayCard() {
    if (isEmpty()) {
        throw std::out_of_range("Hand is empty");
    }

    int points = std::stoi(cards_.front().getInstruction()); // Assuming 'getInstruction()' returns a string
    cards_.pop_front();

    // Assuming 'isPlayable()' checks if the instruction is a valid number
    if (!cards_.front().isPlayable()) {
        cards_.pop_front();
        throw std::logic_error("Card is not playable");
    }

    return points;
}



