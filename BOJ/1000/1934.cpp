#include <iostream>
using namespace std;

int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x%y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int g = gcd(a, b);
		cout << a / g*b / g*g << '\n';
	}
	return 0;
}
/*
(c++17)
#include <iostream>
#include <numeric>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		long long a, b;
		cin >> a >> b;
		cout << lcm(a, b) << '\n';
	}
	return 0;
}
*/