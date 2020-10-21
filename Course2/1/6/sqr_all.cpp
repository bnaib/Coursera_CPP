#include <vector>
#include <map>
#include <utility>

using namespace std;

template <typename F, typename S>
pair<F, S>	operator *(const pair<F, S>& in1, const pair<F, S>& in2);
template <typename F, typename S>
map<F, S>	operator *(const map<F, S>& in1, const map<F, S>& in2);
template <typename T>
vector<T>	operator *(const vector<T>& in1, const vector<T>& in2);
template <typename T>
T			Sqr(const T& in);

template <typename F, typename S>
pair<F, S>	operator *(const pair<F, S>& in1, const pair<F, S>& in2) {
	return (make_pair(in1.first * in2.first, in1.second * in2.second));
}

template <typename F, typename S>
map<F, S>	operator *(const map<F, S>& in1, const map<F, S>& in2) {
	map<F, S>	result;
	for (const auto& [key, value] : in1)
		result[key] = value * in2.at(key);
	return (result);
}

template <typename T>
vector<T>	operator *(const vector<T>& in1, const vector<T>& in2) {
	vector<T>	result;
	for (int i = 0; i < in1.size() && i < in2.size(); i++)
		result.push_back(in1.at(i) * in2.at(i));
	return (result);
}

template <typename T>
T			Sqr(const T& in) {
	return (in * in);
}