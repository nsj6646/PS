#include <cstdio>

int a[3];
int n;
int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x%y);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	int g = a[0];
	for (int i = 0; i < n-1; ++i) {
		g = gcd(g, a[i + 1]);
	}
	for (int i = 1; i <= g; ++i) {
		if (g%i) continue;
		printf("%d\n", i);
	}

	return 0;
}