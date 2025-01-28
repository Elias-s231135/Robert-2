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

static bool operator==(Texture2D lhs, Texture2D rhs)
{
	if (lhs.format == rhs.format)
	{
		if (lhs.height == rhs.height)
		{
			if (lhs.id == rhs.id)
			{
				if (lhs.mipmaps == rhs.mipmaps)
				{
					if (lhs.width == rhs.width)
					{
						return true;
					}
				}
			}
		}
	}
	
	return false;
	

	//return true;
}

static bool operator==(Vector2 lhs, Vector2 rhs)
{
	if (lhs.x == rhs.x)
	{
		if (lhs.y == rhs.y)
		{
			return true;
		}
	}

	
	return false;
	
}

static bool operator==(Critter lhs, Critter rhs)
{
	if (lhs.GetPosition() == rhs.GetPosition())
	{
		if (lhs.GetRadius() == rhs.GetRadius())
		{
			if (lhs.GetVelocity() == rhs.GetVelocity())
			{
				if (lhs.IsDead() == rhs.IsDead())
				{
					if (lhs.IsDirty() == rhs.IsDirty())
					{
						return true;
					}
				}
			}
		}
	}
	
	
	return false;
	
}


namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<> static std::wstring ToString<Texture2D>(const Texture2D& t)
			{
				return L"Texture2D";
			}
			template<> static std::wstring ToString<Critter>(const Critter& t)
			{
				return L"Critter";
			}
		}
	}
}


namespace UnitTestingTemplate
{
	TEST_CLASS(UnitTestingTemplate)
	{
	public:
		
		//Replace "TestMethod1" with a new name outlining what you are testing
		TEST_METHOD(HashTableAddTo)
		{
			Texture2D testTexture = LoadTexture("res/download.png");

			HashTable TestHash(2);
			TestHash.AddTo("testImage", testTexture);

			Assert::AreEqual(TestHash["testImage"], testTexture);
		}

		//Replace "TestMethod2" with a new name outlining what you are testing
		TEST_METHOD(ObjectPoolAllocate)
		{
			Critter testCritter;

			ObjectPool testPool(2);

			testPool.Allocate(testCritter, 1);

			Assert::AreEqual(testPool.GetAlive()[1], testCritter);
		}

		//Replace "TestMethod3" with a new name outlining what you are testing
		TEST_METHOD(ObjectPoolDeallocate)
		{
			Critter testDeadCritter;

			ObjectPool testDeadPool(2);

			testDeadPool.Allocate(testDeadCritter, 1);
	
			testDeadPool.Deallocate(1);

			Assert::AreNotEqual(testDeadPool.GetAlive()[1], testDeadCritter);
		}
	};
}
