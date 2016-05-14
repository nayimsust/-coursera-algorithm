//============================================================================
// Name        : BinaryHeap.cpp
// Author      : nayimsust@gmail.com
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <random>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <assert.h>
#include <exception>

using namespace std;

void KnuthShuffle(int array[], int iLength) {

	time_t t;
	/* Intializes random number generator */
	srand((unsigned) time(&t));

	for (int i = 1; i < iLength; ++i) {
		int iRandom = rand() % i;
		assert(iRandom <= i);
		//cout << "random " << iRandom << endl;
		swap(array[i], array[iRandom]);
	}
}

template<typename T> class MaxHeap {

	T *tData;
	int iDataSize;
	int iArraySize;

public:
	MaxHeap(int iSize = 1);
	~MaxHeap();
	void ResizeArray(int iSize);

	bool IsEmpty();
	int Size();
	void Insert(T &tItem);
	T Delete();
	void Swim(int iChildIndex);
	void Sink(int iParentIndex, int iSize);

	T Max();
	void PrintHeap();

	void Exchange(T &a, T &b);
};

template<typename T> void MaxHeap<T>::ResizeArray(int iSize) {

	T *pArray = new T[iSize*2 + 1];
	for(int i = 1; i <= this->iDataSize; ++i)
		pArray[i] = tData[i];

	if(tData)
		delete[]tData;

	iArraySize = iSize * 2;

	tData = pArray;
}

template<typename T> MaxHeap<T>::MaxHeap(int iSize) {
	tData = new T[iSize+1];
	this->iDataSize = 0;
	this->iArraySize = iSize;
}

template<typename T> T MaxHeap<T>::Max() {
	return tData[1];
}

template<typename T> void MaxHeap<T>::PrintHeap() {
	for(int i = 1; i <= iDataSize; ++i)
		cout << tData[i] << " ";
	cout << endl;
}

template<typename T> MaxHeap<T>::~MaxHeap() {
	if(tData) delete[] tData;
}

template<typename T> bool MaxHeap<T>::IsEmpty() {
	return iDataSize <= 0 ? true : false;
}

template<typename T> int MaxHeap<T>::Size() {
	return iDataSize;
}

template<typename T> void MaxHeap<T>::Insert(T &tItem) {

	if(iDataSize >= iArraySize)
		ResizeArray(iDataSize);

	tData[++iDataSize] = tItem;
	Swim(iDataSize);
}

template<typename T> T MaxHeap<T>::Delete() {

	if(iDataSize > 0) {
		Exchange(tData[1], tData[iDataSize--]);
		Sink(1, iDataSize);
		return tData[iDataSize + 1];
	}

	throw std::exception();
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

	if( iParentIndex *2 <= this->iDataSize && iParentIndex *2 <= iSize) {
		int iLeftChild = iParentIndex *2;
		int iMaxIndex = tData[iLeftChild] > tData[iParentIndex] ? iLeftChild : iParentIndex;

		if( iLeftChild + 1 <= this->iDataSize && iLeftChild + 1 <= iSize)
			iMaxIndex = tData[iLeftChild + 1] > tData[iMaxIndex] ? iLeftChild + 1 : iMaxIndex;

		if(iMaxIndex != iParentIndex)
		{
			Exchange(tData[iParentIndex], tData[iMaxIndex]);
			Sink(iMaxIndex, iSize);
		}
	}
}


template<typename T> void MaxHeap<T>::Exchange(T &a, T &b) {

	T temp = a;
	a = b;
	b = temp;
}



int main() {

	int N = 7;
	int a[N];
	for (int i = 0; i < N; ++i)
		a[i] = N-(i);

	KnuthShuffle(a, N);

	for (int i = 0; i < N; ++i)
		cout << a[i] << " ";
	cout << endl;


	MaxHeap<int> maxHeap;

	for(int i = 0; i < N; ++i) {
		maxHeap.Insert(a[i]);
		cout << "Insert->" << a[i] << "::";
		//cout << maxHeap.Max() << " ";
		maxHeap.PrintHeap();
	}
	cout << endl;


	for (int i = 0; i < N; ++i) {
		cout << "Delete<-" << maxHeap.Delete() << "::";
		maxHeap.PrintHeap();
	}

	cout << endl;


	return 0;
}
