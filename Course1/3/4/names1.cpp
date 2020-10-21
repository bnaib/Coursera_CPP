#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Person {
	private:
		map<int, string>	first_name;
		map<int, string>	last_name;
	public:
	void ChangeFirstName(int year, const string& first_name) {
		this->first_name[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		this->last_name[year] = last_name;
	}
	string GetFullName(int year) {
		string	first_name;
		string	last_name;
		int 	state = 0;

		for (const auto& el : this->first_name) {
			if (el.first > year)
				break;
			state |= 2;
			first_name = el.second;
		}
		for (const auto& el : this->last_name) {
			if (el.first > year)
				break;
			state |= 1;
			last_name = el.second;
		}
		if (state == 0)
			return ("Incognito");
		if (state == 1)
			return (last_name + " with unknown first name");
		if (state == 2)
			return (first_name + " with unknown last name");
		return (first_name + " " + last_name);
	}
};