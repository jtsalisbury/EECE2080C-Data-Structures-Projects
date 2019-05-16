#include "stdafx.h"
#include "CppUnitTest.h"
#include "Classes.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(constructorTest1) {
			Graph * g = new Graph(7);

			Assert::AreEqual(7, g->getSize());
		}

		TEST_METHOD(constructorTest2) {
			Graph * g = new Graph();

			Assert::AreEqual(0, g->getSize());
		}
		TEST_METHOD(outEdgeTest1)
		{
			Graph * g = new Graph(7);
			g->addEdge(1, 2);
			g->addEdge(4, 6);

			int fromVertice = 1;
			int toVertice = 2;
			vector<int> out = g->outEdges(fromVertice);
			bool contains = false;

			for (int i = 0; i < out.size(); i++) {
				if (out[i] == toVertice)
					contains = true;
			}

			Assert::AreEqual(true, contains);
		}
		TEST_METHOD(outEdgeTest2)
		{
			Graph * g = new Graph(7);
			g->addEdge(1, 2);
			g->addEdge(4, 6);

			int fromVertice = 4;
			int toVertice = 6;
			vector<int> out = g->outEdges(fromVertice);
			bool contains = false;

			for (int i = 0; i < out.size(); i++) {
				if (out[i] == toVertice)
					contains = true;
			}

			Assert::AreEqual(true, contains);
		}
		TEST_METHOD(inEdgeTest1) {
			Graph * g = new Graph(7);
			g->addEdge(1, 2);
			g->addEdge(4, 6);

			int fromVertice = 1;
			int toVertice = 2;
			vector<int> in = g->inEdges(toVertice);
			bool contains = false;

			for (int i = 0; i < in.size(); i++) {
				if (in[i] == fromVertice)
					contains = true;
			}

			Assert::AreEqual(true, contains);
		}
		TEST_METHOD(inEdgeTest2) {
			Graph * g = new Graph(7);
			g->addEdge(1, 2);
			g->addEdge(4, 6);

			int fromVertice = 4;
			int toVertice = 6;
			vector<int> in = g->inEdges(toVertice);
			bool contains = false;

			for (int i = 0; i < in.size(); i++) {
				if (in[i] == fromVertice)
					contains = true;
			}

			Assert::AreEqual(true, contains);
		}
		TEST_METHOD(addEdgeTest1)
		{
			Graph * g = new Graph(7);
			g->addEdge(1, 2);
			g->addEdge(1, 2);
			Assert::AreEqual(true, g->hasEdge(1, 2));

		}
		TEST_METHOD(addEdgeTest2) {
			Graph * g = new Graph(7);
			g->addEdge(1, 2);
			g->addEdge(8, 6);
			Assert::AreEqual(true, g->hasEdge(1, 2));
			Assert::AreEqual(false, g->hasEdge(8, 6));
		}

		TEST_METHOD(hasEdgeTest1) {
			Graph * g = new Graph(7);
			g->addEdge(1, 2);
			g->addEdge(2, 1);

			Assert::AreEqual(true, g->hasEdge(1, 2));
			Assert::AreEqual(true, g->hasEdge(2, 1));
		}

		TEST_METHOD(hasEdgeTest2) {
			Graph * g = new Graph(7);
			g->addEdge(6, 6);
			g->addEdge(0, 0);

			Assert::AreEqual(true, g->hasEdge(6, 6));
			Assert::AreEqual(true, g->hasEdge(0, 0));
		}

		TEST_METHOD(removeEdgeTest1) {
			Graph * g = new Graph(7);
			g->addEdge(1, 6);
			g->addEdge(0, 5);

			Assert::AreEqual(true, g->hasEdge(1, 6));
			Assert::AreEqual(true, g->hasEdge(0, 5));

			g->removeEdge(1, 6);
			g->removeEdge(0, 5);

			Assert::AreEqual(false, g->hasEdge(1, 6));
			Assert::AreEqual(false, g->hasEdge(0, 5));
		}

		TEST_METHOD(removeEdgeTest2) {
			Graph * g = new Graph(7);
			g->addEdge(1, 6);
			g->addEdge(0, 5);

			g->removeEdge(2, 4);
			g->removeEdge(1, 3);

			Assert::AreEqual(true, g->hasEdge(1, 6));
			Assert::AreEqual(true, g->hasEdge(0, 5));
		}
	};
}