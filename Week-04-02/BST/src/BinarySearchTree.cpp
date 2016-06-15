//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : nayimsust@gmail.com
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <assert.h>
using namespace std;

template <typename Key, typename Value> class BinarySearchTree {

public:
	BinarySearchTree();
	~BinarySearchTree();

	void Insert(Key key, Value value);
	void DeleteMin();
	void Delete(Key key);
	Value Get(Key key);

	int Size();
	int Size(Key key);
	Key Floor(Key key);
	Key Ceil(Key key);
	int Rank(Key key);
	Key Min();
	Key Max();

private:
	class Node {
	public:
		Key m_Key;
		Value m_Value;
		Node *m_leftNode, m_rightNode;
		int m_iCount;
		Node(): m_leftNode(NULL), m_rightNode(NULL), m_iCount(0){
		}

		Node(Key key, Value value): m_leftNode(NULL), m_rightNode(NULL), m_iCount(0), m_Key(key), m_Value(value){
		}

		~Node() {
		}
	};

private:
	Node* Insert(Key &key, Value &value, Node *Parent) {
		if(Parent == NULL)
			return new Node(key, value);

		if(key == Parent->m_Key)
			Parent->m_Value = value;
		else if(key > Parent->m_Key)
			Parent->m_rightNode = Insert(key, value, Parent->m_rightNode);
		else
			Parent->m_leftNode = Insert(key, value, Parent->m_leftNode);

		Parent->m_iCount = Size(Parent->m_rightNode) + Size(Parent->m_leftNode) + 1;

		return Parent;
	}

	Node * Get(Key &key, Node *Parent) {
		if(Parent == NULL)
			return Parent;

		if(key == Parent->m_Key)
			return Parent;
		else if(key > Parent->m_Key)
			Parent = Get(key, Parent->m_rightNode);
		else
			Parent = Get(key, Parent->m_leftNode);
		return Parent;
	}

	Node * Min(Node *Parent) {
		if(Parent == NULL)
			return NULL;

		Node *leftNode = Min(Parent->m_leftNode);
		if(leftNode == NULL)
			return Parent;
		return leftNode;
	}

	Node * Max(Node *Parent) {
		if(Parent == NULL)
			return NULL;

		Node *rightNode = Min(Parent->m_rightNode);
		if(rightNode == NULL)
			return Parent;
		return rightNode;
	}


	Node * DeleteMin(Node *Parent) {
		if(Parent == NULL)
			return NULL;

		if(Parent->m_leftNode == NULL) {
			if(Parent->m_rightNode == NULL)
				return NULL;
			else
				Parent->m_rightNode;
		}
		else
			Parent->m_leftNode = DeleteMin(Parent->m_leftNode);
		Parent->m_iCount = Size(Parent->m_leftNode) + Size(Parent->m_rightNode) + 1;
		return Parent;
	}

	Node * Delete(Key &key, Node *Parent) {

		if(Parent == NULL)
			return NULL;

		if(Parent->m_Key == key) {

			if(Parent->m_leftNode == NULL)
				return Parent->m_rightNode;
			else if(Parent->m_rightNode == NULL)
				return Parent->m_leftNode;

			Node *node = Parent;
			Parent = Min(node->m_rightNode);
			Parent->m_leftNode = node->m_leftNode;
			Parent->m_rightNode = DeleteMin(node->m_rightNode);
		}
		else if(Parent->m_Key < key)
			Parent->m_rightNode = Delete(key, Parent->m_rightNode);
		else
			Parent->m_leftNode = Delete(key, Parent->m_leftNode);

		Parent->m_iCount = Size(Parent->m_leftNode) + Size(Parent->m_rightNode) + 1;
		return Parent;
	}

	int Size(Key key, Node *Parent) {
		if(Parent == NULL)
			return 0;
		if(Parent->m_Key == key)
			return Parent->m_iCount;
		else if(Parent->m_Key > key)
			return Size(key, Parent->m_leftNode);
		else
			return Size(key, Parent->m_rightNode);
	}

	Key Floor(Key &key, Node *Parent);
	Key Ceil(Key &key, Node *Parent);
	int Rank(Key &key, Node *Parent);


private:
	Node *m_Root;

};

template <typename Key, typename Value> BinarySearchTree<Key, Value>::BinarySearchTree() : m_Root(NULL) {
}

template <typename Key, typename Value> BinarySearchTree<Key, Value>::~BinarySearchTree() {
	delete m_Root;
}

template <typename Key, typename Value> void BinarySearchTree<Key, Value>::Insert(Key key, Value value) {
	m_Root = Insert(key, value, m_Root);
}

template <typename Key, typename Value> Value BinarySearchTree<Key, Value>::Get(Key key) {
	Node *node = Get(key, m_Root);
	if(node)
		return node->m_Value;
	else
		return Value();
}

template <typename Key, typename Value> Key BinarySearchTree<Key, Value>::Min() {
	Node *node = Min(m_Root);
	if(node)
		return node->m_Key;
	else
		return Key();
}

template <typename Key, typename Value> Key BinarySearchTree<Key, Value>::Max() {
	Node *node = Max(m_Root);
	if(node)
		return node->m_Key;
	else
		return Key();
}

template <typename Key, typename Value> void BinarySearchTree<Key, Value>::Delete(Key key) {
	m_Root = Delete(key, m_Root);
}

template <typename Key, typename Value> int BinarySearchTree<Key, Value>::Size() {
	if(m_Root == NULL)
		return 0;
	return m_Root->m_iCount;
}

template <typename Key, typename Value> int BinarySearchTree<Key, Value>::Size(Key key) {
	return Size(key, m_Root);
}

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

int main() {

	cout << "Binary Search tree demo" << endl;

	return 0;
}

