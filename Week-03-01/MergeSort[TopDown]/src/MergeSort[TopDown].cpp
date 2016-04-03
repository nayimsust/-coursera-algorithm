//============================================================================
// Name        : MergeSort[TopDown].cpp
// Author      : nayimsust@gmail.com
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


template<typename T> void Merge(T a[], int start, int mid, int end) {

	T temp[end+1];

	int j, k;
	for(int i = start; i <= end; ++i)
		temp[i] = a[i];

	for(int i = start, j = start, k = mid+1; i <= end; ++i) {
		if(j > mid)
			a[i] = temp[k++];
		else if(k > end)
			a[i] = temp[j++];
		else
			a[i] = (temp[j] < temp[k]) ? temp[j++] : temp[k++];
	}
}


template<typename T> void Sort(T a[], int start, int end) {

	//	base case for recursion
	if(start >= end)
		return;

	//	divide the problem into halves
	int mid = start + (end - start) / 2;

	//	solve the two halves
	Sort(a, start, mid);
	Sort(a, mid + 1, end);

	//	merge the two halves solution this step is called conquer
	if(a[mid] > a[mid+1])
		Merge(a, start, mid, end);
}

int main() {

	int a[] = {1, 4, 0, 3, 23, 90, 9};
	Sort(a, 0, 6);

	for(int i = 0; i < 7; ++i)
		cout << a[i] << " " ;
	cout << endl;

	return 0;
}
