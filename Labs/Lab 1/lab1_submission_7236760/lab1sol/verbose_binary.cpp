// $Id: verbose_binary.cpp,v 1.2 2016/09/23 01:00:59 jlang Exp $
// CSI2372 Solution code for laboratory 1
// ==========================================================================
// (C)opyright:
//
//   Jochen Lang
//   EECS, University of Ottawa
//   800 King Edward Ave.
//   Ottawa, On., K1N 6N5
//   Canada. 
//   http://www.eecs.uottawa.ca
// 
// Creator: jlang (Jochen Lang)
// Email:   jlang@eecs.uottawa.ca
// ==========================================================================
// $Log: verbose_binary.cpp,v $
// Revision 1.2  2016/09/23 01:00:59  jlang
// Added the 1+ liner.
//
// Revision 1.1  2016/09/17 04:29:36  jlang
// Created lab1 for 2016
//
// ==========================================================================
#include <iostream>
#include <bitset>

#include "verbose_binary.h"

using std::bitset;
using std::cout;
using std::endl;

enum class VerboseBinary : short { 
  Null=0,One=1,Two=2,Four=4,Eight=8,Sixteen=16
};

void convert(bitset<5> bs, VerboseBinary vb[6] ) {
  int pos = 0, val = 16; 
  /*
  if (bs.test(4)) vb[pos++]=VerboseBinary::Sixteen;
  if (bs.test(3)) vb[pos++]=VerboseBinary::Eight;
  if (bs.test(2)) vb[pos++]=VerboseBinary::Four;
  if (bs.test(1)) vb[pos++]=VerboseBinary::Two;
  if (bs.test(0)) vb[pos++]=VerboseBinary::One;
	*/
	for (int i=4; i>=0; --i) { 
	  if (bs.test(i)) vb[pos++]=static_cast<VerboseBinary>(val);
	  val >>= 1;
	}
  vb[pos]=VerboseBinary::Null;
}

bitset<5> convert(VerboseBinary vb[6]) {
  short accu = 0;
  for (int i=0; i<6; ++i ) {
    if (vb[i]==VerboseBinary::Null) break;
    accu += static_cast<int>(vb[i]);
  }
  return accu;
}


/* 
void print(VerboseBinary vb[6]) {
  cout << convert(vb) << endl;  
}
*/

void print( VerboseBinary vb[6] ) {
  for (int i=0; i<6; ++i ) {
    if (vb[i]==VerboseBinary::Null) {
      cout << "Null" << endl; break;
    }
    if (vb[i]==VerboseBinary::Sixteen) cout << "Sixteen";
    if (vb[i]==VerboseBinary::Eight) cout << "Eight";
    if (vb[i]==VerboseBinary::Four) cout << "Four";
    if (vb[i]==VerboseBinary::Two) cout << "Two";
    if (vb[i]==VerboseBinary::One) cout << "One";
    cout << ", ";
  }
}




void xorEquals(VerboseBinary aVB[6],
     VerboseBinary bVB[6]) {
  bitset<5> res = convert(aVB) ^ convert(bVB);    
  convert(res,aVB);
}

