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

/*
Returns the ride which took the longest time.
Otherwise, if no Ride is stored, a nullpointer is returned.
*/
Ride* BikeRides::getLongestRide() { 
	
	if (d_rides.empty()) { 
		return nullptr;
	}  

	Ride longestRide; 
	longestRide.d_time = 0.0f;

	for (auto r : d_rides) {
		if (longestRide.d_time < r.d_time) {
			longestRide.d_time = r.d_time;
		
			// Get the rest of the info regarding the longest ride
			longestRide.d_rider = r.d_rider;
			longestRide.d_route.d_destination = r.d_route.d_destination;
			longestRide.d_route.d_distance = r.d_route.d_distance;
		}
	}
	return new Ride(longestRide);
}


/*
Returns true if the nth Ride exists and store the result of the nth ride in d_rides.
Otherwise, false and the result is unchanged
*/
bool BikeRides::getNRide(int nth, Ride& result) {

	if (static_cast<size_t>(nth) >= d_rides.size()) {
		return false;
	}

	result = d_rides.at(nth);

	return true;
}

/*
Add a new Ride to the vector of d_rides
but only if the ride is in the array of training routes
*/
void BikeRides::addRide(const Ride& r) {

	for (int i = 0; i < 3; ++i) {
		if (r.d_route.d_destination == d_trainingRoutes[i].d_destination) {
			d_rides.push_back(r);
			break;
		}
	}
}

/*
Print all the d_rides in order they have been stored
*/
void BikeRides::print() {

	for (auto r : d_rides) {

		cout << r.d_rider << " : Ride to "
			 << r.d_route.d_destination << " of "
			 << r.d_route.d_distance << "km in "
			 << r.d_time << "hrs." << endl;
	}
}

/*
Removes all rides of a given route and returns the number of removed rides
*/
int BikeRides::removeRides(const Route& r) {

	int numOfRemovedRides = 0;
	
	for (auto iter = d_rides.begin(); iter != d_rides.end();) {
		if (iter->d_route.d_destination == r.d_destination) {
			iter = d_rides.erase(iter); 
			++numOfRemovedRides;
		} else {
			++iter;
		}
	} 
	return numOfRemovedRides;
}