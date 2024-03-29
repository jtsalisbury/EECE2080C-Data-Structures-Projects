// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the OBJECTS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// OBJECTS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef OBJECTS_EXPORTS
#define OBJECTS_API __declspec(dllexport)
#else
#define OBJECTS_API __declspec(dllimport)
#endif

#include <queue>
#include <vector>
#include <stack>
#include <list>

// Card class
class OBJECTS_API Card {
	int m_value;
	int m_suit;

	std::string prettyName;
	std::string prettySuit;

public:
	Card(int value, int suit);
	~Card();

	std::string getPrettyName() const;
	std::string getPrettySuit() const;

	int getValue() const;
	int getSuit() const;
};

// Deck class
class OBJECTS_API Deck {
	std::queue<const Card*>* deck = new std::queue<const Card*>();

public:
	Deck();
	~Deck();

	const Card* getNextCard();

	bool removeNextCard();
	bool empty();

	void addCard(const Card* card);

	int length();
};

// Player class
class OBJECTS_API Player {
	std::vector<const Card*> m_hand;
	std::list<const Card*>* m_running = new std::list<const Card*>();

public:
	Player();
	~Player();

	void addCard(const Card* card);
	void discardCard(int index, Deck* deck);
	void resetHand(Deck* deck);
	void pushToStack(int index);

	bool hasWinningStack();
	bool canPushToStack(int index);
	bool canDrawCard();
	bool canDiscardCard();
	bool isValidIndex(int index);
	bool canEndTurn();

	int handLength();
	
	std::string getHandString();
	std::string getStackTop();
};

// World class
class OBJECTS_API World {
private:
	Player* p1 = new Player();
	Player* p2 = new Player();
	Player* curPly;
	Deck* deck = new Deck();

	bool m_turnShouldEnd;
	bool m_availableOptions[5];

public:
	World();
	~World();

	bool shouldGameEnd();
	bool shouldTurnEnd();

	std::string getPlayerOptions(bool firstTurn);
	std::string getCurrentPlayer();
	std::string getPlayerHand();
	std::string getPlayerStack();

	int waitForInput(bool checkOptions);

	void startNewTurn();
	void parseInputOption(int option);
	void resetOptions();
};