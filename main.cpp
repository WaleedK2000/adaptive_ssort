#include <iostream>
#include "adaptiveShiverSort.h"
#include <cstdlib>
#include <windows.h>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
int main()
{
	srand(time(0));
	int checking = 10000;
	int small_val = 1;
	int high_val = 2;
	cout << "Initial Array" << endl;
		float* array = new float[checking];
		ofstream MyFile("Float.txt");
        //Random Case
		MyFile << "Initial Array of Size 10k\n\n\n";
		/*for (int i = 0; i < checking; ++i)
		{
			array[i] = rand();
			cout << array[i] << " ";
			MyFile << array[i] << ",";
		}*/
		//Best Case
		/*for (int i = 0; i < checking; ++i)
		{
			array[i] = i;
			MyFile << array[i] << ",";
			cout << array[i] << " ";
		}*/
		//Float value Case 
		for (int i = 0; i < checking; ++i)
         {
	        array[i] = 1.1 * rand();
	        MyFile << array[i] << ",";
	        cout << array[i] << " ";
         }
		MyFile << "\n\n\n";
		cout << endl;
		//Worst Case
		/*for (int i = 0; i < checking; ++i)
        {
		    if(i%2==0)
	        array[i] = small_val;
			else
			array[i]=high_val;
			MyFile << array[i] << ",";
	        cout << array[i] << " ";
        }*/
		MyFile << "\n\n\n";
		cout << endl;
		auto start = high_resolution_clock::now();
		float* final_output = adaptiveShiverSort(array, checking, 1);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		cout << endl;
		cout << "Execution Time\n";
		cout << duration.count() << endl;
		MyFile << "Execution Time\n";
		MyFile << duration.count() << "\n\n\n";
		cout << endl;
	cout << endl;
	cout << "Final Sorted Array\n";
	MyFile << "Final Sorted Array\n\n\n";
	for (int i = 0; i < checking; ++i)
	{
		cout << final_output[i] << " ";
		MyFile << final_output[i]<<",";
	}
	MyFile << "\n\n\n";


	cout << endl;
	return 0;
}
