/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Justin Chu
Date: 11/8/23
Player.hpp implements the Player class and inherits from the Hand, Deck, ActionCard, and PointCard Class.
*/

#include "Player.hpp"

/**
         * @post: Construct a new Player object
         */
Player::Player() : score_(0), opponent_(nullptr), actiondeck_(nullptr), pointdeck_(nullptr) {}

/**
         * @post: Destroy the Hand object
         */
Player::~Player() {}

/**
         * @return the player's hand
         */
const Hand& Player::getHand() const {
  return hand_;
}

/**
         * @post: Set the player's hand
         * @param const reference to a hand object
         */
void Player::setHand(const Hand& hand) {
  hand_ = hand;
}

/**
         * @return the Player's current score
         */
int Player::getScore() const {
  return score_;
}

/**
         * @post: Set the player's score
         * @param: score 
         */
void Player::setScore(const int& score) {
  score_ = score;
}

 /**
         * @post: Play a given action card
         * @param: an Actioncard object
         * Begin the function by reporting the instruction of the card:
         * PLAYING ACTION CARD: [instruction]
         */
void Player::play(ActionCard&& card) {
  std::string instruction = card.getInstruction();
  std::cout << "PLAYING ACTION CARD: " << instruction << std::endl;
  if(instruction == "REVERSE HAND") {
    hand_.Reverse();
  }
  else if(instruction == "SWAP HAND WITH OPPONENT") {
    Hand temp = getHand();
    setHand(opponent_->getHand());
    opponent_->setHand(temp);
  }
  else {
    std::vector<std::string> stored_words;
    std::string word_holder = "";
    for(int i = 0; i < instruction.size(); i++){ 
      if(instruction[i] == ' '){
        stored_words.push_back(word_holder);
        word_holder = "";
      }
      else{
        word_holder += instruction[i];
      }
    }

    if(stored_words[0] == "DRAW"){
      for(int i = 0; i < std::stoi(stored_words[1]); i++){
        drawPointCard();
      }
    }
    else if(stored_words[0] == "PLAY"){
      for(int i = 0; i < std::stoi(stored_words[1]); i++){
        playPointCard();
      }
    }
  }
}

/**
         * @post: Draw a point card and place it in the player's hand
         */
void Player::drawPointCard() {
  if(pointdeck_ && !pointdeck_->IsEmpty()) {
    hand_.addCard(std::move(pointdeck_->Draw()));
  }
}

/**
         * @post: Play a point card from the player's hand and update the player's score
         */
void Player::playPointCard() {
  if(!hand_.isEmpty()) {
    setScore(getScore() + hand_.PlayCard());
  }
}

 /**
         * @post: Set the opponent of the player
         * @param a pointer to a Player opponent 
         */
void Player::setOpponent(Player* opponent) {
  opponent_ = opponent;
}

/**
         * @return: a pointer to the player's opponent
         */
Player* Player::getOpponent() {
  return opponent_;
}


/**
         * @post: set the action deck of the player 
         * @param: A pointer to a deck holding Action cards 
         */
void Player::setActionDeck(Deck<ActionCard>* actiondeck) {
  actiondeck_ = actiondeck;
}

/**
         * @return a pointer to the player's action deck
         */
Deck<ActionCard>* Player::getActionDeck() {
  return actiondeck_;
}

 /**
         * @post: set the point deck of the player
         * @param: A pointer to a deck holding Point cards
         */
void Player::setPointDeck(Deck<PointCard>* pointdeck) {
  pointdeck_ = pointdeck;
}

/**
         * @return: a pointer to the player's point deck
         */
Deck<PointCard>* Player::getPointDeck() {
  return pointdeck_;
}