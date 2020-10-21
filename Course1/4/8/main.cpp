#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
	string	name;
	string	surname;
	int		day;
	int		month;
	int		year;
};

int main() {
	int					n, i;
	vector<Student>		v;
	Student				s;
	string				str;

	cin >> n;
	while (n-- > 0) {
		cin >> s.name >> s.surname >> s.day >> s.month >> s.year;
		v.push_back(s);
	}
	cin >> n;
	while (n-- > 0) {
		cin >> str >> i;
		i--;
		if (i < 0 || i >= v.size() || !(str == "name" || str == "date"))
			cout << "bad request" << endl;
		else if (str == "name")
			cout << v[i].name << " " << v[i].surname << endl;
		else if (str == "date")
			cout << v[i].day << "." << v[i].month << "." << v[i].year << endl;
	}
}