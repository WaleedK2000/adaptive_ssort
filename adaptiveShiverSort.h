#pragma once

#include <iostream>
#include "Merge.h"
#include "Runs.h"
#include "Stack.h"
#include<fstream>

using namespace std;


// Implemented 
template<class T>
void mergeR1_R2(Stack<Runs<T>>& S) {
	Runs<T> s_1 = S.pop();
	Runs<T> s_2 = S.pop();

	T* n_arr = mergeArr(s_1.arr, s_2.arr, s_1.lenght, s_2.lenght);
	/*delete s_1.arr;
	delete s_2.arr;*/

	s_1.arr = n_arr;
	s_1.lenght = s_1.lenght + s_2.lenght;

	s_1.calLi();
	S.push(s_1);
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
T* adaptiveShiverSort(T* arr, int arr_lenght, int c) {
	Stack<Runs<T>> S;
	int* temp = new int;
	int total = 0;
	*temp = arr[0];
	bool ascending = false;
	bool descending = false;
	int length = 1;
	int start = 0;
	int run = 1;
	ofstream out_1;
	Runs<T> obj;
	for (int i = 1; i < arr_lenght; ++i)
	{
		if (*temp < arr[i] && descending == false)
		{
			ascending = true;
			length = length + 1;
			*temp = arr[i];
		}
		else if (*temp > arr[i] && ascending == false)
		{
			descending = true;
			length = length + 1;
			*temp = arr[i];
		}
		else
		{
			if (ascending == true)
			{
				obj.push(arr, length, start, true);
			}
			else
			{
				obj.push(arr, length, start, false);
			}
			*temp = arr[i];
			start = i;
			total = total + length;
			length = 1;
			ascending = false;
			descending = false;
			cout << "Run " << run << endl;
			run = run + 1;
			Runs<T> obj1 = obj;
			T * check_1=obj1.display();
			S.push(obj1);
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
	}
	if (ascending == true)
	{
		obj.push(arr, length, start, true);
	}
	else
	{
		obj.push(arr, length, start, false);
	}
	total = total + length;
	length = 1;
	ascending = false;
	descending = false;
	cout << "Run " << run << endl;
	run = run + 1;
	Runs<T> obj1 = obj;
	T * check_2=obj1.display();
	S.push(obj1);
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
	while (S.getHeight() >= 2) {
		mergeR1_R2(S);
	}
	cout << endl;
	T* check_array=S.pop().arr;
	/*cout << "After Sorting\n";
	for(int i=0;i< arr_lenght;++i)
	cout<<check_array[i]<<" ";
	cout << endl;*/
	return check_array;
}
