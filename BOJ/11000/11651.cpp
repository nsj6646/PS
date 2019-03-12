#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<pair<int, int>> v;
	while (N--) {
		int x, y;
		cin >> x >> y;
		v.push_back({ y,x });
	}
	sort(v.begin(), v.end());
	for (auto &x : v) {
		cout << x.second << ' ' << x.first << '\n';
	}
	return 0;
}