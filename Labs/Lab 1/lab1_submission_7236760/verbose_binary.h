// ==========================================================================
// Lab 1 submission
// Author: NamChi Nguyen
// Student ID: 7236760
// ==========================================================================

#ifndef VERBOSE_BINARY_H
#define VERBOSE_BINARY_H
#include <bitset>
using std::bitset;

const int arrSize = 6;

// Scoped enum
enum class VerboseBinary : short int {
	One = 1,
	Two = 2,
	Four = 4,
	Eight = 8,
	Sixteen = 16,
	Null = 0
};


/*
Convert bitset into an array of enumerations
*/
void convert(bitset<5> bs, VerboseBinary vb[arrSize]);

/*
Prints bitset as a binary number
*/
void print(VerboseBinary vb[arrSize]);

/*
Perform binary xOR and return result in first array
*/
void xorEquals(VerboseBinary vb[arrSize], VerboseBinary vb2[arrSize]);

/*
Helper function for xorEquals
*/
bitset<5> convertToBits(VerboseBinary vb[arrSize]);
#endif