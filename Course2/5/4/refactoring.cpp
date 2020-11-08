#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human {
  public:
    const string Name;
    const string Type;
    const string Who = Type + ": " + Name;

    Human(const string& name, const string& t = "Human")
      : Name(name), Type(t) {}

    virtual void Walk(const string& destination) const {
      cout << Who << " walks to: " << destination << endl;
    }
};

class Student : public Human {
  private:
    const string FavouriteSong;

  public:
    Student(const string& name, const string& favouriteSong)
      : Human(name, "Student"), FavouriteSong(favouriteSong) {}

    void Learn() const {
      cout << Who << " learns" << endl;
    }

    void SingSong() const {
      cout << Who << " sings a song: " << FavouriteSong << endl;
    }

    void Walk(const string& destination) const override {
      Human::Walk(destination);
      SingSong();
    }
};

class Teacher : public Human {
  private:
    const string Subject;

  public:
    Teacher(const string& name, const string& subject)
      : Human(name, "Teacher"), Subject(subject) {}

    void Teach() const {
      cout << Who << " teaches: " << Subject << endl;
    }
};

class Policeman : public Human {
  public:
    Policeman(const string& name) : Human(name, "Policeman") {}

    void Check(const Human& h) const {
      cout << Who << " checks " << h.Type << ". "
        << h.Type << "'s name is: " << h.Name << endl;
    }
};

void VisitPlaces(const Human& h, const vector<string>& places) {
  for (auto p : places)
    h.Walk(p);
}

int main() {
  Teacher t("Jim", "Math");
  Student s("Ann", "We will rock you");
  Policeman p("Bob");

  VisitPlaces(t, {"Moscow", "London"});
  p.Check(s);
  VisitPlaces(s, {"Moscow", "London"});
  return 0;
}
