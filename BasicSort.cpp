#include "BasicSort.h"

//using namespace std;

void insertionSort (int* array, int sz)
{
	int curr;
	int swap;
	
	for (int i = 1; i < sz; i++)
	{
		swap = array[i];
		curr = i;
		while ((curr > 0) && (array[curr - 1] > swap))
		{
			array[curr] = array[curr - 1];
			curr--;
		}
		array[curr] = swap;
	}
}