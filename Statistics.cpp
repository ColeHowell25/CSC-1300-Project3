/*
	File name: Statistics.cpp
	Author: Cole Howell
	Purpose: Holds function definitions for Statistics.h
	Date: October 30, 2018
*/
#include "Statistics.h"



int* readData(const char* filename, int &size){
	
	int* inputArray; //declaring initial pointer to store an unknown amount of integers
	inputArray = new int[2]; //declaring an initial size for this array
	int num;
	int counter = 0;
	
	ifstream inputFile;
	inputFile.open(filename); //filename entered from command line is opened
	

	while (inputFile >> num){ //as long as the file is able to be read, integers will be stored temporarily in num
		inputArray[counter] = num; //the array sub counter is equal to num
		counter++; //increment the subscript of the array
	}
	
	size = inputArray[0]; //assigns the size to be equal to the first value in the input array
	int* array; //declare the array that will be returned
	array = new int[size]; //the size of this array is the first value from the first array
	
	for (int i=0;i<size;i++){ //fill this array with the rest of the values from the first one 
		array[i] = inputArray[i+1];
		
	}
	
	return array; //returns the array that will be used for rest of program
}	

float findMean(int* numbers, int size){
	
	int sum = 0;
	
	for (int i=0;i<size;i++){ //sums all the values found within the array
		sum += numbers[i];
	}
	return static_cast<float>(sum)/size; //returns the mean
}

float findMedian(int* numbers, int size){
	//both cases return the median of the set of data
	if (size%2 == 0){ //median for size of even number
		return static_cast<float>(numbers[(size-1)/2] + numbers[size/2]-1)/2;
	}
	else{ //median for size of odd number
		return static_cast<float>(numbers[size/2]);
	}
}

int findMode(int* numbers, int size){
	int number = numbers[0]; //the initial number to be tested is the first in the array
	int mode = number; //the initial mode of the set is thie first number
	int count = 1; //the initial count is set to 1 occurrence of the number
	int countMode = 1; //keeps track of the number of times the mode occurs, initially 1
	
	for (int i=1;i<size;i++){
		if (numbers[i] == number){
			count++; //counting the occurrences of this number
		}
		else{ //this will execute when a new number is encountered
			if (count > countMode){ 
				countMode = count;
				mode = number;
			}
			count = 1; //reset the count for the new number
			number = numbers[i];
		}
		
	}
	return mode;
}

void displayInformation(float mean, float median, int mode){
	cout << "The mean of the data set provided is : " << fixed << setprecision(1) << mean << endl; //displays mean to one decimal point
	cout << "The median of the data set provided is : "<< fixed << setprecision(1) << median << endl; //displays median to one decimal point
	cout << "The mode of the data set provided is : " << mode << endl; //displays the mode
	cout << "Thank you, have an above average day :D" << endl;
}