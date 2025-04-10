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

		TEST_METHOD(TestEquilateralTriangle)
		{
			char* expected = "This is a triangle";
			char* actual = is_it_triangle(10, 10, 10);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestIsoscelesTriangle)
		{
			char* expected = "This is a triangle";
			char* actual = is_it_triangle(10, 10, 5);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestScaleneTriangle)
		{
			char* expected = "This is a triangle";
			char* actual = is_it_triangle(7, 10, 5);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestNotATriangle)
		{
			char* expected = "This is not a triangle";
			char* actual = is_it_triangle(1, 2, 3);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestZeroSides)
		{
			char* expected = "This is not a triangle";
			char* actual = is_it_triangle(0, 0, 0);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestNegativeSides)
		{
			char* expected = "This is not a triangle";
			char* actual = is_it_triangle(-1, -1, -1);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestOneSideZero)
		{
			char* expected = "This is not a triangle";
			char* actual = is_it_triangle(0, 10, 10);
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

		TEST_METHOD(TestMethod5) 
		{
			double expected = 0.9999999999999999;
			double actual = clamp(0.9999999999999999, -1.0, 1.0);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod6) 
		{
			double expected = -0.9999999999999999;
			double actual = clamp(-0.9999999999999999, -1.0, 1.0);
			Assert::AreEqual(expected, actual);
		}

	};
			
	TEST_CLASS(Calculate_Angles)
		{
		public:
			TEST_METHOD(TestEquilateralTriangle)
			{
				double angle_A, angle_B, angle_C;
				calculate_angles(10.0, 10.0, 10.0, &angle_A, &angle_B, &angle_C);
				double expected_A = 60.0;
				double expected_B = 60.0;
				double expected_C = 60.0;
				Assert::AreEqual(expected_A, angle_A, 0.0001);
				Assert::AreEqual(expected_B, angle_B, 0.0001);
				Assert::AreEqual(expected_C, angle_C, 0.0001);
			}

			TEST_METHOD(TestRightTriangle)
			{
				double angle_A, angle_B, angle_C;
				calculate_angles(3.0, 4.0, 5.0, &angle_A, &angle_B, &angle_C);
				double expected_A = 36.86989764584402;
				double expected_B = 53.13010235415599;
				double expected_C = 90.0;
				Assert::AreEqual(expected_A, angle_A, 0.01);
				Assert::AreEqual(expected_B, angle_B, 0.01);
				Assert::AreEqual(expected_C, angle_C, 0.01);
			}
	};
}
