#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_3/Lab_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1_calculat_true)
		{
			double n = 7;
			double x = -4;
			double expected = -147;

			double actual = calculate(x, n);
			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(TestMethod2_calculat_true)
		{
			double n = 7;
			double x = 0;
			double expected = 0;

			double actual = calculate(x, n);
			Assert::AreEqual(expected, actual);

		}


		TEST_METHOD(TestMethod3_calculat_true)
		{
			double n = 4;
			double x = 3;
			double expected = 5.5;

			double actual = calculate(x, n);
			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(TestMethod3_calculat_false)
		{
			double n = 4;
			double x = 3;
			double expected = 5;

			double actual = calculate(x, n);
			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(CheckValidParams_true1)
		{
			double start = -5;
			double end = 5;
			bool expected = true;
			
			bool actual = checkStartAndEnd(start, end);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(CheckValidParams_true2)
		{
			double numberOfIteration = 4;
			bool expected = true;

			bool actual = checkValidNumberOfIteration(numberOfIteration);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(CheckValidParams_true3)
		{
			double step = 1.1;
			bool expected = true;

			bool actual = checkStep(step);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(CheckValidParams_false1)
		{
			double step = -7;
			
			try
			{
				checkStep(step);
				Assert::Fail();
			}
			catch (const char* ex) 
			{
				Assert::IsTrue(false);
			}

			
		}

		TEST_METHOD(CheckValidParams_false2)
		{
			double numberOfIteration = 0;

			try
			{
				checkValidNumberOfIteration(numberOfIteration);
				Assert::Fail();
			}
			catch (const char* ex)
			{
				Assert::IsTrue(false);
			}
		}


		TEST_METHOD(CheckValidParams_false3)
		{
			double start = 8;
			double end = -7;

			try
			{
				checkStartAndEnd(start, end);
				Assert::Fail();
			}
			catch (const char* ex)
			{
				Assert::IsTrue(false);
			}


		}
	};
}
