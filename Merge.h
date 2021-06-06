#pragma once

#include <iostream>
#include <cmath>
using namespace std;



int* mergeArr(int* l_ptr, int* r_ptr, int n);
int* merge(int* ptr, int n);

int retOne();
//USE this function 
template<class T>
T* mergeArr(T* l_ptr, T* r_ptr, int l_len, int r_len);


int retOne() {
	return 1;
}


int* mergeArr(int* l_ptr, int* r_ptr, int n)
{
	int l_len = ceil(n / static_cast<float>(2));
	int r_len = n - l_len;

	int* ret = new int[n];
	int i = 0;
	while (l_len > 0 && r_len > 0)
	{
		if (*l_ptr < *r_ptr)
		{
			--l_len;
			ret[i++] = *l_ptr;
			++l_ptr;
		}
		else
		{
			--r_len;
			ret[i++] = *r_ptr;
			++r_ptr;
		}
	}

	while (l_len > 0 && r_len == 0)
	{
		--l_len;
		ret[i++] = *l_ptr;
		++l_ptr;
	}

	while (r_len > 0 && l_len == 0)
	{

		--r_len;
		ret[i++] = *r_ptr;
		++r_ptr;
	}

	return ret;
}

int* merge(int* ptr, int n)
{
	if (n == 1)
	{
		return ptr;
	}

	int m = ceil(static_cast<float>(n) / 2);
	int* midptr = ptr + m;

	int* l_ptr = merge(ptr, m);
	int* r_ptr = merge(midptr, n - m);

	return mergeArr(l_ptr, r_ptr, n);
}

//USE this function
template<class T>
T* mergeArr(T* l_ptr, T* r_ptr, int l_len, int r_len)
{
	int n = l_len + r_len;
	T* ret = new T[n];
	int i = 0;
	while (l_len > 0 && r_len > 0 && i < n)
	{
		if (*l_ptr < *r_ptr)
		{
			--l_len;
			ret[i++] = *l_ptr;
			++l_ptr;
		}
		else
		{
			--r_len;
			ret[i++] = *r_ptr;
			++r_ptr;
		}
	}

	while (l_len > 0 && r_len == 0 && i < n)
	{
		--l_len;
		ret[i++] = *l_ptr;
		++l_ptr;
	}

	while (r_len > 0 && l_len == 0 && i < n)
	{

		--r_len;
		ret[i++] = *r_ptr;
		++r_ptr;
	}

	return ret;
}