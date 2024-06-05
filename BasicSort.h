/*
	BasicSort.h / Sort/*
	BasicSort.h
	Function to sort a user provided array using insertion sort
	7.14.18
	dwbrown
*/

#if !defined BASIC_SORT_H
#define BASIC_SORT_H

//Pre  : array is an unsorted array of integers of size sz
//Post : array is modified in place to be in sorted order in
//	   : ascending order	

void insertionSort (int* array, int sz);

#endif