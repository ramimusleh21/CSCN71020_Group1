#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" {
#include "../CSCN71020_Group1/functions.h"
}

namespace TriangleUnitTest
{
	TEST_CLASS(TestNonNumeric)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			bool expected = true;
			bool actual = validate_triangle_input("100");
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestMethod2)
		{
			bool expected = false;
			bool actual = validate_triangle_input("100%");
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod3)
		{
			bool expected = false;
			bool actual = validate_triangle_input("*");
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod4)
		{
			bool expected = false;
			bool actual = validate_triangle_input("1..0");
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod5)
		{
			bool expected = false;
			bool actual = validate_triangle_input("1.02.55");
			Assert::AreEqual(expected, actual);
		}
	};


	TEST_CLASS(TestIsItTriangle)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char* expected = "This is a triangle";
			char* actual = is_it_triangle(10, 10, 10);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod2)
		{
			char* expected = "This is not a triangle";
			char* actual = is_it_triangle(1, 2, 3);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod3)
		{
			char* expected = "This is not a triangle";
			char* actual = is_it_triangle(0, 0, 0);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod4)
		{
			char* expected = "This is not a triangle";
			char* actual = is_it_triangle(0, 0, 0);
			Assert::AreEqual(expected, actual);
		}
		
	};

	TEST_CLASS(ClampFunction)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			double expected = -1.0;
			double actual = clamp(-1.0, -1.0, 1.0);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod2)
		{
			double expected = 1.0;
			double actual = clamp(1.0, -1.0, 1.0);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod3)
		{
			double expected = -1.0;
			double actual = clamp(-2.0, -1.0, 1.0);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod4)
		{
			double expected = 1.0;
			double actual = clamp(2.0, -1.0, 1.0);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod5) // boundary
		{
			double expected = 0.9999999999999999;
			double actual = clamp(0.9999999999999999, -1.0, 1.0);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod6) // boundary
		{
			double expected = -0.9999999999999999;
			double actual = clamp(-0.9999999999999999, -1.0, 1.0);
			Assert::AreEqual(expected, actual);
		}
	};
}
