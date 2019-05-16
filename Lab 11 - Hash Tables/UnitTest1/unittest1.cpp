#include "stdafx.h"
#include "CppUnitTest.h"
#include "Classes.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(AddTest1)
		{
			CHash * hash = new CHash(100);

			std::string key = "rewq";
			int value = 4;
			CNode * t = new CNode(key, value);

			key = "qwer";
			value = 2;
			t = new CNode(key, value);

			Assert::IsTrue(hash->addItem(t));
		}
		TEST_METHOD(AddTest2)
		{
			CHash * hash = new CHash(2);

			std::string key = "poiuytr";
			int value = 3;
			CNode* t = new CNode(key, value);
			hash->addItem(t);

			key = "poiuytreq";
			value = 76;
			t = new CNode(key, value);
			hash->addItem(t);

			key = "poi";
			value = 12;
			t = new CNode(key, value);

			Assert::IsFalse(hash->addItem(t));
		}
		TEST_METHOD(RemoveTest1)
		{
			CHash * hash = new CHash(100);

			std::string key = "asdf";
			int value = 8;
			CNode * t = new CNode(key, value);
			hash->addItem(t);

			Assert::IsTrue(hash->removeItem(key) == t);
		}
		TEST_METHOD(RemoveTest2)
		{
			CHash * hash = new CHash(100);

			std::string key = "asdf";
			int value = 8;
			CNode* t1 = new CNode(key, value);
			hash->addItem(t1);

			key = "asdf";
			value = 123;
			CNode* t2 = new CNode(key, value);
			hash->addItem(t2);

			Assert::IsTrue(hash->removeItem(key) == t1);
		}
		TEST_METHOD(GetItemTest1)
		{
			CHash* hash = new CHash(100);

			std::string key = "asdf";
			int value = 8;
			CNode* t = new CNode(key, value);
			hash->addItem(t);

			Assert::IsTrue(hash->getItem(key) == t);
		}
		TEST_METHOD(GetItemTest2)
		{
			CHash* hash = new CHash(100);

			std::string key = "asdf";
			int value = 8;
			CNode* t = new CNode(key, value);
			hash->addItem(t);

			key = "asdf";
			value = 123;
			CNode* t2 = new CNode(key, value);
			hash->addItem(t2);

			Assert::IsTrue(hash->getItem(key) == t);
			
		}
		TEST_METHOD(GetLengthTest1)
		{
			CHash* hash = new CHash(100);

			std::string key = "asdf";
			int value = 8;
			CNode* t = new CNode(key, value);
			hash->addItem(t);

			Assert::AreEqual(1, hash->getLength());

			hash->removeItem(key);

			Assert::AreEqual(0, hash->getLength());
		}
		TEST_METHOD(GetLengthTest2)
		{
			CHash* hash = new CHash(100);

			Assert::AreEqual(0, hash->getLength());
		}

		TEST_METHOD(HashTest1) 
		{
			CHash* h = new CHash(100);

			std::string k = "asdf";
			Assert::AreEqual(14, h->hash(k));
			
			k = "";
			Assert::AreEqual(0, h->hash(k));
		}

		TEST_METHOD(HashTest2) 
		{
			CHash* h = new CHash(200);

			std::string k = "hello";
			Assert::AreEqual(132, h->hash(k));
		}
	};
}