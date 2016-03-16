//============================================================================
// Name        : Dijkstra.cpp
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

template<typename T> void Stack<T>::Pop() {

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

template<typename T> class Stack<T*> {
public:
	Stack();
	~Stack();

	T *data;
	Stack *next;

	void Push(T *t);
	T Pop();
	bool Empty();
	T &Top();
	int Size();
};

template <typename T> Stack<T*>::Stack() {
	data = NULL;
	next = NULL;
}

template <typename T> Stack<T*>::~Stack() {
}

template <typename T> void Stack<T*>::Push( T *const ptr) {

	if(!this->next) {
		Stack *stack = new Stack;
		stack->data = ptr;

		this->next = stack;
	}
	else {
		Stack *stack = new Stack;
		stack->data = ptr;
		stack->next = this->next;

		this->next = stack;
	}
}

template<typename T> T Stack<T*>::Pop() {

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

template<typename T> bool Stack<T*>::Empty() {
	return (this->next) ? true : false;
}

template<typename T> T& Stack<T*>::Top() {
	return *this->next->data;
}

template<typename T> int Stack<T*>::Size() {
	size_t t_size = 0;
	Stack *stack = this->next;
	if(!stack) return t_size;

	while(stack) {
		stack = stack->next;
		++ t_size;
	}

	return t_size;
}


enum Operator {
	Plus,
	Minus,
	Multiply,
	Divide,
	Undefined
};

Operator ConvertCharToEnum (char c) {
	if(c == '+')
		return Plus;
	else if(c == '-')
		return Minus;
	else if(c == '*')
		return Multiply;
	else if(c == '/')
		return Divide;
	else
		return Undefined;
};



template<typename T> T EvaluateExpressionWithParenthesis(string &str, T& tResult) {

	Stack<T> sValue;
	Stack<char> sOperator;

	T tAnswer(0);

	for(int iIndex = 0; iIndex < str.size(); ++iIndex) {
//		cout << "command::\"" << str[iIndex] << "\"" << endl;
		Operator op = ConvertCharToEnum(str[iIndex]);

		if(op != Undefined) {
			sOperator.Push(str[iIndex]);
//			cout << "Operator " << str[iIndex] << endl;
		}
		else if(str[iIndex] == '(') {
//			cout << "Left Parenthesis" << endl;
		}
		else if(str[iIndex] == ')') {
//			cout << "Right Parenthesis :: " << sValue.Size() << "::" << sOperator.Size() << endl;
			op = ConvertCharToEnum(sOperator.Top());
			sOperator.Pop();

			T b = sValue.Top();
			sValue.Pop();
			T a = sValue.Top();
			sValue.Pop();

			T c;
			switch(op) {
				case Plus:
					c = a + b;
					sValue.Push(c);
//					cout << a << "::" << b << ":" << c <<endl;
					break;
				case Minus:
					c = a - b;
					sValue.Push(c);
//					cout << a << "::" << b << ":" << c <<endl;
					break;
				case Multiply:
					c = a * b;
					sValue.Push(c);
//					cout << a << "::" << b << ":" << c <<endl;
					break;
				case Divide:
					c = a / b;
					sValue.Push(c);
//					cout << a << "::" << b << ":" << c <<endl;
					break;
				default:
					break;
			}
		}
		else if(str[iIndex] >= '0' && str[iIndex] <= '9') {
//			cout << "Operand " << (str[iIndex] - '0') << endl;
			sValue.Push(str[iIndex] - '0');
		}
		else {
//		cout << "Else " << endl;
		}
	}

	if(sValue.Size() == 1 ) {
		tAnswer = sValue.Top();
//		cout << "Result found and is " << tAnswer << endl;
		tResult = tAnswer;
		return tAnswer;
	}
	else {
		tResult = tAnswer;
//		cout << "Result not found and is " << tAnswer << endl;
		return tAnswer;
	}
}

int main() {

	string sQuestion = "(1+((3-2)*(5/1)))";
//	string sQuestion = "(1+2)";
	int iResult = 0;
	cout << EvaluateExpressionWithParenthesis(sQuestion, iResult) << endl;

	return 0;
}
