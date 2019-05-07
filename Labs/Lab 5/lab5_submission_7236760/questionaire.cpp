// ==========================================================================
// Lab 5 submission
// Author: NamChi Nguyen
// Student ID: 7236760
// ==========================================================================

#include <string>
#include <iostream>
#include <vector>
#include "questionaire.h"

// Default ctor
Questionaire::Questionaire() {}

// Deep copy ctor
Questionaire::Questionaire(const Questionaire &q) {

	for (auto t : q.d_text) {
		d_text.push_back(new TextEntry(*t));
	}

	for (auto n : q.d_number) {
		d_number.push_back(new NumberResponse(*n));
	}

	for (auto s : q.d_select) {
		d_select.push_back(new SelectionResponse(*s));
	}
}

void Questionaire::addTextEntry(const TextEntry& _text) {
	TextEntry *t = new TextEntry(_text);
	d_text.push_back(t);
}
void Questionaire::addNumberResponse(const NumberResponse& _num) {
	NumberResponse *n = new NumberResponse(_num);
	d_number.push_back(n);
}
void Questionaire::addSelectionResponse(const SelectionResponse& _num) {
	SelectionResponse *s = new SelectionResponse(_num);
	d_select.push_back(s);
}

void Questionaire::conduct() {
	for (auto t : d_text) {
		t->ask();
	}
	for (auto n : d_number) {
		n->ask();
		n->getNumber(); 
	}
	for (auto s : d_select) { 
		s->ask();
		s->getSelection();
	}
}


void Questionaire::printAnswers() {

	for (auto t : d_text) {
		t->print();
	}

	for (auto n : d_number) {
		n->print();
	}

	for (auto s : d_select) {
		s->print();
	}
}

//Destructor
Questionaire::~Questionaire() {
	// Free the memory from the pointers
	for (auto t : d_text) {
		delete t;
	}

	for (auto n : d_number) {
		delete n;
	}

	for (auto s : d_select) {
		delete s;
	}
}




