#include "query.h"

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
