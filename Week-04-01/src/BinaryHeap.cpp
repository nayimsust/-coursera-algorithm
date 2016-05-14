//============================================================================
// Name        : BinaryHeap.cpp
// Author      : nayimsust@gmail.com
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;



template<typename T> class MaxHeap {

	T *tData;
	int iSize;

public:
	MaxHeap(int iSize = 1);
	~MaxHeap();
	void ResizeArray(int iSize);

	bool IsEmpty();
	int Size();
	void Insert();
	T Delete();
	void Swim(int iChildIndex);
	void Sink(int iParentIndex, int iSize);

	void Exchange(T a, T b);
};

template<typename T> void MaxHeap<T>::ResizeArray(int iSize) {

	T *pArray = new T[iSize*2 + 1];
	for(int i = 1; i <= iSize; ++i)
		pArray[i] = tData[i];

	if(tData)
		delete[]tData;

	tData = pArray;
}

template<typename T> MaxHeap<T>::MaxHeap(int iSize) {
	tData = new T[iSize+1];
	this->iSize = iSize;
}

template<typename T> MaxHeap<T>::~MaxHeap() {
	if(tData) delete[] tData;
}

template<typename T> bool MaxHeap<T>::IsEmpty() {
	return iSize <= 0 ? true : false;
}

template<typename T> int MaxHeap<T>::Size() {
	return iSize;
}

template<typename T> void MaxHeap<T>::Insert() {

}

template<typename T> T MaxHeap<T>::Delete() {

}

template<typename T> void MaxHeap<T>::Swim(int iChildIndex) {

	if(iChildIndex > 1) {
		int iParent = iChildIndex / 2;
		if(tData[iChildIndex] > tData[iParent]) {
			Exchange(tData[iChildIndex], tData[iParent]);
			Swim(iParent);
		}
	}
}

template<typename T> void MaxHeap<T>::Sink(int iParentIndex, int iSize) {

}


template<typename T> void MaxHeap<T>::Exchange(T a, T b) {

	T temp = a;
	a = b;
	b = temp;
}



int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
