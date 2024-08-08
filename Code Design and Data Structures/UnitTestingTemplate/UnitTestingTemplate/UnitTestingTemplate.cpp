#include "CppUnitTest.h"
#include "Critter.h"
#include "HashTable.h"
#include "ObjectPool.h"

/*
Template Document For Building your CDDS Assessment Task 2 Unit Tests

Reference Link: https://learn.microsoft.com/en-us/visualstudio/test/how-to-use-microsoft-test-framework-for-cpp?view=vs-2022
Assert Class Reference Link: https://learn.microsoft.com/en-us/dotnet/api/microsoft.visualstudio.testtools.unittesting.assert?view=visualstudiosdk-2022
**You can use the assert reference above to view all the various calls you can make for pass/fail tests**


!!!Please note this is not the only way to structure a Unit Testing Project, you can refer to the top reference link for different project structures!!!

Testing your own data structures / classes:

1.Import your necessary .h and .cpp files you want to test the logic of
	a.Copy/Move your files into this projects solution directory
	b.Right click project in Solution Explore ("UnitTestingTemplate") and Select Add->Existing Item
	c.Select your copied/moved files to add

2.Include your header file at the top of this .cpp 

3.Write your 3 logical tests in the given TestMethodX 
*/

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestingTemplate
{
	TEST_CLASS(UnitTestingTemplate)
	{
	public:
		
		//Replace "TestMethod1" with a new name outlining what you are testing
		TEST_METHOD(TestMethod1)
		{


			Assert::AreEqual(1, 1);
		}

		//Replace "TestMethod2" with a new name outlining what you are testing
		TEST_METHOD(TestMethod2)
		{


			Assert::AreEqual(1, 1);
		}

		//Replace "TestMethod3" with a new name outlining what you are testing
		TEST_METHOD(TestMethod3)
		{


			Assert::AreEqual(1, 1);
		}
	};
}
