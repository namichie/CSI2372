// ==========================================================================
// $Id: main.cpp,v 1.1 2016/09/17 04:29:35 jlang Exp $
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
// $Log: main.cpp,v $
// Revision 1.1  2016/09/17 04:29:35  jlang
// Created lab1 for 2016
//
// ==========================================================================
#include <iostream>
#include <bitset>

#include "verbose_binary.h"

/** Do not alter
* Your solution must work with this main program
**/
int main() {
  int a,b;
  bitset<5> aBs,bBs;
  std::cout << "Enter two numbers between 0-31:" << std::endl;
  std::cin >> a >> b;
  if (a<0 || a>31) return -1;
  if (b<0 || b>31) return -2;
  aBs = static_cast<bitset<5>>(a);
  bBs = static_cast<bitset<5>>(b);
  // std::cout << aBs << " " << bBs << std::endl;
  VerboseBinary aVB[6];
  VerboseBinary bVB[6];
  convert(aBs,aVB);
  convert(bBs,bVB);
  print(aVB);
  print(bVB);  
  xorEquals(aVB,bVB);
  print(aVB);
  return 0;
}
