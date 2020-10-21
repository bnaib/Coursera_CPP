#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void	new_bus(
	map<string, vector<string>>& buses,
	map<string, vector<string>>& stops,
	vector<string>& out) {
	string	bus;
	string	stop;
	int		n;

	cin >> bus >> n;
	if (buses.count(bus)) {
		out.push_back("Incorrect bus name, skip");
		return ;
	}
	while (n-- > 0) {
		cin >> stop;
		buses[bus].push_back(stop);
		if (std::count(stops[stop].begin(), stops[stop].end(), bus) == 0)
			stops[stop].push_back(bus);
	}
}

void	buses_for_stop(
	map<string, vector<string>>& stops,
	vector<string>& out) {
	string	stop;
	string	str = "";
	bool	first = true;

	cin >> stop;
	if (stops.count(stop) == 0) {
		out.push_back("No stop");
		return ;
	}
	for (const string& s : stops[stop]) {
		if (first)
			first = false;
		else
			str += " ";
		str += s;
	}
	out.push_back(str);
}

void	stops_for_bus(
	map<string, vector<string>>& buses,
	map<string, vector<string>>& stops,
	vector<string>& out) {
	string	bus;
	string	str;
	size_t	i;

	cin >> bus;
	if (buses.count(bus) == 0) {
		out.push_back("No bus");
		return ;
	}
	for (const string& s : buses[bus]) {
		str = "Stop " + s + ":";
		i = 0;
		for (const string& ss : stops[s]) {
			if (ss != bus)
				str += " " + ss;
			i++;
		}
		if (i == 1)
			out.push_back("Stop " + s + ": no interchange");
		else
			out.push_back(str);
	}
}

void	all_buses(
	map<string, vector<string>>& buses,
	vector<string>& out) {
	string	bus;
	string	str = "";

	if (buses.size() == 0) {
		out.push_back("No buses");
		return ;
	}
	for (auto bus_el : buses) {
		str = "Bus " + bus_el.first + ":";
		for (const string& s : bus_el.second)
			str += " " + s;
		out.push_back(str);
	}
}

int		main() {
	map<string, vector<string>> buses;
	map<string, vector<string>> stops;
	vector<string>		out;
	int					n;
	string				str;

	cin >> n;
	while (n-- > 0) {
		cin >> str;
		if (str == "NEW_BUS")
			new_bus(buses, stops, out);
		else if (str == "BUSES_FOR_STOP")
			buses_for_stop(stops, out);
		else if (str == "STOPS_FOR_BUS")
			stops_for_bus(buses, stops, out);
		else
			all_buses(buses, out);
	}
	for (const string& s : out)
		cout << s << endl;
	return (0);
}