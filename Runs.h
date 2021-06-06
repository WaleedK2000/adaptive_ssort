#pragma once

#include <cmath>
template <class T>
struct Runs
{
	T* arr;
	int lenght;
	int c;
	int li;

	Runs() {
		arr = nullptr;
		lenght = 0;
		c = 1;
		li = 0;
	}

	int calLi() {
		float val = log2(lenght / static_cast<float>(c));
		li = floor(val);
		return li;
	}

};

