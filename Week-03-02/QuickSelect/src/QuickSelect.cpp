//============================================================================
// Name        : QuickSelect.cpp
// Author      : nayimsust@gmail.com
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iostream>
#include <stdio.h>
#include <random>
#include <cstdlib>
#include <ctime>
#include <assert.h>
using namespace std;

/*
 * this problem knowns as K-th largest number of unordered array data.
 */

void swap(int &a, int &b) {
	if (&a == &b)
		return;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

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

bool Less(int& a, int& b) {
	return (a < b) ? true : false;
}

int Partition(int a[], int lo, int hi) {
	int i, j;
	int pivot_item = a[lo];
	int k = i = lo;
	j = hi;
	while (i < j) {
		/* Move left while item < pivot */
		while (a[i] <= pivot_item && i != hi)
			i++;
		/* Move right while item > pivot */
		while (a[j] > pivot_item && j != lo)
			j--;
		if (i < j)
			swap(a[i], a[j]);
	}
	/* right is final position for the pivot */
	swap(a[k], a[j]);
	return j;
}

int QuickSelect(int a[], int start, int end, int index) {

	int k = Partition(a, start, end);
	if(k == index)
		return a[k];

	if(k > index)
		return QuickSelect(a, start, k-1, index);
	else
		return QuickSelect(a, k + 1, end, index);
}

int main() {

	int N = 50;
	int a[N];
	for (int i = 0; i < N; ++i)
		a[i] = N-(i);

	KnuthShuffle(a, N);

	for (int i = 0; i < N; ++i)
		cout << a[i] << " ";

	cout << endl << "QuickSelected:: " << N/2 << "-th largest Element is " << QuickSelect(a, 0, N-1, N/2) << endl;

}
