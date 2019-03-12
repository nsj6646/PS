#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<string> v;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	//sort(v.begin(), v.end(), [](string u, string v) {
	//	if (u.size() < v.size()) {
	//		return true;
	//	}
	//	else if (u.size() == v.size()) {
	//		return u < v;
	//	}
	//	else {
	//		return false;
	//	}
	//});
	//sort(v.begin(), v.end(), [](string u, string v) {
	//	if (u.size() == v.size()) {
	//		return u < v;
	//	}
	//	else {
	//		return u.size() < v.size();
	//	}
	//});
	//sort(v.begin(), v.end(), [](string u, string v) {
	//	return (u.size() < v.size()) || (u.size() == v.size() && u < v);
	//});
	sort(v.begin(), v.end(), [](string u, string v) {
		return make_pair(u.size(), u) < make_pair(v.size(), v);
	});
	auto last = unique(v.begin(), v.end());
	for (auto it = v.begin(); it != last; ++it) {
		cout << *it << '\n';
	}
	return 0;
}
