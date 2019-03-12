#include <iostream>
#include <algorithm>
using namespace std;
int d[1001];
int p[10001];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = max(d[i], d[i - j] + p[j]);
		}
	}
	cout << d[n];
	return 0;
}