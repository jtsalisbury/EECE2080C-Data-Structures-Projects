#include "stdafx.h"
#include "CppUnitTest.h"
#include "RecursionList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace UnitTest1
{		
	TEST_CLASS(UnitTestFactorial)
	{
	public:
		
		TEST_METHOD(Loop1)
		{
			FactorialByLoop calculator;

			int val = calculator.CalculateFactorial(3);
			Assert::AreEqual(6, val);

			Assert::AreEqual(24, calculator.CalculateFactorial(4));
			Assert::AreEqual(120, calculator.CalculateFactorial(5));
			Assert::AreEqual(720, calculator.CalculateFactorial(6));
			Assert::AreEqual(5040, calculator.CalculateFactorial(7));
			Assert::AreEqual(40320, calculator.CalculateFactorial(8));
			Assert::AreEqual(362880, calculator.CalculateFactorial(9));
			Assert::AreEqual(3628800, calculator.CalculateFactorial(10));
		}

		TEST_METHOD(Loop2)
		{
			FactorialByLoop calculator;

			int val = calculator.CalculateFactorial(10);

			Assert::AreEqual(3628800, val);
		}

		TEST_METHOD(Recursion1)
		{
			FactorialByRecursion calculator;

			int val = calculator.CalculateFactorial(3);

			Assert::AreEqual(6, val);
			Assert::AreEqual(24, calculator.CalculateFactorial(4));
			Assert::AreEqual(120, calculator.CalculateFactorial(5));
			Assert::AreEqual(720, calculator.CalculateFactorial(6));
			Assert::AreEqual(5040, calculator.CalculateFactorial(7));
			Assert::AreEqual(40320, calculator.CalculateFactorial(8));
			Assert::AreEqual(362880, calculator.CalculateFactorial(9));
			Assert::AreEqual(3628800, calculator.CalculateFactorial(10));
		}

		TEST_METHOD(Recursion2)
		{
			FactorialByRecursion calculator;

			int val = calculator.CalculateFactorial(10);

			Assert::AreEqual(3628800, val);

		}

		TEST_METHOD(Recursion3)
		{
			FactorialByRecursion calculator;

			int val = calculator.CalculateFactorial(5000);

			Assert::AreEqual(100, val);

		}

		TEST_METHOD(Stack1)
		{
			FactorialByStack calculator;

			int val = calculator.CalculateFactorial(3);

			Assert::AreEqual(6, val);

		}

		TEST_METHOD(Stack2)
		{
			FactorialByStack calculator;

			int val = calculator.CalculateFactorial(10);

			Assert::AreEqual(3628800, val);


		}

		TEST_METHOD(UserDefinedException1)
		{

			try
			{
				SimpleExceptionMethod(1);
				//Did not throw exception
				Assert::Fail();
			}
			catch (MyException m)
			{
				//Good 
			}
			catch (std::exception e)
			{
				//Bad Did not catch user defined exception
				Assert::Fail();
			}


			try
			{
				SimpleExceptionMethod(-1);
				//Did not throw exception
				Assert::Fail();
			}
			catch (MyException m)
			{
				// Good
			}
			catch (std::exception e)
			{
				//Bad Did not catch user defined exception
				Assert::Fail();
			}

		}



	};
}