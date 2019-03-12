#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ull a, b;
	cin >> a >> b;
	if (a > b) swap(a, b);
	if (a == b) cout << 0 << '\n';
	else cout << b - a - 1 << '\n';
	for (ull i = a+1; i < b; ++i) {
		cout << i << ' ';
	}
	return 0;
}