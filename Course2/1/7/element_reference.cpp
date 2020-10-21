#include <map>
#include <stdexcept>

using namespace std;

template <typename F, typename S>
S&		GetRefStrict(map<F, S>& m, const F& k) {
	try {
		return (m.at(k));
	} catch(out_of_range) {
		throw runtime_error("runtime_error");
	}
}