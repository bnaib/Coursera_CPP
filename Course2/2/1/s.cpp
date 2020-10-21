#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

enum class	QueryType {
	NewBus,
	BusesForStop,
	StopsForBus,
	AllBuses
};

struct		Query {
	QueryType		type;
	string			bus;
	string			stop;
	vector<string>	stops;
};

istream&	operator >>(istream& is, Query& q) {
	string		type;
	int			n;

	q.stops.clear();
	is >> type;
	if (type == "NEW_BUS") {
		is >> q.bus;
		q.type = QueryType::NewBus;
		is >> n;
		while (n-- > 0) {
			is >> q.stop;
			q.stops.push_back(q.stop);
		}
	} else if (type == "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	} else if (type == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	} else if (type == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	}
	return (is);
}

struct		BusesForStopResponse {
	string						stop;
	map<string, vector<string>> stops_to_buses;
};

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

struct		StopsForBusResponse {
	string						bus;
	map<string, vector<string>> buses_to_stops;
	map<string, vector<string>>	stops_to_buses;
};

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

struct		AllBusesResponse {
	map<string, vector<string>>	buses_to_stops;
};

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

class		BusManager {
	private:
		map<string, vector<string>> buses_to_stops;
		map<string, vector<string>> stops_to_buses;
	public:
		void					AddBus(
			const string& bus,
			const vector<string>& stops
		) {
			buses_to_stops.insert(make_pair(bus, stops));
			for (const auto& stop : stops)
				stops_to_buses[stop].push_back(bus);
		}
		BusesForStopResponse	GetBusesForStop(const string& stop) const {
			return (BusesForStopResponse{stop, this->stops_to_buses});
		}
		StopsForBusResponse GetStopsForBus(const string& bus) const {
			return (StopsForBusResponse{
				bus,
				this->buses_to_stops,
				this->stops_to_buses
			});
		}
		AllBusesResponse		GetAllBuses() const {
			return (AllBusesResponse{this->buses_to_stops});
		}
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
