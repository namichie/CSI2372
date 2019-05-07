// ==========================================================================
// Lab 1 submission
// Author: NamChi Nguyen
// Student ID: 7236760
// ==========================================================================

#include <iostream>
#include <bitset>
#include "verbose_binary.h"

using std::bitset;
using std::cout;
using std::endl;

/*
Convert bitset into an array of enumerations
*/
void convert(bitset<5> bs, VerboseBinary vb[arrSize]) {

	int pos = 0;

	if (bs.test(4)) {
		vb[pos++] = VerboseBinary::Sixteen;
	}
	if (bs.test(3)) {
		vb[pos++] = VerboseBinary::Eight;
	}
	if (bs.test(2)) {
		vb[pos++] = VerboseBinary::Four;
	}
	if (bs.test(1)) {
		vb[pos++] = VerboseBinary::Two;
	}
	if (bs.test(0)) {
		vb[pos++] = VerboseBinary::One;
	}
	vb[pos] = VerboseBinary::Null;
}

/*
Prints bitset as a binary number
*/
void print(VerboseBinary vb[arrSize]) {
	for (int i = 0; i < arrSize; ++i) {

		if (vb[i] == VerboseBinary::Sixteen) {
			std::cout << "Sixteen";
		}
		if (vb[i] == VerboseBinary::Eight) {
			std::cout << "Eight";
		}
		if (vb[i] == VerboseBinary::Four) {
			std::cout << "Four";
		}
		if (vb[i] == VerboseBinary::Two) {
			std::cout << "Two";
		}
		if (vb[i] == VerboseBinary::One) {
			std::cout << "One";
		}
		if (vb[i] == VerboseBinary::Null) {
			std::cout << "Null" << std::endl;
			break;
		}
		std::cout << ", ";
	}
}

/*
Perform binary xOR and return result in first array
*/
void xorEquals(VerboseBinary vb[arrSize], VerboseBinary vb2[arrSize]) {
	bitset<5> res;
	res = convertToBits(vb) ^ convertToBits(vb2);
	convert(res, vb);
}

/*
Helper function for xorEquals
*/
bitset<5> convertToBits(VerboseBinary vb[arrSize]) {
	bitset<5> res;
	for (int i = 0; i < arrSize; ++i) {
		if (vb[i] == VerboseBinary::Sixteen) {
			res.set(4, 1);
		}
		if (vb[i] == VerboseBinary::Eight) {
			res.set(3, 1);
		}
		if (vb[i] == VerboseBinary::Four) {
			res.set(2, 1);
		}
		if (vb[i] == VerboseBinary::Two) {
			res.set(1, 1);
		}
		if (vb[i] == VerboseBinary::One) {
			res.set(0, 1);
		}
	}
	return res;
}




