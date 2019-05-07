// $Id: verbose_binary.h,v 1.1 2016/09/17 04:29:36 jlang Exp $
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
// $Log: verbose_binary.h,v $
// Revision 1.1  2016/09/17 04:29:36  jlang
// Created lab1 for 2016
//
// ==========================================================================
#ifndef VERBOSE_BINARY_H_
#define VERBOSE_BINARY_H_

#include <bitset>

using std::bitset;

enum class VerboseBinary : short;

void convert(bitset<5> bs, VerboseBinary vb[6]);
void print(VerboseBinary vb[6]);
void xorEquals(VerboseBinary aVB[6],
     VerboseBinary bVB[6]);
     
#endif
