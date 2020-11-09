#pragma once

#include "date.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

class Database {
  private:
    std::map<Date,
      std::pair<std::set<std::string>,
      std::vector<std::set<std::string>::iterator>>> db;
  public:
    void Add(const Date& date, const std::string& event);
    void Print(std::ostream& is) const;
    std::string Last(const Date& date) const;

    template<typename T>
    int RemoveIf(const T& f);

    template<typename T>
    std::vector<std::pair<Date, std::string>> FindIf(const T& f) const;

};

template<typename T>
int Database::RemoveIf(const T& f)
{
  int count = 0;

  for (auto& el : db) {
    auto i = std::stable_partition(
      el.second.second.begin(),
      el.second.second.end(),
      [&](const auto& event) -> bool {
        if (f(el.first, *event)) {
          count++;
          el.second.first.erase(*event);
          return false;
        }
        return true;
      }
    );
    el.second.second.erase(i, el.second.second.end());
  }
  for (auto it = db.begin(); it != db.end();) {
    if (it->second.first.empty())
      db.erase(it++);
    else
      it++;
  }
  return (count);
}

template<typename T>
std::vector<std::pair<Date, std::string>> Database::FindIf(const T& f) const
{
  std::vector<std::pair<Date, std::string>> v;

  for (const auto& el : db) {
    auto it = std::find_if(
      el.second.second.begin(),
      el.second.second.end(),
      [&](const auto& event) -> bool {
        if (f(el.first, *event))
          v.push_back(std::make_pair(el.first, *event));
        return false;
      }
    );
  }
  return (v);
}
