#include "pch.h"
#include "CppUnitTest.h"
#include "..//Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73rec
{
	TEST_CLASS(UnitTest73rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int z;
			int** a = new int* [0, 1];
			int n = 2;
			z = Num(a, n);
			Assert::AreEqual(z, 1);
		}
	};
}
