#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[9];
vector<int> v;
void solve(int i, int sum) {
	if (i == 9) {
		if (v.size() == 7 && sum == 100) {
			sort(v.begin(), v.end());
			for (int x : v) {
				cout << x << '\n';
			}
			exit(0);
		}
	}
	if (v.size()==7&&sum == 100) {
		sort(v.begin(), v.end());
		for (int x : v) {
			cout << x << '\n';
		}
		exit(0);
	}
	if (i < 9) {
		solve(i + 1, sum);
		v.push_back(a[i]);
		solve(i + 1, sum + a[i]);
		v.pop_back();
	}
}
int main()
{
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
	}
	sort(a, a + 9);
	solve(0,0);
	return 0;
}