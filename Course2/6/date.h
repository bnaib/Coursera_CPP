#pragma once

#include <string>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <memory>

class Date {
  private:
    int Year;
    int Month;
    int Day;

    void SetYear(const int year);
    void SetMonth(const int month);
    void SetDay(const int day);
  public:
    Date(int y, int m, int d);
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
    std::string DateToStr() const;

};

Date ParseDate(std::istream& is);

std::ostream& operator << (std::ostream& os, const Date& date);
std::ostream& operator << (std::ostream& os, const std::pair<Date, std::string>& pair);

bool operator <(const Date& d1, const Date& d2);
bool operator <=(const Date& d1, const Date& d2);
bool operator >(const Date& d1, const Date& d2);
bool operator >=(const Date& d1, const Date& d2);
bool operator ==(const Date& d1, const Date& d2);
bool operator !=(const Date& d1, const Date& d2);
