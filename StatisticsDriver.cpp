/*
	File name: StatisticsDriver.cpp
	Author: Cole Howell
	Purpose: Drive program that calculates mean, median, and mode
	Date: October 28, 2018
 */

#include "Statistics.h"
#include "BasicSort.h"

  
int main(int argc, char** argv){
	
	float mean, median;
	int mode;
	//command line input validation
	if (argc != 2){
		cout << "Error: Invalid number of arguments" << endl;
		cout << "Only enter the executable file and the input file name you wish to use." << endl;
		return 0;
	}
	ifstream inputFile(argv[1]);
	if (!inputFile.good()){
		cout << "File does not exist. Try again." << endl;
		return 0;
	}
	//////////////////////////////////////

	int size = 1; //sets an arbitrary initial value for size which will be changed later
	int* array; //creates pointer for an array of integers
	array = readData(argv[1],size); //assigns the pointer to an array made from this function
	
	insertionSort(array,size); //organizes the array

	
	mean = findMean(array,size); //calculates the mean of the array
	median = findMedian(array,size); //calculates the median of the array
	mode = findMode(array,size); //calculates the mode of the array
	
	cout << "Welcome to the statistics program." << endl;
	cout << "The statistics for the " << size << " read in values are : " << endl;
	displayInformation(mean,median,mode); //displays the mean, median, and mode of the given set of data
	
	delete[] array;
	return 0;
}