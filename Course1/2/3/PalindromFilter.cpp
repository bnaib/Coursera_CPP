#include <string>
#include <vector>

bool	IsPalindrom(string str) {
	size_t	endi = str.size();
	size_t	starti = 0;

	if (endi-- < 2)
		return (true);
	while (endi >= starti) {
		if (str[endi] != str[starti])
			return (false);
		endi--;
		starti++;
	}
	return (true);	
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> result;

	for (string w : words) {
		if (IsPalindrom(w) && w.size() >= minLength)
			result.push_back(w);
	}
	return (result);
}