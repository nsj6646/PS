#include <cstdio>

int a[10];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int ans = 0;
	int m = n - 1;
	while (k > 0) {
		if (a[m] > k) {
			m -= 1;
			continue;
		}
		ans += k / a[m];
		k %= a[m];
	}
	printf("%d", ans);
	return 0;
}