#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = i + 1;
	}
	do {
		for (int x : v) {
			cout << x << ' ';
		}
		cout << '\n';
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}