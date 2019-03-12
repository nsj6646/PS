//cC m= n!/(m!*(n-m)!)
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;
	if (m == 0) {
		cout << 0;
		return 0;
	}
	int k2 = 0, k5 = 0;
	int nm = n - m;
	for (long long i = 2; i <= n; i *= 2) {
		k2 += n / i;
	}
	for (long long i = 5; i <= n; i *= 5) {
		k5 += n / i;
	}
	for (long long i = 2; i <= m; i *= 2) {
		k2 -= m / i;
	}
	for (long long i = 5; i <= m; i *= 5) {
		k5 -= m / i;
	}
	for (long long i = 2; i <= nm; i *= 2) {
		k2 -= nm / i;
	}
	for (long long i = 5; i <= nm; i *= 5) {
		k5 -= nm / i;
	}
	cout << min(k2, k5);
	return 0;
}
/*
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	long long two = 0, five = 0;
	long long n, m;
	cin >> n >> m;
	for (long long i = 2; i <= n; i *= 2) {
		two += n / i;
	}
	for (long long i = 2; i <= n - m; i *= 2) {
		two -= (n - m) / i;
	}
	for (long long i = 2; i <= m; i *= 2) {
		two -= m / i;
	}
	for (long long i = 5; i <= n; i *= 5) {
		five += n / i;
	}
	for (long long i = 5; i <= n - m; i *= 5) {
		five -= (n - m) / i;
	}
	for (long long i = 5; i <= m; i *= 5) {
		five -= m / i;
	}
	cout << min(two, five) << '\n';
	return 0;
}
*/