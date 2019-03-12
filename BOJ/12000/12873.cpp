#include <iostream>
#include <list>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	list<int> l;
	for (int i = 1; i <= n; i++) {
		l.push_back(i);
	}
	auto it = l.begin();
	long long t = 1;
	while (l.size() > 1) {
		int n = (t*t*t) % l.size();
		if (n == 0) {
			if (it == l.begin()) {
				it = l.end();
			}
			--it;
			it = l.erase(it);
			if (it == l.end()) {
				it = l.begin();
			}
			t += 1;
			continue;
		}
		//int n = t * t*t;
		for (int i = 1; i < n; i++) {
			++it;
			if (it == l.end()) {
				it = l.begin();
			}
		}
		it = l.erase(it);
		if (it == l.end()) {
			it = l.begin();
		}
		t += 1;
	}
	cout << l.front();
	return 0;
}