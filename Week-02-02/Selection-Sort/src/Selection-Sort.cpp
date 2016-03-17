//============================================================================
// Name        : Selection-Sort.cpp
// Author      : nayimsust
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//============================================================================
// Name        : Stack.cpp
// Author      : nayimsust@gmail.com
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>

using namespace std;

template<typename T> class Stack {
public:
	Stack();
	~Stack();

	T data;
	Stack *next;

	void Push(const T &t);
	void Pop();
	bool Empty();
	T &Top();
	int Size();
};

template<typename T> Stack<T>::Stack() {
	next = NULL;
}

template<typename T> Stack<T>::~Stack() {
}

template<typename T> void Stack<T>::Push(const T &ref) {

	if (!this->next) {
		Stack *stack = new Stack;
		stack->data = ref;

		this->next = stack;
	} else {
		Stack *stack = new Stack;
		stack->data = ref;
		stack->next = this->next;

		this->next = stack;
	}
}

template<typename T> void Stack<T>::Pop() {

	if (!this->next)
		return;

	Stack* stack = this->next->next;

	if (!stack) {
		delete (this->next);
		this->next = NULL;
	} else {
		delete (this->next);
		this->next = stack;
	}
}

template<typename T> bool Stack<T>::Empty() {
	return (this->next) ? true : false;
}

template<typename T> T& Stack<T>::Top() {
	return this->next->data;
}

template<typename T> int Stack<T>::Size() {
	size_t t_size = 0;
	Stack *stack = this->next;
	if (!stack)
		return t_size;

	while (stack) {
		stack = stack->next;
		++t_size;
	}

	return t_size;
}

template<typename T> class Stack<T*> {
public:
	Stack();
	~Stack();

	T *data;
	Stack *next;

	void Push(T *t);
	void Pop();
	bool Empty();
	T *Top();
	int Size();
};

template<typename T> Stack<T*>::Stack() {
	data = NULL;
	next = NULL;
}

template<typename T> Stack<T*>::~Stack() {
}

template<typename T> void Stack<T*>::Push(T * const ptr) {

	if (!this->next) {
		Stack *stack = new Stack;
		stack->data = ptr;

		this->next = stack;
	} else {
		Stack *stack = new Stack;
		stack->data = ptr;
		stack->next = this->next;

		this->next = stack;
	}
}

template<typename T> void Stack<T*>::Pop() {

	if (!this->next)
		return;

	Stack* stack = this->next->next;

	if (!stack) {
		delete (this->next);
		this->next = NULL;
	} else {
		delete (this->next);
		this->next = stack;
	}
}

template<typename T> bool Stack<T*>::Empty() {
	return (this->next) ? true : false;
}

template<typename T> T* Stack<T*>::Top() {
	return this->next->data;
}

template<typename T> int Stack<T*>::Size() {
	size_t t_size = 0;
	Stack *stack = this->next;
	if (!stack)
		return t_size;

	while (stack) {
		stack = stack->next;
		++t_size;
	}

	return t_size;
}


class Me{
public:
	int value;
	Me():value(0){
	}

	Me(int i): value(i) {

	}

	~Me(){
	}

	int GetMe() {
		return value;
	}

	int compareTo(Me &rMe) {

		if(this == &rMe)
			return 0;
		if(this->value < rMe.value) return -1;
		if(this->value > rMe.value) return 1;
		return 0;
	}
};

bool Less(Me &m1, Me &m2) {
	return m1.compareTo(m2) < 0;
}

void Exchange(Me array[], int i, int j) {
	Me m3 = array[i];
	array[i] = array[j];
	array[j] = m3;
}

void SelectionSort(Me array[], int iLength) {

	int iMin;
	for(int i = 0; i < iLength; ++i) {
		iMin = i;
		for(int j = i + 1; j < iLength; ++j) {
			if(Less(array[j], array[iMin])) {
				iMin = j;
			}
		}
		Exchange(array, i, iMin);
	}
}

int main() {

	int iLength = 10;
	Me me[iLength];

	for(int i = 0; i < iLength; ++i) {
		me[i] = Me(iLength - i);
	}

	for(int i = 0; i < iLength; ++i) {
		cout << me[i].GetMe() << endl;
	}


	SelectionSort(me, 10);

	cout << "After Selection sort" << endl;

	for(int i = 0; i < iLength; ++i) {
		cout << me[i].GetMe() << endl;
	}

	return 0;
}
