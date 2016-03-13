//============================================================================
// Name        : Iterator.cpp
// Author      : nayimsust@gmail.com
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <cassert>
#include <algorithm>

using namespace std;

template<typename T> class Stack {
public:
	Stack();
	~Stack();

	T data;
	Stack *next;

	void Push(const T &t);
	T Pop();
	bool Empty();
	T &Top();
	int Size();

	/*	for getting iterator	*/
	class Iterator;
	Iterator begin() {
		return Iterator(this->next);
	}
	Iterator &end() {
		return Iterator(NULL);
	}


	/*	Iterator class this stack implementation	*/
public:
	class Iterator {
		Stack *stack;
	public:
		Iterator();
		Iterator(Stack *stack);
		Iterator(const Iterator &rIterator);
		~Iterator();
		Iterator& operator=(Iterator rIterator) {
			this->stack = rIterator.stack;
			return *this;
		}

		T& operator*() {
			return stack->data;
		}

		Iterator& operator++() {
			stack = stack->next;
			return *this;
		}

		Iterator operator++(int) {
			Iterator it = *this;
			stack = stack->next;
			return it;
		}

		bool operator!=(Iterator &iterator) {
			return (stack == iterator.stack) ? false : true;
		}

		bool operator==(Iterator &iterator) {
			return (stack != iterator.stack) ? false : true;
		}
	};

};

template<typename T> Stack<T>::Iterator::Iterator() {
	stack = NULL;
}

template<typename T> Stack<T>::Iterator::Iterator(Stack *stack) {
	this->stack = stack;
}

template<typename T> Stack<T>::Iterator::~Iterator() {
	//TODO
}

template<typename T> Stack<T>::Iterator::Iterator(const Iterator &rIterator) {
	this->stack = rIterator.stack;
}

template <typename T> Stack<T>::Stack() {
	next = NULL;
}

template <typename T> Stack<T>::~Stack() {
}

template <typename T> void Stack<T>::Push( const T &ref) {

	if(!this->next) {
		Stack *stack = new Stack;
		stack->data = ref;

		this->next = stack;
	}
	else {
		Stack *stack = new Stack;
		stack->data = ref;
		stack->next = this->next;

		this->next = stack;
	}
}

template<typename T> T Stack<T>::Pop() {

	if(!this->next) return;

	Stack* stack = this->next->next;

	if(!stack) {
		delete(this->next);
		this->next = NULL;
	}
	else {
		delete(this->next);
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
	if(!stack) return t_size;

	while(stack) {
		stack = stack->next;
		++ t_size;
	}

	return t_size;
}

int main() {

	Stack<int> stack;
	stack.Push(78);


	cout << stack.Top() << endl;

	return 0;
}
