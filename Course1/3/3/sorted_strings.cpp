#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class SortedStrings {
	private:
		vector<string>	strings;
	public:
		void AddString(const string& s) {
			this->strings.push_back(s);
		}
		vector<string> GetSortedStrings() {
			sort(begin(this->strings), end(this->strings),
				[](string x1, string x2){return (x1 < x2);});
			return (this->strings);
		}
};