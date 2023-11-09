/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Justin Chu
Date: 11/8/23
Hand.cpp implementd the Hand class.
*/

#include "Hand.hpp"

// Big Five and constructor
/**
 * @post: Construct a new Hand object
 */
Hand::Hand()
{
}

/**
 * @post: Destroy the Hand object
 */
Hand::~Hand()
{
    cards_.clear();
}

/**
 * Copy Constructor
 * @param: other Hand object
 */
Hand::Hand(const Hand &other)
{
    cards_ = other.cards_;
}

/**
 * Copy Assignment Operator
 * @param: other Hand object
 * @return this Hand
 */
Hand &Hand::operator=(const Hand &other)
{
    if (this != &other)
    {
        cards_ = other.cards_;
    }
    return *this;
}

/**
 * Move Constructor
 * @param: other Hand object
 */
Hand::Hand(Hand &&other)
{
    cards_ = std::move(other.cards_);
}

/**
 * Move assignment operator
 * @param: other Hand object
 * @return this Hand
 */
Hand &Hand::operator=(Hand &&other)
{
    if (this != &other)
    {
        cards_ = std::move(other.cards_);
    }
    return *this;
}

/**
 * @return Hand
 */
const std::deque<PointCard> &Hand::getCards() const
{
    return cards_;
}

/**
 * @post: Add a card to the hand
 * @param PointCard object
 */
void Hand::addCard(PointCard &&card)
{
    card.setDrawn(true);
    cards_.push_back(card);
}

/**
 * @return true if hand is empty, false otherwise
 */
bool Hand::isEmpty() const
{
    return cards_.empty();
}

/**
 * @post: Reverse the hand
 */
void Hand::Reverse()
{
    if (cards_.size() > 1)
    {
        for (int i = 0; i < cards_.size() / 2; i++)
        {
            if (i != cards_.size() - i - 1)
                std::swap(cards_[i], cards_[cards_.size() - i - 1]);
        }
    }
}

/**
 * @post: Play the card at the front of the hand, removing it from the hand
 * Throws an exception if the hand is empty or the card is not playable
 * If the card is not playable, the card is removed from the hand
 * @return the points earned from playing the card
 */
int Hand::PlayCard()
{
    if (isEmpty() || !(cards_.front().isPlayable()))
    {
        if (!(cards_.front().isPlayable()))
            cards_.pop_front();
        throw "Empty Deck or Card is not Playable";
    }

    int points = std::stoi(cards_.front().getInstruction());
    cards_.pop_front();
    return points;
}


