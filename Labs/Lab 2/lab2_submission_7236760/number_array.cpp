// ==========================================================================
// Lab 2 submission
// Author: NamChi Nguyen
// Student ID: 7236760
// ==========================================================================

#include <iostream>
#include <sstream>
#include "number_array.h"

using std::cout;
using std::endl;

/* Returns a pointer to the first occurence of the element in the array
Otherwise, returns a nullpointer
*/
int *findFirst(int value, int arr[], int length) { 
	int *foundFirst;
	for (int i = 0; i < length; i++) { 
		if (arr[i] == value) {
			foundFirst = &arr[i];
			return foundFirst;
		}
	}
	return nullptr;
}

/* Return a pointer to an array of all the found occurences of the value */
int **findAll(int value, int arr[], int length, int &numFound) { 

	int **res = new int *[length];

	int index = 0;
	for (int i = 0; i < length; ++i) {
		if (arr[i] == value) {
			res[index] = &arr[i];
			++index;
		}
	}
	numFound = index;
	return res;
}

/* Prints the array */
void printArray(int arr[], int length) {
	char *comma = "";
	std::stringstream ss;
	
	ss << "[";
	for (auto arrPtr = arr; arrPtr != arr + length; ++arrPtr) {
		ss << comma << (*arrPtr);
		comma = ",";
	}
	ss << "]";
	cout << ss.str();
}


/* Returns a pointer to a new array containing all the elements of the 1st and 2nd array */
int *append(int(*arrA)[4], int(&arrB)[3]) {

	int *res = new int[7];
	
	int index = 0;

	// I could not figure out a way to use a range loop for the pointer to an array
	for (int i = 0; i < 4; ++i) {
		res[index] = *(*arrA + i);
		++index;
	}

	for (auto i : arrB) { 
		res[index] = i;
		++index;
	}
	return res;
}