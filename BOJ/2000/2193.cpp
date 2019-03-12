#include <iostream>
using namespace std;

long long d[91];
long long pn(int n) {
	if (n <= 1) {
		return n;
	}
	else {
		if (d[n] < 1) {
			d[n] = pn(n - 1) + pn(n - 2);
			return d[n];
		}
		return d[n];
	}
}
int main()
{
	int n;
	cin >> n;
	cout << pn(n);
	return 0;
}