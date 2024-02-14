#include "TemplateArray.h"
#include "TodoItem.h"

int main()
{
	try
	{
		TemplateArray<int> intArray;

		////Test Capacity with add(T item) and remove() methods()

		intArray.pushBack(1);
		intArray.pushBack(1); // &&
		intArray.pushBack(2); // &&

		int leftValueNumber = 3;
		intArray.pushBack(leftValueNumber); // &

		intArray.print();

		intArray.removeBack();
		intArray.removeBack();
		intArray.removeBack();
		intArray.removeBack();
		intArray.print();

		for (int i = 0; i < 18; i++)
		{
			intArray.pushBack(i);
		}
		intArray.print();

		intArray.removeBack();
		intArray.removeBack();
		intArray.removeBack();
		intArray.print();

		for (int i = 0; i < 5000; i++)
		{
			intArray.pushBack(i);
		}
		intArray.print();

		for (int i = 0; i < 10000; i++)
		{
			intArray.removeBack();
		}
		intArray.print();
		//////////////////////////////////////////////////


		// Test with structure (without dynamic data)
		TemplateArray<TodoItem> todoItems;
		for (int i = 0; i < 3; i++)
		{
			todoItems.pushBack(TodoItem
				{
					"Action " + to_string(i), (i % 2 == 0 ? true : false)
				});
		}

		TodoItem leftValueAction{ "Left-value action", true };
		todoItems.pushBack(leftValueAction); // &

		todoItems.print();

		for (int i = 0; i < 150; i++)
		{
			todoItems.removeBack();
		}
		todoItems.print();
		// ///////////////////////////////////////////////////////////////////////



		// getAt
		// setAt
		// With intArray
		for (int i = 0; i < 15; i++)
		{
			intArray.pushBack(i);
		}
		intArray.print();


		cout << intArray.getAt(4) << endl;

		intArray.setAt(10, 666);
		intArray.setAt(11, 888);
		int someNumber = 123456;
		intArray.setAt(12, someNumber);

		cout << intArray.getAt(10) << endl;
		cout << intArray.getAt(11) << endl << endl;

		intArray.print();
		// /////////////////////////////////////////////////

		// insertAt
		// removeAt
		intArray.insertAt(13, 100);
		intArray.print();

		intArray.insertAt(13, 200);
		intArray.print();


		intArray.removeAt(13);
		intArray.printWithCapacityMemoryForDebug();
		intArray.removeAt(13);
		intArray.printWithCapacityMemoryForDebug();


		intArray.removeAt(1);
		intArray.removeAt(intArray.getSize());
		intArray.printWithCapacityMemoryForDebug();
		///////////////////////////////////////////////////



		// freeExtraMemory
		for (int i = 0; i < 64; i++)
		{
			intArray.pushBack(i);
		}
		intArray.print();

		intArray.freeExtraMemory();
		intArray.printWithCapacityMemoryForDebug();

		for (int i = 0; i < 500; i++)
		{
			intArray.pushBack(i);
		}
		intArray.printWithCapacityMemoryForDebug();

		for (int i = 0; i < 500; i++)
		{
			intArray.removeBack();
		}
		intArray.printWithCapacityMemoryForDebug();

		for (int i = 0; i < 70; i++)
		{
			intArray.removeBack();
		}
		intArray.printWithCapacityMemoryForDebug();
		// ////////////////////////////////////////////////////////////


		// append(T& arr)
		// append(TemplateArray<T>& arr)
		intArray.removeAll();

		int* someArr = new int[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		intArray.append(someArr);
		intArray.printWithCapacityMemoryForDebug();

		intArray.append(someArr);
		intArray.append(someArr);
		intArray.append(someArr);
		intArray.append(someArr);
		intArray.append(someArr);
		intArray.append(someArr);
		intArray.printWithCapacityMemoryForDebug();

		TemplateArray<int> newIntArray;
		newIntArray.append(someArr);
		newIntArray.append(someArr);

		intArray.append(newIntArray);
		intArray.printWithCapacityMemoryForDebug();

		delete[] someArr;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}