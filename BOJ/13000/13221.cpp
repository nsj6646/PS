#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x, y;
	cin >> x >> y;
	int n;
	cin >> n;
	int ansX, ansY;
	int ans = 987654321;
	for (int i = 0; i < n; ++i) {
		int xi, yi;
		cin >> xi >> yi;
		int taxi = abs(xi - x) + abs(yi - y);
		if (ans > taxi) {
			ans = taxi;
			ansX = xi;
			ansY = yi;
		}
	}
	cout << ansX << ' ' << ansY;
	return 0;
}