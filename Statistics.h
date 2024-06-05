#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/*Purpose: Reads integer data from file name that is passed to function
  Pre: Character array corresponding to file
  Post: Integer pointer that contains the data from the given file*/
int* readData (const char* filename, int& size);

/*Purpose: Finds the average value of a set of data
  Pre : Integer pointer of a set size 
  Post: returns a float*/
float findMean (int* numbers, int size);

/*Purpose: Finds the middle value of a set of data
  Pre: Integer pointer of a set size
  Post: returns a float*/
float findMedian (int* numbers, int size);

/*Purpose: Finds the number that occurs most often in a set of data
  Pre: Integer pointer of set size
  Post: Returns an integer */
int findMode (int* numbers, int size);

/*Purpose: Display the previous three values
  Pre: mean, median, and mode from previous functions
  Post: none*/
void displayInformation (float mean, float median, int mode);

#endif