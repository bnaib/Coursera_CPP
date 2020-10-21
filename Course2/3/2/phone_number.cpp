#include <regex>
#include "phone_number.h"

using namespace std;

PhoneNumber::PhoneNumber(const string &international_number) {
  smatch res;
  regex rx("^\\+(.+?)-(.+?)-(.+)$");

  if (!regex_match(international_number, res, rx)) {
    throw invalid_argument("String: \"" + international_number
      + "\" isn't phone");
  }
  this->country_code_ = res[1];
  this->city_code_ = res[2];
  this->local_number_ = res[3];
}

string    PhoneNumber::GetCountryCode() const {
  return (this->country_code_);
}

string    PhoneNumber::GetCityCode() const {
  return (this->city_code_);
}

string    PhoneNumber::GetLocalNumber() const {
  return (this->local_number_);
}

string    PhoneNumber::GetInternationalNumber() const {
  return (
    "+" + this->country_code_ +
    "-" + this->city_code_ +
    "-" + this->local_number_
  );
}