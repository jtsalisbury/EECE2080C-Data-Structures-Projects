#include "stdafx.h"
#include "Objects.h"
#include <string>
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest) {
	public:
		
		TEST_METHOD(CardTest1)
		{
			Card* c = new Card(1, 1);
			std::string v = "Ace";
			std::string s = "Hearts";

			Assert::AreEqual(v, c->getPrettyName());
			Assert::AreEqual(s, c->getPrettySuit());
			Assert::AreEqual(1, c->getValue());
			Assert::AreEqual(1, c->getSuit());
		}

		TEST_METHOD(CardTest2)
		{
			Card* c = new Card(13, 4);
			const std::string v = "King";
			const std::string s = "Clubs";

			Assert::AreEqual(v, c->getPrettyName());
			Assert::AreEqual(s, c->getPrettySuit());
			Assert::AreEqual(13, c->getValue());
			Assert::AreEqual(4, c->getSuit());
		}

		TEST_METHOD(CardTest3)
		{
			Card* c = new Card(20, 7);
			const std::string v = "";
			const std::string s = "";

			Assert::AreEqual(v, c->getPrettyName());
			Assert::AreEqual(s, c->getPrettySuit());
			Assert::AreEqual(-1, c->getValue());
			Assert::AreEqual(-1, c->getSuit());
		}



		TEST_METHOD(DeckTest1)
		{
			Deck* d = new Deck();

			Assert::IsFalse(d->empty());
			Assert::IsFalse(nullptr == d->getNextCard());
		}

		TEST_METHOD(DeckTest2)
		{
			Deck* d = new Deck();

			for (int i = 0; i < 56; i++) {
				d->removeNextCard();
			}

			Assert::AreEqual(0, d->length());
			Assert::IsTrue(d->empty());
			Assert::IsFalse(d->removeNextCard());
		}

		TEST_METHOD(DeckTest3)
		{
			Deck* d = new Deck();
			const Card* c;

			c = d->getNextCard();
			d->removeNextCard();

			Assert::AreEqual(51, d->length());
			
			d->addCard(c);
			Assert::AreEqual(52, d->length());
		}


		TEST_METHOD(PlayerTest1)
		{
			Player* p = new Player();
			std::string s = "King";

			Assert::IsFalse(p->hasWinningStack());

			for (int i = 1; i <= 13; i++) {
				p->addCard(new Card(i, 1));
				p->pushToStack(0);
			}

			Assert::IsTrue(p->hasWinningStack());
			Assert::AreEqual(p->getStackTop(), s);
		}

		TEST_METHOD(PlayerTest2)
		{
			Player* p = new Player();
			Card* c = new Card(4, 4);

			p->addCard(c);

			Assert::IsFalse(p->canPushToStack(0));
			Assert::IsTrue(p->canDrawCard());
		}

		TEST_METHOD(PlayerTest3)
		{
			Player* p = new Player();

			for (int i = 1; i <= 6; i++) {
				p->addCard(new Card(i, 1));
			}

			Assert::IsTrue(p->canDiscardCard());
			Assert::IsFalse(p->canDrawCard());
			Assert::IsFalse(p->canEndTurn());
		}

		TEST_METHOD(WorldTest1)
		{
			World* w = new World();

			Assert::IsFalse(w->shouldGameEnd());
			Assert::IsFalse(w->shouldTurnEnd());
		}

		TEST_METHOD(WorldTest2) 
		{
			World* w = new World();
			w->startNewTurn();

			std::string s = "Player 1"; 
			std::string s2 = "None";

			Assert::AreEqual(s, w->getCurrentPlayer());
			Assert::AreEqual(s2, w->getPlayerStack());
		}

		TEST_METHOD(WorldTest3)
		{
			World* w = new World();
			w->startNewTurn();

			std::string s = "Player 2";
			std::string s2 = "";

			w->startNewTurn();

			Assert::AreEqual(s, w->getCurrentPlayer());
			Assert::AreEqual(s2, w->getPlayerHand());
		}

	};
}