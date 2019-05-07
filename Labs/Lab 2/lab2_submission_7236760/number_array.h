// ==========================================================================
// Lab 2 submission
// Author: NamChi Nguyen
// Student ID: 7236760
// ==========================================================================

#ifndef NUMBER_ARRAY_H
#define NUMBER_ARRAY_H

int *findFirst(int value, int arr[], int length); 

void printArray(int arr[], int length);

int **findAll(int value, int arr[], int length, int& numFound);

int *append(int(*arrA)[4], int(&arrB)[3]);

#endif