#include <cstdio>
int Fibo(int n);
int dp[46];
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d",Fibo(n));
	return 0;
}
int Fibo(int n) {
	if (n <= 1) {
		return n;
	}
	else {
		if (dp[n] > 0) {
			return dp[n];
		}
		else {
			dp[n]= Fibo(n - 1) + Fibo(n - 2);
			return dp[n];
		}
	}
}