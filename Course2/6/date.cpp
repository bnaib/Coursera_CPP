#include "date.h"

void Date::SetYear(const int year) { this->Year = year; }

void Date::SetMonth(const int month) {
  if (month < 1 || month > 12) {
    throw std::domain_error("Month value is invalid: "
      + std::to_string(month));
  }
  this->Month = month;
}

void Date::SetDay(const int day) {
  if (day < 1 || day > 31) {
    throw std::domain_error("Day value is invalid: "
      + std::to_string(day));
  }
  this->Day = day;
}

Date::Date(int y, int m, int d) {
  this->SetYear(y);
  this->SetMonth(m);
  this->SetDay(d);
}

int Date::GetYear() const { return this->Year; }
int Date::GetMonth() const { return this->Month; }
int Date::GetDay() const { return this->Day; }

std::string Date::DateToStr() const {
  std::ostringstream oss;
  oss << *this;
  return oss.str();
}

Date ParseDate(std::istream& is) {
  int year, month, day;
  std::string d;

  is >> d;
  std::stringstream ss(d);

  if (!(ss >> year) || ss.peek() != '-')
    throw std::domain_error("Wrong date format: " + d);
  ss.ignore();
  if (!(ss >> month) || ss.peek() != '-')
    throw std::domain_error("Wrong date format: " + d);
  ss.ignore();
  if (!(ss >> day) || !ss.eof())
    throw std::domain_error("Wrong date format: " + d);
  return Date(year, month, day);
}

std::ostream& operator <<(std::ostream& s, const Date& d) {
  s << std::setfill('0') << std::setw(4) << d.GetYear()
    << "-" << std::setfill('0') << std::setw(2) << d.GetMonth()
    << "-" << std::setfill('0') << std::setw(2) << d.GetDay();
  return (s);
}

std::ostream& operator << (std::ostream& os, const std::pair<Date, std::string>& p) {
  os << p.first << " " << p.second;
  return os;
}

bool operator <(const Date& d1, const Date& d2) {
  if (d1.GetYear() != d2.GetYear())
    return (d1.GetYear() < d2.GetYear());
  if (d1.GetMonth() != d2.GetMonth())
    return (d1.GetMonth() < d2.GetMonth());
  return (d1.GetDay() < d2.GetDay());
}

bool operator <=(const Date& d1, const Date& d2) {
  if (d1.GetYear() != d2.GetYear())
    return (d1.GetYear() < d2.GetYear());
  if (d1.GetMonth() != d2.GetMonth())
    return (d1.GetMonth() < d2.GetMonth());
  return (d1.GetDay() <= d2.GetDay());
}

bool operator >(const Date& d1, const Date& d2) {
  if (d1.GetYear() != d2.GetYear())
    return (d1.GetYear() > d2.GetYear());
  if (d1.GetMonth() != d2.GetMonth())
    return (d1.GetMonth() > d2.GetMonth());
  return (d1.GetDay() > d2.GetDay());
}

bool operator >=(const Date& d1, const Date& d2) {
  if (d1.GetYear() != d2.GetYear())
    return (d1.GetYear() > d2.GetYear());
  if (d1.GetMonth() != d2.GetMonth())
    return (d1.GetMonth() > d2.GetMonth());
  return (d1.GetDay() >= d2.GetDay());
}

bool operator ==(const Date& d1, const Date& d2) {
  return (
    d1.GetYear() == d2.GetYear() &&
    d1.GetMonth() == d2.GetMonth() &&
    d1.GetDay() == d2.GetDay()
  );
}

bool operator !=(const Date& d1, const Date& d2) {
  return (
    d1.GetYear() != d2.GetYear() ||
    d1.GetMonth() != d2.GetMonth() ||
    d1.GetDay() != d2.GetDay()
  );
}
