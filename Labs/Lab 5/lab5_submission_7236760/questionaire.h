// ==========================================================================
// $Id: questionaire_skel.h,v 1.1 2016/10/14 22:19:53 jlang Exp $
// CSI2372 Lab Assignment 5 2016
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
// $Log: questionaire_skel.h,v $
// Revision 1.1  2016/10/14 22:19:53  jlang
// Created Lab 5.
//
// ==========================================================================
#ifndef _Questionaire_h_
#define _Questionaire_h_

#include <string>
#include <iostream>
#include <vector>

#include "text_entry.h"

using std::string;

class Questionaire { 
	std::vector<TextEntry*> d_text; 
	std::vector<NumberResponse*> d_number; 
	std::vector<SelectionResponse*> d_select;
public:

	// Default ctor
	Questionaire();

	// Deep copy ctor
	Questionaire(const Questionaire &q);

	//Dtor
	~Questionaire();
	
	void addTextEntry(const TextEntry& _text);
	void addNumberResponse(const NumberResponse& _num);
	void addSelectionResponse(const SelectionResponse& _num);
	void conduct();
	void printAnswers();
};
#endif