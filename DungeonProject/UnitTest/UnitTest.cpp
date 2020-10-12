#include "pch.h"
#include "CppUnitTest.h"
#include "../Source/DungeonProject/DoorKey.h"
#include "../Source/DungeonProject/DungeonProjectCharacter.h"
#include "../Source/DungeonProject/Door.h"
#include "UObject/ConstructorHelpers.h""

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			class ADungeonProjectCharacter* character;
			class ADoorKey* key;
			class ADoor* door;

			key = NewObject

			key->Doors.Add(door);
			Assert::AreEqual(false, key->Interact(character));
		}
	};
}
