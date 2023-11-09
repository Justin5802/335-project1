/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Justin Chu
Date: 11/8/23
Deck.hpp implements the Deck class.
*/

#include "Deck.hpp"

// Default constructor
template <typename CardType>
Deck<CardType>::Deck() 
{
    cards_.clear();
}

// Destructor
template <typename CardType>
Deck<CardType>::~Deck() {
    cards_.clear();
}

// AddCard function implementation
template <typename CardType>
void Deck<CardType>::AddCard(const CardType& card) {
    cards_.push_back(card);
}

// Draw function implementation
template <typename CardType>
CardType&& Deck<CardType>::Draw() {
    if (!IsEmpty()){
        cards_.back().setDrawn(true);
        CardType &&tmp = std::move(cards_.back());
        cards_.pop_back();
        return std::move(tmp);
    }
}

// IsEmpty function implementation
template <typename CardType>
bool Deck<CardType>::IsEmpty() const {
    return cards_.empty();
}

// Shuffle function implementation
template <typename CardType>
void Deck<CardType>::Shuffle() {
    std::mt19937 gen;
    gen.seed(2028358904);
    std::shuffle(cards_.begin(), cards_.end(), gen);
}

// getSize function implementation
template <typename CardType>
int Deck<CardType>::getSize() const {
    return cards_.size();
}

// getDeck function implementation
template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const {
    return cards_;
}