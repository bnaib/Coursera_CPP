#include <iostream>
#include <string>
#include <vector>
using namespace std;


void	next_month(
	vector<vector<string>>& concerns,
	const vector<int>& days_of_month,
	int& month) {
	month++;
	if (month > 11)
		month = 0;
	else if (days_of_month[month] < days_of_month[month - 1]) {
		for (int i = days_of_month[month] + 1;
			i <= days_of_month[month - 1]; i++) {
			concerns[days_of_month[month] - 1].insert(
				concerns[days_of_month[month] - 1].end(),
				concerns[i - 1].begin(), concerns[i - 1].end());
		}
		concerns.resize(days_of_month[month]);
	} else
		concerns.resize(days_of_month[month]);
}

void	dump_day(const vector<string>& v, vector<string>& out) {
	string	str = to_string(v.size());

	for (string s : v)
		str += " " + s;
	out.push_back(str);
}

int main() {
	int						q;
	int						i;
	int						month = 0;
	string					str;
	vector<int> 			days_of_month =
		{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31};
	vector<vector<string>>	concerns(31);
	vector<string>			out;

	cin >> q;
	while (q-- > 0) {
		cin >> str;
		if (str == "NEXT") {
			next_month(concerns, days_of_month, month);
			continue ;
		}
		cin >> i;
		i--;
		if (str == "DUMP") {
			dump_day(concerns[i], out);
			continue ;
		}
		cin >> str;
		concerns[i].push_back(str);
	}
	for (string s : out)
		cout << s << endl;
	return (0);
}