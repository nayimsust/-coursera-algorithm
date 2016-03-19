//============================================================================
// Name        : Shuffle-Sort.cpp
// Author      : nayimsust
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <random>
#include <cstdlib>
#include <ctime>
#include <assert.h>

using namespace std;

void swap(int &a, int &b) {
	if(&a == &b)
		return;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void KnuthShuffle(int array[], int iLength) {

	time_t t;
	/* Intializes random number generator */
	srand((unsigned) time(&t));

	for(int i = 1; i < iLength; ++i) {
		int iRandom = rand() % i;
		assert(iRandom <= i);
		cout << "random " << iRandom << endl;
		swap(array[i], array[iRandom]);
	}
}


int main() {


	int N = 10;
	int data[N];

	for(int i = 1; i <= N; ++i) {
		data[i-1] = i;
		cout << data[i-1] << " ";
	}

	cout << endl;

	KnuthShuffle(data, N);
	cout << endl << "After Knuth shuffle " << endl;

	for(int i = 1; i <= N; ++i) {
		cout << data[i-1] << " ";
	}
	return 0;
}
