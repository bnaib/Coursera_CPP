#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <memory>

using namespace std;

class Figure {
  protected:
    const string N;
  public:
    Figure(const string& name = "FIGURE") : N(name) {};
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const= 0;
};

class Rect : public Figure {
  private:
    const double W = 0;
    const double H = 0;
    const double P = (W + H) * 2.0;
    const double S = W * H;
  public:
    Rect(double w, double h) : Figure("RECT"), W(w), H(h) {}
    string Name() const override { return (N); }
    double Perimeter() const override { return (P); }
    double Area() const override { return (S); }
};

class Triangle : public Figure {
  private:
    const double A = 0;
    const double B = 0;
    const double C = 0;
    const double P = A + B + C;
    const double p = P / 2.0;
    const double S = sqrt(p * (p - A) * (p - B) * (p - C));
  public:
    Triangle(double a, double b, double c) :
      Figure("TRIANGLE"), A(a), B(b), C(c) {}
    string Name() const override { return (N); }
    double Perimeter() const override { return (P); }
    double Area() const override { return (S); }
};

class Circle : public Figure {
  private:
    const double R = 0;
    const double P = 2.0 * 3.14 * R;
    const double S = 3.14 * R * R;
  public:
    Circle(double r) : Figure("CIRCLE"), R(r) {}
    string Name() const override { return (N); }
    double Perimeter() const override { return (P); }
    double Area() const override { return (S); }
};

shared_ptr<Figure> CreateFigure(istream& is) {
  string name;
  double d[3];
  shared_ptr<Figure> result;

  is >> name;
  if (name == "RECT") {
    is >> d[0] >> d[1];
    result = make_shared<Rect>(d[0], d[1]);
  } else if (name == "TRIANGLE") {
    is >> d[0] >> d[1] >> d[2];
    result = make_shared<Triangle>(d[0], d[1], d[2]);
  } else if (name == "CIRCLE") {
    is >> d[0];
    result = make_shared<Circle>(d[0]);
  }
  return (result);
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
