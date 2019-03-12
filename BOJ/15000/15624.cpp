#include <cstdio>

const long long mod = 1000000007;

int main()
{
	long long f0 = 0LL;
	long long f1 = 1LL;
	long long f;
	int n;
	scanf("%d", &n);
	if (n == 0) {
		printf("%d", f0);
		return 0;
	}
	else if (n == 1) {
		printf("%d", f1);
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		f = f0 + f1;
		f %= mod;
		f0 = f1;
		f1 = f;
	}
	printf("%d", f);
	return 0;
}