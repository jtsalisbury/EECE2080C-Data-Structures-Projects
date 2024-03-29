// Objects.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Objects.h"
#include <vector>
#include <algorithm>
#include <random>

#include <iostream>

// Easy assigning of card and suit names
std::string OBJECTS_API_CARD_NAMES[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
std::string OBJECTS_API_SUIT_NAMES[4] = { "Hearts", "Spades", "Diamonds", "Clubs" };

// Card constructor
Card::Card(int val, int s) {

	// Validate value conditions
	if (val < 1 || val > 13) {
		m_value = -1;
		prettyName = "";
	}
	else {
		m_value = val;
		prettyName = OBJECTS_API_CARD_NAMES[val - 1];
	}

	// Validate suit conditions
	if (s < 1 || s > 4) {
		m_suit = -1;
		prettySuit = "";
	}
	else {
		m_suit = s;
		prettySuit = OBJECTS_API_SUIT_NAMES[s - 1];
	}
}

// Card destructor
Card::~Card() {
}

// Return the pretty name of the card. "One, Two, etc"
std::string Card::getPrettyName() const {
	return prettyName;
}

// Return the numerical value of the card
int Card::getValue() const {
	return m_value;
}

// Return the pretty suit of the card. "Clubs, Hearts, etc"
std::string Card::getPrettySuit() const {
	return prettySuit;
}

// Return the numerical suit of the card
int Card::getSuit() const {
	return m_suit;
}



// Deck constructor
Deck::Deck() {
	std::vector<const Card*> t_deck;

	// Push a bunch of cards to a vector
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 13; j++) {
			t_deck.push_back(new const Card(j, i));
		}
	}

	// From stack overflow
	//https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector

	// Randomize the vector
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(t_deck), std::end(t_deck), rng);

	// Push the randomized vector to a queue
	for (int i = 0; i < t_deck.size(); i++) {
		deck->push(t_deck[i]);
	}
}

// Re-add a card to the deck
void Deck::addCard(const Card* card) {
	deck->push(card);
}

// Deck destructor. Empty the contents of the queue
Deck::~Deck() {
	while (!deck->empty()) {
		delete deck->front();

		deck->pop();
	}
	
	delete deck;
}

// Return the next card to be drawn
const Card* Deck::getNextCard() {
	if (deck->empty())
		return nullptr;

	return deck->front();
}

// Try to remove the next card from the deck
bool Deck::removeNextCard() {
	if (deck->empty())
		return false;

	deck->pop();

	return true;
}

// Return whether the deck is empty
bool Deck::empty() {
	return deck->empty();
}

// Return how many cards are in the deck
int Deck::length() {
	return deck->size();
}


// Player constructor
Player::Player() {
}

// Player destructor. Remove all cards from the stack
Player::~Player() {
	while (!m_running->empty()) {
		delete m_running->front();

		m_running->pop_front();
	}

	delete m_running;
}

// Add a card to the player's hand
void Player::addCard(const Card* card) {
	m_hand.push_back(card);
}

// Remove a card from the player's hand and add it to the bottom of the deck
void Player::discardCard(int index, Deck* deck) {

	deck->addCard(m_hand[index]);
	
	m_hand.erase(m_hand.begin() + index);

	m_hand.shrink_to_fit();
}

// Remove all 5 cards from the player's hand and push it back to the deck
void Player::resetHand(Deck* deck) {
	for (int i = 0; i < m_hand.size(); i++) {
		deck->addCard(m_hand[i]);
	}

	m_hand.clear();

	m_hand.shrink_to_fit();
}

// Return whether the top value of the running stack is a king
bool Player::hasWinningStack() {
	return !m_running->empty() && m_running->back()->getValue() == 13;
}

// Can the player push a card from their hand to their stack
bool Player::canPushToStack(int index) {
	if (m_hand[index]->getValue() == 1 && m_running->size() == 0) {
		return true;
	} else if (m_running->size() == 0) {
		return false;
	}

	return m_running->back()->getValue() == m_hand[index]->getValue() - 1;
}

bool Player::canDrawCard() {
	return m_hand.size() < 6;
}

bool Player::canDiscardCard() {
	return m_hand.size() > 5;
}

int Player::handLength() {
	return m_hand.size();
}

bool Player::canEndTurn() {
	return m_hand.size() == 5;
}

// Push a card from the hand to the stack
void Player::pushToStack(int index) {
	m_running->push_back(m_hand[index]);

	m_hand.erase(m_hand.begin() + index);
	m_hand.shrink_to_fit();
}

// Validate whether a hand position is valid (ex: try to remove 7th card)
bool Player::isValidIndex(int index) {
	if (index < 0 || index > m_hand.size()- 1) {
		return false;
	}

	return true;
}

// Turn the player's hand into a string
std::string Player::getHandString() {
	std::string str = "";

	for (int i = 0; i < m_hand.size(); i++) {
		str += m_hand[i]->getPrettyName() + ",";
	}

	return str.substr(0, str.length() - 1);
}

std::string Player::getStackTop() {
	return m_running->empty() ? "None" : m_running->back()->getPrettyName();
}


// World constructor
// m_availableOptions is a helper. It is reset at the begining of a turn. 
//		Each index is set to an option: 0 Turn End, etc. It is checked to make sure it can be called each turn.
World::World() {
	m_turnShouldEnd = false;

	curPly = p2;
}

// World destructor
World::~World() {
	delete p1;
	delete p2;
	delete curPly;
	delete deck;
}

bool World::shouldGameEnd() {
	return curPly->hasWinningStack();
}

// Helper to prevent repetitive code in the logic. 
// This constantly checks for invaid input or options.
int World::waitForInput(bool checkOptions) {
	int in;

	std::cin >> in;
	
	while ((in < 0 || in > 4) || (checkOptions && !m_availableOptions[in])) {
		std::cout << "Invalid option! Try again: ";

		std::cin >> in;
	}

	return in;
}

// Change the player
void World::startNewTurn() {
	curPly = (curPly == p1) ? p2 : p1;

	m_turnShouldEnd = false;
}

void World::resetOptions() {
	for (int i = 0; i < 5; i++) {
		m_availableOptions[i] = false;
	}
}

std::string World::getCurrentPlayer() {
	return (curPly == p1) ? "Player 1" : "Player 2";
}

// Grab all the options available for the player. Set the index of the available option to true so we don't have to retest it.
std::string World::getPlayerOptions(bool firstTurn) {
	std::string options = "";
	
	if (firstTurn) {
		options += "1: Pick Card\n";
		m_availableOptions[1] = true;

		if (curPly->handLength() == 5) {
			options += "4: Draw New Cards\n";
			m_availableOptions[4] = true;
		} 

		return options;
	}

	if (curPly->canEndTurn()) {
		options += "0: End Turn\n";
		m_availableOptions[0] = true;
	}
	if (curPly->canDrawCard()) {

		options += "1: Draw Card\n";
		m_availableOptions[1] = true;
	}

	if (curPly->canDiscardCard()) {

		options += "2: Discard Card\n";
		m_availableOptions[2] = true;
	}

	options += "3: Attempt to add card to stack\n";
	m_availableOptions[3] = true;

	return options;
}

// This contains the logic for an inputted option.
void World::parseInputOption(int option) {
	if (!m_availableOptions[option]) {
		return;
	}

	int input;
	if (option == 0) { // End Turn
		m_turnShouldEnd = true;
	}
	if (option == 1) { // Draw card
		curPly->addCard(deck->getNextCard());
		deck->removeNextCard();
	}
	if (option == 2) { // Discard card

		std::cout << "Enter card position in hand (1,2,...) or 0 to exit: ";
		input = waitForInput(false);

		if (input == 0)
			return;

		if (curPly->isValidIndex(input - 1)) 
			curPly->discardCard(input - 1, deck);

		m_turnShouldEnd = true;
			
	}
	if (option == 3) { // Push to stack
		std::cout << "Enter card position in hand (1,2,...) or 0 to exit: ";
		input = waitForInput(false);

		if (input == 0)
			return;

		if (curPly->isValidIndex(input - 1)) {
			if (!curPly->canPushToStack(input - 1)) {
				std::cout << "This card can't be pushed to the stack!" << std::endl;

				return;
			}

			curPly->pushToStack(input - 1);
		}
	}
	if (option == 4) { // Reset the hand
		while (curPly->canDiscardCard()) {
			curPly->discardCard(0, deck);
		}

		for (int i = 0; i < 5; i++) {
			curPly->addCard(deck->getNextCard());
			deck->removeNextCard();
		}

		m_turnShouldEnd = true;
	}
}

bool World::shouldTurnEnd() {
	return m_turnShouldEnd;
}

std::string World::getPlayerHand() {
	return curPly->getHandString();
}

std::string World::getPlayerStack() {
	return curPly->getStackTop();
}