//============================================================================
// Name        : Convex-Hull.cpp
// Author      : nayimsust
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;


/* farthest pair of points is the extreme point in convex hull
 *
 */


/*
 * polar coordinate system (r, theta)
 * theta is angle with x axis counter clock wise and r is the distance.
 *
 * cartesian coordinate system(x, y)
 *
 */


/*
 * Graham scan algorithm to solve the convex hull problem
 * steps.
 *
 * 1.	find the minimum point P in basis of minimum y axis value.
 * 2. 	sort the points with the polar angle with respect to P point.
 * 3.	traverse the sorted point and go in counter clock wise direction if any point faild to do that remove the point in convex hall list
 */


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



class Point2D{

	public:
		double m_x, m_y;

	public:
		Point2D(): m_x(0), m_y(0){
		}

		Point2D(double x, double y): m_x(x), m_y(y) {
		}

		double Euclidian_Distance(Point2D &point) {
			double dy = (point.m_y - m_y);
			double dx = (point.m_x - m_x);
			return sqrt(dy*dy + dx*dx);
		}
};

int CCW(Point2D a, Point2D b, Point2D c) {

	double determinant = (a.m_x*(b.m_y-c.m_y)) - (a.m_y*(b.m_x-c.m_x)) + (b.m_x*c.m_y - b.m_y*c.m_x);
	if(determinant < 0) return -1;
	else if(determinant > 0) return 1;
	else return 0;
}

int main() {

	return 0;
}
