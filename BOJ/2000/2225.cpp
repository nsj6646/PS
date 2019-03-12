#include <iostream>
using namespace std;

//long long d[201][201];
long long d[201];
int main()
{
	int mod = 1000000000;
	int n, k;
	cin >> n >> k;
	//d[0][0] = 1LL;
	//for (int i = 1; i <= k; i++) {
	//	for (int j = 0; j <= n; j++) {
	//		for (int l = 0; l <= j; l++) {
	//			d[i][j] += d[i - 1][j - l];
	//			d[i][j] %= mod;
	//		}
	//	}
	//}
	d[0] = 1LL;
	for (int i = 1; i <= k; i++) {
		for (int j = n; j >= 0;j--) {
			for (int l = 1; l <= j; l++) {
				d[j] += d[j - l];
				d[j] %= mod;
			}
		}
	}
	cout << d[n];
	return 0;
}
/*
#include<cstdio>
int n, k, dp[201] = { 1 };
int main() {
scanf("%d %d", &n, &k);
for (int i = 1; i <= k; i++)
for (int j = 1; j <= n; j++) dp[j] = (dp[j - 1] + dp[j]) % (int)(1e9);
printf("%d", dp[n]);
return 0;
}
*/
