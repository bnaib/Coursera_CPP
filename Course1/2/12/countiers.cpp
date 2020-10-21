#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


void	change_capital(
	map<string, string>& m,
	vector<string>& out) {
	string	country;
	string	capital;

	cin >> country >> capital;
	if (m.count(country)) {
		if (m[country] == capital)
			out.push_back("Country " + country + " hasn't changed its capital");
		else
			out.push_back("Country " + country + " has changed its capital from "
				+ m[country] + " to " + capital);
	} else
		out.push_back("Introduce new country " + country + " with capital " + capital);
	m[country] = capital;
}

void	rename(
	map<string, string>& m,
	vector<string>& out) {
	string	old_country;
	string	new_country;

	cin >> old_country >> new_country;
	if (new_country == old_country ||
		m.count(old_country) == 0 ||
		m.count(new_country))
		out.push_back("Incorrect rename, skip");
	else {
		m[new_country] = m[old_country];
		m.erase(old_country);
		out.push_back("Country " + old_country
			+ " with capital " + m[new_country]
			+ " has been renamed to " + new_country);
	}
}

void	about(
	map<string, string>& m,
	vector<string>& out) {
	string	country;

	cin >> country;
	if (m.count(country))
		out.push_back("Country " + country + " has capital " + m[country]);
	else
		out.push_back("Country " + country + " doesn't exist");
}

void	dump(
	map<string, string>& m,
	vector<string>& out) {
	bool	first = true;
	string	str = "";

	if (m.size()) {
		for (const auto& el : m) {
			if (first)
				first = false;
			else
				str += " ";
			str += el.first + "/" + el.second;
		}
		out.push_back(str);
	} else
		out.push_back("There are no countries in the world");
}

int		main() {
	map<string, string> m;
	vector<string>		out;
	int					n;
	string				str;

	cin >> n;
	while (n-- > 0) {
		cin >> str;
		if (str == "CHANGE_CAPITAL")
			change_capital(m, out);
		else if (str == "RENAME")
			rename(m, out);
		else if (str == "ABOUT")
			about(m, out);
		else
			dump(m, out);
	}
	for (const string& s : out)
		cout << s << endl;
	return (0);
}