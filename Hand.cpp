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
Hand::~Hand() {
    cards_.clear();
}

// Copy Constructor
Hand::Hand(const Hand& other){
    cards_ = other.cards_;
}

// Copy Assignment Operator
Hand& Hand::operator=(const Hand& other) {
    if (this != &other) {
        cards_ = other.cards_;
    }
    return *this;
}

// Move Constructor
Hand::Hand(Hand&& other){
    cards_ = std::move(other.cards_);
}

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
    card.setDrawn(true);
    cards_.push_back(card);
}

bool Hand::isEmpty() const {
    return cards_.empty();
}

void Hand::Reverse() {
    if (cards_.size() > 1){
        for (int i = 0; i < cards_.size() / 2; i++){
            if (i != cards_.size() - i - 1)
                std::swap(cards_[i], cards_[cards_.size() - i - 1]);
        }
    }
}

int Hand::PlayCard() {
    if (isEmpty() || !(cards_.front().isPlayable())){
        if (!(cards_.front().isPlayable()))
            if (!(cards_.front().isPlayable()))
                cards_.pop_front();
            throw "Empty Hand or Card is not Playable";
        }
        int points = std::stoi(cards_.front().getInstruction());
        cards_.pop_front();
        return points;
    }




