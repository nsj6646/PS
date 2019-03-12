#include <iostream>

using namespace std;
typedef unsigned long long ull;

ull gcd(ull x, ull y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x%y);
}
int main()
{
	ios::sync_with_stdio(false);

	ull a, b;
	cin >> a >> b;
	ull n = gcd(a, b);

	for (ull i = 0; i < n; i++) {
		cout << 1;
	}
	return 0;
}