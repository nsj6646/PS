#include <cstdio>

int s[100001];
int n, m;
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		s[i] = s[i - 1] + x;
	}
	for (int i = 1; i <= m; i++) {
		int j, k;
		scanf("%d %d", &j, &k);
		printf("%d\n", s[k] - s[j-1]);
	}

	return 0;
}