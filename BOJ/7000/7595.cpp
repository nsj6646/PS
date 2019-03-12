#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while (cin >> n && n) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= i; ++j) {
				cout << '*';
			}
			cout << '\n';
		}

	}
	return 0;
}