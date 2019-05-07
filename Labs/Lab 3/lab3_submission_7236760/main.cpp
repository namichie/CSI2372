// ==========================================================================
// Lab 3 submission
// Author: NamChi Nguyen
// Student ID: 7236760
// ==========================================================================

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "bikerides.h"

using std::cout;
using std::endl;
using std::string;

// Helper print method
void printSingleRide(Ride *r) {

	cout << r->d_rider << " : Ride to "
		<< r->d_route.d_destination << " of "
		<< r->d_route.d_distance << "km in "
		<< r->d_time << "hrs." << endl;
}

int main() {

	std::array<Route, 3> options{ { Route{ "Trim Road", 25.0f }, Route{ "Gatineau Park", 30.0f }, Route{ "Pinhey Point", 45.0f } } };

	BikeRides br;
	
	Ride a{"Sophia", options[1], 4.5f}; 
	Ride b{"Sophia", options[2], 4.1f};
	Ride c{"Emma", options[0], 2.5f};
	Ride d{"Liam", options[1], 3.5f};
	Ride e{"Oliver", options[1], 5.1f};
	Ride f{"Maya", options[2], 3.2f};

	// Add 6 bikes
	br.addRide(a);
	br.addRide(b);
	br.addRide(c);
	br.addRide(d);
	br.addRide(e);
	br.addRide(f);
	br.BikeRides::print();
	cout << "------------------------------------------------- " << endl;

	// Get longest ride
	Ride *l = br.BikeRides::getLongestRide();
	printSingleRide(l);
	delete l;
	cout << "------------------------------------------------- " << endl;

	// Get Nth entry where N = 3 
	Ride nthRide;
	br.BikeRides::getNRide(3, nthRide);
	printSingleRide(&nthRide);
	cout << "------------------------------------------------- " << endl;
	
	// Remove all rides of Gatineau Park 
	br.BikeRides::removeRides(options[1]);
	br.BikeRides::print();
	cout << "------------------------------------------------- " << endl;
	return 0;
}