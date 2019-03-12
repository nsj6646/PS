#include <cstdio>

int a[100000];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int sum = 0;
	for (int i = 0; i < k; i++) {
		sum += a[i];
	}
	int ans = sum;

	for (int i = 1; i <= n - k; i++) {
		sum = sum - a[i - 1] + a[i + k - 1];
		if (ans < sum) {
			ans = sum;
		}
	}

	printf("%d", ans);
	return 0;
}