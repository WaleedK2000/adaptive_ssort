#pragma once

#include <iostream>
#include "Merge.h"
#include "Runs.h"
#include "Stack.h"

using namespace std;


// TODO:
//Not implemented
template<class T>
Stack<Runs<T>>* decomposeToRuns(T* arr, int arr_lenght, int c) {

	//Start of place Holder for testing purpose
	T* ptr = new T[23];

	for (int i = 0; i < 23; ++i) {
		ptr[i] = 40 + i * 2;
	}
	//End of place Holder for testing purpose

	Stack<Runs<T>>* s = new Stack<Runs<T>>;

	Runs<T>* r_ptr = new Runs<T>;

	r_ptr->arr = ptr;
	r_ptr->lenght = 23;
	r_ptr->c = c;
	r_ptr->calLi();

	s->push(*r_ptr);
	return s;
}

// NOT Implemented 
template<class T>
void mergeR1_R2(Stack<Runs<T>>& S) {
	
}

// Implemented and tested
template<class T>
void mergeR2_R3(Stack<Runs<T>>& S) {


	Runs<T> s_1 = S.pop();
	Runs<T> s_2 = S.pop();
	Runs<T> s_3 = S.pop();

	
	T* n_arr = mergeArr(s_2.arr, s_3.arr, s_2.lenght, s_3.lenght);


	s_2.arr = n_arr;
	s_2.lenght = s_2.lenght + s_3.lenght;
	s_2.calLi();

	S.push(s_2);
	S.push(s_1);
}



template <class T>
int* adaptiveShiverSort(T* arr, int arr_lenght, int c) {

	Stack<Runs<T>>* running = decomposeToRuns(arr, arr_lenght, c);
	Stack<Runs<T>> S;

	while (running->getHeight() > 0) {

		S.push(running->pop());
		while (true) {

			if (S.getHeight() == 1) {
				break;
			}

			int l1 = S[0]->calLi();
			int l2 = INT_MIN;
			int l3 = INT_MIN;
			if (S.getHeight() >= 2) {
				l2 = S[1]->calLi();
			}

			if (S.getHeight() >= 3) {
				l3 = S[2]->calLi();
			}

			if (S.getHeight() >= 3 && ((l1 >= l3) || (l2 >= l3))) {
				//merge R2 and R3 by poping first three runs
				
				mergeR2_R3(S);
				continue;
			}
			else if (S.getHeight() >= 2 && (l1 >= l2)) {
				
				mergeR1_R2(S);
				continue;

			}
			else {
				break;
			}
		}
	}

	while (S.getHeight() >= 2) {

		mergeR1_R2(S);
	}

	return S.pop().arr;
}
