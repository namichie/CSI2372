// ==========================================================================
// $Id: main_skel.cpp,v 1.1 2016/10/10 20:41:56 jlang Exp $
// CSI2372 Lab Assignment 4 2016
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
// $Log: main_skel.cpp,v $
// Revision 1.1  2016/10/10 20:41:56  jlang
// Created Lab 4.
//
// ==========================================================================
#include <iostream>
#include <string>
#include <array>

#include "fruit_grower.h"

using std::cout;
using std::cerr;
using std::endl;


class RandBool {
	std::mt19937 d_generator;
	std::bernoulli_distribution d_distribution;

public:
	RandBool() : d_distribution(0.25) {
		std::random_device rd;
		d_generator.seed(rd());
	}

	bool get() {
		return d_distribution(d_generator);
	}
};


int main() {
	// Array of fruit
	std::array<Fruit, 10> fruits{ Fruit{ "apple" },
		Fruit{ "pear" },
		Fruit{ "pineapple" },
		Fruit{ "mango" },
		Fruit{ "kiwi" },
		Fruit{ "grape" },
		Fruit{ "banana" },
		Fruit{ "peach" },
		Fruit{ "nectarine" },
		Fruit{ "plum" },
	};
	// Array of growers
	std::array<Grower, 3> growers{ Grower{ "Smith" },
		Grower{ "Green Thumb" },
		Grower{ "Flowering Gardens" }
	};

	IdManager idm;
	RandBool rb;

	// Assigning IDs to each fruit and grower
	for (auto &f : fruits) {
		idm.assignFruitId(f);
	}

	for (auto &g : growers) {
		idm.assignGrowerId(g);
	}

	// Randomly assign fruits to growers and growers to fruits
	for (auto &g : growers) {
		for (auto &f : fruits) {
			if (rb.get()) {
				g.addFruit(f);
				f.addGrower(g);
			}
		}
	}
	 
	
	//Print fruit and its growers
	for (auto &f : fruits) {
		cout << "========================" << endl;
		f.print();
		cout << "-----------------------" << endl;
		auto growerIds = f.getGrowerIds();

		for (auto &gID : growerIds) {
			for (auto g : growers) {
				if (g.getCode() == gID) {
					cout << "    ";
					g.print();
					break;
				}
			}
		}
	}
	cout << "========================" << endl;


	//Print grower and its fruits
	for (auto &g : growers) {
		cout << "========================" << endl;
		g.print();
		cout << "-----------------------" << endl;

		auto fruitIds = g.getFruitIds();

		for (auto &fID : fruitIds) {
			for (auto f : fruits) {
				if (f.getCode() == fID) {
					cout << "    ";
					f.print();
					break;
				}
			}
		}
	}
	cout << "========================" << endl;
	return 0;
}