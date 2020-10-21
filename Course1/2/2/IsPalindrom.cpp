#include <string>

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