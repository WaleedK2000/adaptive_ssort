#include <iostream>
#include "adaptiveShiverSort.h"
using namespace std;

int main()
{

	int* tem = new int;

	int* narr = adaptiveShiverSort(tem, 1, 1);
	for (int i = 0; i < 23; ++i) {
		cout << narr[i] << " ";
	}
	return 0;


	return 0;
}
