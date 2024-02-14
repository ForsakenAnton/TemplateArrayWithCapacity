#pragma once
#include "Shared.h"

template<typename T>
class TemplateArray
{
private:
	int size;
	int capacity;
	T* arr;

	void incrementSize();
	void decrementSize();

	void increaseCapacity();
	void reduceCapacity();
	void resizeArray();

	//void newMemory();

public:
	explicit TemplateArray(int capacity = MIN_CAPACITY);
	~TemplateArray();

	bool isEmpty();
	int getSize() const;
	int getCapacity();

	void print();
	void printWithCapacityMemoryForDebug();

	T& getFirstByRef();
	T& getLastByRef();

	void freeExtraMemory();

	//void pushBack(const T item);
	void pushBack(const T& item);
	void removeBack();
	void removeAll();

	//void setAt(int index, const T item);
	void setAt(int index, const T& item);

	T& getAt(int index) const;
	T& operator [] (int index);
	T operator [] (int index) const;

	//void insertAt(int index, const T item);
	void insertAt(int index, const T& item);
	void removeAt(int index);

	void append(T* arr);
	void append(const TemplateArray<T>& templateArr);
};

//#include "TemplateArray.inl"

template<typename T>
void TemplateArray<T>::incrementSize()
{
	size++;
}

template<typename T>
void TemplateArray<T>::decrementSize()
{
	size--;
}

template<typename T>
void TemplateArray<T>::increaseCapacity()
{
	capacity *= CAPACITY_STEP;
	resizeArray();
}

template<typename T>
void TemplateArray<T>::reduceCapacity()
{
	capacity /= CAPACITY_STEP;
	resizeArray();
}

template<typename T>
void TemplateArray<T>::resizeArray()
{
	T* tempArr = new T[capacity]{ };
	for (int i = 0; i < size; i++)
	{
		tempArr[i] = arr[i];
	}

	delete[] arr;
	arr = tempArr;

	tempArr = nullptr;
}

//template<typename T>
//void TemplateArray<T>::newMemory()
//{
//	arr = new int[capacity];
//}

template<typename T>
TemplateArray<T>::TemplateArray(int capacity)
	: size{ 0 },
	capacity{ capacity },
	arr{ new T[capacity]{ } }
{
}

template<typename T>
TemplateArray<T>::~TemplateArray()
{
	if (arr != nullptr)
	{
		delete[] arr;
	}
}

template<typename T>
bool TemplateArray<T>::isEmpty()
{
	return size == 0;
}

template<typename T>
int TemplateArray<T>::getSize() const
{
	return size;
}

template<typename T>
int TemplateArray<T>::getCapacity()
{
	return capacity;
}

template<typename T>
void TemplateArray<T>::print()
{
	cout << "Size: " << size << endl;
	cout << "Capacity: " << capacity << endl;

	cout << "Array:\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

template<typename T>
void TemplateArray<T>::printWithCapacityMemoryForDebug()
{
	cout << "printWithCapacityMemoryForDebug()\n";

	cout << "Size: " << size << endl;
	cout << "Capacity: " << capacity << endl;

	cout << "Array from zero to size:\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "Array from size to capacity:\n";
	for (int i = size; i < capacity; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

template<typename T>
T& TemplateArray<T>::getFirstByRef()
{
	isEmpty() ? 
		throw exception("Array is empty") : 
		arr[0];
}

template<typename T>
T& TemplateArray<T>::getLastByRef()
{
	isEmpty() ? 
		throw exception("Array is empty") : 
		arr[size - 1];
}

template<typename T>
void TemplateArray<T>::freeExtraMemory()
{
	if (isEmpty() || capacity <= 16)
	{
		return;
	}

	capacity = size;
	resizeArray();
}


//template<typename T>
//void TemplateArray<T>::pushBack(const T item)
//{
//	pushBack(item);
//}

template<typename T>
void TemplateArray<T>::pushBack(const T& item)
{
	if (size == capacity)
	{
		increaseCapacity();
	}

	arr[size] = item;
	incrementSize();
}

template<typename T>
void TemplateArray<T>::removeBack()
{
	if (isEmpty())
	{
		return;
	}
	else if (size == capacity / CAPACITY_STEP &&
		capacity / CAPACITY_STEP >= 16)
	{
		reduceCapacity();
	}

	int removedIndex = size - 1;
	arr[removedIndex] = T();
	decrementSize();
}

template<typename T>
inline void TemplateArray<T>::removeAll()
{
	size = 0;
	capacity = MIN_CAPACITY;
	if (arr != nullptr)
	{
		delete[] arr;
		arr = new T[capacity]{ };
	}
}


//template<typename T>
//void TemplateArray<T>::setAt(int index, const T item)
//{
//	setAt(index, item);
//}

template<typename T>
void TemplateArray<T>::setAt(int index, const T& item)
{
	if (index >= getSize() || index < 0)
	{
		throw exception("Index is out of range\n");
	}

	//arr[index] = std::forward<T>(item); 0_o
	arr[index] = item;
}


template<typename T>
T& TemplateArray<T>::getAt(int index) const
{
	index = index - 1;
	if (index >= getSize() || index < 0)
	{
		throw exception("Index is out of range\n");
	}

	return arr[index];
}

template<typename T>
T& TemplateArray<T>::operator[](int index)
{
	return getAt(index);
}

template<typename T>
T TemplateArray<T>::operator[](int index) const
{
	return getAt(index);
}


//template<typename T>
//void TemplateArray<T>::insertAt(int index, const T item)
//{
//	insertAt(index, item);
//}

template<typename T>
void TemplateArray<T>::insertAt(int index, const T& item)
{
	index = index - 1;
	if (index >= getSize() || index < 0)
	{
		throw exception("Index is out of range\n");
	}

	if (size == capacity)
	{
		increaseCapacity();
	}

	incrementSize();

	for (int currentIndex = size - 1, previousIndex = size - 2;
		currentIndex > index;
		currentIndex--, previousIndex--)
	{
		arr[currentIndex] = arr[previousIndex];
		if (index == previousIndex)
		{
			arr[previousIndex] = item;
			break;
		}
	}
}

template<typename T>
void TemplateArray<T>::removeAt(int index)
{
	index = index - 1;
	if (index >= getSize() || index < 0)
	{
		throw exception("Index is out of range\n");
	}
	else if (size == capacity / CAPACITY_STEP &&
		capacity / CAPACITY_STEP >= 16)
	{
		reduceCapacity();
	}

	decrementSize();

	for (int currentIndex = index, nextIndex = index + 1;
		currentIndex < size;
		currentIndex++, nextIndex++)
	{
		arr[currentIndex] = arr[nextIndex];
	}
}

template<typename T>
void TemplateArray<T>::append(T* arr)
{
	if (arr == nullptr)
	{
		return;
	}

	auto size = _msize(arr) / sizeof(arr[0]);

	for (int i = 0; i < size; i++)
	{
		this->pushBack(arr[i]);
	}
}

template<typename T>
void TemplateArray<T>::append(const TemplateArray<T>& templateArr)
{
	if (templateArr.arr == nullptr)
	{
		return;
	}

	//auto size = _msize(templateArr.arr) / sizeof(templateArr.arr[0]);

	for (int i = 0; i < templateArr.getSize(); i++)
	{
		this->pushBack(templateArr.arr[i]);
	}
}
