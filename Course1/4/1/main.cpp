#include <string>
using namespace std;

struct Specialization {
	string str;
	explicit Specialization(const string& str) {
		this->str = str;
	}
};

struct Course {
	string str;
	explicit Course(const string& str) {
		this->str = str;
	}
};

struct Week {
	string str;
	explicit Week(const string& str) {
		this->str = str;
	}
};

struct LectureTitle {
	string specialization;
	string course;
	string week;
	LectureTitle(Specialization s, Course c, Week w) {
		this->specialization = s.str;
		this->course = c.str;
		this->week = w.str;
	}
};