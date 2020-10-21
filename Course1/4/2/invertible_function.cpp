#include <vector>
#include <algorithm>
using namespace std;

class FunctionPart {
	private:
		char	operation;
		double	value;
	public:
		FunctionPart(char operation, double value) {
			this->operation = operation;
			this->value = value;
		}
		double	Apple(double value) const{
			if (this->operation == '+')
				return value + this->value;
			else
				return value - this->value;
		}
		void	Ivert() {
			if (this->operation == '+')
				this->operation = '-';
			else
				this->operation = '+';
		}
};

class Function {
	private:
		vector<FunctionPart> acts;
	public:
		void		AddPart(char action, double value) {
			this->acts.push_back({action, value});
		}
		double		Apply(double value) const{
			for (const auto& i : this->acts)
				value = i.Apple(value);
			return (value);
		}
		void		Invert() {
			for (auto& i : this->acts)
				i.Ivert();
			reverse(this->acts.begin(), this->acts.end());
		}
};