#include "bus_manager.h"

void                  BusManager::AddBus(
  const string& bus,
  const vector<string>& stops
) {
  buses_to_stops.insert(make_pair(bus, stops));
  for (const auto& stop : stops)
    stops_to_buses[stop].push_back(bus);
}

BusesForStopResponse  BusManager::GetBusesForStop(const string& stop) const {
  return (BusesForStopResponse{stop, this->stops_to_buses});
}

StopsForBusResponse   BusManager::GetStopsForBus(const string& bus) const {
  return (StopsForBusResponse{
    bus,
    this->buses_to_stops,
    this->stops_to_buses
  });
}

AllBusesResponse      BusManager::GetAllBuses() const {
  return (AllBusesResponse{this->buses_to_stops});
}
