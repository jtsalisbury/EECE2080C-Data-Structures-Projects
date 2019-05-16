#include "stdafx.h"
#include "CppUnitTest.h"
#include "LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(ArrayBasedLinkedListTest1)
		{
			ArrayBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));
			Assert::IsTrue(linkedList.add(2));
			Assert::IsTrue(linkedList.add(3));
			Assert::IsTrue(linkedList.add(4));
			Assert::IsTrue(linkedList.add(5));
			Assert::IsTrue(linkedList.add(6));
			Assert::IsTrue(linkedList.add(7));
			Assert::IsTrue(linkedList.add(8));
			Assert::IsTrue(linkedList.add(9));
			Assert::IsTrue(linkedList.add(10));
			Assert::IsFalse(linkedList.add(11));

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("1 2 3 4 5 6 7 8 9 10"), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

		TEST_METHOD(ArrayBasedLinkedListTest2)
		{
			ArrayBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));
			Assert::IsTrue(linkedList.add(2));
			Assert::IsTrue(linkedList.add(3));
			Assert::IsTrue(linkedList.add(4));
			Assert::IsTrue(linkedList.add(5));
			Assert::IsTrue(linkedList.add(6));
			Assert::IsTrue(linkedList.add(7));
			Assert::IsTrue(linkedList.add(8));
			Assert::IsTrue(linkedList.add(9));
			Assert::IsTrue(linkedList.add(10));
			Assert::IsFalse(linkedList.add(11));

			Assert::IsTrue(linkedList.remove(2));
			Assert::IsTrue(linkedList.remove(4));
			Assert::IsTrue(linkedList.remove(6));
			Assert::IsTrue(linkedList.remove(8));

			Assert::IsFalse(linkedList.remove(2));
			Assert::IsFalse(linkedList.remove(4));
			Assert::IsFalse(linkedList.remove(6));
			Assert::IsFalse(linkedList.remove(8));

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("1 3 5 7 9 10"), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

		TEST_METHOD(PointerBasedLinkedListTest1)
		{
			PointerBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));
			Assert::IsTrue(linkedList.add(2));
			Assert::IsTrue(linkedList.add(3));
			Assert::IsTrue(linkedList.add(4));
			Assert::IsTrue(linkedList.add(5));
			Assert::IsTrue(linkedList.add(6));
			Assert::IsTrue(linkedList.add(7));
			Assert::IsTrue(linkedList.add(8));
			Assert::IsTrue(linkedList.add(9));
			Assert::IsTrue(linkedList.add(10));
			Assert::IsTrue(linkedList.add(11));

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("1 2 3 4 5 6 7 8 9 10 11"), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

		TEST_METHOD(PointerBasedLinkedListTest2)
		{
			PointerBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));
			Assert::IsTrue(linkedList.add(2));
			Assert::IsTrue(linkedList.add(3));
			Assert::IsTrue(linkedList.add(4));
			Assert::IsTrue(linkedList.add(5));
			Assert::IsTrue(linkedList.add(6));
			Assert::IsTrue(linkedList.add(7));
			Assert::IsTrue(linkedList.add(8));
			Assert::IsTrue(linkedList.add(9));
			Assert::IsTrue(linkedList.add(10));
			Assert::IsTrue(linkedList.add(11));

			Assert::IsTrue(linkedList.remove(2));
			Assert::IsTrue(linkedList.remove(4));
			Assert::IsTrue(linkedList.remove(6));
			Assert::IsTrue(linkedList.remove(8));

			Assert::IsFalse(linkedList.remove(2));
			Assert::IsFalse(linkedList.remove(4));
			Assert::IsFalse(linkedList.remove(6));
			Assert::IsFalse(linkedList.remove(8));

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("1 3 5 7 9 10 11"), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

	};
}