#include <iostream>
#include <map>
#include <string>

using namespace std;

class Person {
  private:
    map<int, string> first_names;
    map<int, string> last_names;
    string FindByYear(const map<int, string>& m, int year) {
      auto it = m.upper_bound(year);
      string result;
      if (it != m.begin())
        result = (--it)->second;
      return result;
    }
  public:
    void    ChangeFirstName(int year, const string& first_name) {
      first_names[year] = first_name;
    }
    void    ChangeLastName(int year, const string& last_name) {
      last_names[year] = last_name;
    }
    string  GetFullName(int year) {
      const string first_name = this->FindByYear(first_names, year);
      const string last_name = this->FindByYear(last_names, year);
      if (first_name.empty() && last_name.empty())
        return "Incognito";
      else if (first_name.empty())
        return last_name + " with unknown first name";
      else if (last_name.empty())
        return first_name + " with unknown last name";
      else
        return first_name + " " + last_name;
    }
};
