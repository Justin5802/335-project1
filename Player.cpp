/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name
Date
Player.cpp implements the Player class.
*/

#include "Player.hpp"
#include <iostream>

// Constructor
Player::Player() : score_(0), opponent_(nullptr), actiondeck_(nullptr), pointdeck_(nullptr) {}

// Destructor
Player::~Player() {}

// Accessors and Mutators
const Hand& Player::getHand() const {
    return hand_;
}

void Player::setHand(const Hand& hand) {
    hand_ = hand;
}

int Player::getScore() const {
    return score_;
}

void Player::setScore(const int& score) {
    score_ = score;
}

Player* Player::getOpponent() {
    return opponent_;
}

void Player::setOpponent(Player* opponent) {
    opponent_ = opponent;
}

Deck<ActionCard>* Player::getActionDeck() {
    return actiondeck_;
}

void Player::setActionDeck(Deck<ActionCard>* actiondeck) {
    actiondeck_ = actiondeck;
}

Deck<PointCard>* Player::getPointDeck() {
    return pointdeck_;
}

void Player::setPointDeck(Deck<PointCard>* pointdeck) {
    pointdeck_ = pointdeck;
}

// Player actions
void Player::play(ActionCard&& card) {
     std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;

}

void Player::drawPointCard() {
    if (!pointdeck_->IsEmpty()) {
        PointCard&& drawnCard = pointdeck_->Draw();
        hand_.addCard(std::move(drawnCard));
    }
}

void Player::playPointCard() {
    if (!hand_.isEmpty()) {
        int points = hand_.PlayCard();
        score_ += points;
    }
}
