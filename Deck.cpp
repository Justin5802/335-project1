/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name
Date
Deck.cpp Defines the Deck class.
*/

#include "Deck.hpp"

// Default constructor
template <typename CardType>
Deck<CardType>::Deck() {}

// Destructor
template <typename CardType>
Deck<CardType>::~Deck() {}

// AddCard function implementation
template <typename CardType>
void Deck<CardType>::AddCard(const CardType& card) {
    cards.push_back(card);
}

// Draw function implementation
template <typename CardType>
CardType&& Deck<CardType>::Draw() {
    if (IsEmpty()) {
        throw std::out_of_range("Deck is empty");
    }

    CardType drawnCard = std::move(cards_.back());
    cards.pop_back();
    return std::move(drawnCard);
}

// IsEmpty function implementation
template <typename CardType>
bool Deck<CardType>::IsEmpty() const {
    return cards.empty();
}

// Shuffle function implementation
template <typename CardType>
void Deck<CardType>::Shuffle() {
    std::mt19937 rng(2028358904);
    std::shuffle(cards.begin(), cards.end(), rng);
}

// getSize function implementation
template <typename CardType>
int Deck<CardType>::getSize() const {
    return cards.size();
}

// getDeck function implementation
template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const {
    return cards;
}