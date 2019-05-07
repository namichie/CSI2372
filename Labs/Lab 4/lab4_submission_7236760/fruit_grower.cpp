// ==========================================================================
// Lab 4 submission
// Author: NamChi Nguyen
// Student ID: 7236760
// ==========================================================================

#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <vector>

#include "fruit_grower.h"

using std::string;
using std::cout;
using std::endl;

// FRUIT
Fruit::Fruit(const string& _type) {
	d_type  = _type;
}

void Fruit::setCode(int _code) { 
	d_code = _code;
}

int Fruit::getCode() const {
	return d_code;
}

bool Fruit::addGrower(const Grower& _grower) {
	int id = _grower.getCode();
	
	if (id == -1) { //if no id
		return false;
	}
	d_growers.push_back(id);
	return true;
}

const std::vector<int>& Fruit::getGrowerIds() { 
	return d_growers;
}

void Fruit::print() const { 
	cout << d_code << " : " << d_type << endl;
}

//GROWER
Grower::Grower(const string& _type) {
	d_name = _type;
}

void Grower::setCode(int _code) {
	d_code = _code;
}

int Grower::getCode() const {
	return d_code;
}

bool Grower::addFruit(const Fruit& _fruit) {

	int id = _fruit.getCode();

	if (id == -1) { 
		return false;
	}
	d_fruits.push_back(id);
	return true;
}

const std::vector<int>& Grower::getFruitIds() {
	return d_fruits;
}

void Grower::print() const {
		cout << d_code << " : " << d_name << endl;
}

//ID
// Assigns an unique Id from 0..49 for the fruit and sets it in _fruit, passed by ref and returns id assigned
int IdManager::assignFruitId(Fruit& _fruit) {

	int id = -1;
	bool uniqueID = false;

	while (!uniqueID) {
		do {
			id = getRandomId();

		} while (id < 0 || id > 49); // If ID is not within range, keep getting a new ID

		uniqueID = true;
		for (auto f : d_fruitIds) {
			if (f == id) {
				uniqueID = false;
				break;
			}
		}
	}

	_fruit.Fruit::setCode(id);
	d_fruitIds.push_back(id);

	return id;
}


// Assigns an unique Id from 50..99 for the grower and sets it in _grower passed by ref
int IdManager::assignGrowerId(Grower& _grower) {

	auto id = -1;
	auto uniqueID = false;

	while (!uniqueID) {
		do {
			id = getRandomId();
		
		} while (id < 50 || id > 99);
		
		uniqueID = true;
		for (auto g : d_growerIds) {
			if (g == id) {
				uniqueID = false;
				break;
			}
		}
	}

	_grower.Grower::setCode(id);
	d_growerIds.push_back(id);

	return id;
}