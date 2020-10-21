#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Person {
	private:
		map<int, string>	first_name;
		map<int, string>	last_name;
		string	GetName(const map<int, string>& name, int year) {
			string	result;

			for (const auto& el : name) {
				if (el.first > year)
					break;
				result = el.second;
			}
			return (result);
		}
		vector<string>	GetNames(const map<int, string>& name, int year) {
			vector<string>	result;

			for (const auto& el : name) {
				if (el.first > year)
					break;
				if (result.size() == 0 || result[0] != el.second)
					result.insert(begin(result), 1, el.second);
			}
			return (result);
		}
		string		GetStringNames(vector<string> s) {
			string	str = s[0];

			if (s.size() == 1)
				return (str);
			str += " (";
			for (int i = 1; i < s.size(); i++) {
				if (i != 1)
					str += ", ";
				str += s[i];
			}
			str += ")";
			return (str);
		}
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

			first_name = this->GetName(this->first_name, year);
			last_name = this->GetName(this->last_name, year);
			if (first_name.empty() && last_name.empty())
				return ("Incognito");
			if (first_name.empty())
				return (last_name + " with unknown first name");
			if (last_name.empty())
				return (first_name + " with unknown last name");
			return (first_name + " " + last_name);
		}
		string GetFullNameWithHistory(int year) {
			vector<string>		first_name;
			vector<string>		last_name;

			first_name = this->GetNames(this->first_name, year);
			last_name = this->GetNames(this->last_name, year);
			if (first_name.size() == 0 && last_name.size() == 0)
				return ("Incognito");
			if (first_name.size() == 0) {
				return (GetStringNames(last_name) +
					" with unknown first name");
			}
			if (last_name.size() == 0) {
				return (GetStringNames(first_name) +
					" with unknown last name");
			}
			return (GetStringNames(first_name) +
				" " + GetStringNames(last_name));
		}
};