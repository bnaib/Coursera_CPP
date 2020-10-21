#include <string>
#include <vector>
using namespace std;

void	MoveStrings(vector<string>& source, vector<string>& destination) {
	destination.insert(destination.end(), source.begin(), source.end());
	source.clear();
}