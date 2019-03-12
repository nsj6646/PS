#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
	return y ? gcd(y, x%y) : x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	int x = a1 * b2 + a2 * b1;
	int y = b1 * b2;
	int g = gcd(x, y);
	cout << x / g << ' ' << y / g;
	return 0;
}