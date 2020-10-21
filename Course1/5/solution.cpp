#include <iostream>
#include <sstream>
#include <exception>
#include <map>
#include <set>
#include <iomanip>
using namespace std;

class Date {
	private:
		int	day;
		int month;
		int year;
		void		ThrowWrongDateFormat(const string& date) {
			throw domain_error("Wrong date format: " + date);
		}
		void		CheckAndIgnore(istream& s, char c, const string& date) {
			if (s.peek() != c)
				ThrowWrongDateFormat(date);
			s.ignore(1);
		}
	public:
		int			GetYear() const{return (this->year);}
		int			GetMonth() const{return (this->month);}
		int			GetDay() const{return (this->day);}
		explicit	Date(const string& date) {
			stringstream	ss(date);

			ss >> this->year;
			this->CheckAndIgnore(ss, '-', date);
			ss >> this->month;
			this->CheckAndIgnore(ss, '-', date);
			if (!(ss >> this->day))
				ThrowWrongDateFormat(date);
			if (!ss.eof())
				ThrowWrongDateFormat(date);
			if (this->month < 1 || this->month > 12) {
				throw domain_error("Month value is invalid: "
					+ to_string(this->month));
			}
			if (this->day < 1 || this->day > 31)
				throw domain_error("Day value is invalid: "
					+ to_string(this->day));
		}
};

bool	operator <(const Date& d1, const Date& d2) {
	if (d1.GetYear() != d2.GetYear())
		return (d1.GetYear() < d2.GetYear());
	if (d1.GetMonth() != d2.GetMonth())
		return (d1.GetMonth() < d2.GetMonth());
	return (d1.GetDay() < d2.GetDay());
}

ostream&	operator <<(ostream& s, const Date& d) {
	s << setfill('0') << setw(4) << d.GetYear()
		<< "-" << setfill('0') << setw(2) << d.GetMonth()
		<< "-" << setfill('0') << setw(2) << d.GetDay();
	return (s);
}

class Database {
	private:
		map<Date, set<string>> db;
	public:
		void AddEvent(const Date& date, const string& event) {
			this->db[date].insert(event);
		}
		bool DeleteEvent(const Date& date, const string& event) {
			if (this->db.count(date) == 0 ||
				this->db[date].count(event) == 0) {
				cout << "Event not found" << endl;
				return (false);
			} else {
				cout << "Deleted successfully" << endl;
				this->db[date].erase(event);
				return (true);
			}
		}
		int  DeleteDate(const Date& date) {
			int		n;

			if ((n = this->db.count(date)) != 0)
				n = this->db[date].size();
			cout << "Deleted " << n << " events" << endl;
			this->db.erase(date);
			return (n);
		}
		void Find(const Date& date) const {
			if (this->db.count(date) == 0)
				return ;
			for (const auto& i : this->db.at(date))
				cout << i << endl;
		}

		void Print() const {
			for (const auto& i : this->db) {
				for (const auto& k : i.second)
					cout << i.first << " " << k << endl;
			}
		}
};



void	Print(map<Date, set<string>>& m, stringstream& ss) {
	for (const auto& i : m) {
		for (const auto& k : i.second)
			cout << i.first << " " << k << endl;
	}
}

void	LoadCommand(Database& db, const string& line) {
	stringstream	ss;
	string	command;
	string		date;
	string		action;

	ss << line;
	ss >> command;
	if (command == "") {
		return ;
	} else if (command == "Add") {
		ss >> date >> action;
		db.AddEvent(Date(date), action);
	} else if (command == "Del") {
		ss >> date;
		Date 	d(date);
		if (ss >> action)
			db.DeleteEvent(d, action);
		else
			db.DeleteDate(d);
	} else if (command == "Find") {
		ss >> date;
		db.Find(Date(date));
	} else if (command == "Print") {
		db.Print();
	} else
		 throw domain_error("Unknown command: " + command);
}

int main() {
	Database db;

	string command;
	while (getline(cin, command)) {
		try {
			LoadCommand(db, command);
		} catch (domain_error& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}