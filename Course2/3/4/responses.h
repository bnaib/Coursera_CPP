#pragma once

#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct		BusesForStopResponse {
	string						stop;
	map<string, vector<string>> stops_to_buses;
};

ostream&	operator << (ostream& os, const BusesForStopResponse& r);

struct		StopsForBusResponse {
	string						bus;
	map<string, vector<string>> buses_to_stops;
	map<string, vector<string>>	stops_to_buses;
};

ostream&	operator << (ostream& os, const StopsForBusResponse& r);

struct		AllBusesResponse {
	map<string, vector<string>>	buses_to_stops;
};

ostream&	operator <<(ostream& os, const AllBusesResponse& r);
