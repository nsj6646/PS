#include <iostream>
using namespace std;
long long d[101][10];
int main()
{
	int n;
	cin >> n;
	int mod = 1000000000;
	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			//if (j == 0) {
			//	d[i][j] = d[i - 1][1];
			//}
			//else if (j > 0 && j < 9) {
			//	d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % mod;
			//}
			//else if (j == 9) {
			//	d[i][j] = d[i - 1][8];
			//}
			d[i][j] = 0;
			if (j - 1 >= 0)d[i][j] += d[i - 1][j - 1];
			if (j + 1 <= 9)d[i][j] += d[i - 1][j + 1];
			d[i][j] %= mod;
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += d[n][i];
	}
	ans %= mod;
	cout << ans;
	return 0;
}