#define N		1000000
#include <cstdio>

int n, b, c;
int a[N];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	scanf("%d %d", &b, &c);

	long long ans = 0;

	for (int i = 0; i < n; ++i) {
		a[i] -= b;
		ans += 1;
		if (a[i] <= 0) continue;
		ans += a[i] / c;
		a[i] %= c;
		if (a[i]) {
			ans += 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}