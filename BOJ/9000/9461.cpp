#include <iostream>
using namespace std;

long long d[101];
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		d[1] = d[2] = d[3] = 1;
		d[4] = d[5] = 2;
		for (int i = 6; i <= n; i++) {
			d[i] = d[i - 5] + d[i - 1];
		}
		cout << d[n] << '\n';
	}
	return 0;
}