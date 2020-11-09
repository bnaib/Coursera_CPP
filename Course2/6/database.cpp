#include "database.h"

void Database::Add(const Date& date, const std::string& event)
{
  if (db.count(date)) {
    const auto i = db[date].first.insert(event);
    if (i.second)
      db[date].second.push_back(i.first);
  } else {
    auto i = db[date].first.insert(event);
    db[date].second.push_back(i.first);
  }
}

void Database::Print(std::ostream& is) const {
  for (const auto& el : db) {
    for (const auto& it : el.second.second)
      is << el.first << " " << *it << std::endl;
  }
}

std::string Database::Last(const Date& date) const
{
  const auto it = db.upper_bound(date);
  std::ostringstream oss;

  if (it == db.begin())
    throw std::invalid_argument("No entries");
  oss << std::prev(it)->first << " " << *std::prev(it)->second.second.back();
  return (oss.str());
}
