#include "pch.h"
#include "CppUnitTest.h"

extern "C" {

#include "../CSCN71020_Group1/functions.h"

}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleUnitTest {

	TEST_CLASS(TestPerimeter) {

	public:

		
		TEST_METHOD(TestMethod1) {

		float expected = 12.00;
		float actual = calculate_perimeter(3, 3);
		Assert::AreEqual(expected, actual);

		}

	};

	// Functional Test
	TEST_CLASS(TestArea) {

	public:

		
		TEST_METHOD(TestMethod1) {

		float expected = 9.00;
		float actual = calculate_area(3, 3);
		Assert::AreEqual(expected, actual);

		}

	};




		TEST_CLASS(TestIsItRectangle) {
	
		public:

			// Functional Test
			TEST_METHOD(TestMethod1) {
		
				float lines[6] = {5,5,4,4,3,3};
				int expected = 0;
				int actual = IsitRectangle(lines);
				Assert::AreEqual(expected, actual);
		
			}

			TEST_METHOD(TestMethod2) {
		
				float lines[6] = { 2,5,3,4,3,4 };
				int expected = 1;
				int actual = IsitRectangle(lines);
				Assert::AreEqual(expected, actual);


			}

			TEST_METHOD(TestMethod3) {

				float lines[6] = { 4,4,4,4,4,4 };
				int expected = 1;
				int actual = IsitRectangle(lines);
				Assert::AreEqual(expected, actual);


			}
	
		};

	}
