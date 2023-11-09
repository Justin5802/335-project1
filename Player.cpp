#include "Player.hpp"


Player::Player() : score_(0), opponent_(nullptr), actiondeck_(nullptr), pointdeck_(nullptr) {}

Player::~Player() {}
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


void Player::drawPointCard() {
  if(pointdeck_ && !pointdeck_->IsEmpty()) {
    hand_.addCard(std::move(pointdeck_->Draw()));
  }
}

void Player::playPointCard() {
  if(!hand_.isEmpty()) {
    setScore(getScore() + hand_.PlayCard());
  }
}

void Player::setOpponent(Player* opponent) {
  opponent_ = opponent;
}

Player* Player::getOpponent() {
  return opponent_;
}

void Player::setActionDeck(Deck<ActionCard>* actiondeck) {
  actiondeck_ = actiondeck;
}

Deck<ActionCard>* Player::getActionDeck() {
  return actiondeck_;
}

void Player::setPointDeck(Deck<PointCard>* pointdeck) {
  pointdeck_ = pointdeck;
}

Deck<PointCard>* Player::getPointDeck() {
  return pointdeck_;
}