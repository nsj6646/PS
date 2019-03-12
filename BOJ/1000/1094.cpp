#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt = 0;
int x;
vector<int> a;
int main()
{
	cin >> x;
	a.push_back(64);
	while (true) {
		int total = 0;
		for (int s : a) {
			total += s;
		}

		if (total > x) {
			auto iter = min_element(a.begin(), a.end());
			*iter /= 2;
			int l = *iter;
			a.push_back(l);
			if (total - l >= x) {
				a.pop_back();
				total -= l;
			}
		}
		if (total == x) {
			break;
		}
	}

	cout << a.size();
	
	return 0;
}