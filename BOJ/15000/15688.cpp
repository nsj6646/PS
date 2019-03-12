#include <cstdio>

int a[2000001];
int counting[2000001];
int ans[2000001];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a[x + 1000000] += 1;
	}
	for (int i = 0; i < 2000001; i++) {
		counting[i] += a[i];
	}
	for (int i = 0; i < 2000001; i++) {
		while (--counting[i] >= 0) {
			printf("%d\n", i - 1000000);
		}
	}
	return 0;
}