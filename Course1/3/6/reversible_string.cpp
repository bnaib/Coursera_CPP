#include <string>
#include <algorithm>
using namespace std;

class ReversibleString {
	private:
		string	str;
	public:
		ReversibleString() {}
		ReversibleString(string str) {
			this->str = str;
		}
		void	Reverse() {
			reverse(this->str.begin(), this->str.end());
		}
		string ToString() const {
			return (this->str);
		}
};