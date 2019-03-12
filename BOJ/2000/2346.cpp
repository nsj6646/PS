#include <iostream>
#include <list>

using namespace std;


int main()
{
	int N;
	list<pair<int, int>> l;
	
	int num;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		l.push_back({ i, num });
	}
	auto it = l.begin();

	while (--N) {
		cout << it->first << ' ';
		auto temp = it;
		int step = it->second;

		if (step > 0) {
			++it;
			if (it == l.end()) {
				it = l.begin();
			}
			l.erase(temp);
			for (int i = 1; i < step; i++) {
				++it;
				if (it == l.end()) {
					it = l.begin();
				}
			}
		}
		else {
			step = -step;
			if (it == l.begin()) {
				it = l.end();
			}
			--it;
			l.erase(temp);
			for (int i = 1; i < step; i++) {
				if (it == l.begin()) {
					it = l.end();
				}
				--it;
			}
		}
	}
	cout << l.front().first;
	return 0;
}