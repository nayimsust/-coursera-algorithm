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
#include <vector>

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
	return (this->next) ? false : true;
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
	return (this->next) ? false : true;
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

template<typename T> class Point2D{

	public:
		T m_x, m_y;
		T polar_Angle;

	public:
		T GetX() {
			return m_x;
		}

		T GetY() {
			return m_y;
		}

		void SetPolarAngle(T angle) {
			polar_Angle = angle;
		}

		T GetPolarAngle() {
			return polar_Angle;
		}

	public:
		Point2D(): m_x(0), m_y(0), polar_Angle(0){
		}

		Point2D(T x, T y): m_x(x), m_y(y) {
		}

		double Euclidian_Distance(Point2D &point) {
			T dy = (point.m_y - m_y);
			T dx = (point.m_x - m_x);
			return sqrt(dy*dy + dx*dx);
		}

		int compareToX(Point2D &point) {

			if(this == &point)
				return 0;

			if(this->m_x > point->m_x) return 1;
			if(this->m_x < point->m_x) return -1;
			if(this->m_y > point->m_y) return 1;
			if(this->m_y < point->m_y) return -1;
			return 0;
		}

		int compareToY(Point2D &point) {

			if(this == &point)
				return 0;

			if(this->m_y > point->m_y) return 1;
			if(this->m_y < point->m_y) return -1;
			if(this->m_x > point->m_x) return 1;
			if(this->m_x < point->m_x) return -1;
			return 0;
		}
};

template<typename T> void Exchange(Point2D<T> &p1, Point2D<T> &p2) {

	if(&p1 == &p2)
		return;

	Point2D<T> temp;

	temp  = p1;
	p1 = p2;
	p2 = temp;
}

int compareToX(Point2D<double> &p1, Point2D<double> &p2) {

	if(&p1 == &p2)
		return 0;

	if(p1.m_x > p2.m_x) return 1;
	if(p1.m_x < p2.m_x) return -1;
	if(p1.m_y > p2.m_y) return 1;
	if(p1.m_y < p2.m_y) return -1;
	return 0;
}

int compareToY(Point2D<double> &p1, Point2D<double> &p2) {

	if(&p1 == &p2)
		return 0;

	if(p1.m_y > p2.m_y) return 1;
	if(p1.m_y < p2.m_y) return -1;
	if(p1.m_x > p2.m_x) return 1;
	if(p1.m_x < p2.m_x) return -1;
	return 0;
}

int compareToPolarAngle(Point2D<double> &p1, Point2D<double> &p2) {

	if(&p1 == &p2)
		return 0;

	if(p1.polar_Angle > p2.polar_Angle) return 1;
	if(p1.polar_Angle < p2.polar_Angle) return -1;
	return 0;
}

template<class T, class Compare> void InsertionSort(T array[], int iLength, Compare comp) {

	for(int i = 0; i < iLength; ++i) {
		for(int j = i; j >= 1; --j) {
			if(comp(array[j], array[j-1]) < 0)
				Exchange(array[j], array[j-1]);
			else
				break;
		}
	}
}

template<typename T> T CalculatePolarAngle(Point2D<T> p1, Point2D<T> p2) {

	double deltaX = (double)(p2.m_x - p1.m_x);
	double deltaY = (double)(p2.m_y - p1.m_y);
	double angle;

	if (deltaX == 0 && deltaY == 0)
		return 0;

	angle = atan2(deltaY,deltaX) * 57.295779513082;

   if (angle < 0)
	angle += 360.;

	return angle;
}

template<typename T> int CCW(Point2D<T> a, Point2D<T> b, Point2D<T> c) {

	double determinant = (a.m_x*(b.m_y-c.m_y)) - (a.m_y*(b.m_x-c.m_x)) + (b.m_x*c.m_y - b.m_y*c.m_x);
	if(determinant > 0) return 1;
	else if(determinant < 0) return -1;
	else return 0;
}

template <typename T> T TRand(T fMin, T fMax) {
    T f = (T)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

int main() {

	int iSize = 20;
	double RANGE_MIN = 1;
	double RANGE_MAX = 100;

	Point2D<double> Points[iSize];

	/*	randomly generate the sample points	*/
	cout << endl << "Sample points for Convex Hull" << endl;
	for(int i = 0; i < iSize; ++i) {

		double x = TRand(RANGE_MIN, RANGE_MAX);
		double y = TRand(RANGE_MIN, RANGE_MAX);
		Point2D<double> point(x, y);

		Points[i] = point;
		cout << Points[i].GetX() << " " << Points[i].GetY() << endl;
	}

	/*	find the pivot point according to minimum y axis so lets sort	*/
	InsertionSort(Points, iSize, compareToY);
	cout << endl << "Sorted According to Y-axis value" << endl;
	for(int i = 0; i < iSize; ++i) {
		cout << Points[i].GetX() << " " << Points[i].GetY() << endl;
	}
	cout << endl << "Pivot is " << Points[0].GetX() << " " << Points[0].GetY() << endl;

	/*
	 * Calculate the polar angle with the pivot of all points.
	 */
	for(int i = 0; i < iSize; ++i) {
		Points[i].SetPolarAngle(CalculatePolarAngle(Points[0], Points[i]));
	}
	InsertionSort(Points, iSize, compareToPolarAngle);
	cout << endl << "Sorted According to Polar angle value" << endl;
	for(int i = 0; i < iSize; ++i) {
		cout << Points[i].GetX() << " " << Points[i].GetY() << " " << Points[i].GetPolarAngle() << endl;
	}

	/*
	 *	Now convex hull algorithm implemention
	 */
	Stack<Point2D<double> > hull;
	hull.Push(Points[0]);
	hull.Push(Points[1]);

	Point2D<double> p2;
	Point2D<double> p1;

	for(int i = 2; i < iSize; ++i) {
		p2 = Points[i];
		p1 = hull.Top();
		hull.Pop();

		while(hull.Size() >= 1 && CCW(hull.Top(), p1, p2) < 1) {
			p1 = hull.Top();
			hull.Pop();
		}

		hull.Push(p1);
		hull.Push(p2);
	}


	cout << endl << "Result of convex hull is " << hull.Size() << " Points the smallest perimeter to cover all Points" << endl;
	while(!hull.Empty()) {
		cout << hull.Top().GetX() << " " << hull.Top().GetY() << " " << hull.Top().GetPolarAngle() << endl;
		hull.Pop();
	}

	return 0;
}
