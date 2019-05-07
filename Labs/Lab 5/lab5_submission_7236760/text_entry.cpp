// ==========================================================================
// Lab 5 submission
// Author: NamChi Nguyen
// Student ID: 7236760
// ==========================================================================

#include <string>
#include <iostream>
#include "text_entry.h"

using std::string;

using std::cout;
using std::endl;
using std::cin;

// TEXT ENTRY
// Ctor
TextEntry::TextEntry(const string& _question) : d_question(_question) {}

// show question and record answer; returns the length of the answer 
int TextEntry::ask() {

	cout << d_question << " : ";
	cin >> d_answer; 

	return d_answer.length();
}

// get the current answer
string TextEntry::getResponse() {
	return d_answer;
}

// print question and answer
void TextEntry::print() {
	cout << d_question << " : " << d_answer << endl;
}


//NUMBER RESPONSE
//Ctor
NumberResponse::NumberResponse(const string& _question) : TextEntry(_question) {

	// Setting some default limits
	d_lowerLim = 0;
	d_upperLim = 10000;
}

// show question and record answer; returns true if entered number is within the limits
bool NumberResponse::ask() {

	cout << d_question << " : ";
	cin >> d_number;

	return limits(d_lowerLim, d_upperLim);
}

// sets the limits; returns true if current number is within the limits (inclusive)
bool NumberResponse::limits(int _lowerLim, int _upperLim) {
	d_lowerLim = _lowerLim;
	d_upperLim = _upperLim;

	return (d_number >= d_lowerLim && d_number <= d_upperLim);
}

// turn limits off
void NumberResponse::limitOff() {
	d_activeLim = false;
}

// accessor: get the current answer
int NumberResponse::getNumber() {
	return d_number;
}

// print question and answer
void NumberResponse::print() {
	cout << d_question << " : " << d_number << endl;
}


//SELECTION RESPONSE
//Ctor
SelectionResponse::SelectionResponse(const string& _question, int numChoices) : NumberResponse(_question) {
	d_lowerLim = 0;
	d_upperLim = numChoices - 1;
}

// show question and record answer; returns the answer
// will ask until a valid choice is made 
int SelectionResponse::ask() {

	do {
		NumberResponse::ask();
	} while (d_number < d_lowerLim || d_number > d_upperLim);  // if true, continue to ask, if false then it's a valid choice
	return d_number;
}

// accessor: get the current answer 
int SelectionResponse::getSelection() {
	return d_number;
}

// print question and answer
void SelectionResponse::print() {
	cout << d_question << " : " << d_number << endl;
}