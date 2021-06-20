#pragma once


#include <iostream>
template<class T>
struct Node {
	T val;
	Node<T>* next;
};

template <class T>
class Stack
{
	Node<T>* top;
	int height;

public:

	Stack() {
		top = nullptr;
		height = 0;
	}

	void push(T type) {

		Node<T>* temp = new Node<T>;
		temp->val = type;
		temp->next = top;
		top = temp;
		++height;
	}

	T pop() {
		T val = top->val;
		top = top->next;
		--height;
		return val;
	}

	int getHeight() {
		return height;
	}

	//If Stack[i] does not exist return nullptr
	//Stack [0] must return top of stack
	//Stack [1] must return top of stack + 1
	//Stack [2] must return top of stack + 2
	//Stack [3] must return top of stack + 3
	//TODO
	//NOT IMPLEMENTED
	T* operator[](int i) {

		if (i >= height || height == 0) {

			return nullptr;
		}

		Node<T>* temp = top;

		while (i > 0) {
			temp = temp->next;
			std::cout << i;
			i -= 1;
		}

		return &temp->val;

	}



};

