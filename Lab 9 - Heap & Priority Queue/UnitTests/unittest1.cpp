#include "stdafx.h"
#include "CppUnitTest.h"

#include "Heap.h"
#include "PriorityQueue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(PriorityQueue1)
		{
			CPriorityQueue* c = new CPriorityQueue();
			std::string s1 = "3 2 1";
			std::string s2 = "";
			std::string s3 = "100 1";

			c->insert(1);
			c->insert(2);
			c->insert(3);

			Assert::AreEqual(3, c->getSize());
			Assert::AreEqual(s1, c->getString());

			c->insert(-1);

			Assert::AreEqual(s1 + " -1", c->getString());

			c->remove();
			c->remove();
			c->remove();
			c->remove();

			Assert::AreEqual(0, c->getSize());
			Assert::AreEqual(s2, c->getString());

			c->insert(100);
			c->insert(1);

			Assert::AreEqual(2, c->getSize());
			Assert::AreEqual(s3, c->getString());
		}
		TEST_METHOD(PriorityQueue2)
		{
			CPriorityQueue * c = new CPriorityQueue();

			Assert::AreEqual(0, c->getSize());

			c->insert(1);
			c->insert(2);
			c->insert(3);
			c->remove();

			Assert::AreEqual(2, c->getSize());

			c->insert(500);
			c->insert(500);

			Assert::AreEqual(4, c->getSize());

			c->remove();
			c->remove();
			c->remove();
			c->remove();

			Assert::AreEqual(0, c->getSize());
		}

		TEST_METHOD(Heap1)
		{
			CHeap* c = new CHeap();
			std::string s1 = "3000 42 100 7 29 10 75";
			std::string s2 = "42 29 10 7";
			std::string s3 = "29 10 7";

			c->insert(7);
			c->insert(75);
			c->insert(100);
			c->insert(42);
			c->insert(29);
			c->insert(10);
			c->insert(3000);

			Assert::AreEqual(7, c->getSize());
			Assert::AreEqual(s1, c->getString());

			c->remove();
			c->remove();
			c->remove();

			Assert::AreEqual(4, c->getSize());
			Assert::AreEqual(s2, c->getString());

			c->remove();

			Assert::AreEqual(3, c->getSize());
			Assert::AreEqual(s3, c->getString());
		}

		TEST_METHOD(Heap2)
		{
			CHeap* c = new CHeap();

			Assert::AreEqual(0, c->getSize());

			c->insert(7);
			c->insert(75);
			c->insert(100);
			c->insert(42);
			c->insert(29);
			c->insert(10);
			c->insert(3000);
			c->insert(-1);

			Assert::AreEqual(8, c->getSize());

			c->remove();
			c->remove();

			Assert::AreEqual(6, c->getSize());

			c->insert(500);
			c->insert(500);

			Assert::AreEqual(8, c->getSize());

			for (int i = 0; i < 8; i++) {
				c->remove();
			}
			
			Assert::AreEqual(0, c->getSize());
		}
	};
}