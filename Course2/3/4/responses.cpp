#include "responses.h"

ostream&	operator << (ostream& os, const BusesForStopResponse& r) {
	if (r.stops_to_buses.count(r.stop) == 0) {
		cout << "No stop";
	} else {
		for (const string& bus : r.stops_to_buses.at(r.stop)) {
			cout << bus << " ";
		}
	}
	return (os);
}

ostream&	operator << (ostream& os, const StopsForBusResponse& r) {
	bool	first = true;

	if (r.buses_to_stops.count(r.bus) == 0) {
		cout << "No bus";
	} else {
		for (const string& stop : r.buses_to_stops.at(r.bus)) {
			if (!first)
				cout << endl;
			first = false;
			cout << "Stop " << stop << ": ";
			if (r.stops_to_buses.at(stop).size() == 1) {
				cout << "no interchange";
			} else {
				for (const string& other_bus : r.stops_to_buses.at(stop)) {
					if (r.bus != other_bus) {
						cout << other_bus << " ";
					}
				}
			}
		}
	}
	return (os);
}

ostream&	operator <<(ostream& os, const AllBusesResponse& r) {
	bool	first = true;

	if (r.buses_to_stops.empty()) {
		cout << "No buses";
	} else {
		for (const auto& bus_item : r.buses_to_stops) {
			if (!first)
				cout << endl;
			first = false;
			cout << "Bus " << bus_item.first << ": ";
			for (const string& stop : bus_item.second) {
				cout << stop << " ";
			}
		}
	}
	return (os);
}
